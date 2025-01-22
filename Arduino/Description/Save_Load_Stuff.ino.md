This code manages **persistent storage** for the system's settings, Wi-Fi credentials, and tray configurations using the **Preferences library** in ESP32. The Preferences library allows data to be stored in non-volatile memory (NVS), so it persists across device reboots. Here's a detailed explanation of the key functions:

---

### **1. Overview**
- **Purpose:** Save and load system settings, Wi-Fi credentials, and tray configurations to/from non-volatile storage.
- **Key Features:**
  - **Wi-Fi Management:** Save and load Wi-Fi SSID and password.
  - **System Settings:** Save and load general settings like volume, time zone, and passcode.
  - **Tray Settings:** Save and load individual tray configurations (e.g., name, alert time, color).
  - **Clear Preferences:** Remove stored data when needed.

---

### **2. Wi-Fi Management**

#### **2.1. `loadWifiCredentials`**
- **Purpose:** Load Wi-Fi credentials (SSID and password) from the "wifi" namespace in Preferences.
- **How it works:**
  1. Opens the "wifi" namespace in read-only mode.
  2. Checks if the keys `"ssid"` and `"password"` exist.
  3. If they exist, retrieves their values and stores them in the provided `ssid` and `password` references.
  4. Returns `true` if credentials are found, otherwise `false`.

```cpp
bool loadWifiCredentials(String &ssid, String &password) {
  preferences.begin("wifi", true); // Open "wifi" namespace in read-only mode
  if (!preferences.isKey("ssid") || !preferences.isKey("password")) {
    preferences.end();
    return false; // Credentials not found
  }
  ssid = preferences.getString("ssid", ""); // Load SSID
  password = preferences.getString("password", ""); // Load password
  preferences.end();
  return true; // Credentials loaded successfully
}
```

---

#### **2.2. `saveWifiCredentials`**
- **Purpose:** Save Wi-Fi credentials (SSID and password) to the "wifi" namespace in Preferences.
- **How it works:**
  1. Opens the "wifi" namespace in read/write mode.
  2. Stores the provided `ssid` and `password` as strings.
  3. Closes the Preferences.

```cpp
void saveWifiCredentials(const char* ssid, const char* password) {
  preferences.begin("wifi", false); // Open "wifi" namespace in read/write mode
  preferences.putString("ssid", ssid); // Save SSID
  preferences.putString("password", password); // Save password
  preferences.end();
}
```

---

#### **2.3. `clearWifiPreferences`**
- **Purpose:** Clear all Wi-Fi credentials stored in the "wifi" namespace.
- **How it works:**
  1. Opens the "wifi" namespace in read/write mode.
  2. Clears all keys in the namespace.
  3. Closes the Preferences.

```cpp
void clearWifiPreferences() {
  preferences.begin("wifi", false); // Open "wifi" namespace in read/write mode
  preferences.clear(); // Clear all data in the namespace
  preferences.end();
}
```

---

### **3. System Settings Management**

#### **3.1. `saveSettings`**
- **Purpose:** Save general system settings (e.g., volume, time zone, passcode) to the "appSettings" namespace.
- **How it works:**
  1. Opens the "appSettings" namespace in read/write mode.
  2. Retrieves values from the GUI (e.g., dropdowns, sliders, checkboxes).
  3. Stores the values in Preferences using appropriate keys.
  4. Closes the Preferences.

```cpp
void saveSettings() {
  preferences.begin("appSettings", false); // Open "appSettings" namespace in read/write mode

  // Save dropdown value (e.g., number of trays)
  installedTrays = lv_dropdown_get_selected(ui_HowManyTrayDROP) + 1;
  preferences.putInt("installedTrays", installedTrays);

  // Save checkbox values (e.g., mute sound, screensaver)
  muteSound = lv_obj_has_state(ui_MuteCHK, LV_STATE_CHECKED);
  preferences.putBool("muteSound", muteSound);

  clockSS = lv_obj_has_state(ui_ScreensaverCHK1, LV_STATE_CHECKED);
  preferences.putBool("clockSS", clockSS);

  // Save slider values (e.g., UTC offset, volume)
  utcOffset = lv_slider_get_value(ui_UTCSlider);
  preferences.putInt("utcOffset", utcOffset);

  spkvolume = lv_slider_get_value(ui_VolSlider);
  preferences.putInt("spkvolume", spkvolume);

  // Save passcode and Telegram settings
  preferences.putString("passcode", passcode);
  preferences.putBool("enabledpasscode", enabledpasscode);
  preferences.putString("bot_token", BOT_TOKEN);
  preferences.putString("chat_id", CHAT_ID);

  preferences.end(); // Close the Preferences
}
```

---

#### **3.2. `loadSettings`**
- **Purpose:** Load general system settings from the "appSettings" namespace and update the GUI.
- **How it works:**
  1. Opens the "appSettings" namespace in read-only mode.
  2. Retrieves values from Preferences using appropriate keys.
  3. Updates the GUI elements (e.g., dropdowns, sliders, checkboxes) with the loaded values.
  4. Closes the Preferences.

```cpp
void loadSettings() {
  preferences.begin("appSettings", true); // Open "appSettings" namespace in read-only mode

  // Load dropdown value (e.g., number of trays)
  installedTrays = preferences.getInt("installedTrays", 1);
  lv_dropdown_set_selected(ui_HowManyTrayDROP, installedTrays - 1);

  // Load checkbox values (e.g., mute sound, screensaver)
  muteSound = preferences.getBool("muteSound", false);
  lv_obj_add_state(ui_MuteCHK, muteSound ? LV_STATE_CHECKED : 0);

  clockSS = preferences.getBool("clockSS", false);
  lv_obj_add_state(ui_ScreensaverCHK1, clockSS ? LV_STATE_CHECKED : 0);

  // Load slider values (e.g., UTC offset, volume)
  utcOffset = preferences.getInt("utcOffset", 0);
  lv_slider_set_value(ui_UTCSlider, utcOffset, LV_ANIM_OFF);

  spkvolume = preferences.getInt("spkvolume", 10);
  lv_slider_set_value(ui_VolSlider, spkvolume, LV_ANIM_OFF);

  // Load passcode and Telegram settings
  passcode = preferences.getString("passcode", "");
  enabledpasscode = preferences.getBool("enabledpasscode", false);
  BOT_TOKEN = preferences.getString("bot_token", "");
  CHAT_ID = preferences.getString("chat_id", "");

  preferences.end(); // Close the Preferences
}
```

---

### **4. Tray Settings Management**

#### **4.1. `saveTraySettings`**
- **Purpose:** Save individual tray settings (e.g., name, alert time, color) to the "traySettings" namespace.
- **How it works:**
  1. Opens the "traySettings" namespace in read/write mode.
  2. Stores tray-specific values (e.g., name, hour, minute, color) using keys that include the tray index.
  3. Closes the Preferences.

```cpp
void saveTraySettings(int trayIndex) {
  if (trayIndex < 1 || trayIndex > 10) return; // Validate tray index

  preferences.begin("traySettings", false); // Open "traySettings" namespace in read/write mode

  // Save tray name
  char key[20];
  snprintf(key, sizeof(key), "trayName%d", trayIndex);
  preferences.putString(key, lv_textarea_get_text(ui_TraydescTXT));

  // Save tray hour and minute
  snprintf(key, sizeof(key), "trayHour%d", trayIndex);
  preferences.putInt(key, lv_dropdown_get_selected(ui_TrayHourDROP));

  snprintf(key, sizeof(key), "trayMin%d", trayIndex);
  preferences.putInt(key, lv_dropdown_get_selected(ui_TrayMinutesDROP) * 5);

  // Save tray alert enabled status
  snprintf(key, sizeof(key), "trayAlertEna%d", trayIndex);
  preferences.putBool(key, lv_obj_has_state(ui_TrayAlertCHK, LV_STATE_CHECKED));

  // Save tray color
  snprintf(key, sizeof(key), "trayColor%d", trayIndex);
  preferences.putInt(key, lv_roller_get_selected(ui_ColorRoller));

  preferences.end(); // Close the Preferences
}
```

---

#### **4.2. `loadTraySettings`**
- **Purpose:** Load individual tray settings from the "traySettings" namespace and update the GUI.
- **How it works:**
  1. Opens the "traySettings" namespace in read-only mode.
  2. Retrieves tray-specific values (e.g., name, hour, minute, color) using keys that include the tray index.
  3. Updates the GUI elements with the loaded values.
  4. Closes the Preferences.

```cpp
void loadTraySettings(int trayIndex) {
  if (trayIndex < 1 || trayIndex > 10) return; // Validate tray index

  preferences.begin("traySettings", true); // Open "traySettings" namespace in read-only mode

  // Load tray name
  char key[20];
  snprintf(key, sizeof(key), "trayName%d", trayIndex);
  String trayName = preferences.getString(key, "");
  lv_textarea_set_text(ui_TraydescTXT, trayName.c_str());

  // Load tray hour and minute
  snprintf(key, sizeof(key), "trayHour%d", trayIndex);
  int hourIndex = preferences.getInt(key, 0);
  lv_dropdown_set_selected(ui_TrayHourDROP, hourIndex);

  snprintf(key, sizeof(key), "trayMin%d", trayIndex);
  int minIndex = preferences.getInt(key, 0) / 5;
  lv_dropdown_set_selected(ui_TrayMinutesDROP, minIndex);

  // Load tray alert enabled status
  snprintf(key, sizeof(key), "trayAlertEna%d", trayIndex);
  bool alertEnabled = preferences.getBool(key, false);
  if (alertEnabled) {
    lv_obj_add_state(ui_TrayAlertCHK, LV_STATE_CHECKED);
  } else {
    lv_obj_clear_state(ui_TrayAlertCHK, LV_STATE_CHECKED);
  }

  // Load tray color
  snprintf(key, sizeof(key), "trayColor%d", trayIndex);
  int colorIndex = preferences.getInt(key, 0);
  lv_roller_set_selected(ui_ColorRoller, colorIndex, LV_ANIM_OFF);

  preferences.end(); // Close the Preferences
}
```

---

### **5. Summary**
- **Persistent Storage:** The Preferences library is used to store and retrieve data across reboots.
- **Namespaces:** Different namespaces (`wifi`, `appSettings`, `traySettings`) are used to organize data.
- **GUI Integration:** The code interacts with GUI elements (e.g., sliders, dropdowns, checkboxes) to save and load settings.
- **Flexibility:** Supports saving/loading for multiple trays and various system settings.

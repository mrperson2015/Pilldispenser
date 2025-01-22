This code handles **Wi-Fi configuration** for a smart device using a graphical interface powered by **LVGL**. It allows the user to scan for available Wi-Fi networks, select one from a dropdown menu, enter the password, and connect to the network. Here's a detailed explanation of each part:

---

### **1. Connecting to Wi-Fi**

#### **1.1. `keyboard_wifi_event_handler`**
- **Purpose:** Handles user interactions with the Wi-Fi configuration screen's keyboard (e.g., "Accept" or "Cancel" buttons).
- **How it works:**
  - **`LV_EVENT_READY`:** Triggered when the user presses "Accept" after entering the Wi-Fi password.
    - Displays a "Connecting to Wi-Fi..." message.
    - Creates a timer (`connect_wifi_event_cb`) to initiate the Wi-Fi connection process.
  - **`LV_EVENT_CANCEL`:** Triggered when the user presses "Cancel."
    - Navigates back to the settings screen (`ui_SettingSCR`).

```cpp
static void keyboard_wifi_event_handler(lv_event_t * e) {
  lv_event_code_t code = lv_event_get_code(e);
  if (code == LV_EVENT_READY) { // User pressed "Accept"
    lv_label_set_text(ui_WifiScanPANLBL, "Connecting to Wi-Fi...");
    lv_obj_clear_flag(ui_WifiScanPAN, LV_OBJ_FLAG_HIDDEN); // Show the Wi-Fi scan panel
    lv_timer_t* timer = lv_timer_create(connect_wifi_event_cb, 500, NULL); // Start connection timer
  }
  if (code == LV_EVENT_CANCEL) { // User pressed "Cancel"
    lv_scr_load(ui_SettingSCR); // Go back to the settings screen
  }
}
```

---

#### **1.2. `connect_wifi_event_cb`**
- **Purpose:** Timer callback function that initiates the Wi-Fi connection process.
- **How it works:**
  - Calls the `connectToWifi()` function to handle the actual connection logic.
  - Deletes the timer after execution.

```cpp
static void connect_wifi_event_cb(lv_timer_t * timer) {
  connectToWifi(); // Start the Wi-Fi connection process
  lv_timer_del(timer); // Delete the timer
}
```

---

#### **1.3. `connectToWifi`**
- **Purpose:** Handles the logic for connecting to a Wi-Fi network.
- **How it works:**
  1. **Retrieve User Input:**
     - Gets the selected SSID from the dropdown menu (`ui_SSIDDropDown`).
     - Gets the password from the text box (`ui_PassTxtBox`).
  2. **Start Wi-Fi Connection:**
     - Disconnects any existing connections and sets the Wi-Fi mode to `WIFI_STA` (station mode).
     - Attempts to connect to the selected SSID using the provided password.
     - Retries up to 10 times, with a 1-second delay between attempts.
  3. **Handle Connection Result:**
     - If connected:
       - Displays a success message with the device's IP address.
       - Updates the UI to show the Wi-Fi icon and hide the "No Wi-Fi" icon.
       - Saves the Wi-Fi credentials using `saveWifiCredentials()`.
     - If not connected:
       - Displays a failure message and updates the UI to show the "No Wi-Fi" icon.

```cpp
void connectToWifi() {
  uint16_t selectedIdx = lv_dropdown_get_selected(ui_SSIDDropDown); // Get selected SSID index
  char ssid[32];
  lv_dropdown_get_selected_str(ui_SSIDDropDown, ssid, sizeof(ssid)); // Get SSID string

  const char* password = lv_textarea_get_text(ui_PassTxtBox); // Get password from text box

  // Start Wi-Fi connection
  WiFi.disconnect(true);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  int maxRetries = 10; // Retry up to 10 times
  while (WiFi.status() != WL_CONNECTED && maxRetries-- > 0) {
    delay(1000); // Wait 1 second between retries
  }

  if (WiFi.status() == WL_CONNECTED) { // Connection successful
    String message = "Connected successfully!\n\nIP Address: ";
    message += WiFi.localIP().toString(); // Append IP address
    lv_obj_add_flag(ui_NoWifiIconIMG, LV_OBJ_FLAG_HIDDEN); // Hide "No Wi-Fi" icon
    lv_obj_clear_flag(ui_WifiIconIMG, LV_OBJ_FLAG_HIDDEN); // Show Wi-Fi icon
    internetstatus = 1; // Update internet status
    lv_label_set_text(ui_WifiScanPANLBL, message.c_str()); // Show success message
    lv_label_set_text(ui_SkipWifiBTNLBL, "Next"); // Update button label
    saveWifiCredentials(ssid, password); // Save credentials
  } else { // Connection failed
    lv_obj_clear_flag(ui_NoWifiIconIMG, LV_OBJ_FLAG_HIDDEN); // Show "No Wi-Fi" icon
    lv_obj_add_flag(ui_WifiIconIMG, LV_OBJ_FLAG_HIDDEN); // Hide Wi-Fi icon
    internetstatus = 0; // Update internet status
    lv_label_set_text(ui_WifiScanPANLBL, "Failed to connect.\nClick scan to try again."); // Show failure message
  }
}
```

---

### **2. Scanning for Wi-Fi Networks**

#### **2.1. `scan_wifi_event_handler`**
- **Purpose:** Handles the "Scan" button click event on the Wi-Fi configuration screen.
- **How it works:**
  - Displays a "Scanning Wi-Fi networks..." message.
  - Creates a timer (`scan_wifi_event_cb`) to initiate the Wi-Fi scan process.

```cpp
static void scan_wifi_event_handler(lv_event_t * e) {
  lv_event_code_t code = lv_event_get_code(e);
  if (code == LV_EVENT_CLICKED) { // User clicked the "Scan" button
    lv_label_set_text(ui_WifiScanPANLBL, "Please wait...\n\nScanning wifi networks\nin progress");
    lv_obj_clear_flag(ui_WifiScanPAN, LV_OBJ_FLAG_HIDDEN); // Show the Wi-Fi scan panel
    lv_timer_t* timer = lv_timer_create(scan_wifi_event_cb, 500, NULL); // Start scan timer
  }
}
```

---

#### **2.2. `scan_wifi_event_cb`**
- **Purpose:** Timer callback function that initiates the Wi-Fi scan process.
- **How it works:**
  - Calls the `populateSSIDDropdown()` function to scan for networks and populate the dropdown menu.
  - Deletes the timer after execution.

```cpp
static void scan_wifi_event_cb(lv_timer_t * timer) {
  populateSSIDDropdown(); // Scan for Wi-Fi networks and populate the dropdown
  lv_timer_del(timer); // Delete the timer
}
```

---

#### **2.3. `populateSSIDDropdown`**
- **Purpose:** Scans for available Wi-Fi networks and populates the dropdown menu with the results.
- **How it works:**
  1. **Start Wi-Fi Scan:**
     - Sets the Wi-Fi mode to `WIFI_STA` and disconnects any existing connections.
     - Calls `WiFi.scanNetworks()` to scan for available networks.
  2. **Populate Dropdown:**
     - Iterates through the list of detected networks and adds each SSID to the dropdown menu (`ui_SSIDDropDown`).
  3. **Enable Input Fields:**
     - Enables the keyboard and password text box for user input.
     - Hides the Wi-Fi scan panel.

```cpp
void populateSSIDDropdown() {
  WiFi.mode(WIFI_STA); // Set Wi-Fi to station mode
  WiFi.disconnect(); // Disconnect any existing connections
  delay(100); // Short delay before scanning

  int16_t networkCount = WiFi.scanNetworks(); // Scan for networks

  for (int i = 0; i < networkCount; ++i) {
    lv_dropdown_add_option(ui_SSIDDropDown, WiFi.SSID(i).c_str(), LV_DROPDOWN_POS_LAST); // Add SSID to dropdown
  }
  lv_obj_clear_state(ui_Keyboard, LV_STATE_DISABLED); // Enable keyboard
  lv_obj_clear_state(ui_PassTxtBox, LV_STATE_DISABLED); // Enable password text box
  lv_obj_add_flag(ui_WifiScanPAN, LV_OBJ_FLAG_HIDDEN); // Hide Wi-Fi scan panel
}
```

---

### **3. Summary**

#### **Connecting to Wi-Fi:**
1. **User Action:**
   - Selects an SSID from the dropdown and enters the password.
   - Presses "Accept" to connect.
2. **System Behavior:**
   - Initiates the connection process (`connectToWifi`).
   - Displays success or failure messages based on the connection result.
   - Saves the Wi-Fi credentials if the connection is successful.

#### **Scanning for Wi-Fi Networks:**
1. **User Action:**
   - Presses the "Scan" button to search for available networks.
2. **System Behavior:**
   - Scans for networks and populates the dropdown menu with the results.
   - Enables the keyboard and password text box for user input.

#### **Key Features:**
- **Dynamic Dropdown:** Populates the dropdown menu with available Wi-Fi networks.
- **User Feedback:** Provides real-time feedback (e.g., "Connecting to Wi-Fi...", "Failed to connect").
- **Credential Storage:** Saves Wi-Fi credentials for future use.

This system provides a user-friendly interface for configuring Wi-Fi on the device.

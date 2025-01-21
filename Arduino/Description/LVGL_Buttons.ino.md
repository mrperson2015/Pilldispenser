This code defines **event handlers** for various buttons and user interactions in a smart dispensing system. Each handler responds to a specific button press or event, performing actions like saving settings, dispensing items, clearing preferences, or navigating between screens. Below is a detailed explanation of the key event handlers and their functionality.

---

### **1. General Structure of Event Handlers**
Each event handler follows this structure:
```cpp
static void <ButtonName>_event_handler(lv_event_t * e) {
  lv_event_code_t code = lv_event_get_code(e); // Get the event type (e.g., CLICKED)
  if (code == LV_EVENT_CLICKED) {
    // Perform the action for the button
  }
}
```
- **`lv_event_t *e`**: Represents the event triggered by the button.
- **`lv_event_get_code(e)`**: Retrieves the type of event (e.g., `LV_EVENT_CLICKED` for a button press).
- **Action Logic**: Executes specific actions when the button is clicked.

---

### **2. Key Event Handlers**

#### **2.1. `SettingBackBTN_event_handler`**
- **Purpose:** Saves settings and reboots the system when the "Back" button in the settings screen is clicked.
- **How it works:**
  - Calls `saveSettings()` to save the current configuration.
  - Creates a timer (`reboot_timer`) to restart the ESP32 after 1 second.

```cpp
static void SettingBackBTN_event_handler(lv_event_t * e) {
  if (lv_event_get_code(e) == LV_EVENT_CLICKED) {
    saveSettings();
    lv_timer_t* timer = lv_timer_create(reboot_timer, 1000, NULL);
  }
}

static void reboot_timer(lv_timer_t * timer) {
  ESP.restart(); // Restart the ESP32
  lv_timer_del(timer); // Delete the timer
}
```

---

#### **2.2. `WifiClearBTN_event_handler`**
- **Purpose:** Clears saved Wi-Fi preferences when the "Clear Wi-Fi" button is clicked.
- **How it works:**
  - Calls `clearWifiPreferences()` to delete stored Wi-Fi credentials.

```cpp
static void WifiClearBTN_event_handler(lv_event_t * e) {
  if (lv_event_get_code(e) == LV_EVENT_CLICKED) {
    clearWifiPreferences();
  }
}
```

---

#### **2.3. `VolTestBTN_event_handler`**
- **Purpose:** Tests the speaker volume when the "Test Volume" button is clicked.
- **How it works:**
  - Reads the value of the volume slider (`ui_VolSlider`) and sets the speaker volume (`spkvolume`).
  - Plays a test sound using `Playsound(2)`.

```cpp
static void VolTestBTN_event_handler(lv_event_t * e) {
  if (lv_event_get_code(e) == LV_EVENT_CLICKED) {
    spkvolume = lv_slider_get_value(ui_VolSlider);
    Playsound(2);
  }
}
```

---

#### **2.4. `DisplaceBTN_event_handler`**
- **Purpose:** Starts the displacement process for a tray when the "Displace" button is clicked.
- **How it works:**
  - Sets `displacementinprogress` to `true`.
  - Calls `displace()` with the selected tray and the number of steps from the dropdown menu (`ui_DisplaceTrayDROP`).

```cpp
static void DisplaceBTN_event_handler(lv_event_t * e) {
  if (lv_event_get_code(e) == LV_EVENT_CLICKED) {
    displacementinprogress = true;
    displace(selectedtray, lv_dropdown_get_selected(ui_DisplaceTrayDROP) + 1);
  }
}
```

---

#### **2.5. `HalfDisplaceBTN_event_handler`**
- **Purpose:** Starts a "half displacement" process for alignment purposes.
- **How it works:**
  - Sets `fixaligment` to `true` and starts the dispensing process for the selected tray by creating a timer (`dispense_step1_timer`).

```cpp
static void HalfDisplaceBTN_event_handler(lv_event_t * e) {
  if (lv_event_get_code(e) == LV_EVENT_CLICKED) {
    fixaligment = true;
    traytodispense = selectedtray;
    lv_timer_t* timer = lv_timer_create(dispense_step1_timer, 250, NULL);
  }
}
```

---

#### **2.6. `TrueDismissBTN_event_handler`**
- **Purpose:** Handles dismissal of alerts when the "Dismiss" button is clicked.
- **How it works:**
  - Loops through all trays to check if any are triggered.
  - If a tray is triggered, starts a batch dispensing process (`dispensebatch()`).
  - Updates flags like `alertinprogress` and `dismissinprogress`.

```cpp
static void TrueDismissBTN_event_handler(lv_event_t * e) {
  if (lv_event_get_code(e) == LV_EVENT_CLICKED) {
    for (int i = 1; i <= 10; i++) {
      if (traytriggered[i]) {
        dispensebatchinprogress = true;
        dismissinprogress = true;
        currentpixelcolor = index_to_pixel(trayColor[i]);
        currentcolordispense = trayColor[i];
        dispensebatch(currentcolordispense);
        break;
      }
    }
    alertinprogress = false;
    lv_obj_add_state(ui_DispenseBTN, LV_STATE_DISABLED);
  }
}
```

---

#### **2.7. `DispenseAgainBTN_event_handler`**
- **Purpose:** Dispenses trays that are checked again when the "Dispense Again" button is clicked.
- **How it works:**
  - Loops through all trays and dispenses any that are checked (`trayCheckedState[i]`).
  - Clears the checked state and disables buttons after dispensing.

```cpp
static void DispenseAgainBTN_event_handler(lv_event_t * e) {
  if (lv_event_get_code(e) == LV_EVENT_CLICKED) {
    for (int i = 1; i <= 10; i++) {
      if (trayCheckedState[i]) {
        currentpixelcolor = index_to_pixel(trayColor[i]);
        dispense(i);
        trayCheckedState[i] = false;
        lv_obj_clear_state(ui_TrayIMG[i], LV_STATE_CHECKED);
      }
    }
    lv_obj_add_state(ui_DispenseBTN, LV_STATE_DISABLED);
    lv_obj_add_state(ui_TraycfgBTN, LV_STATE_DISABLED);
  }
}
```

---

#### **2.8. `DispenseBTN_event_handler`**
- **Purpose:** Handles the main "Dispense" button click.
- **How it works:**
  - If passcode protection is disabled, calls `Dispense_Action()` to start dispensing.
  - If passcode protection is enabled, navigates to the lock screen.

```cpp
static void DispenseBTN_event_handler(lv_event_t * e) {
  if (lv_event_get_code(e) == LV_EVENT_CLICKED) {
    if (!enabledpasscode) {
      Dispense_Action();
    } else {
      nextaction = 1;
      lv_scr_load(ui_LockSCR);
    }
  }
}
```

---

#### **2.9. `TraycfgBTN_event_handler`**
- **Purpose:** Opens the tray configuration screen for the selected tray.
- **How it works:**
  - Identifies the selected tray (`selectedtray`) and loads its settings.
  - If passcode protection is enabled, navigates to the lock screen.

```cpp
static void TraycfgBTN_event_handler(lv_event_t * e) {
  if (lv_event_get_code(e) == LV_EVENT_CLICKED) {
    for (int i = 1; i <= 10; i++) {
      if (trayCheckedState[i]) selectedtray = i;
    }
    if (!enabledpasscode) {
      loadTraySettings(selectedtray);
      lv_scr_load(ui_TrayConfigSCR);
    } else {
      nextaction = 2;
      lv_scr_load(ui_LockSCR);
    }
  }
}
```

---

### **3. Summary**
- **Event Handlers:** These functions respond to user interactions (e.g., button clicks) and perform specific actions like saving settings, starting dispensing, or navigating between screens.
- **Timers:** Some actions (e.g., dispensing) are delayed using timers to allow for step-by-step execution.
- **State Management:** Flags like `alertinprogress`, `dismissinprogress`, and `trayCheckedState[]` are used to track the system's current state and ensure proper behavior.

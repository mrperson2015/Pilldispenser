This function, `passkey_event_handler`, handles the **passcode input** from the user. It is triggered when the user interacts with the passcode input field (e.g., presses "Accept" or "Cancel"). The function validates the entered passcode and determines the next action based on the system's state.

---

### **1. Purpose**
- **Validate Passcode:** Checks if the entered passcode matches the system's stored passcode (`passcode`).
- **Perform Next Action:** Executes a specific action (e.g., dispensing, loading tray settings, or opening the settings screen) based on the value of `nextaction`.
- **Handle Cancel:** Clears the passcode input and returns to the main screen if the user cancels the operation.

---

### **2. Key Variables**
- **`codefromscreen`:** The passcode entered by the user, retrieved from the text area (`ui_PassTXT`).
- **`passcode`:** The correct passcode stored in the system.
- **`nextaction`:** A flag that determines what action to perform after the passcode is validated:
  - `1`: Dispense action.
  - `2`: Load tray settings.
  - `3`: Open the settings screen.

---

### **3. How It Works**

#### **Step 1: Check Event Type**
The function first determines the type of event triggered:
- **`LV_EVENT_READY`:** The user has entered the passcode and pressed "Accept."
- **`LV_EVENT_CANCEL`:** The user has pressed "Cancel."

```cpp
lv_event_code_t code = lv_event_get_code(e);
```

---

#### **Step 2: Handle `LV_EVENT_READY` (Passcode Entered)**
1. **Retrieve the Entered Passcode:**
   ```cpp
   String codefromscreen = lv_textarea_get_text(ui_PassTXT);
   ```

2. **Validate the Passcode:**
   - If the entered passcode matches the stored passcode:
     - Clear the text area (`ui_PassTXT`).
     - Perform the action based on the value of `nextaction`.
   - If the passcode is incorrect:
     - Clear the text area.
     - Reset `nextaction` to `0`.
     - Return to the main screen (`ui_MainSCR`).

   ```cpp
   if (codefromscreen == passcode) {
       lv_textarea_set_text(ui_PassTXT, ""); // Clear the text area
       if (nextaction == 1) { // Dispense action
           nextaction = 0;
           Dispense_Action();
           return;
       }
       if (nextaction == 2) { // Load tray settings
           nextaction = 0;
           loadTraySettings(selectedtray);
           lv_scr_load(ui_TrayConfigSCR);
           return;
       }
       if (nextaction == 3) { // Open settings screen
           nextaction = 0;
           lv_scr_load(ui_SettingSCR);
           return;
       }
   } else { // Incorrect passcode
       lv_textarea_set_text(ui_PassTXT, ""); // Clear the text area
       nextaction = 0;
       lv_scr_load(ui_MainSCR); // Return to the main screen
   }
   ```

---

#### **Step 3: Handle `LV_EVENT_CANCEL` (Cancel Button Pressed)**
- If the user presses "Cancel":
  - Clear the text area (`ui_PassTXT`).
  - Reset `nextaction` to `0`.
  - Return to the main screen (`ui_MainSCR`).

```cpp
if (code == LV_EVENT_CANCEL) {
    lv_textarea_set_text(ui_PassTXT, ""); // Clear the text area
    nextaction = 0;
    lv_scr_load(ui_MainSCR); // Return to the main screen
}
```

---

### **4. Example Scenarios**

#### **Scenario 1: Correct Passcode**
- **User Action:** Enters the correct passcode and presses "Accept."
- **System Behavior:**
  - Clears the passcode input field.
  - Checks the value of `nextaction`:
    - If `nextaction == 1`: Calls `Dispense_Action()` to dispense items.
    - If `nextaction == 2`: Loads tray settings and navigates to the tray configuration screen.
    - If `nextaction == 3`: Navigates to the settings screen.
  - Resets `nextaction` to `0`.

---

#### **Scenario 2: Incorrect Passcode**
- **User Action:** Enters an incorrect passcode and presses "Accept."
- **System Behavior:**
  - Clears the passcode input field.
  - Resets `nextaction` to `0`.
  - Navigates back to the main screen.

---

#### **Scenario 3: Cancel Button Pressed**
- **User Action:** Presses "Cancel" without entering a passcode.
- **System Behavior:**
  - Clears the passcode input field.
  - Resets `nextaction` to `0`.
  - Navigates back to the main screen.

---

### **5. Summary**
- **Purpose:** This function validates the passcode entered by the user and determines the next action based on the system's state.
- **Key Features:**
  - Handles both "Accept" and "Cancel" events.
  - Supports multiple actions (`Dispense_Action`, loading tray settings, opening settings).
  - Ensures the system returns to a safe state (main screen) if the passcode is incorrect or canceled.
- **Flow:**
  1. Check the event type (`Accept` or `Cancel`).
  2. If `Accept`, validate the passcode and perform the appropriate action.
  3. If `Cancel`, clear the input and return to the main screen.

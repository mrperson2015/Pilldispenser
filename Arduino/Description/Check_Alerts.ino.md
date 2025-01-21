This code is part of a **smart tray dispensing system** that uses timers, LEDs, and a graphical interface to manage and alert users about scheduled tasks (e.g., taking pills). Below is a detailed explanation of the key functions and their roles, broken down for someone new to this technology.

---

### **1. `check_trays_timer_cb`**
This function is a **timer callback** that runs periodically to check if any trays need to trigger an alert based on the current time.

#### **Key Steps:**
1. **Get Current Time:**
   ```cpp
   time_t now;
   struct tm timeinfo;
   time(&now);
   localtime_r(&now, &timeinfo);
   ```
   - Retrieves the current time and converts it into a readable format (hours and minutes).

2. **Check Each Tray:**
   ```cpp
   for (int i = 1; i <= 10; i++) {
       if (trayAlertEna[i] && !alreadyTriggered[i] && trayEnabled[i] && !traydisptoday[i] && !traydismtoday[i]) {
           if (trayHours[i] == timeinfo.tm_hour && trayMin[i] == timeinfo.tm_min) {
               // Trigger the alert
           }
       }
   }
   ```
   - Loops through all 10 trays to check if:
     - Alerts are enabled for the tray (`trayAlertEna[i]`).
     - The tray hasn’t already triggered (`!alreadyTriggered[i]`).
     - The tray is enabled (`trayEnabled[i]`).
     - The tray hasn’t been dismissed or dispensed today (`!traydisptoday[i]` and `!traydismtoday[i]`).
     - The current time matches the tray’s scheduled time (`trayHours[i]` and `trayMin[i]`).

3. **Trigger an Alert:**
   ```cpp
   traytriggered[i] = true;
   alreadyTriggered[i] = true;
   Playsound(1);
   alertinprogress = true;
   ```
   - Marks the tray as triggered and plays a sound to alert the user.
   - Updates the GUI to show the alert and enables the "Dispense" button.

4. **Telegram Alert:**
   ```cpp
   if (BOT_TOKEN != "" && CHAT_ID != "" && !telegram_alertonce) {
       lv_timer_create(telegram_timer, telegraminterval, NULL);
   }
   ```
   - If Telegram is configured, it sends a message to notify the user about the alert.

5. **Reset Trays at a Specific Time:**
   ```cpp
   if (resetHours == timeinfo.tm_hour && resetMin == timeinfo.tm_min) {
       traydisptoday[i] = false;
       traydismtoday[i] = false;
   }
   ```
   - Resets the tray status (e.g., clears "dispensed today" flags) at a specific reset time.

---

### **2. `telegram_timer`**
This function sends a Telegram message to notify the user about the triggered trays.

#### **Key Steps:**
1. **Check Alert Status:**
   ```cpp
   if (alertinprogress && telegramalertinterval > 0 && internetstatus != 0) {
   ```
   - Ensures that an alert is in progress, Telegram alerts are enabled, and the device is connected to the internet.

2. **Build the Message:**
   ```cpp
   String

This code represents the **startup sequence** for a smart dispensing system. It initializes various components, including Wi-Fi, servos, and the graphical user interface (GUI), and ensures the system is ready for operation. The startup process is broken into multiple steps, each executed sequentially using **timers**. Here's a detailed explanation of the code:

---

### **1. Overview of the Startup Process**
The startup process is divided into **15 steps**, each represented by a timer callback function (`startup_stepX_timer`). These steps:
1. Load Wi-Fi credentials and attempt to connect to Wi-Fi.
2. Lock servos for trays sequentially (Tray 1 to Tray 10).
3. Initialize the main system components (e.g., GUI, timers, web server, Telegram bot).
4. Load the main screen and prepare the system for user interaction.

---

### **2. Key Components of the Startup Process**

#### **2.1. Wi-Fi Initialization**
- **Step 1 (`startup_step1_timer`)**:
  - Attempts to load Wi-Fi credentials using `loadWifiCredentials()`.
  - If credentials are found, proceeds to connect to Wi-Fi (`startup_step2_timer`).
  - If no credentials are found, skips Wi-Fi setup and starts locking Tray 1's servo (`startup_step5_timer`).

```cpp
static void startup_step1_timer(lv_timer_t * timer) {
  if (loadWifiCredentials(ssidload, passwordload)) {
    lv_label_set_text(ui_LoadinginfoLBL, "Connecting Wifi...");
    lv_bar_set_value(ui_LoadingBAR, 2, LV_ANIM_ON);
    lv_timer_create(startup_step2_timer, 250, NULL);
  } else {
    lv_label_set_text(ui_LoadinginfoLBL, "Tray 1 Servo Lock...");
    lv_bar_set_value(ui_LoadingBAR, 5, LV_ANIM_ON);
    setServoPulse(0, 70);
    lv_timer_create(startup_step5_timer, 500, NULL);
  }
  lv_timer_del(timer);
}
```

- **Step 2 (`startup_step2_timer`)**:
  - Configures the ESP32 as a Wi-Fi station and attempts to connect to the loaded credentials.
  - If successful:
    - Updates the GUI to show the connected status and IP address.
    - Proceeds to the next step (`startup_step3_timer`).
  - If unsuccessful:
    - Updates the GUI to show a connection error.
    - Proceeds to the next step (`startup_step3_timer`).

```cpp
static void startup_step2_timer(lv_timer_t * timer) {
  WiFi.disconnect(true);
  WiFi.mode(WIFI_STA);
  WiFi.hostname(HOSTNAME.c_str());
  WiFi.begin(ssidload, passwordload);

  int maxRetries = 10;
  while (WiFi.status() != WL_CONNECTED && maxRetries-- > 0) {
    delay(1000);
  }

  if (WiFi.status() == WL_CONNECTED) {
    lv_bar_set_value(ui_LoadingBAR, 3, LV_ANIM_ON);
    lv_label_set_text(ui_LoadinginfoLBL, ("Connected - IP " + WiFi.localIP().toString()).c_str());
    internetstatus = 1;
    lv_timer_create(startup_step3_timer, 2000, NULL);
  } else {
    lv_bar_set_value(ui_LoadingBAR, 3, LV_ANIM_ON);
    lv_label_set_text(ui_LoadinginfoLBL, "Connection Error...");
    internetstatus = 0;
    lv_timer_create(startup_step3_timer, 2000, NULL);
  }
  lv_timer_del(timer);
}
```

---

#### **2.2. Servo Initialization**
- **Steps 5 to 14 (`startup_step5_timer` to `startup_step14_timer`)**:
  - Sequentially locks the servos for each tray (Tray 1 to Tray 10).
  - For each tray:
    - Moves the servo to the locked position (`setServoPulse()`).
    - Detaches the servo to save power (`detachServo()`).
    - Updates the progress bar (`ui_LoadingBAR`) and loading message (`ui_LoadinginfoLBL`).
    - Proceeds to the next tray.

```cpp
static void startup_step5_timer(lv_timer_t * timer) {
  detachServo(0);
  lv_bar_set_value(ui_LoadingBAR, 6, LV_ANIM_ON);
  lv_label_set_text(ui_LoadinginfoLBL, "Tray 2 Servo Lock...");
  setServoPulse(1, 70);
  lv_timer_create(startup_step6_timer, 500, NULL);
  lv_timer_del(timer);
}
```

This pattern is repeated for all trays (Tray 1 to Tray 10).

---

#### **2.3. Final Initialization**
- **Step 15 (`startup_step15_timer`)**:
  - Finalizes the startup process by:
    - Loading the main screen (`ui_MainSCR`).
    - Initializing timers for inactivity and alert sounds.
    - Loading tray settings for all trays.
    - Starting the web server, Telegram bot, and other internet-dependent services if Wi-Fi is connected.
    - Setting the system as "loaded" (`systemloaded = true`).

```cpp
static void startup_step15_timer(lv_timer_t * timer) {
  inactivity_timer = lv_timer_create(timeout_action, 120000, NULL);
  alertsound_timer = lv_timer_create(DFPlayer_Alarm_Timer, 60000, NULL);
  lv_scr_load(ui_MainSCR);

  for (int i = 1; i <= 10; i++) {
    loadTraySettings(i);
  }

  if (internetstatus) {
    webroute();
    MDNS.begin(HOSTNAME);
    AsyncElegantOTA.begin(&server);
    server.begin();
    MDNS.addService("http", "tcp", 80);
    if (BOT_TOKEN != "" && CHAT_ID != "") {
      bot = new UniversalTelegramBot(BOT_TOKEN, secured_client);
    }
  }

  lv_timer_create(check_trays_timer_cb, 15000, NULL);
  lv_timer_create(flashing_timer, 250, NULL);
  updateTrays();
  systemloaded = true;
  lv_timer_del(timer);
}
```

---

### **3. Supporting Functions**

#### **3.1. `setupTime()`**
- Configures the ESP32 to synchronize time using NTP servers.
- Waits for time synchronization and updates the GUI with the current time and date.

```cpp
void setupTime() {
  configTime(utcOffset * 3600, dstEnabled ? 3600 : 0, "pool.ntp.org", "time.nist.gov");

  struct tm timeinfo;
  while (!getLocalTime(&timeinfo)) {
    delay(1000);
  }

  char timeString[6];
  strftime(timeString, sizeof(timeString), "%H:%M", &timeinfo);
  lv_label_set_text(ui_ClockLBL, timeString);
}
```

---

#### **3.2. `timeout_action()`**
- Handles screen inactivity by switching to a blank or clock screen.
- Clears tray states and disables buttons.

```cpp
static void timeout_action(lv_timer_t* timer) {
  lv_scr_load(ui_BlankSCR);
  for (int i = 1; i <= 10; i++) {
    trayCheckedState[i] = false;
    lv_obj_clear_state(ui_TrayIMG[i], LV_STATE_CHECKED);
  }
  lv_obj_add_state(ui_DispenseBTN, LV_STATE_DISABLED);
  showLED(pixels.Color(0, 0, 0));
}
```

---

### **4. Summary of the Startup Process**
1. **Wi-Fi Setup:**
   - Attempts to connect to Wi-Fi and updates the GUI with the connection status.

2. **Servo Initialization:**
   - Sequentially locks the servos for all trays, ensuring they are in the correct position.

3. **Final Initialization:**
   - Loads tray settings, initializes timers, and starts internet-dependent services (e.g., web server, Telegram bot).

4. **Main Screen:**
   - Displays the main screen and prepares the system for user interaction.

---

### **5. Key Features**
- **Timers:** Used to execute each step sequentially with delays.
- **GUI Updates:** Progress bar and messages keep the user informed during startup.
- **Wi-Fi and Internet Services:** Ensures the system is connected and ready for remote control.
- **Servo Management:** Locks all tray servos to ensure proper operation.

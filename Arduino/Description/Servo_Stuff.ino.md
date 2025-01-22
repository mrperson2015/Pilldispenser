These two functions, `setServoPulse` and `detachServo`, are used to control **servo motors** connected to the system. They utilize the **Adafruit PWM Servo Driver** (likely the `Adafruit_PWMServoDriver` library) to send precise PWM (Pulse Width Modulation) signals to the servos. Here's a detailed explanation:

---

### **1. `setServoPulse`**
- **Purpose:** Moves a servo motor to a specific angle by sending the appropriate PWM signal.
- **How it works:**
  1. **Input Parameters:**
     - `n`: The servo number (or channel) to control.
     - `pulse`: The desired angle for the servo, typically between `0°` and `180°`.
  2. **Mapping the Angle to Pulse Length:**
     - The servo expects a specific pulse width (in microseconds) to move to a given angle.
     - The `map()` function converts the angle (`0°` to `180°`) into the corresponding pulse width (`SERVOMIN` to `SERVOMAX`).
       - `SERVOMIN`: The pulse width for the servo's minimum position (e.g., 0°).
       - `SERVOMAX`: The pulse width for the servo's maximum position (e.g., 180°).
  3. **Send the PWM Signal:**
     - The `pwm.setPWM()` function sends the calculated pulse width to the specified servo channel (`n`).

#### **Code Explanation:**
```cpp
void setServoPulse(uint8_t n, double pulse) {
  double pulselength;
  
  // Map the angle (0° to 180°) to the corresponding pulse width (SERVOMIN to SERVOMAX)
  pulselength = map(pulse, 0, 180, SERVOMIN, SERVOMAX);

  // Send the PWM signal to the servo on channel 'n'
  pwm.setPWM(n, 0, pulselength);
}
```

#### **Example:**
- If `SERVOMIN = 150` and `SERVOMAX = 600`:
  - `pulse = 0°` → `pulselength = 150` (minimum pulse width).
  - `pulse = 90°` → `pulselength = 375` (midpoint pulse width).
  - `pulse = 180°` → `pulselength = 600` (maximum pulse width).
- The servo moves to the corresponding angle based on the pulse width.

---

### **2. `detachServo`**
- **Purpose:** Stops controlling a servo by halting the PWM signal.
- **How it works:**
  1. **Input Parameter:**
     - `num`: The servo number (or channel) to stop controlling.
  2. **Stop the PWM Signal:**
     - The `pwm.setPWM(num, 0, 0)` function stops sending any PWM signal to the specified servo channel.
     - This effectively "detaches" the servo, allowing it to move freely or stop holding its position.

#### **Code Explanation:**
```cpp
void detachServo(uint8_t num) {
  // Stop sending the PWM signal to the servo on channel 'num'
  pwm.setPWM(num, 0, 0);
}
```

#### **Why Detach a Servo?**
- **Power Saving:** Servos consume power to hold their position. Detaching them reduces power usage.
- **Prevent Overheating:** Continuous operation can cause servos to overheat. Detaching them when not in use helps prevent this.
- **Allow Free Movement:** Detaching the servo allows it to move freely without resistance.

---

### **3. How These Functions Work Together**
- **`setServoPulse`:** Moves the servo to a specific angle by sending a PWM signal.
- **`detachServo`:** Stops controlling the servo by halting the PWM signal.

#### **Example Usage:**
```cpp
setServoPulse(0, 90); // Move servo on channel 0 to 90°
delay(1000);          // Wait for 1 second
detachServo(0);       // Stop controlling the servo on channel 0
```

---

### **4. Key Concepts**
- **PWM (Pulse Width Modulation):**
  - Servos are controlled by varying the width of the PWM signal.
  - A typical servo expects a pulse width between **1ms (minimum)** and **2ms (maximum)**, repeated every 20ms.
  - The `SERVOMIN` and `SERVOMAX` values represent these pulse widths in terms of the PWM driver's resolution (e.g., 12-bit resolution for the Adafruit PWM Servo Driver).

- **Mapping Angles to Pulse Widths:**
  - The `map()` function converts the desired angle (`0°` to `180°`) into the corresponding pulse width (`SERVOMIN` to `SERVOMAX`).

---

### **5. Summary**
- **`setServoPulse`:** Moves a servo to a specific angle by mapping the angle to a pulse width and sending the PWM signal.
- **`detachServo`:** Stops sending the PWM signal to a servo, effectively detaching it.
- **Use Case:** These functions are essential for controlling servo motors in applications like robotic arms, smart dispensers, or any system requiring precise angular movement.

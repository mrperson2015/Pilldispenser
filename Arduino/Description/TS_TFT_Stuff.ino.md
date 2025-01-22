These two functions, `my_disp_flush` and `my_touchpad_read`, are essential for integrating a **TFT display** and a **touchscreen** with the **LVGL (Light and Versatile Graphics Library)**. They handle **display updates** and **touch input**, allowing the system to render graphics and respond to user interactions. Here's a detailed explanation:

---

### **1. `my_disp_flush`**
- **Purpose:** Handles the process of updating the display (TFT screen) with new graphical data from LVGL.
- **How it works:**
  1. **Calculate the Area to Update:**
     - The `area` parameter specifies the rectangular region of the screen that needs to be updated.
     - The width (`w`) and height (`h`) of the area are calculated using the coordinates of the rectangle (`x1`, `x2`, `y1`, `y2`).

  2. **Start Writing to the Display:**
     - The `tft.startWrite()` function begins a batch write operation to the display, which is more efficient than writing pixel-by-pixel.

  3. **Set the Address Window:**
     - The `tft.setAddrWindow()` function defines the region of the display to update, based on the `area` coordinates.

  4. **Push Pixel Data:**
     - The `tft.pushColors()` function sends the pixel data (`color_p`) to the display. The pixel data is provided by LVGL and represents the colors to render in the specified area.

  5. **End Writing:**
     - The `tft.endWrite()` function ends the batch write operation.

  6. **Notify LVGL:**
     - The `lv_disp_flush_ready()` function tells LVGL that the flushing (display update) is complete, allowing it to continue with other tasks.

#### **Code:**
```cpp
void my_disp_flush(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p) {
  uint32_t w = (area->x2 - area->x1 + 1); // Calculate width of the area
  uint32_t h = (area->y2 - area->y1 + 1); // Calculate height of the area

  tft.startWrite(); // Begin writing to the display
  tft.setAddrWindow(area->x1, area->y1, w, h); // Set the region to update
  tft.pushColors((uint16_t *)&color_p->full, w * h, true); // Send pixel data
  tft.endWrite(); // End writing

  lv_disp_flush_ready(disp_drv); // Notify LVGL that flushing is complete
}
```

#### **Key Functions:**
- **`tft.startWrite()` and `tft.endWrite()`:** Optimize the process by batching multiple write operations.
- **`tft.setAddrWindow(x, y, w, h)`:** Defines the region of the display to update.
- **`tft.pushColors(data, size, swapBytes)`:** Sends the pixel data to the display.

#### **Example Workflow:**
1. LVGL determines which part of the screen needs to be updated.
2. LVGL calls `my_disp_flush` with the area and pixel data.
3. The function updates the specified region of the display with the new pixel data.

---

### **2. `my_touchpad_read`**
- **Purpose:** Reads touch input from the touchscreen and provides the data to LVGL.
- **How it works:**
  1. **Check if the Screen is Touched:**
     - The `ts.touched()` function checks if the touchscreen is currently being touched.

  2. **Get Touch Coordinates:**
     - If the screen is touched, the `ts.getPoint()` function retrieves the raw touch coordinates (`p.x` and `p.y`).

  3. **Calibrate the Touchscreen:**
     - The raw touch coordinates are compared to the minimum and maximum values (`touchScreenMinimumX`, `touchScreenMaximumX`, etc.).
     - These values are updated dynamically to ensure the touch input is properly calibrated.

  4. **Map Coordinates to Screen Pixels:**
     - The `map()` function converts the raw touch coordinates to pixel coordinates on the screen (`screenWidth` and `screenHeight`).

  5. **Update LVGL Input Data:**
     - The mapped coordinates are stored in `data->point.x` and `data->point.y`.
     - The touch state is set to `LV_INDEV_STATE_PR` (pressed).

  6. **Handle Inactivity Timer:**
     - If the system is loaded (`systemloaded`), the inactivity timer is reset, and a signal is sent to keep the screen active.

  7. **Handle Touch Release:**
     - If the screen is not touched, the touch state is set to `LV_INDEV_STATE_REL` (released).

#### **Code:**
```cpp
void my_touchpad_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data) {
  if (ts.touched()) { // Check if the screen is touched
    TS_Point p = ts.getPoint(); // Get the raw touch coordinates

    // Auto-calibrate the touchscreen
    if (p.x < touchScreenMinimumX) touchScreenMinimumX = p.x;
    if (p.x > touchScreenMaximumX) touchScreenMaximumX = p.x;
    if (p.y < touchScreenMinimumY) touchScreenMinimumY = p.y;
    if (p.y > touchScreenMaximumY) touchScreenMaximumY = p.y;

    // Map raw coordinates to screen pixels
    data->point.x = map(p.x, touchScreenMinimumX, touchScreenMaximumX, 1, screenWidth);
    data->point.y = map(p.y, touchScreenMinimumY, touchScreenMaximumY, 1, screenHeight);
    data->state = LV_INDEV_STATE_PR; // Set touch state to "pressed"

    // Reset inactivity timer if the system is loaded
    if (systemloaded) {
      lv_timer_reset(inactivity_timer);
      digitalWrite(21, HIGH);
    }
  } else {
    data->state = LV_INDEV_STATE_REL; // Set touch state to "released"
  }
}
```

#### **Key Functions:**
- **`ts.touched()`:** Checks if the touchscreen is being touched.
- **`ts.getPoint()`:** Retrieves the raw touch coordinates.
- **`map(value, in_min, in_max, out_min, out_max)`:** Maps a value from one range to another (e.g., raw touch coordinates to screen pixels).

#### **Example Workflow:**
1. The user touches the screen.
2. The function retrieves the raw touch coordinates and maps them to screen pixels.
3. The mapped coordinates and touch state are passed to LVGL for processing.

---

### **3. How These Functions Work Together**
- **`my_disp_flush`:** Updates the display with new graphical data from LVGL.
- **`my_touchpad_read`:** Reads touch input and provides it to LVGL for interaction.

#### **Example Workflow:**
1. **Display Update:**
   - LVGL determines which part of the screen needs to be updated.
   - It calls `my_disp_flush` to send the new pixel data to the display.
2. **Touch Input:**
   - The user touches the screen.
   - LVGL calls `my_touchpad_read` to get the touch coordinates and state.
   - The touch data is used to interact with the GUI (e.g., pressing a button).

---

### **4. Key Concepts**
- **LVGL Integration:**
  - LVGL requires custom functions to handle display updates (`my_disp_flush`) and input devices (`my_touchpad_read`).
- **Display Flushing:**
  - Only the parts of the screen that need updating are redrawn, improving performance.
- **Touchscreen Calibration:**
  - The raw touch coordinates are dynamically calibrated to ensure accurate mapping to screen pixels.

---

### **5. Summary**
- **`my_disp_flush`:** Sends graphical data from LVGL to the TFT display, updating specific regions of the screen.
- **`my_touchpad_read`:** Reads touch input from the touchscreen, maps it to screen coordinates, and provides it to LVGL.
- **Integration with LVGL:** These functions allow LVGL to render graphics and handle user interactions on the hardware.

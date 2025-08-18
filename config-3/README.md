# Soil Moisture Monitor — Config 2 🌱  

This version adds an **LCD1602 display** to the basic soil moisture monitor.  
It shows real-time soil readings and plant status alongside the LED indicators.  

---

## Features  
- 🌿 Real-time soil moisture readings (capacitive sensor)  
- 💡 LCD1602 shows raw sensor value + status (Dry, Moist, Good)  
- 🔴🟡🟢 LEDs provide quick visual feedback  
- 🧠 Threshold logic for dry/borderline/good soil conditions  
- 🧱 Breadboard prototype (can be moved into a case later)  

---

## Components Used  
- Arduino Uno (REXQualis)  
- Capacitive Soil Moisture Sensor v1.2  
- LCD1602 (parallel, 16-pin) + 10k potentiometer  
- Red, Yellow, and Green LEDs  
- 3 × 220Ω resistors  
- Breadboard + jumper wires  

---

## Wiring  

### Sensor → Arduino  
- VCC → 5V  
- GND → GND  
- AOUT → A0  

### LEDs → Arduino  
- Red → D8 (via 220Ω resistor)  
- Yellow → D9 (via 220Ω resistor)  
- Green → D10 (via 220Ω resistor)  

### LCD1602 (parallel) → Arduino  
- RS → D7  
- RW → GND  
- E  → D6  
- D4 → D5  
- D5 → D4  
- D6 → D3  
- D7 → D2  
- VSS → GND  
- VDD → 5V  
- VO (contrast) → middle pin of 10k pot (ends to 5V & GND)  
- A (backlight +) → 5V  
- K (backlight –) → GND  

---

## Usage  
1. Upload `SoilMoistureMonitor.ino` from this folder to your Arduino Uno.  
2. Turn the potentiometer knob until text is visible on the LCD.  
3. Open Serial Monitor (9600 baud) to also view raw sensor readings.  
4. Insert sensor into soil and observe feedback:  
   - **Red LED + DRY** → needs water  
   - **Yellow LED + Moist** → borderline  
   - **Green LED + Good** → healthy  

---

## Calibration  
- Check sensor reading **in air** (usually ~600–800).  
- Check sensor reading **in wet soil** (usually ~200–350).  
- Update the `DRY` and `MOIST` threshold values in the `.ino` file to match your plant’s needs.  

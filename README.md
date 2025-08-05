Soil Moisture Monitor

An Arduino-based soil moisture monitor using a capacitive sensor and LED indicators (red, yellow, green) to visually represent soil health. Designed for plant care and DIY electronics learning.

Features

- Real-time moisture readings using capacitive soil sensor
- 🔴🟡🟢 LED indicators for dry, borderline, and well-watered conditions
- Calibrated analog threshold logic
- Breadboard-based prototype (3D-printable case optional)

Components Used

- Arduino Uno (REXQualis)
- Capacitive Soil Moisture Sensor v1.2
- Red, Yellow, and Green LEDs
- 220Ω resistors (3x)
- Jumper wires & breadboard

Wiring

| Sensor Pin | Arduino |
|------------|---------|
| VCC        | 5V      |
| GND        | GND     |
| AOUT       | A0      |

| LED Color | Arduino Pin |
|-----------|-------------|
| Red       | D8          |
| Yellow    | D9          |
| Green     | D10         |

Code

See [`SoilMoistureMonitor.ino`](./SoilMoistureMonitor.ino)

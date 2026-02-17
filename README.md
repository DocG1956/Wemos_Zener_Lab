# Wemos Zener Lab

Zener Diode Voltage Tester using Wemos D1 Mini Pro.

## Project Description
measures voltage on Analog Pin A0 and outputs the value to Serial Monitor in CSV format.
Designed to test Zener Diodes by measuring the voltage drop across them.

## Wiring Diagram

**WARNING**: Wemos D1 Mini Pro A0 pin max input is approx **3.2V - 3.3V**.
To measure up to 5V (or higher), you **MUST** use a voltage divider.

```
       +5V (from Source/Wemos 5V)
        |
        R (Current Limiting Resistor, e.g., 220Ω - 1kΩ)
        |
        +-----> Probe Point (Cathode of Zener)
        |
      -----
       / \   Zener Diode (Anode to GND)
      -----
        |
       GND

  [Probe Point] ---- R1 (e.g., 220k) ----+-----> A0 (Wemos D1 Mini Pro)
                                         |
                                        R2 (e.g., 100k)
                                         |
                                        GND
```
*Note: The Wemos D1 Mini Pro A0 pin already has an internal voltage divider (typically 220k:100k), allowing it to measure up to ~3.2V. If you are measuring standard Zener voltages (e.g., 5.1V), you need an additional external divider to bring the voltage below 3.2V at the pin.*

## Usage
1. Compile and upload the code to Wemos D1 Mini Pro.
2. Open Serial Monitor at **115200 baud**.
3. Data will be streamed in simple CSV format: `Time(ms), ADC_Value, Voltage(V)`.
4. Connect the circuit as shown above.

## Files
- `Zener_Project.ino`: Main Arduino sketch.
- `results.csv`: Placeholder for data logging.

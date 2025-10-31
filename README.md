# IS20101-InterruptSikm--NNM24IS199
```markdown
# Interrupt Controller Simulation (Java)

## 🧠 Overview
This project simulates a simple **Interrupt Controller** in Java.  
It demonstrates how hardware interrupts (like from a keyboard, mouse, or printer) are handled using multithreading, priorities, and interrupt masking.

Each device runs on a separate thread and raises interrupts at random intervals.  
The controller manages these interrupts based on **priority** and **mask status** (enabled/disabled).

---

## ⚙️ Features
- Simulates multiple hardware devices:
  - Keyboard
  - Mouse
  - Printer
- Devices can be **masked** (disabled) or **enabled**.
- Interrupts are handled in **priority order**:
  1. Keyboard (highest)
  2. Mouse
  3. Printer (lowest)
- Real-time interrupt logs with timestamps.
- Thread-safe operations using synchronization and wait/notify.

---

## 🧩 Classes Overview

| Class | Description |
|--------|--------------|
| `Device` | Enum representing different devices with names and priorities. |
| `InterruptEvent` | Represents an interrupt raised by a device. |
| `InterruptController` | Core class that manages interrupt masking, queuing, and handling. |
| `DeviceThread` | Simulates each device generating interrupts at random intervals. |
| `InterruptControllerShort` | Main class to start the simulation. |

---

## ▶️ How It Works
1. Each device runs on a separate thread.
2. Devices randomly raise interrupts.
3. The controller:
   - Ignores masked devices.
   - Adds unmasked device interrupts to a priority queue.
4. The handler thread continuously processes interrupts in order of priority.
5. Processed interrupts are logged with timestamps.

---

## 🧪 Example Output

```

Keyboard enabled
Mouse enabled
Printer masked
Keyboard → ISR done
Mouse → ISR done
Keyboard → ISR done
...

=== ISR Log ===
12:34:56 - Keyboard
12:34:57 - Mouse
12:34:59 - Keyboard

Simulation complete.

````

---

## 💻 How to Run

### **1️⃣ Compile**
Open your terminal in the project directory and run:
```bash
javac InterruptControllerShort.java
````

### **2️⃣ Run**

Then execute the compiled class:

```bash
java InterruptControllerShort
```

---

## ⏱️ Simulation Time

* Runs for 8 seconds by default.
* You can change the runtime by modifying this line in `main()`:

  ```java
  Thread.sleep(8000);
  ```

---

## 📜 Notes

* Interrupts from masked devices are ignored and printed as `masked`.
* You can change the initial mask settings in:

  ```java
  ic.maskDevice(Device.KEYBOARD, true);
  ic.maskDevice(Device.MOUSE, true);
  ic.maskDevice(Device.PRINTER, false);
  ```
* Try experimenting by enabling/disabling devices or adding new ones!

---

## 👨‍💻 Author

**Samskruthi MB**
Project: *Interrupt Controller Simulation using Java Threads*

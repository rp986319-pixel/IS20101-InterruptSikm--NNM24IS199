# IS20101-InterruptSikm--NNM24IS199
```markdown
# Interrupt Handler Simulation (C using pthreads)

## Overview
This project simulates a **simple interrupt handling system** in C using **POSIX threads (pthreads)**.  
It demonstrates how an interrupt controller handles interrupts from different devices — **Keyboard**, **Mouse**, and **Printer** — while implementing **masking** and **synchronization** using mutex locks.

Each interrupt source is represented as a separate thread that simulates an **Interrupt Service Routine (ISR)**.

---

## Features
- Multi-threaded simulation using **pthreads**
- Demonstrates **masking** (disabling certain interrupts)
- Uses **mutex locks** for synchronized access
- Simulates real-world **interrupt handling**
- Logs all interrupts (processed or ignored)

---

## Interrupt Priority

Keyboard > Mouse > Printer

Although interrupts are generated randomly, this order represents their **intended priority** in real systems.

---

## Masking Configuration
Interrupt masks determine which devices are active (0) or ignored (1):

```c
int mask_keyboard = 0;  // 0 = active
int mask_mouse = 1;     // 1 = masked (ignored)
int mask_printer = 0;   // 0 = active

Compilation & Execution

Save the file as:

interrupt_handler.c

Compile using GCC:

gcc interrupt_handler.c -o interrupt_handler -lpthread

Run the program:

./interrupt_handler


---

Sample Output

=== INTERRUPT HANDLER SIMULATION ===
Priority: Keyboard > Mouse > Printer

Keyboard Interrupt Received -> Processing ISR -> Done
Interrupt Ignored (Masked Device)
Printer Interrupt Received -> Processing ISR -> Done
Keyboard Interrupt Received -> Processing ISR -> Done
Interrupt Ignored (Masked Device)
Printer Interrupt Received -> Processing ISR -> Done

All interrupts handled successfully. Execution complete.


---

Key Concepts Demonstrated

Multithreading: pthread_create() and pthread_join()

Synchronization: pthread_mutex_lock() and pthread_mutex_unlock()

Randomized Interrupt Simulation: rand() for generating random events

ISR Simulation: Each thread acts as a device’s Interrupt Service Routine



---

Conclusion

This program is a simple but effective simulation of an interrupt handling mechanism.
It helps you understand:

How masking prevents certain interrupts

How mutex locks prevent race conditions

How threads simulate simultaneous hardware activity


## Author

**Samskruthi MB**
Project: *Interrupt Controller Simulation using Java Threads*

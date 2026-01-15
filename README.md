# NanoWatch
A microcontroller powered watch with wifi, bluetooth, calculators and other communication methods while conserving power.

![image](https://github.com/user-attachments/assets/387494ab-b98e-4f41-b48d-098ae847ba7d)
(Random image for ref, of course, mine will look much different)

The watch is basically a small self-contained computer strapped to your wrist.

At the center is the **Arduino Nano 33 BLE Rev 2**. This is the brain. Everything either feeds into it or is controlled by it. It keeps track of time, runs the logic for apps like the calculator, listens for button presses, talks over Bluetooth, and decides when to sleep to save power.

Power comes from a **Lithium Polymer battery**. The battery does not directly power the Arduino because the voltage isn’t stable across discharge. So the battery first goes into the **TP4056 charger module**. This module has two jobs:

* charge the battery safely when external power is connected
* pass battery power forward when unplugged

From the TP4056 output, power goes into the **AMS1117 voltage regulator**. The regulator’s only job is to take the battery’s varying voltage and turn it into a steady voltage that the Arduino Nano can safely run on. This creates a stable power rail for the whole system.

That regulated power line is shared by:

* the Arduino Nano
* the TM1637 display
* the switch array

The **TM1637 4-digit display** is the watch’s face. It connects to the Arduino using just two data pins. The Arduino sends it numbers to show:

* time (hours and minutes)
* date (by switching modes)
* calculator results
* simple UI feedback

Because the TM1637 is low power, the Arduino can dim it or turn it off entirely when the watch is idle to save battery.

The **switch array** is the input system. Each switch is wired to Arduino input pins. When a switch is pressed, the Arduino detects it and decides what that press means based on the current mode:

* in clock mode -> switch display or settings
* in calculator mode -> number or operator input
* in system mode -> Bluetooth or power actions

No switch does anything on its own. Every press is just a signal; the Arduino interprets it.

For wireless features, the Arduino’s built-in **Bluetooth Low Energy** handles pairing and communication. No external module is needed. BLE is used instead of classic Bluetooth because it consumes far less power and suits short, infrequent data transfers.

Physically, everything is mounted on or between **plexiglass layers**, which act as:

* structural support
* electrical isolation
* protection for components

The plexiglass sandwich holds the PCB, battery, and modules tightly in place.

The whole assembly is wrapped or backed with **artificial leather**, which:

* makes it wearable
* hides the electronics
* improves comfort and durability

**Small neodymium magnets** are embedded in the strap or edges. These magnets allow:

* magnetic strapping to the wrist
* easy removal of the watch module
* future modular attachments (battery pack, sensor module, etc.)

In operation, the flow is simple:

* battery powers system
* regulator stabilizes voltage
* Arduino wakes, checks time, updates display
* buttons trigger logic
* BLE stays idle unless needed
* Arduino enters low-power sleep whenever possible



<img width="638" height="460" alt="schema" src="https://github.com/user-attachments/assets/1a20328f-e82d-4d3a-91f2-00975d749b08" />


<img width="1584" height="396" alt="LinkedIn cover - 5" src="https://github.com/user-attachments/assets/bb28025e-d9e1-4ecc-a2a1-abcfd9d51263" />



# NanoWatch
A microcontroller powered watch with wifi, bluetooth, calculators and other communication methods while conserving power.


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



https://github.com/user-attachments/assets/9a22fa63-88e6-42b2-8494-47285df3df49


The whole assembly is wrapped or backed with artificial leather, which:

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


|Name|Description|Amount|Link|Cost|Cost $|
|-|-|-|-|-|-|
|TM1637 4 Bit Display|Enough for clock + basic features while consuming low power|1|https://robocraze.com/products/tm1637-4-digit-7-segment-led-display?variant=40192593658009&country=IN&currency=INR&utm_medium=product_sync&utm_source=google&utm_content=sag_organic&utm_campaign=sag_organic&campaignid=22271813913&adgroupid=&keyword=&device=c&gad_source=1&gad_campaignid=22271815110&gbraid=0AAAAADgHQvbn5UsfGL3ZZmw_JxklkOa43&gclid=CjwKCAiAu67KBhAkEiwAY0jAlVUw7iF6btRjvq3Xzyjr0TOxG5N4bdAQ0jhS0TG7J5-CXC9m0ci_7BoCcEoQAvD_BwE|₹45.00|$0.50|
|Small Nd magnets|For magnetic modularity|1 (100pcs)|https://www.amazon.in/gp/product/B075PMRBWJ/ref=ox_sc_act_title_8?smid=AP7MBNLZTN3FQ&psc=1|₹275.00|$3.03|
|Switch Array|For controlling input and processing data|8|https://robu.in/product/digital-sensor-ttp223b-module-capacitive-touch-switch/|₹120.00|$1.32|
|Artificial Leather|For strapping and covering the watch|70cm^2|https://www.amazon.in/gp/product/B09DCP41JD/ref=ox_sc_act_title_5?smid=A2ZGAXPBI2YBYH&psc=1|₹200.00|$2.20|
|TP4096 Charger module|For charging|1|https://robu.in/product/tp4056-1a-li-ion-lithium-battery-charging-module-with-current-protection-type-c/|₹25.00|$0.28|
|Plexiglass|For mounting and containing the circuits|1|https://www.amazon.in/gp/product/B097JQLNRW/ref=ox_sc_act_title_1?smid=A1YQOYZBR78PZF&psc=1|₹299.00|$3.29|
|Lithium Polymer Batteries|For power and space efficiency|2|https://www.amazon.in/gp/product/B0CYQ6H8FW/ref=ox_sc_act_title_3?smid=A2MVLA5NURHGBS&psc=1|₹302.00|$3.32|
|Voltage Regulator|For providing stable voltage to Nano|1|https://robu.in/product/dc-dc-1-8v-5v-to-3-3v-boost-and-buck-power-module/?gad_source=1&gad_campaignid=17416544847&gbraid=0AAAAADvLFWcO_xeiUoTKrfT0WPjsJeLrH&gclid=CjwKCAiAu67KBhAkEiwAY0jAlV1EwRc7QIY71OZ8BFnK6DXi7Ab7a9E5U0J6SR_FGI4e0hnhRyVwrhoC6D0QAvD_BwE|₹51.00|$0.56|
|Arduino Nano 33 BLE Rev 2|"Best due to its size| power and BLE support"|1|https://www.amazon.in/gp/product/B0FF9GGXWD/ref=ox_sc_act_title_7?smid=AJ6SIZC8YQDZX&psc=1|"₹2|119.00"|$23.31|
|Total||||"₹3|436.00"|$37.80


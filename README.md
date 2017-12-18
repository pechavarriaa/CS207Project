# CS207Project
Source code and documentation for 3x3 Led-Cube

## Prerequisites

### Hardware
- Neopixels (Preferably the mini-pcb ones) here is a neopixel breakdown by Phillip Burgess from Adafruit https://cdn-learn.adafruit.com/downloads/pdf/adafruit-neopixel-uberguide.pdf
- Soldering iron along with soldering wire, wires to connect neopixels
- Arduino nano
- HC-05/HC-06 Bluetooth Module
- 7.4v 2200mAh lipo battery
- Android Phone
- Paper Card (to make diffusers)
- Magnets
- 3D printed parts from STL file
- 24 M4 bolts and 24 M4 nuts
  
### Software
- Arduino IDE
- FastLED library from https://github.com/FastLED/FastLED
- Rubiks3x3.h Header from this repository 
- Android Studio (optional to make custom app for the cube)
          
## Assemble

### Hardware
First start by 3D printing the cube from 3D files folder. Then
assemble 9 neopixels per face from the cube. Then solder the neopixels
in this order 

<img src="https://github.com/pechavarriaa/CS207Project/blob/master/img/SolderingOrder.JPG" width="400px" align="middle"/>

(note that one has to solder 5v with 5v from one led to another, Dout to Din, and Gnd to Gnd).

After having all 6 faces ready, Solder the last neopixel from the Down face to the first of the Front face, then 
from Front face to Right face, from Right to Back, from Back to Left, and finally from Left to Up.

Once the 6 faces are soldered and together, connect the first neopixel from the Down face to the battery (before this step regulate the voltage from 7.4v to 5v to avoid burning the neopixels), connecting ground with ground and 5v with 5v.
The data pin to the neopixel has to go connected from arduino digital pin 8.

Connect the Bluetooth Module Vcc to 5v from arduino, Ground with Ground and finally the RX and TX pin of the module to digital pins 9 and 10 of the arduino. (make sure to use a voltage divider to connect to RX of the module)

after all the connections are done, close the cube with the nuts and bolts. Later cut the paper card to have 54 small 30mm by 30mm pieces to put them inside the covers of the cube. Later place the magnets in the covers and in the inside cube.

### Software

Download Rubiks3x3.h and LedCube.ino from scr folder. Download and Install FastLED library.
Flash the Arduino Nano with LedCube.ino.

Download any Android app from Google Play to send commands to the hc-05 module, discover the hc-05 and pair it with the android phone.

## Using the Cube

Once the assemble steps are done, send the following commands to use the cube:

-reset: set the cube to the original state
-r: right move
-f: front move
-b: back move
-l: left move
-u: up move
-d: down move
-m: middle layer move
-e: middle layer move
-s: middle layer move
-x: rotate the cube on X-axis
-y: rotate the cube on Y-axis
-z: rotate the cube on Z-axis
-k: turn off the lights
-g: animations start and after animations, the cube get to original state

After sending any command, send an 'O' to finalize the command.




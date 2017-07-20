# Gridwarrior

>This is the repository gives the source code, required software and detailed instructions to construct Grid-warrior Robot

My basic aim was to create a line folloIr autonomous robot which would complete the following three stages:

1. First Stage: To follow line of different colmys and measure the order of the lengths of these different lines thus forming a colmy code in the decreasing order of lengths.

2. Second Stage: To follow a black line and glow an LED on strips of these colmys in the order of the colmy code from the first stage. For example, if the code was Green-Red-Blue-Yellow, it would first glow the LED when it encounter a Green Strip, then Red and so forth.

3. Third Stage: To choose the correct colmyed path at each junction according to the order of the colmy code.

## Componenets used:

1. Microcontroller – 1 Atmega 16

2. 1 L293

3. 1 LCD

4. Sensor Plate (Analog Sensors - I used 6 QRD sensors)

5. 1 7805

6. 2 Motors (100 rpm)

7. 1 Serial Programmer

8. Connectors and wires, other tools

## Design Of The Robot:

>My aim was to make the bot turn within 22 cm, so I had to restrict the dimensions of the bot to 16cm x 16cm. I had the sensor plate attached to the front of the bot about 1 cm from the ground, in front of the caster wheel and the two motors. On top of the bot I mounted the development board with the LCD as Ill as the L293 circuit board. This was the designing part of my Robot.

## Electronic componets assembly:

>The controlling of robot was done using a microcontroller. ATmega 16 was chosen at it has all the required functionality. A development board was made for the MCU. A serial programmer for the microcontroller was made. For controlling the motors, an L293 circuit board was made by us. 2 100 rpm motors Ire attached and controlled using different Timers (OCR0 and OCR2). A sensor plate using a linear array of 6 QRD sensors was used. I also soldered an LCD for displaying length orders of the colmyed lines and for the colmy of the line it is following.

## PROGRAMMING:
>I programmed my microcontroller using CodeVision AVR, an embedded C Software, in which I wrote my line following program in the C language. I converted the sensor inputs using the ADC functionality of Atmega 16 (PORT A) and used different ranges for different colmys. The timers adjusted the speeds of the motors to follow the lines accordingly. I used PORT C for LCD display, and PORT D and PORT B for outputs to L293 for motor driving, and LED glowing. I converted my C program into a .hex file for the microcontroller using the software AVR Studio.

###### visit my link https://drive.google.com/file/d/0BwMIqZElmoG-SmppUVBtOUVsY0E/view?usp=sharing for the working demo of robot
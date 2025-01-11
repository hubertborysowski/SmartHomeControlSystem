# arduino.md

Communication between the created environment and the Arduino consists of sending bytes in the form of 'char' characters through the serial port. 
Each character is assigned to a corresponding GPIO, allowing the program to indirectly check the state of the GPIO and send feedback. 
The following characters have been assigned for communication:
- 'A': Digital pin 2
- 'a': Digital pin 2 (off)
- 'B': Digital pin 3 (PWM)
- 'b': Digital pin 3 (PWM) (off)
- 'C': Digital pin 4
- 'c': Digital pin 4 (off)
- 'D': Digital pin 5 (PWM)
- 'd': Digital pin 5 (PWM) (off)
- 'E': Digital pin 6 (PWM)
- 'e': Digital pin 6 (PWM) (off)
- 'F': Digital pin 7
- 'f': Digital pin 7 (off)
In addition, other characters have been used to activate individual functions:
- '+': Enable PWM increase function.
- '-': Enable PWM decrease function.
- '=': Distable PWM functionts.
- 'X': Send data from ATH20 + BMP280
- 'Y': Check current pin state.
- 'Z': Check all pin states.

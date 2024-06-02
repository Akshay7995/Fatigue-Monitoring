# Fatigue-Monitoring

Fatigue Monitoring System with Arduino

This project implements a basic fatigue monitoring system using an Arduino microcontroller to detect potential drowsiness based on sensor input.

Functionality:

(i)Sensor: The system relies on a sensor (connected to pin sensorPin) to detect changes in a user's state. The specific sensor type and its behavior are not explicitly defined in the provided code.

**Consider using an eye blink sensor, EEG sensor, or other suitable sensor depending on your chosen approach to fatigue detection.

(ii)Thresholds: The system utilizes two thresholds (minSensorDuration and minSensorDuration2) to determine what constitutes a "long" sensor activation period.

**minSensorDuration: If the sensor is inactive for a duration exceeding this threshold, it's considered a potential indication of drowsiness.

**minSensorDuration2: If the sensor remains inactive for a longer duration exceeding this second threshold, the system triggers an alert.

(iii)Relay and Buzzer Control:

**A relay (connected to pin Relay) is used to potentially control an external device based on the detected drowsiness state (e.g., activating a coffee machine or adjusting lighting).

**A buzzer (connected to pin buzzer) is activated to provide an audible alert for the user when drowsiness is detected.

(iv)Serial Communication: The system outputs messages to the serial monitor (set to 9600 baud) for debugging and monitoring purposes.

Hardware Requirements:

*Arduino microcontroller

*Sensor (type based on your chosen approach)

*Relay 

*Buzzer 

*Jumper wires

Software Requirements:

*Arduino IDE 

Uploading the Code:

*Install the Arduino IDE.

*Connect your Arduino board to your computer.

*Open the provided code (fatigue_monitoring.ino) in the Arduino IDE.

*Select your Arduino board and serial port from the IDE's tools menu.

*Upload the code to your Arduino board.

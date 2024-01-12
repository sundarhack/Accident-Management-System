Project Overview
----------------------------------------------------------------------------------------------------------------------------------------------------
The Accident Management System is a project that aims to create a comprehensive system for monitoring and managing accidents using Arduino UNO,Arduino IDE, Flask (a Python web framework), and ESP01 (an ESP8266 module),GPS Module,GSM Module. The system integrates hardware components, including sensors and microcontrollers, with software components to detect accidents, collect relevant data, and provide real-time alerts and assistance.

Key Components
----------------------------------------------------------------------------------------------------------------------------------------------------
Arduino: Arduino is an open-source microcontroller platform that forms the core of the hardware system. It is responsible for collecting data from various sensors and controlling other components.

ESP01 (ESP8266 Module): ESP01 is a Wi-Fi enabled microcontroller module that allows communication between the Arduino and the internet. It enables the system to send data to a web server and receive real-time notifications.

Sensors: Various sensors are used to detect accidents and gather essential data. For example
    GPS Module: Tracks the location of the accident.
    GSM Module: Enables communication via SMS or call in case of emergencies.
Flask: Flask is a lightweight web framework in Python that allows the development of web applications. It is used to create a web interface for the accident management system, providing a user-friendly dashboard to monitor accidents and manage data.

Project Workflow
-------------------------------------------------------------------------------------------------------------------------------------------------
Sensor Data Collection: The Arduino reads data from sensors such as the accelerometer, GPS module, and GSM module. It collects information about the impact force, location, and other relevant details.

Data Processing: The Arduino processes the collected sensor data and prepares it for transmission to the web server. It can convert the data into a suitable format and package it for transmission.

Communication with ESP01: The Arduino communicates with the ESP01 module over a serial connection. It sends the processed sensor data to the ESP01, which handles the Wi-Fi connectivity.

Web Server Integration: The ESP01 module connects to a web server through Wi-Fi and sends the collected sensor data. The server can be set up using Flask to receive and process the data.

Emergency Notifications: In the event of an accident, the system can trigger emergency notifications. For example, it can send an SMS or make a call to predefined emergency contacts with the accident details and location.

Circuit Design
--------------------------------------------------------------------------------------------------------------------------------------------------

![Screenshot 2023-07-14 175720](https://github.com/sanjith-21/FEC/assets/95207736/c136f7a0-423b-4ebb-834e-f7f16d0a3e94)

Workflow
--------------------------------------------------------------------------------------------------------------------------------------------------

![Screenshot 2023-07-14 180336](https://github.com/sanjith-21/FEC/assets/95207736/fb7565f4-49e8-4816-9e1c-feee8edf2a56)

Report
-------------------------------------------------------------------------------------------------------------------------------------------------
[AMS.pdf](https://github.com/sanjith-21/FEC/files/12050454/AMS.pdf)


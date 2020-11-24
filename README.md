# Lego Car

Lego car controlled by 2 ESP32 and a Raspberry Pi. Created with Webstorm, Node.js, NPM, NGINX, Fail2Ban and Arduino IDE.

## Table of contents
* [General info](#general-info)
* [Technologies](#technologies)
* [Setup](#setup)
* [Features](#features)
* [Inspiration](#inspiration)

## General info
This project is a lego car that can be controlled by remote clients.
	
## Technologies
Project is created using the following software:
	
 - Arduino IDE version: 1.8.13
 - Webstorm version: 2020.2.3
 - Fail2Ban version: 0.9.3
 - Node.js version: 14.15.1
 - NPM version: 5.8.0
 - NGINX version:


Project is created using the following hardware:

 - 2x ESP32DEVKIT-C
 - Raspberry Pi 3 Model B+
 - Any Router

	
## Setup

 - Run ESP32_socket_prosjekt.ino on the first ESP32.
 - Run ESP32_socket_prosjekt_servo.ino on your second servo.
 - Setup Fail2Ban with iP tables on the Raspberry Pi.
 - Setup NGINX on the Raspberry Pi.
 - Setup Node.js on the Raspberry Pi.
 - Setup NPM on the Raspberry Pi.
 - Install "file-system", "express" and "socket.io" in NPM.
 - Upload index.html, script.js, server_no_encrypt-js, socket.js and style.css to the Raspberry.
 - On the Raspberry, locate the uploaded files and place them in the "html" folder in "/var/www/html".
 - Set up Port Forwarding on your Local Router in order to get access from outside your local network. (Optional)
 
 ## Features
 
  - Build an awesome car that can be wirelessly controlled by anyone at anytime.
  - Simply connect to the car anywhere and have fun driving.
 
 
 ## Inspiration

This project was inspired by our growing interest for IoT and the will to learn more code.

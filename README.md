# Lego Car

Lego car controlled by 2 ESP32 and a Raspberry Pi. Created with Webstorm, Node.js, NPM, NGINX, Fail2Ban and Arduino IDE.

## Table of contents
* [General info](#general-info)
* [Technologies](#technologies)
* [Setup](#setup)
* [Wiring diagram](#Wiring diagram)


## General info
This project is a lego car that can be controlled by remote clients.
	
## Technologies
Project is created using the following software:
	
 - Arduino IDE version: 1.8.13
 - Webstorm version: 2020.2.3
 - Fail2Ban version: 0.9.3
 - Node.js version: 14.15.1
 - NPM version: 
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
 - Upload index.html, script.js, server_no_encrypt-js, socket.js and style.css to the Raspberry.
 - On the Raspberry, locate the uploaded files and place them in the "html" folder in "/var/www/html".
 - Set up Port Forwarding on your Local Router in order to get access from outside your local network. (Optional)

//Including the necassary libraries
#include <WiFi.h>// Imports the needed WiFi libraries
#include <WiFiMulti.h> //We need a second one for the ESP32 (these are included when you have the ESP32 libraries)

#include <SocketIoClient.h> //Import the Socket.io library, this also imports all the websockets

#include <analogWrite.h> //analogWrite library to work with ESP32

//  Defining  DC-motor controller L298N ports

const int enA = 14;  // defines the pin that controls the DC-motors speed
const int in1 = 26;  // defines one of the pins that decides the rotation direction
const int in2 = 27;  // defines the other pin that decides the rotation direction


WiFiMulti WiFiMulti; //Declare an instane of the WiFiMulti library
SocketIoClient webSocket; //Decalre an instance of the Socket.io library


void event(const char * payload, size_t length) { //Default event, what happens when you connect
  Serial.printf("got message: %s\n", payload);
}

void changeDriveState(const char * DriveStateData, size_t length) { //Same logic as earlier
  Serial.printf("Drive State: %s\n", DriveStateData);
  Serial.println(DriveStateData);

  //Data conversion
  String dataString(DriveStateData);
  int DriveState = dataString.toInt();

  Serial.print("This is the Drive state in INT: ");
  Serial.println(DriveState);

  ControlDCMotor(DriveState); //Calling the DC-Motor-function with the drivestates 
}

void setup() {
    // defines the DC-motor controller pins as outputs
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT); 
    pinMode(enA, OUTPUT);
    
    
    Serial.begin(9600); //Initiates serial monitor

    
    Serial.setDebugOutput(true); //Set debug to true (during ESP32 booting)

    Serial.println();
    Serial.println();
    Serial.println();

      for(uint8_t t = 4; t > 0; t--) { //More debugging
          Serial.printf("[SETUP] BOOT WAIT %d...\n", t);
          Serial.flush();
          delay(1000);
      }

    WiFiMulti.addAP("SSID", "Password"); //Add a WiFi hotspot (addAP = add AccessPoint) (put your own network name and password in here)

    while(WiFiMulti.run() != WL_CONNECTED) { //Here we wait for a successfull WiFi connection untill we do anything else
      Serial.println("Not connected to wifi...");
        delay(100);
    }

    Serial.println("Connected to WiFi successfully!"); //When we have connected to a WiFi hotspot

    //Here we declare all the different events the ESP32 should react to if the server tells it to.
    //a socket.emit("identifier", data) with any of the identifieres as defined below will make the socket call the functions in the arguments below
    webSocket.on("clientConnected", event); //For example, the socket.io server on node.js calls client.emit("clientConnected", ID, IP) Then this ESP32 will react with calling the event functio
    webSocket.on("DriveStateChange", changeDriveState);
    
    webSocket.begin("IP address", "port"); //This starts the connection to the server with the ip-address/domainname and a port (unencrypted)
}

//Defines the function that makes the car drive with the states forward (1), backwards (-1) and stand still (0)
void ControlDCMotor(int DriveState){
  
  if(DriveState == 1) { //Forward
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enA, 255);
      
} else if (DriveState == -1){ //Backward
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enA, 255);
     
} else if(DriveState == 0){ //Still
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    analogWrite(enA, 0);
  }
}

void loop() {
  webSocket.loop(); //Keeps the socket communication running by looping it
}

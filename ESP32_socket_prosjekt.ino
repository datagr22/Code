#include <Servo.h>
#include <analogWrite.h>


//Selve bilen

const int enA = 14;
const int in1 = 27;
const int in2 = 12;
const int servoPin = 13;
const int trigPin = 32;
const int echoPin = 33;

long duration;
int distance;


Servo myServo;
//Eksempelkoden

#include <WiFi.h>//Imports the needed WiFi libraries
#include <WiFiMulti.h> //We need a second one for the ESP32 (these are included when you have the ESP32 libraries)

#include <SocketIoClient.h> //Import the Socket.io library, this also imports all the websockets

WiFiMulti WiFiMulti; //Declare an instane of the WiFiMulti library
SocketIoClient webSocket; //Decalre an instance of the Socket.io library

//void ControlDCMotor(int _enA, int in1, int in2);
//void ControlServo(Servo _MyServo);


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
  Drive(DriveState);
}

void changeTurnState(const char * TurnStateData, size_t length) {
  Serial.printf("Turn State: %s\n", TurnStateData);
  Serial.println(TurnStateData);

  //Data conversion
  String dataString(TurnStateData);
  int TurnState = dataString.toInt();


  Serial.print("This is the Turn state in INT: ");
  Serial.println(TurnState);

  
  softTurn(TurnState);
}


void setup() {
    //SELVE BILEN
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT); 
    pinMode(enA, OUTPUT);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    
    myServo.attach(servoPin);
    
    //EKSEMPELKODE
    Serial.begin(9600); //Start the serial monitor

    
    Serial.setDebugOutput(true); //Set debug to true (during ESP32 booting)

    Serial.println();
    Serial.println();
    Serial.println();

      for(uint8_t t = 4; t > 0; t--) { //More debugging
          Serial.printf("[SETUP] BOOT WAIT %d...\n", t);
          Serial.flush();
          delay(1000);
      }

    WiFiMulti.addAP("Mathisen", "sommerfugl94"); //Add a WiFi hotspot (addAP = add AccessPoint) (put your own network name and password in here)

    while(WiFiMulti.run() != WL_CONNECTED) { //Here we wait for a successfull WiFi connection untill we do anything else
      Serial.println("Not connected to wifi...");
        delay(100);
    }

    Serial.println("Connected to WiFi successfully!"); //When we have connected to a WiFi hotspot

    //Here we declare all the different events the ESP32 should react to if the server tells it to.
    //a socket.emit("identifier", data) with any of the identifieres as defined below will make the socket call the functions in the arguments below
    webSocket.on("clientConnected", event); //For example, the socket.io server on node.js calls client.emit("clientConnected", ID, IP) Then this ESP32 will react with calling the event functio
    webSocket.on("DriveStateChange", changeDriveState);
    webSocket.on("TurnStateChange", changeTurnState);
    

    webSocket.begin("10.0.0.24", 2520); //This starts the connection to the server with the ip-address/domainname and a port (unencrypted)
}

//Drive the car forwards or backwards (THIS IS JUST AN EXAMPLE AND NOT WHAT YOU HAVE TO USE IT FOR)
void Drive(int a){
  
  if(a == 1) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enA, 150);
      
} else if (a == -1){
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enA, 150);
     
} else if(a == 0){
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    analogWrite(enA, 0);
  }
}



//Turn the car left or right (turns with the frontwheels)
void softTurn(int Direction) {
  
  if(Direction == 1) {
    myServo.write(10);
  }
  else if(Direction == -1){
    myServo.write(100);
  }
  else if (Direction == 0){
    myServo.write(50);
  }
}


void loop() {
  webSocket.loop();
//
//  digitalWrite(trigPin, LOW);
//  delayMicroseconds(2);
//  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(2);
//  digitalWrite(trigPin, LOW);
//
//  duration = pulseIn(echoPin, HIGH);
//
//  distance = duration*0.034/2;
//
//  
//
//  ControlDCMotor(enA, in1, in2);
//  ControlServo(myServo);
//}
//
//
//void ControlDCMotor(int _enA, int in1, int in2){
//  
//  if(distance < 10){
//    delay(10);
//    digitalWrite(in1, HIGH);
//    digitalWrite(in2, LOW);
//
//    analogWrite(enA, 150);
//    
//  }
//  else if(distance > 10){
//    digitalWrite(in1, LOW);
//    digitalWrite(in2, HIGH);
//
//    analogWrite(enA, 150);
//  }
//  else{
//    digitalWrite(in1, LOW);
//    digitalWrite(in2, LOW);
//
//    analogWrite(enA, 0);
//  } 
//}
//void ControlServo(Servo _myServo){
//  
//  if(distance < 10){
//    myServo.write(100);
//  }
//  else if(distance > 10){
//    myServo.write(50);
//  }
}

  //Keeps the WebSocket connection running 
  //DO NOT USE DELAY HERE, IT WILL INTERFER WITH WEBSOCKET OPERATIONS
  //TO MAKE TIMED EVENTS HERE USE THE millis() FUNCTION OR PUT TIMERS ON THE SERVER IN JAVASCRIPT

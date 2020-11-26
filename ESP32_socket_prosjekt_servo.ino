#include <WiFi.h>//Imports the needed WiFi libraries
#include <WiFiMulti.h> //We need a second one for the ESP32 (these are included when you have the ESP32 libraries)

#include <SocketIoClient.h> //Import the Socket.io library, this also imports all the websockets

#include <Servo_ESP32.h> //Import the Servo_ESP32 library
#include <analogWrite.h> //Import the analogWrite.h library

const int servoPin = 13; //Defines the servopin

int TurnState; // 

WiFiMulti WiFiMulti; //Declare an instane of the WiFiMulti library
SocketIoClient webSocket; //Declare an instance of the Socket.io library
Servo_ESP32 myServo; //Declare an instance of the Servo_ESP32 library

void ControlServo(Servo_ESP32 myServo);


void event(const char * payload, size_t length) { //Default event, what happens when you connect
  Serial.printf("got message: %s\n", payload);
}

void changeTurnState(const char * TurnStateData, size_t length) {
  Serial.printf("Turn State: %s\n", TurnStateData);
  Serial.println(TurnStateData);

  //Data conversion
  String dataString(TurnStateData);
  TurnState = dataString.toInt();


  Serial.print("This is the Turn state in INT: ");
  Serial.println(TurnState);

  
  ControlServo(TurnState);
}

void setup() {

    myServo.attach(servoPin);//Attach the servo to the servopin
    
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

    WiFiMulti.addAP("NetworkName","Password"); //Add a WiFi hotspot (addAP = add AccessPoint) (put your own network name and password in here)

    while(WiFiMulti.run() != WL_CONNECTED) { //Here we wait for a successfull WiFi connection untill we do anything else
      Serial.println("Not connected to wifi...");
        delay(100);
    }

    Serial.println("Connected to WiFi successfully!"); //When we have connected to a WiFi hotspot

    //Here we declare all the different events the ESP32 should react to if the server tells it to.
    //a socket.emit("identifier", data) with any of the identifieres as defined below will make the socket call the functions in the arguments below
    webSocket.on("clientConnected", event); //For example, the socket.io server on node.js calls client.emit("clientConnected", ID, IP) Then this ESP32 will react with calling the event functio
    webSocket.on("TurnStateChange", changeTurnState);
    

    webSocket.begin("IP address", "Port"); //This starts the connection to the server with the ip-address/domainname and a port (unencrypted)
}

//Turn the car left (1), right (-1) and forward (0)
void ControlServo(int TurnState) {
 
  if(TurnState == 1) {
    myServo.write(0);
  }
  else if(TurnState == -1){
    myServo.write(100);
  }
  else if(TurnState == 0){
    myServo.write(60);
  }
}

void loop() {
  webSocket.loop(); //Keeps the socket communication running by looping it
}

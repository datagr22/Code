#include <Zumo32U4.h>


Zumo32U4ProximitySensors prox;
Zumo32U4ButtonA A;
Zumo32U4Motors motors;
Zumo32U4LCD lcd;


int turn;
int drive;
bool seen;
int lastTurn;
int LValue;
int RValue;
int stop;

void setup() {
  prox.initThreeSensors();
  A.waitForButton();

}

void loop() {

  prox.read();
  LValue=prox.countsFrontWithLeftLeds();
  RValue=prox.countsFrontWithRightLeds();
  

  seen=(LValue>4 or RValue>4);
    
  
  if (seen){
    turn-=10;
  }
  else{
    turn+=10;
  }
  turn=constrain(turn,200,400);
  if (seen){

    if (LValue<RValue){
      motors.setSpeeds(turn,-turn);
      lastTurn=1;
    }
    else if (LValue>RValue){
      motors.setSpeeds(-turn,turn);
      lastTurn=0;
    }
    else{
      if(LValue==6){
        motors.setSpeeds(0,0);
      }
      else{
        motors.setSpeeds(200,200);
      }
    }
  }
  else{
    if (lastTurn==1){
      motors.setSpeeds(turn,-turn);
    }
    else{
      motors.setSpeeds(-turn,turn);
    }
  }
  lcd.clear();
  lcd.print(LValue);
  lcd.print(RValue);
  lcd.gotoXY(0,1);
  lcd.print(turn);
  
}

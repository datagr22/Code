#define USE_BUZZER 0

int trigPin = 2;
int echoPin = 4;
double hastighet = 0.034;
int frekvens = 1000;
int roed = 5;
int groenn = 6;


void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  

}

void loop() {
  long tid = 0;
  long avstand = 0;
  long intervall = 100;
  int x = 10;
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);

  tid = pulseIn(echoPin, HIGH);
    
  avstand = (tid / 2) * hastighet;
  intervall = map(avstand,0,354,100,1000);

  Serial.print(" avstand:");
  Serial.print(avstand);
  Serial.print(" tid:");
  Serial.print(tid);
  Serial.print(" intervall:");
  Serial.println(x);

 
  if(avstand > 0 && avstand < 100){
    digitalWrite(groenn,LOW);
    digitalWrite(roed,HIGH);
  }else{
    digitalWrite(groenn,HIGH);
    digitalWrite(roed,LOW);
  }
  
}

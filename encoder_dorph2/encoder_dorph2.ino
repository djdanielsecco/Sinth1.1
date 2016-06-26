#define encoder0PinA  2
#define encoder0PinB  3

int encoder0Pos = 0;
int TT = 31;
void setup() {


  pinMode(encoder0PinA, INPUT);
  digitalWrite(encoder0PinA, HIGH);       // turn on pullup resistor
  pinMode(encoder0PinB, INPUT);
  digitalWrite(encoder0PinB, HIGH);       // turn on pullup resistor

  attachInterrupt(0, doEncoder, CHANGE);  // encoder pin on interrupt 0 - pin 2
  Serial.begin (115200);
  Serial.println("start");                // a personal quirk

}

void loop(){}

void doEncoder() {

  if (digitalRead(encoder0PinA) == digitalRead(encoder0PinB)) 
  {
    encoder0Pos++;
  } 
  
  else 
  {
    encoder0Pos--;
  }

  encoder0Pos = constrain(encoder0Pos ,10, 1000);
  tone(9, encoder0Pos);
  Serial.println(encoder0Pos);
  
}


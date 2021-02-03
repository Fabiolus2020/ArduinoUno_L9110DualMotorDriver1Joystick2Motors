const int A1A = 2;//define pin 2 for A1A
const int A1B = 3;//define pin 3 for A1B

const int B1A = 4;//define pin 8 for B1A
const int B1B = 5;//define pin 9 for B1B

// Define Joystick Connections
#define joyX A0
#define joyY A1

int joyposX = 512;
int joyposY = 512;


void setup() {
  Serial.begin(9600);
  pinMode(B1A, OUTPUT); // define pin as output
  pinMode(B1B, OUTPUT);
  pinMode(A1A, OUTPUT);
  pinMode(A1B, OUTPUT);
  digitalWrite(B1A, LOW);
  digitalWrite(B1B, LOW);
  digitalWrite(A1A, LOW);
  digitalWrite(A1B, LOW);
  delay(3000);
}

void loop() {
  // put your main code here, to run repeatedly:

  joyposX = analogRead(joyX);
  joyposY = analogRead(joyY);

  //Serial.println(joyposX);
  Serial.println(joyposY);

  if (joyposX > 510)
  {
    // This is forward
    digitalWrite(A1A, LOW);
    digitalWrite(A1B, HIGH);
    digitalWrite(B1A, LOW);
    digitalWrite(B1B, HIGH);

  }

  else if (joyposX < 480)
  {
    // This is backward
    digitalWrite(A1A, HIGH);
    digitalWrite(A1B, LOW);
    digitalWrite(B1A, HIGH);
    digitalWrite(B1B, LOW);

  }

  else if (joyposY < 480)
  {
    // This is right
    digitalWrite(A1A, HIGH);
    digitalWrite(A1B, LOW);
    digitalWrite(B1A, LOW);
    digitalWrite(B1B, HIGH);

  }

  else if (joyposY > 520)
  {
    // This is right
    digitalWrite(A1A, LOW);
    digitalWrite(A1B, HIGH);
    digitalWrite(B1A, HIGH);
    digitalWrite(B1B, LOW);

  }

  else
  {
    digitalWrite(B1A, LOW);
    digitalWrite(B1B, LOW);
    digitalWrite(A1A, LOW);
    digitalWrite(A1B, LOW);
  }

}

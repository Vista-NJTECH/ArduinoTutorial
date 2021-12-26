const int trigPin = 8; // Trigger Pin of Ultrasonic Sensor
const int echoPin = A0; // Echo Pin of Ultrasonic Sensor
int greenLED = 12;
int redLED = 13;
int LEFT_A = 10;
int LEFT_B = 11;
int RIGHT_A = 4;
int RIGHT_B = 5;
int sped1 = 9;
int sped2 = 6;

#define leftT  3
#define midT   2
#define rightT  7


long duration;
long cm;

void setup() {
  Serial.begin(9600); // Starting Serial Terminal
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LEFT_A, OUTPUT);
  pinMode(LEFT_B, OUTPUT);
  pinMode(RIGHT_A, OUTPUT);
  pinMode(RIGHT_B, OUTPUT);
  pinMode(sped1, OUTPUT);
  pinMode(sped2, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(leftT, INPUT);
  pinMode(rightT, INPUT);
  pinMode(midT, INPUT);

}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);

  cm = microsecondsToCentimeters(duration);
  Serial.println(cm);
  if (cm < 18)
  {
    stop1();
  }
  else {
    if (digitalRead(2) == 1 && digitalRead(7) == 0 && digitalRead(3) == 0)
    {
      forward();

    }
    else if (digitalRead(2) == 1 && digitalRead(7) == 0 && digitalRead(3) == 1)
    {

      right();
    }
    else if (digitalRead(2) == 1 && digitalRead(7) == 1 && digitalRead(3) == 0)
    {

      left();
    }
    else if (digitalRead(2) == 0 && digitalRead(7) == 0 && digitalRead(3) == 0)
    {

      leftNew();

    }
  }
}



long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}


void forward()
{
  green();
  digitalWrite(LEFT_A, LOW);
  digitalWrite(LEFT_B, HIGH);
  digitalWrite(RIGHT_A, LOW);
  digitalWrite(RIGHT_B, HIGH);
  analogWrite(sped1, 100);
  analogWrite(sped2, 100);
}
void back()
{
  green();
  digitalWrite(LEFT_A, HIGH);
  digitalWrite(LEFT_B, LOW);
  digitalWrite(RIGHT_A, HIGH);
  digitalWrite(RIGHT_B, LOW);
  analogWrite(sped1, 110);
  analogWrite(sped2, 110);
}
void left()
{
  green();
  digitalWrite(LEFT_A, LOW);
  digitalWrite(LEFT_B, LOW);
  digitalWrite(RIGHT_A, LOW);
  digitalWrite(RIGHT_B, HIGH);
  analogWrite(sped1, 170);
  analogWrite(sped2, 260);
}
void right()
{
  green();
  digitalWrite(LEFT_A, LOW);
  digitalWrite(LEFT_B, HIGH);
  digitalWrite(RIGHT_A, LOW);
  digitalWrite(RIGHT_B, LOW);
  analogWrite(sped1, 260);
  analogWrite(sped2, 170);
}
void stop1()
{
  red();
  digitalWrite(LEFT_A, LOW);
  digitalWrite(LEFT_B, LOW);
  digitalWrite(RIGHT_A, LOW);
  digitalWrite(RIGHT_B, LOW);
}

void green()
{
  digitalWrite(greenLED, HIGH);
  digitalWrite(redLED, LOW);
}


void red()
{
  digitalWrite(redLED, HIGH);
  digitalWrite(greenLED, LOW);
}


void leftNew()
{
  green();

  digitalWrite(LEFT_A, LOW);
  digitalWrite(LEFT_B, HIGH);
  digitalWrite(RIGHT_A, HIGH);
  digitalWrite(RIGHT_B, LOW);
  analogWrite(sped1, 200);
  analogWrite(sped2, 160);

}
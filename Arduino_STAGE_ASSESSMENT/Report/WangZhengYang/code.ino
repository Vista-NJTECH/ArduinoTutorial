const uint8_t Left_A = 4 ;
const uint8_t Left_B = 5 ;
const uint8_t Right_A = 2 ;
const uint8_t Right_B = 3 ;
const uint8_t Speed_Right = 11;
const uint8_t Speed_Left = 10;
const uint8_t trigPin = 13;
const int echoPin = 12;
const int inPin_Left = 7;
const int inPin_Middle = 8;
const int inPin_Right = 9;
const int redLED = A0;
const int greenLED = 6;

long duration;
long inches;
long cm;

int flag = 0;

void setup() {
  pinMode(Left_A, OUTPUT);
  pinMode(Left_B, OUTPUT);
  pinMode(Right_A, OUTPUT);
  pinMode(Right_B, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(inPin_Left, INPUT);
  pinMode(inPin_Middle, INPUT);
  pinMode(inPin_Right, INPUT);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  Serial.begin(9600);
  delay(5000);
}

void loop() {
  Serial.println(judgeDistance());
  if (judgeDistance() == false || judgeBlackM() == false)
  {
    Stop(10);
    flag = 0;
  }
  if (judgeDistance() == true && judgeBlackM() == true && judgeBlackR() == false && judgeBlackL() == false)
  {
    goAhead(10, 100);
  }
  if (judgeDistance() == true && judgeBlackM() == false && judgeBlackR() == true && judgeBlackL() == false)
  {
    turnRight(10, 100);
  }
  if (judgeDistance() == true && judgeBlackM() == false && judgeBlackR() == false && judgeBlackL() == true)
  {
    turnLeft(10, 100);
  }
  if (judgeDistance() == true && judgeBlackM() == true && judgeBlackR() == false && judgeBlackL() == true)
  {
    goAhead(157, 125);
    turnLeft(650, 150);
  }
  if (judgeDistance() == true && judgeBlackM() == true && judgeBlackR() == true && judgeBlackL() == false)
  {
    goAhead(157, 125);
    turnRight(650, 150);
  }
}

void goBack(int delaytime, int carspeed)
{
  digitalWrite(Left_A, HIGH);
  digitalWrite(Left_B, LOW);
  digitalWrite(Right_A, HIGH);
  digitalWrite(Right_B, LOW);
  analogWrite(Speed_Right, carspeed);
  analogWrite(Speed_Left, carspeed);
  green();
  delay(delaytime);
}//倒退

void stoptime(int delaytime)
{
  digitalWrite(Left_A, LOW);
  digitalWrite(Left_B, LOW);
  digitalWrite(Right_A, LOW);
  digitalWrite(Right_B, LOW);
  red();
  delay(delaytime);
}//停止一段时间

void goAhead(int delaytime, int carspeed) {
  digitalWrite(Left_A, LOW);
  digitalWrite(Left_B, HIGH);
  digitalWrite(Right_A, LOW);
  digitalWrite(Right_B, HIGH);
  analogWrite(Speed_Right, carspeed);
  analogWrite(Speed_Left, carspeed);
  green();
  delay(delaytime);
}//前进

void turnRight(int delaytime, int carspeed) {
  digitalWrite(Left_A, LOW);
  digitalWrite(Left_B, HIGH);
  digitalWrite(Right_A, HIGH);
  digitalWrite(Right_B, LOW);
  analogWrite(Speed_Right, carspeed);
  analogWrite(Speed_Left, carspeed);
  green();
  delay(delaytime);
}//向右转

void turnLeft(int delaytime, int carspeed) {
  digitalWrite(Left_A, HIGH);
  digitalWrite(Left_B, LOW);
  digitalWrite(Right_A, LOW);
  digitalWrite(Right_B, HIGH);
  analogWrite(Speed_Right, carspeed);
  analogWrite(Speed_Left, carspeed);
  green();
  delay(delaytime);
}//向右转

void Stop(int delaytime) {
  digitalWrite(Left_A, LOW);
  digitalWrite(Left_B, LOW);
  digitalWrite(Right_A, LOW);
  digitalWrite(Right_B, LOW);
  red();
  delay(delaytime);
}

bool judgeDistance() {
  digitalWrite(trigPin, LOW);
  delay(2 / 29 / 2);
  digitalWrite(trigPin, HIGH);
  delay(10 / 29 / 2);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  cm = duration / 29 / 2;

  if (cm < 10)
    return false;
  if (cm >= 10)
    return true;
}

bool judgeBlackM() {
  int result;
  result = digitalRead(inPin_Middle);
  if (result == 0)
    return false;
  if (result == 1)
    return true;
}

bool judgeBlackL() {
  int result;
  result = digitalRead(inPin_Left);
  if (result == 0)
    return false;
  if (result == 1)
    return true;
}

bool judgeBlackR() {
  int result;
  result = digitalRead(inPin_Right);
  if (result == 0)
    return false;
  if (result == 1)
    return true;
}

void red()
{
  digitalWrite(redLED, HIGH);
  digitalWrite(greenLED, LOW);
}

void green() {
  digitalWrite(greenLED, HIGH);
  digitalWrite(redLED, LOW);
}
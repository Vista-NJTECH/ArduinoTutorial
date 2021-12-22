#include "Sonar_lib.h"

int distance;

char format[]={"cm","mm"};               //just two format

void setuo(){
    setSonarPin(8, 9);                   //trigPin,echoPin
    Serial.begin(9600);
}

void loop(){
    distance = sonarStart(format[0]);    //cm
    Serial.print("Distance: ");
    Serial.println(distance);
}
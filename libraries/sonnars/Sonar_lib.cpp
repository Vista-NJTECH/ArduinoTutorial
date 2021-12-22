/**************************************************
 * Just support version > 1.0.0
 * ************************************************/

#include "Sonar_lib.h"
#include "Arduino.h"

char format[]={"cm","mm"}

unsigned int trigPin;
unsigned int echoPin;
long duration;
int distance;

Sonar::setSonarPin(trigPin, echoPin){
    pinMode(trigPin, OUTPUT); 
    pinMode(echoPin, INPUT); 
}

Sonar::sonarStart(char){
    if (char == format[0]){
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance= duration*0.034/2;
    return diatance;
    }   
    if (char == format[1]){
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance= duration*0.034/2;
    return diatance * 10;
    }   
}
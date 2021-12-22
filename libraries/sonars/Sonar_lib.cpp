/**************************************************
 * Just support version > 1.0.0
 * ************************************************/

#include "Sonar_lib.h"
#include "Arduino.h"

unsigned int trigPin;
unsigned int echoPin;
long duration;
int distance;

void Sonar::setSonarPin(trigPin, echoPin){
    pinMode(trigPin, OUTPUT); 
    pinMode(echoPin, INPUT); 
}

int Sonar::sonarStart(){
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance= duration*0.034/2;
    return distance;
}
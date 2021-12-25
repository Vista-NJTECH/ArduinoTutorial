/**************************************************
 * Just support version >= 1.0.0
 * ************************************************/

#include "Sonar_lib.h"
#include "Arduino.h"

unsigned int trigPin;
unsigned int echoPin;

long duration;
long distance;

void Sonar::setSonarPin(unsigned int trigPin, unsigned int echoPin){
    pinMode(trigPin, OUTPUT); 
    pinMode(echoPin, INPUT); 
}

long Sonar::sonarStart(){
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);

    distance= duration*0.034/2;
    return distance;
}
#ifndef SONAR_LIB_H
#define SONAR_LIB_H

#include "Arduino.h"

char format[] = {"cm","mm"}
class Sonar {
  void setSonarPin(int, int);
  sonarStart(format[0]);
}
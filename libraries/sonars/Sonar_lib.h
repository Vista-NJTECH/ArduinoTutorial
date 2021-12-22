#include "Arduino.h"

class Sonar {
  public:
    void setSonarPin(unsigned int, unsigned int);
    int sonarStart();
};
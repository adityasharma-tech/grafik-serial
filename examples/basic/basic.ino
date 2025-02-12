#include "GrafikSerial.h"

GrafikLogger* logger;
GrafikPlotter* plotter;

const int analogPin = A0;

void setup() {
    Grafik grafik(0);
    logger = grafik.createLogger(1);
    plotter = grafik.createPlotter(2);
}

void loop() {
    int randomValue = analogRead(analogPin); // Generate a random number between 0 and 300
    String logMessage = "Random Value: " + String(randomValue);
    logger->log(logMessage.c_str());
    plotter->plotData(randomValue);
    delay(50);
}

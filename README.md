# grafik-serial library v1.0.1

The __Arduino GrafikSerial__ library helps you to log & plot your arduino sensor data to your grafik-studio dashboard where you can visalize your sensor data in realtime. This allows you to plot multiple data points and logs with multiple devices at sametime.

## Installation
1. "Download": https://github.com/adityasharma-tech/grafik-serial/archive/master.zip the master branch from Github.
2. Unzip and modify the folder name to "GrafikSerial"
3. Move the modified folder on your Library folder (On your `Libraries` folder inside your Arduino IDE / Other IDE)

## How to use
First include the __GrafikSerial__ library in your project:
```cpp
#include "GrafikSerial.h"
```

You can define a new logger/plotter as:
```cpp
GrafikLogger* logger1; // logger
GrafikPlotter* plotter1; // plotter

void setup(){
    ...
}
```

Then initialize the loggers and plotters with GrafikSerial as:
```cpp
void setup() {
    Grafik grafik(0); // `0` is here the unique deviceId across your multiple iOT devices.
    logger = grafik.createLogger(5123); // `5123` is here the unique loggerId across this project.
    plotter = grafik.createPlotter(5234); //  `5234` is here the unique plotterId across this project.
}
```

Now you can simply low the data in the loop or in the setup or anywhere in the code as:
```cpp
logger->log("App initialized successfully");
plotter->plotData(5.23); //float value
```


## Example
A very simple arduino code which will log and plot the `A0` analog pin values: 
```cpp
#include "GrafikSerial.h"

GrafikLogger* logger;
GrafikPlotter* plotter;

const int analogPin = A0;

void setup() {
    Grafik grafik(0);
    logger = grafik.createLogger(5123);
    plotter = grafik.createPlotter(5124);
}

void loop() {
    int randomValue = analogRead(analogPin); // Generate a random number between 0 and 300
    String logMessage = "Random Value: " + String(randomValue);
    logger->log(logMessage.c_str());
    plotter->plotData(randomValue);
    delay(50);
}
```


## IMPORTANT
| Key | Value |
|---------|--------------|
| DeviceId   | This id helps in differenciate multiple IoT devices reading at same time. | 
| LoggerId   |  This unique id across your single project is unique for loggers.|
| PlotterId  | This unique id across your single project is unique for plotters.|

```
Don't give same id to multiple plotters/loggers same id unless it will cause you to break your data logging.
```
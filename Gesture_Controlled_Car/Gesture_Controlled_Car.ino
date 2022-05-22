
#define CUSTOM_SETTINGS
#define INCLUDE_SENSOR_MODULE
#include <DabbleESP32.h>

#define left_f 27
#define left_b 26
#define right_f 25
#define right_b 33

void setup() {
  Serial.begin(115200);    // make sure your Serial Monitor is also set at this baud rate.
  Dabble.begin("MyEsp32");   //set bluetooth name of your device
  pinMode(left_f, OUTPUT);
  pinMode(left_b, OUTPUT);
  pinMode(right_f, OUTPUT);
  pinMode(right_b, OUTPUT);
}

void loop() {
  Dabble.processInput();             //this function is used to refresh data obtained from smartphone.Hence calling this function is mandatory in order to get data properly from your mobile.
  print_Accelerometer_data();

  if ((Sensor.getAccelerometerYaxis()) >= 4)
  {
    digitalWrite (left_f, HIGH);
    digitalWrite (left_b, LOW);
    digitalWrite (right_f, HIGH);
    digitalWrite (right_b, LOW);
    delay(200);
  }

  else if ((Sensor.getAccelerometerYaxis()) <= -4)
  {
    digitalWrite (left_f, LOW);
    digitalWrite (left_b, HIGH);
    digitalWrite (right_f, LOW);
    digitalWrite (right_b, HIGH);
    delay(200);
  }

  else if ((Sensor.getAccelerometerXaxis()) <= -4)
  {
    digitalWrite (left_f, LOW);
    digitalWrite (left_b, HIGH);
    digitalWrite (right_f, HIGH);
    digitalWrite (right_b, LOW);
    delay(200);
  }

  else if ((Sensor.getAccelerometerXaxis()) >= 4)
  {
    digitalWrite (left_f, HIGH);
    digitalWrite (left_b, LOW);
    digitalWrite (right_f, LOW);
    digitalWrite (right_b, HIGH);
    delay(200);
  }

  else
  {
    digitalWrite (left_f, LOW);
    digitalWrite (left_b, LOW);
    digitalWrite (right_f, LOW);
    digitalWrite (right_b, LOW);
    delay(200);
  }
}


void print_Accelerometer_data()
{
  Serial.print("X_axis: ");
  Serial.print(Sensor.getAccelerometerXaxis(), 4);
  Serial.print('\t');
  Serial.print("Y_axis: ");
  Serial.print(Sensor.getAccelerometerYaxis(), 4);
  Serial.print('\t');
  Serial.print("Z_axis: ");
  Serial.println(Sensor.getAccelerometerZaxis(), 4);
  Serial.println();
}

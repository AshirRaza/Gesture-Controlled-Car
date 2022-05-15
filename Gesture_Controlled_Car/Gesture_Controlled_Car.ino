

BluetoothSerial SerialBT;
#include <Dabble.h>
#include <DabbleInputs.h>
#include <SensorModule.h>
#include <motorControls.h>

#define CUSTOM_SETTINGS
#define INCLUDE_SENSOR_MODULE
#include <AFMotor.h>

#define INCLUDE_DABBLEINPUTS_MODULE
#define INCLUDE_MOTORCONTROL_MODULE

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
    Serial.write(SerialBT.read());
  }
  delay(20);
}

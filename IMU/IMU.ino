#include <Wire.h>
#define IMU_ADDR 0x68
#define IMU_INIT 0x6B

#define GYRO_X_H 0x43
#define GYRO_X_L 0x44
#define GYRO_Y_H 0x45
#define GYRO_Y_L 0x46
#define GYRO_Z_H 0x47
#define GYRO_Z_L 0x48

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

struct imuResult
{
  int16_t gyroX = 0, gyroY = 0, gyroZ = 0;
};

void initIMU()
{
  Wire.begin();
  Wire.beginTransmission(IMU_ADDR);
  Wire.write(IMU_INIT);
}

struct imuResult readFromIMU()
{
  struct imuResult returnStruct;
  Wire.beginTransmission(IMU_ADDR);
  Wire.write(GYRO_X_H);
  Wire.endTransmission(false);
  Wire.requestFrom(IMU_ADDR, 6, true); //We want to get the next 6 bytes. 
  returnStruct.gyroX = Wire.read() << 8 | Wire.read(); //We get the high and low registers and put them in an int with 16 bits
  returnStruct.gyroY = Wire.read() << 8 | Wire.read();
  returnStruct.gyroZ = Wire.read() << 8 | Wire.read();
  
  return returnStruct;
  
}

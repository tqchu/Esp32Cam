#include "esp_camera.h"
#include "SoftwareSerial.h"
#include "stdlib.h"

String results[8] = {"20","30","20","30", "20","30","20","30" };
//String results[8] = { ""000"", ""001"", ""010"", ""011"", ""100"", ""101"", ""110"", ""111"" };
// void setup() {
//   Serial.begin(115200);  // Bạn khởi tạo một cổng Serial tại baudrate 9600. Ở Client, bạn cũng phải mở một cổng Serial cùng Baudrate với HOST
// }

void getResultFromServer(){
  int index = rand() % 8;
  String result = results[index];
  Serial.println(result);
}

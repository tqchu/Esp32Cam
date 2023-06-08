#include "DFRobotDFPlayerMini.h"
#include "SoftwareSerial.h"

SoftwareSerial mySoftwareSerial(10, 11);  // chân Rx nối với chân D2, Chân Tx nối với chân D1 11-Rx 10-Tx
DFRobotDFPlayerMini myDFPlayer;

String results[] = { "11", "121", "131", "110", "21", "31", "10", "120", "130", "20", "30" };


void setup() {
  //Khởi tạo Serial ở baudrate 115200 (trùng với Cam )
  Serial.begin(115200);
  mySoftwareSerial.begin(9600);

  if (!myDFPlayer.begin(mySoftwareSerial, true, false)) {
    while (true) {
      delay(10);
    }
  }
  // Thiết lập âm lượng cho loa 
  myDFPlayer.volume(25);  //Volume 5
  myDFPlayer.EQ(0);
}

int findAudio(String result) {
  for (int i = 0; i < 11; i++) {
    if (result == results[i]) {
      return i + 1;
    }
  }
  return 0;
}
void loop() {

  if (Serial.available()) {
    String s = Serial.readString();
    s.trim();

    int audioFile = findAudio(s);
    if (audioFile > 0) {
      myDFPlayer.playMp3Folder(audioFile);
      delay(5500);
      myDFPlayer.stop();
    }
  }

}

int plus, minus;

void functionMP3() {
  plus = digitalRead(7);
  minus = digitalRead(8);

  if (plus == HIGH) {
    myDFPlayer.volumeUp();
    Serial.print("Current volume:");
    Serial.println(myDFPlayer.readVolume());
  }

  if (minus == HIGH) {
    myDFPlayer.volumeDown();
    Serial.print("Current volume:");
    Serial.println(myDFPlayer.readVolume());
  }
}
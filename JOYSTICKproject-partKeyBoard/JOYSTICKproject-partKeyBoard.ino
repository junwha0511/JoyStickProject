#include<Keyboard.h>
//방향 상수
const int FRONT = 1;
const int BACK = 2;
const int RIGHT = 3;
const int LEFT = 4;

void setup() {
  Serial1.begin(115200);

  Keyboard.begin();
}

void loop() {
  String receive = Serial1.readStringUntil('|'); // |가 나올 때까지 패킷 받음
  int _direction=receive.toInt();
  switch (_direction) {  
    case 0:
      break;
    case FRONT:
      Keyboard.press('W');
      delay(10);
      Keyboard.releaseAll();
      break;
    case BACK:
      Keyboard.press('S');
      delay(10);
      Keyboard.releaseAll();
      break;
    case LEFT:
      Keyboard.press('A');
      delay(10);
      Keyboard.releaseAll();
      break;
    case RIGHT:
      Keyboard.press('D');
      delay(10);
      Keyboard.releaseAll();
      break;
  }
}

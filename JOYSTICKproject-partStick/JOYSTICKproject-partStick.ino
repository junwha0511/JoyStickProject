const int pin_x = 14; //Analog 0번 핀
const int pin_y = 15; //Analog 1번 핀

const int X_THRESHOLD_LOW = 490; //x중간 범위
const int X_THRESHOLD_HIGH = 530;

const int Y_THRESHOLD_LOW = 490; //y중간 범위
const int Y_THRESHOLD_HIGH = 530;

//방향 상수
const int FRONT = 1;
const int BACK = 2;
const int RIGHT = 3;
const int LEFT = 4;

void setup() {
  Serial.begin(115200); //115200 보드레이트로 시작
}

void loop() {
  int _direction = getDirection(analogRead(pin_x),analogRead(pin_y));
  String Data = (String)_direction+"|"; //한 패킷의 끝을 |로 구분
//  Serial.print("X:");
//  Serial.print(analogRead(pin_x));
//  Serial.println();
//  Serial.print("Y:");
//  Serial.print(analogRead(pin_y));
//  Serial.println(); this is testing code
  char Packet[20]; //패킷을 담을 문자열
  Data.toCharArray(Packet,20); //패킷을 문자열에 담음
  Serial.write(Packet); //Serial 포트로 패킷 전송 
}

int getDirection(int x_position, int y_position) {
    int x_direction = 0; //초기 방향 0
    int y_direction = 0;

    //기준값과 비교해 방향을 1, -1로 지정
    if (x_position > X_THRESHOLD_HIGH) {
      x_direction = 1;
    }else if(x_position < X_THRESHOLD_LOW) {
      x_direction = -1;
    }
    if (y_position > Y_THRESHOLD_HIGH) {
      y_direction = 1;
    }else if(y_position < Y_THRESHOLD_LOW) {
      y_direction = -1;
    }
    
    if (x_direction == 0 && y_direction == 1) {
      return FRONT;
    } else if (x_direction == 0 && y_direction == -1) {
      return BACK;
    } else if (x_direction == 1 && y_direction >= 0) {
      return LEFT;
    } else if (x_direction == -1 && y_direction >= 0) {
      return RIGHT;
    }
    return 0;
}


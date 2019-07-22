

/*             */
/* SLAVE BORAD */
/*             */

/*
[[ FRAP ( Fire Report As soon as Possible) ]]
:: All-In-One fire extinguisher for automatic reporting and maintenance

[[ Features ]]
  
  1. Automatic fire report.
    ⚫ Detecting fire extinguisher's weight through a pressure sensor in the box. 
     If the fire extinguisher is off for a certain time, TTS ( Text to Speech ) will be initiated.
     After passing the certain time, it will notify gas and temperature values at the momenth 
      to users through an application.
  
  2. Fire extinguisher maintenance.
    ⚫ There is a ON/OFF switch. When maintenance is began, the switch is supposed to be OFF.
     The switch will be ON after passing the certain maintenance time.
     As soon as the switch is ON, it will notify the info to the maintenaner.
  
  3. Gas and Temperature remote detection.
    ⚫ Listening to detecting gas and temperature.
     If one of them is over its threshold, it will send both data to the main board.

[[ Features in SLAVE BOARD ]]

  1. Gas detection through FC-22.
  
  2. Temperature dection through TMP36.
  
  3. Sending gas and temperature every second to MAIN BOARD through HC-05.

*/
#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); //블루투스의 Tx, Rx핀을 2번 3번핀으로 설정

float T_Value; // = 온도 값
float G_Value; // = 가스 값

void setup() {
  // 시리얼 통신의 속도를 9600으로 설정
  Serial.begin(9600);
  while (!Serial) {
    ; //시리얼통신이 연결되지 않았다면 코드 실행을 멈추고 무한 반복
  }


  Serial.println("Hello World!");

  //블루투스와 아두이노의 통신속도를 9600으로 설정
  mySerial.begin(9600);
}

void loop() { //코드를 무한반복합니다.
  if (mySerial.available()) { //블루투스에서 넘어온 데이터가 있다면
    Serial.write(mySerial.read()); //시리얼모니터에 데이터를 출력
  }
  if (Serial.available()) {    //시리얼모니터에 입력된 데이터가 있다면
    mySerial.write(Serial.read());  //블루투스를 통해 입력된 데이터 전달
  }
}

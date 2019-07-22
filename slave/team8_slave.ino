

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

  int Gas_Value = A0;
  int Temperature_Value = A1;
  SoftwareSerial HC05(2,3);

void setup(){
  Serial.begin(9600);
  HC05.begin(9600);

  pinMode(Gas_Value, INPUT);
  pinMode(Temperature_Value, INPUT);
}

void loop(){
  int Gas, Temp, data[2];
  Gas = analogRead(Gas_Value);
  Temp = analogRead(Temperature_Value);

  data[0] = Gas;
  data[1] = Temp;
  
  delay(1000);

  HC05.print(" data = ");
  HC05.print(data[0], DEC);
  HC05.print("  ");
  HC05.println(data[1], DEC);

}



/*            */
/* MAIN BORAD */
/*            */

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

[[ Features in MAIN BORAD ]] 

  1. Listening to SLAVE BOARD through HC-05

  2. Detecting fire extinguisher's existence through HC-SR04

  3. Switching to the maintenance mode that doesn't activate sending notifications through 

  4. Sending notifications automatically if some conditions are satisfied through 
                                         [ GAS / TEMPERATURE / PRESSURE ] 
*/

/* Macros */
#define daytosecond 86400;

/* Pin variables*/
const int trigPin = A0;
const int echoPin = A1;

/* Third-party variables */
const unsigned float D; // = Distance threshold
const float T; // = Temperature threshold
const float G; // = Gas threshold
float duration = 0; 
float T_Value; // = Temperature value
float G_Value; // = Gas value
uint8_t Pressure_Count = 10; // = 10 seconds.
boolean Clean = True; // ON (If it is ON, it's the time to check and maintain the fire extinguisher.
boolean Flag = FALSE;
uint16_t Clean_Count = daytosecond * 30; // 30 days 

/* Functions */
boolean checkFunction(float T_Value, float G_Value, float T, float G);
uint32_t Distance(float duration);
float Get_T();
float Get_G();
void SendNotification(float temperature from sensor, float gas);
float returnTemperature(float sensorValue);

/**************************************************************************************/
/**************************************************************************************/
/**************************************************************************************/
/**************************************************************************************/

void setup() {
  pinMode(triggerpin,OUTPUT);
  pinMode(echopin, INPUT);
  Serial.begin(115200);
}

void loop() {

  /* 1. Fire extinguisher management */
  if ((Clean == false) && (Flag == false)){
      Flag = True;
    }

  if (Flag){
      Clean_Count--;

      if(Clean_Count == 0){
          Flag = false;
          Clean = true;
          Clean_Count = 30;
          delay(1000);
        }
    }
  /* 2. Ultrasonic wave detection */
  digitalWrite(triggerpin,LOW);
  delayMicroseconds(2);
  digitalWrite(triggerpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerpin, LOW);
  duration = pulseIn(echopin,HIGH);
  uint32_t Distance_mm = Distance(duration);
  
  if (Distance_mm > D){
      
      TTS()
      delay(1000);
      Pressure_Count--;

      if(Pressure_Count == 0){
        SendNotification(Get_T(), Get_G());
        Pressure_Count = 10;
        }
    }
  else{
      Pressure_Count = 10;
    }
  
  /* 3. Gas / Temperature checking */
  if (checkFunction(Get_T(), Get_G(), T, G){ // one of them is over its threshold.
      SendNotification(Get_T(), Get_G());
    }
}


/**************************************************************************************/
/**************************************************************************************/
/**************************************************************************************/
/**************************************************************************************/

                              /* Implementing Functions */

uint32_t Distance(float duration){
  uint32_t DistanceCalc;
  //DistanceCalc = ((time/2.9)/2);
  DistanceCalc = ((float)(340 * duration) / 10000) / 2; // cm
  return DistanceCalc;
}

float Get_T(){
    // return temperature from slave
  }

  
float Get_G(){
    // return Gas from slave
  }

void SendNotification(float temperature from sensor, float gas){
    //
    delay(1000);
  }

boolean checkFunction(float T_Value, float G_Value, float T, float G){
  if(returnTemperature(T_Value) > T || G_Value > G){
      // add data deletion in main board
      return True; // detection success
    } 
  // add data deletion in main board  
  }

float returnTemperature(float sensorValue){
  float voltage = sensorValue *5000.0/1024.0; 
    // Voltage changed from the value estimated by the sensor. 
  
  float celsius = (voltage -500)/10.0; 
    // Temperature changed from Voltage.

  return celsius;
  }

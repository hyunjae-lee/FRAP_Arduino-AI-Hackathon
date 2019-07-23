#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "e857e001dbbc49deb46beb6c9d854cb4";
char ssid[] = "AndroidHotspot7041";
char password[] = "qwertypoiu";

String popup = "Fire";

String extinguisher_location = "용산구 청파로 77, 3층 디지털대장간";
String phone_number = "010-****-****";
String extinguisher_serial = "A01";
String msg;

float lat = 37.533, lon = 126.959; //디지털대장간 좌표

int report = 0; 

WidgetMap myMap(V1);

void setup() {
  pinMode(D1, INPUT);

  WiFi.begin(ssid, password);
  Blynk.begin(auth, ssid, password);

  Serial.begin(9600);
}

void loop() {
  Blynk.run();
  report = digitalRead(D1); 
  if (report == HIGH) {
    Serial.println("Alert");
    msg = "Location: \n" + extinguisher_location + "\nPhone number: " + phone_number + "\nSerial Number: " + extinguisher_serial;

    Blynk.notify(msg);

    myMap.location(0, lat, lon, popup);

    delay(5000);

    myMap.clear();
  }
  delay(1000);
}

#include <TinyGPS++.h>
#include <SoftwareSerial.h>

static const int RXPin = 4, TXPin = 3;
String fecha, pos;

// The TinyGPS++ object
TinyGPSPlus gps;

// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);

void setup(){
  Serial.begin(115200);
  ss.begin(9600);
}

void loop(){
  // This sketch displays information every time a new sentence is correctly encoded.
  while (ss.available() > 0){
    gps.encode(ss.read());
    if (gps.location.isUpdated()){
      pos=String(gps.location.lat(), 6)+"\t"+String(gps.location.lng(), 6);
      Serial.print("Lat & Long\t"); 
      Serial.print(pos);
      /*Serial.print("Lat & Long "); 
      Serial.print(gps.location.lat(), 6);
      Serial.print(" Longitude= "); */
      Serial.println(gps.location.lng(), 6);
      Serial.print("date & time\t"); 
      fecha=String(gps.date.year())+"/"+String(gps.date.month())+"/"+String(gps.date.day())+"\t"+String(gps.time.hour())+":"+String(gps.time.minute());
      Serial.println(fecha); 
      
    }
  }
}
# include<SoftwareSerial.h>
# define rPin 4 //pin receptor, onectado a transmisor
# define tPin 5 //pin transmisor, conectado a receptor 
SoftwareSerial bt(rPin,tPin);//rx tx
String mnsg1,mnsg2;
void setup() {
  Serial.begin(9600);
  bt.begin(9600);
}

void loop() {
  if(bt.available()){
    mnsg1=bt.readString();
    Serial.print(mnsg1);
  }
  if(Serial.available()){
    mnsg2=Serial.readString();
    bt.print(mnsg2);
  }
}

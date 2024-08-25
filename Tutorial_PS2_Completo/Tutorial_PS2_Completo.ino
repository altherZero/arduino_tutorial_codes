#include <PS2X_lib.h>

PS2X ps2x;
int led1= 2;
int led2= 10;
int ain2=8;//motor 1
int ain1=7;//motor 1
int pwma=6;//motor 1
int pwmb=5;//motor 2
int bin1=4;//motor 2
int bin2=3;//motor 2
bool x;
bool y;
bool z;
int vell=0;
int velr=0;
int error = 0;
byte vibrate = 0;

void setup()
{
  Serial.begin(9600);
  error = ps2x.config_gamepad(11,12,A0,A2,true,true);  //(clock, command, attention, data)

  if(error == 0)
  {
    Serial.println("Controlador encontrado y configurado");
  }
  else
  {
    Serial.println("Error, mando no encontrado");
  }
}

void loop() 
{
  int temp;
  ps2x.read_gamepad(false,vibrate);

  vibrate = ps2x.Analog(PSAB_BLUE);
  
  /*if(ps2x.Button(PSB_PAD_UP))
  {
    temp = ps2x.Analog(PSAB_PAD_UP);
    Serial.print("Presionaste arriba: ");
    Serial.println(temp);
  }
  
  else if(ps2x.Button(PSB_PAD_DOWN))
  {
    temp = ps2x.Analog(PSAB_PAD_DOWN);
    Serial.print("Presionaste abajo: ");
    Serial.println(temp);
  }

  else if(ps2x.Button(PSB_PAD_LEFT))
  {
    temp = ps2x.Analog(PSAB_PAD_LEFT);
    Serial.println("Presionaste izquierda: ");
    Serial.print(temp);
  }

  else if(ps2x.Button(PSB_PAD_RIGHT))
  {
    temp = ps2x.Analog(PSAB_PAD_RIGHT);
    Serial.println("Presionaste derecha: ");
    Serial.print(temp);
  }


  if(ps2x.Button(PSB_BLUE))
  {
    Serial.println("Presionaste X: ");
  }
  if(ps2x.Button(PSB_PINK))
  {
    Serial.println("Presionaste cuadrado: ");
  }
  if(ps2x.Button(PSB_RED))
  {
    Serial.println("Presionaste redondo: ");
  }
  if(ps2x.Button(PSB_GREEN))
  {
    Serial.println("Presionaste triangulo: ");
  }
  if(ps2x.Button(PSB_L1))
  {
    Serial.println("Presionaste L1: ");
  }
  if(ps2x.Button(PSB_L2))
  {
    Serial.println("Presionaste L2: ");
  }
  if(ps2x.Button(PSB_R1))
  {
    Serial.println("Presionaste R1: ");
  }
  if(ps2x.Button(PSB_R2))
  {
    Serial.println("Presionaste R2: ");
  }

  
  if(ps2x.Button(PSB_SELECT))
  {
    Serial.println("Presionaste seleccionar: ");
  }
  else if(ps2x.Button(PSB_START))
  {
    Serial.println("Presionaste entrar: ");
  }*/

  
   int ly,lx,ry,rx;
      ly=ps2x.Analog(PSS_LY); //Mando Izquierdo
      //ly=0.9*(-1*(ly-127));
      lx=ps2x.Analog(PSS_LX); 
      //lx=0.9*(lx-127);
      ry=ps2x.Analog(PSS_RY); //Mando derecho
      //ry=0.9*(-1*(ry-127));
      rx=ps2x.Analog(PSS_RX); 
      //rx=0.9*(rx-127);

      if(120<=ly&&ly<=134){//posicion normal
      x=false;
      y=false;
      vell=0;
      }     
      else if(ly<120){//avance
      x=true;
      y=false; 
      vell=(255-2*(ly))*0.395;
      }      
      else if(ly>134){//reversa
      x=false;
      y=true;
      vell=((2.017*ly)-282)*0.395;
      }      
      /*if(120<=rx&&rx<=134){
      velr=vell;
     }
     
      else if(rx<120){
      velr=vell*0.5;
      }
      
      else if(rx>134){
      velr=vell;  
      vell=vell*0.5;
      }*/
      velr=vell*(1/0.395);  
     Serial.println(ly);
     Serial.println(vell);
     Serial.println(x);
     Serial.println(y);  
    digitalWrite(ain1,x); 
    digitalWrite(ain2,y);
    analogWrite(pwma,vell);
    digitalWrite(bin1,x); 
    digitalWrite(bin2,y);
    analogWrite(pwmb,velr);
    }

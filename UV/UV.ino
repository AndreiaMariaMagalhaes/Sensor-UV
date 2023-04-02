
//definir pin UV
int pino_sensor = A0;
String UV = "0";
//definir pin rgb
int pino_Azul = 11;
int pino_Verde = 10;
int pino_Vermelho = 9;
#define COMMON_ANODE
void setup(void)
{
  Serial.begin(9600);
  pinMode(pino_sensor, INPUT);
  pinMode(pino_Azul, OUTPUT);
  pinMode(pino_Verde, OUTPUT);
  pinMode(pino_Vermelho, OUTPUT);
  teatarCores();
}

void loop() {
  int stringLength = 0; 
  UV = readSensor();
  //Serial.print(UV);
  Serial.print("Index UV: ");
  Serial.println(UV);
  Serial.println("**************************");
  delay(1500);
}

String readSensor()
{
  String UVIndex = "0";
  int sensorValue = 0;
  
  sensorValue = analogRead(0);                        //connect UV sensor to Analog 0   
  int voltage = (sensorValue * (5.0 / 1023.0))*1000;  //Voltage in miliVolts

  Serial.print("Valor Leitura:");
  Serial.println(sensorValue);

  Serial.print("Valor Voltagem:");
  Serial.print(voltage);
  Serial.println(" mV");
  
  if(voltage<50)
  {
    UVIndex = "0";
    colorLed(0,153,0);
  }else if (voltage>50 && voltage<=227)
  {
    UVIndex = "0";
    colorLed(0,204,0);
  }else if (voltage>227 && voltage<=318)
  {
    UVIndex = "1";
    colorLed(51,255,51);
  }
  else if (voltage>318 && voltage<=408)
  {
    UVIndex = "2";
    colorLed(178,255,102);
  }else if (voltage>408 && voltage<=503)
  {
    UVIndex = "3";
    colorLed(153,153,0);
  }
  else if (voltage>503 && voltage<=606)
  {
    UVIndex = "4";
    colorLed(204,204,0);
  }else if (voltage>606 && voltage<=696)
  {
    UVIndex = "5";
    colorLed(255,255,0);
  }else if (voltage>696 && voltage<=795)
  {
    UVIndex = "6";
    colorLed(204,102,0);
  }else if (voltage>795 && voltage<=881)
  {
    UVIndex = "7";
    colorLed(255,153,51);
  }
  else if (voltage>881 && voltage<=976)
  {
    UVIndex = "8";
    colorLed(153,0,0);
  }
  else if (voltage>976 && voltage<=1079)
  {
    UVIndex = "9";
    colorLed(255,0,0);
      }
  else if (voltage>1079 && voltage<=1170)
  {
    UVIndex = "10";
    colorLed(255,102,102);
  }else if (voltage>1170)
  {
    UVIndex = "11";
    colorLed(127,0,255);
  }
  return UVIndex;
}

void colorLed(int r, int g, int b){
  
  #ifdef COMMON_ANODE
    r=255-r;
    g=255-g;
    b=255-b;
  #endif 
  
    analogWrite(pino_Vermelho, r);
    analogWrite(pino_Verde, g);
    analogWrite(pino_Azul, b);
  }

 void teatarCores(){
    //Testar color
    delay(1500);
    colorLed(0,0,255); //testar Azul
    delay(1500);
    colorLed(255,0,0); //testar vermelho
    delay(1500);
    colorLed(0,255,0); //testar vermelho
    delay(1500);
    colorLed(255,255,255); //testar Branco
    delay(1500);
  }

#include <Arduino.h>
#include <TM1637Display.h>
#include <ArduinoBLE.h>

#define CLK 2
#define DIO 3
#define BTN1 4
#define BTN2 5
#define BTN3 6
#define BTN4 7
#define BTN5 8

TM1637Display disp(CLK,DIO);
BLEService svc("180A");
BLEStringCharacteristic chr("2A57",BLERead|BLENotify,20);

int hr=12,min=0,sec=0;
int mode=0;
bool sleep=false;
unsigned long last=0,tick=0;
int val=0;
char oper=' ';
bool fresh=true;

void setup(){
  pinMode(BTN1,INPUT_PULLUP);
  pinMode(BTN2,INPUT_PULLUP);
  pinMode(BTN3,INPUT_PULLUP);
  pinMode(BTN4,INPUT_PULLUP);
  pinMode(BTN5,INPUT_PULLUP);
  disp.setBrightness(0x02);
  if(!BLE.begin()){while(1);}
  BLE.setLocalName("Watch");
  BLE.setAdvertisedService(svc);
  svc.addCharacteristic(chr);
  BLE.addService(svc);
  BLE.advertise();
}

void loop(){
  BLEDevice dev=BLE.central();
  if(dev){
    while(dev.connected()){
      tick_time();
      handle_btns();
      update_disp();
    }
  }
  tick_time();
  handle_btns();
  update_disp();
  if(millis()-last>30000&&!sleep){
    disp.setBrightness(0x00);
    sleep=true;
  }
}

void tick_time(){
  if(millis()-tick>=1000){
    tick=millis();
    sec++;
    if(sec>=60){sec=0;min++;if(min>=60){min=0;hr++;if(hr>=24)hr=0;}}
  }
}

void handle_btns(){
  if(digitalRead(BTN1)==LOW){
    delay(200);
    last=millis();
    if(sleep){disp.setBrightness(0x02);sleep=false;return;}
    mode=(mode+1)%3;
  }
  if(mode==0&&digitalRead(BTN2)==LOW){
    delay(200);
    hr=(hr+1)%24;
  }
  if(mode==0&&digitalRead(BTN3)==LOW){
    delay(200);
    min=(min+1)%60;
  }
  if(mode==1){
    if(digitalRead(BTN2)==LOW){
      delay(200);
      if(fresh){val=0;fresh=false;}
      val=val*10+1;
      if(val>9999)val=9999;
    }
    if(digitalRead(BTN3)==LOW){
      delay(200);
      if(fresh){val=0;fresh=false;}
      val=val*10+2;
      if(val>9999)val=9999;
    }
    if(digitalRead(BTN4)==LOW){
      delay(200);
      int tmp=val;
      if(oper=='+')val=val+tmp;
      if(oper=='-')val=val-tmp;
      if(oper=='*')val=val*tmp;
      if(oper=='/')if(tmp!=0)val=val/tmp;
      oper='+';
      fresh=true;
    }
    if(digitalRead(BTN5)==LOW){
      delay(200);
      val=0;oper=' ';fresh=true;
    }
  }
}

void update_disp(){
  if(mode==0){
    int show=(hr*100)+min;
    disp.showNumberDecEx(show,0b01000000,true);
  }
  if(mode==1){
    disp.showNumberDec(val,false);
  }
  if(mode==2){
    int date=1225;
    disp.showNumberDec(date,false);
  }
}

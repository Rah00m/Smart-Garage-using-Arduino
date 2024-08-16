#include <LiquidCrystal_I2C.h>


#include <Servo.h>
Servo myservo1;
LiquidCrystal_I2C lcd(0x27, 16, 2);
#define ir1 4
#define ir2 7
#define FLAME 6 
#define ALARM 8 
int room = 3;
int old1 = 1;
int old2 = 1;
int old3 = 1;
int old4 = 1;

int i;
unsigned long Time;
unsigned long Time2;
unsigned long Time3;
unsigned long Time4;
int ldr_pin = 11;
int led_pin = 2;
int led =3;
void setup() {lcd.init();
  // put your setup clcd.init();
lcd.backlight();
 pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  myservo1.attach(9);
  pinMode(ldr_pin,INPUT);
  pinMode(led_pin,OUTPUT);
  pinMode(FLAME, INPUT);
  pinMode(ALARM, OUTPUT);
lcd.begin(16,2);
lcd.print("car parking");
delay(1000);
lcd.clear();
lcd.setCursor(0,1);
lcd.print("EMPTY:");
lcd.setCursor(6,1);
   lcd.print(room);
   }

void loop() {



  int fire = digitalRead(FLAME);// read FLAME sensor


  if( fire == HIGH)
  {
    digitalWrite(ALARM,HIGH);// set the buzzer ON
  }else{
    digitalWrite(ALARM,LOW); // Set the buzzer OFF
    // Flame sensor code for Robojax.com

  }
  
  
 if (digitalRead(ir1) == 0 && old1 == 1&&old2==1&& room>0) 
  {
       for(i=90;i>=0;i=i-10){
  myservo1.write(i);

      delay(100);
    old1=0;
    old3=0;}Time=millis();}
if((millis()-Time)>3000&&digitalRead(ir2)==1&&digitalRead(ir1)==1&& i==-10&&old2==1){
       
      
  for(i=0;i<=90;i=i+10){
    myservo1.write(i);
    delay(100);
    old1=1;
    old2=1;}}
/*while(digitalRead(ir1) == 0 ){digitalRead(ir1);
int fire = digitalRead(FLAME);// read FLAME sensor


  if( fire == HIGH)
  {
    digitalWrite(ALARM,HIGH);// set the buzzer ON
   
  }else{
    digitalWrite(ALARM,LOW); // Set the buzzer OFF
   
    // Flame sensor code for Robojax.com

  }if( digitalRead( ldr_pin ) == 1){
      digitalWrite( led_pin,HIGH);
   }
   else{
      digitalWrite( led_pin , LOW);
   }}*/
 
 if(digitalRead(ir2)==0&&old1==0&& room>0&&old3==0)
 {old3=1;
  room = room - 1;lcd.setCursor(6,1);
   lcd.print(room);
  
   Time3=millis();
   if(millis()-Time3>3000)
  
  { for(i=0;i<=90;i=i+10){
  myservo1.write(i);
   delay(100);}
old1=1;
   }
   
   while(digitalRead(ir2) == 0 ){digitalRead(ir2);
   int fire = digitalRead(FLAME);// read FLAME sensor


  if( fire == HIGH)
  {
    digitalWrite(ALARM,HIGH);// set the buzzer ON
    
  }else{
    digitalWrite(ALARM,LOW); // Set the buzzer OFF
   
    // Flame sensor code for Robojax.com

  }
  if( digitalRead( ldr_pin ) == 1){
      digitalWrite( led_pin,HIGH);
      digitalWrite(led,HIGH);
   }
   else{
      digitalWrite( led_pin , LOW);
      digitalWrite(led,LOW);
   }}
  
   }
   if (digitalRead(ir2) == 0 && old2 == 1&&old1==1&& room<3) 
  {
      for(i=90;i>=0;i=i-10){
  myservo1.write(i);
      delay(100);
    }old2=0;old4=0;Time2=millis();}if((millis()-Time2)>3000&&digitalRead(ir2)==1&&digitalRead(ir1)==1&& i==-10&&old1==1){
       
      
  for(i=0;i<=90;i=i+10){
    myservo1.write(i);
    delay(100);
    old1=1;
    old2=1;}}
/*while(digitalRead(ir2) == 0 ){digitalRead(ir2);
int fire = digitalRead(FLAME);// read FLAME sensor


  if( fire == HIGH)
  {
    digitalWrite(ALARM,HIGH);// set the buzzer ON
    
  }else{
    digitalWrite(ALARM,LOW); // Set the buzzer OFF
    
    // Flame sensor code for Robojax.com

  }
  if( digitalRead( ldr_pin ) == 1){
      digitalWrite( led_pin,HIGH);
   }
   else{
      digitalWrite( led_pin , LOW);
   }}
 } */
 
 
 if(digitalRead(ir1)==0&&old2==0&&old4==0&& room<3)
 {old4=1;
  room = room + 1;
   lcd.setCursor(6,1);
   lcd.print(room);
   Time4=millis();
   if(millis()-Time4>3000)
  { for(i=0;i<=90;i=i+10){
  myservo1.write(i);
   delay(100);}
   old2=1;}
   while(digitalRead(ir1) == 0 ){digitalRead(ir1);
   int fire = digitalRead(FLAME);// read FLAME sensor


  if( fire == HIGH)
  {
    digitalWrite(ALARM,HIGH);// set the buzzer ON
  }else{
    digitalWrite(ALARM,LOW); // Set the buzzer OFF
    
    // Flame sensor code for Robojax.com

  }if( digitalRead( ldr_pin ) == 1){
      digitalWrite( led_pin,HIGH);
      digitalWrite(led,HIGH);
   }
   else{
      digitalWrite( led_pin , LOW);
      digitalWrite(led,LOW);
   }}}
  if(room==0){lcd.setCursor(0,0);
    lcd.print("ALL ARE FULL!!!");}
    else{lcd.setCursor(0,0);
    lcd.print("U CAN PARK HERE");
    }

if( digitalRead( ldr_pin ) == 1){
      digitalWrite( led_pin,HIGH);
      digitalWrite(led,HIGH);
   }
   else{
      digitalWrite( led_pin , LOW);
      digitalWrite(led,LOW);
   }
   
}
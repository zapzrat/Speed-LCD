#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);



int pinSpeed_1 = 13;
int pinSpeed_2 = 12;
int pinSpeed_3 = 11;

int state_Speed_1 = 0;
int state_Speed_2 = 0;
int state_Speed_3 = 0;

int coin_10 = 0 ;
int coin_5 = 0 ;
int coin_1 = 0 ;

int oneClink_1 = 0;
int oneClink_2 = 0;
int oneClink_3 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Micro Projects TH");

  pinMode(pinSpeed_1, INPUT); 
  pinMode(pinSpeed_2, INPUT); 
  pinMode(pinSpeed_3, INPUT);



  lcd.begin();
  lcd.print("Hello");
  lcd.setCursor(0, 1);
  lcd.print("Micro Project TH");

  delay(1000);

  lcd.clear();

}

void loop() {
  // put your main code here, to run repeatedly:
  state_Speed_1 = digitalRead(pinSpeed_1);
  state_Speed_2 = digitalRead(pinSpeed_2);
  state_Speed_3 = digitalRead(pinSpeed_3);

//  Serial.print("state_Speed_1 : "); Serial.println(state_Speed_1);
//  Serial.print("state_Speed_2 : "); Serial.println(state_Speed_2);
//  Serial.print("state_Speed_3 : "); Serial.println(state_Speed_3);


  if (state_Speed_1 == 1) {
    if (oneClink_1 == 0) {
      oneClink_1 = 1;
      coin_1 ++;
    }
  }
  else if (state_Speed_1 == 0 ) {
    oneClink_1 = 0;
  }



  if (state_Speed_2 == 1) {
    if (oneClink_2 == 0) {
      oneClink_2 = 1;
      coin_5++;
    }
  }
  else if (state_Speed_2 == 0 ) {
    oneClink_2 = 0;
  }



  if (state_Speed_3 == 1) {
    if (oneClink_3 == 0) {
      oneClink_3 = 1;
      coin_10 ++;
    }
  }
  else if (state_Speed_3 == 0 ) {
    oneClink_3 = 0;
  }


//  Serial.print("coin_1 : "); Serial.println(coin_1);
//  Serial.print("coin_5 : "); Serial.println(coin_5);
//  Serial.print("coin_10 : "); Serial.println(coin_10);
//
//
//  Serial.println("************************************************");
//  Serial.println("************************************************");
//  Serial.println();


  lcd.setCursor(0, 0);
  lcd.print("c_1 :");
  lcd.print(coin_1);


  lcd.setCursor(9, 0);
  lcd.print("c_5 :");
  lcd.print(coin_5);

  lcd.setCursor(0, 1);
  lcd.print("c_10 :");
  lcd.print(coin_10);
//  delay(1000);

  
}

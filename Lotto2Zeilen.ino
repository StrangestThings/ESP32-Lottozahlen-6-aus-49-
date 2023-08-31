#include <analogWrite.h>
#include <ESP32Tone.h>
#include <ESP32PWM.h>

#include <LiquidCrystal.h>
LiquidCrystal lcd(22, 23, 5, 18, 19, 21);

long int counter = 1;

  
void setup() {

  // Datenausgabe einrichten
  lcd.begin(16, 2);
  Serial.begin(9600);

  // Konstanten für die Entscheidungen einstellen

  long int ziehungen = 0;
  int finz = 0;
  int game = 0;
  int fingame = 0;
  long int Mkopf = 0;
  long int Mzahl = 0;
  long int winkel=0;


pinMode(33, OUTPUT); // Grüne Diode, welche das Ergebnis anzeigt! 
pinMode(32, OUTPUT); // Rote Diode, welche Berechnungen anzeigt!
pinMode(25, OUTPUT); // Blaue Diode, welche nächste Ziehung anzeigt!

digitalWrite(33, HIGH);
digitalWrite(32, HIGH);
digitalWrite(25, HIGH);


  // ******************* ENDE Void Setup
}

void loop() {



if(counter==1){

digitalWrite(33, HIGH);
digitalWrite(32, HIGH);
digitalWrite(25, HIGH);

lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Lotto-");
    lcd.setCursor(0, 1);
    lcd.print("Simulator (2023)");
    delay (3000);
    lcd.setCursor(0, 0);
    lcd.print("Quantenfluxt so");
    lcd.setCursor(0, 1);
    lcd.print("vor sich hin... ");
    delay (3000);
}

digitalWrite(33, LOW);
digitalWrite(32, LOW);
digitalWrite(25, HIGH);

lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Ziehung: ");
    lcd.print(counter);
delay(1000);
lcd.clear();
counter++;

digitalWrite(33, LOW);
digitalWrite(32, HIGH);
digitalWrite(25, LOW);

  // Und nun das entsprechende Array für das Spiel 6aus49 generieren

    long int Array[49] = {};
    long int Num[6] = {};
    long int Numfin[6] = {};
    long int Numfin2[6] = {};

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Fluxcompensating");

digitalWrite(32, HIGH);
digitalWrite(15, LOW);

    for (long int j = 0; j < 2000000; j++) {
      Array[random(0, 49)]++;
      if ((j % 20000) < 1) {
        lcd.setCursor(0, 1);
        lcd.print(j / 20000);
        lcd.print(" Prozent...");
      }
    }

  
    // Die 6 am meisten gezogenen Zahlen identifizieren

    for (int drw = 0; drw < 6; drw++) {

      long int tst = 0;
      long int tst1 = 0;

      for (int k = 0; k < 49; k++) {
        if (Array[k] > tst) {
          tst = Array[k];
          tst1 = (k + 1);
        }
      }

      //Serial.println(tst1);
      Num[drw] = tst1;
      Array[tst1 - 1] = 0;
    }

    // Das Array mit den Zahlen nach Größe sortieren

    for (int drw = 0; drw < 6; drw++) {

      long int tst = 0;
      long int tst1 = 0;

      for (int k = 0; k < 6; k++) {
        if (Num[k] > tst) {
          tst = Num[k];
          tst1 = (k + 1);
        }
      }

      
      Numfin[drw] = tst;
      
      Num[tst1 - 1] = 0;
    }

    // Und nun die Sortierung umkehren

    for (int k = 0; k < 6; k++) {
      Numfin2[5 - k] = Numfin[k];
    }

digitalWrite(33, HIGH);
digitalWrite(32, LOW);
digitalWrite(25, LOW);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Zahlen: ");

    lcd.print(Numfin2[0]);
    lcd.print("-");
    lcd.print(Numfin2[1]);
    lcd.print("-");
    lcd.setCursor(0, 1);
    lcd.print(Numfin2[2]);
    lcd.print("-");
    lcd.print(Numfin2[3]);
    lcd.print("-");
    lcd.print(Numfin2[4]);
    lcd.print("-");
    lcd.print(Numfin2[5]);  



delay(1500);

  }

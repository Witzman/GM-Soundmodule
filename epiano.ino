

const uint8_t PROGRAM_CHANGE = 0xC0;

#include <LiquidCrystal.h>
#include <Encoder.h> // Include the PJRC Encoder library

const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define encoder0PinA 12
#define encoder0PinB 11
const int buttonPin = 9;     // the number of the pushbutton pin
uint8_t encoder0Pos = 0;
 byte encoder0PinALast = LOW;
 byte encoderN = LOW;
const int buttondownPin = 10;     // the number of the pushbutton pin

const byte channel = 1; // MIDI channel 1
const byte controller = 10111111; // General Purpose Controller 1


int buttonState = 0;         // variable for reading the pushbutton status



void MIDIchange(int command, int MIDIbank) {
  Serial.write(command);//send note on or note off command 
  Serial.write(MIDIbank);//send pitch data
//Serial.println(encoder0Pos);
delay(50);

}
void setup() {
Serial.begin(31250);
//Serial.begin(9600);
pinMode (encoder0PinA,INPUT);
pinMode (encoder0PinB,INPUT);
   pinMode(buttonPin, INPUT_PULLUP);
   pinMode(buttondownPin, INPUT_PULLUP);
   lcd.begin(16, 2);
   lcd.print("GM Soundmodule");
}

void loop() {

encoderN = digitalRead(encoder0PinA);
   if ((encoder0PinALast == LOW) && (encoderN == HIGH)) {
     if (digitalRead(encoder0PinB) == LOW) {
       if (encoder0Pos > 0) {
       encoder0Pos--;
       lcd.clear();
       delay(10);
       }
     } else {
      if (encoder0Pos < 127) {
       encoder0Pos++;
       lcd.clear();
       delay(20);
      }
     }
  } 
  encoder0PinALast = encoderN;

 int buttonValue = digitalRead(buttonPin);
   if (buttonValue == LOW){
       MIDIchange(PROGRAM_CHANGE, encoder0Pos);
       lcd.setCursor(0,0);
       lcd.clear();
switch (encoder0Pos) {
    case 0:    
      lcd.print("Piano 1");
      break;
    case 1:    
      lcd.print("Piano");
      break;
    case 2:    
      lcd.print("Br. Piano");
      break;
    case 3:    
      lcd.print("El Grd.Piano");
      break;
    case 4:    
      lcd.print("Honky Tonk Pian");
      break;
    case 5:    
      lcd.print("El. Piano 1");
      break;
    case 6:    
      lcd.print("El. Piano 2");
      break;
    case 7:    
      lcd.print("Harpischord");
      break;
    case 8:    
      lcd.print("Clavi");
      break;
    case 9:    
      lcd.print("Celesta");
      break;
    case 10:    
      lcd.print("Glockenspiel");
      break;
    case 11:    
      lcd.print("MusicBox");
      break;
    case 12:    
      lcd.print("Vibraphone");
      break;
    case 13:    
      lcd.print("Marimba");
      break;
    case 14:    
      lcd.print("Xylophone");
      break;
    case 15:    
      lcd.print("Tubular Bells");
      break;
    case 16:    
      lcd.print("Santur");
      break;
    case 17:    
      lcd.print("Dr. Organ");
      break;
    case 18:    
      lcd.print("Pe. Organ");
      break;
     case 19:    
      lcd.print("Rock Organ");
      break;
    case 20:    
      lcd.print("Church Organ");
      break;
    case 21:    
      lcd.print("Reed Organ");
      break;
    case 22:    
      lcd.print("Accordion");
      break;
    case 23:    
      lcd.print("Harmonica");
      break;
    case 24:    
      lcd.print("Ta. Accordion");
      break;
    case 25:    
      lcd.print("Guitar Ac ny");
      break;
    case 26:    
      lcd.print("Guitar Ac st");
      break;
    case 27:    
      lcd.print("Guitar El ja");
      break;
    case 28:    
      lcd.print("Guitar El cl");
      break;
     case 29:    
      lcd.print("Guitar El mu");
      break;
    case 30:    
      lcd.print("Guitar El od");
      break; 
    case 31:    
      lcd.print("Guitar El di");
      break;
    case 32:    
      lcd.print("Guitar harm");
      break;
    case 33:    
      lcd.print("Bass ac");
      break;
    case 34:    
      lcd.print("Bass finger");
      break;
    case 35:    
      lcd.print("Bass picked");
      break;
    case 36:    
      lcd.print("Bass Fretless");
      break;
    case 37:    
      lcd.print("Slap Bass 1");
      break;
    case 38:    
      lcd.print("Slap Bass 2");
      break;
     case 39:    
      lcd.print("Synth Bass 1");
      break;
    case 40:    
      lcd.print("Synth Bass 2");
      break; 
    case 41:    
      lcd.print("Violin");
      break;
    case 42:    
      lcd.print("Viola");
      break;
    case 43:    
      lcd.print("Cello");
      break;
    case 44:    
      lcd.print("Contrabass");
      break;
    case 45:    
      lcd.print("Trem. String");
      break;
    case 46:    
      lcd.print("Pizz. String");
      break;
    case 47:    
      lcd.print("Orch. Harp");
      break;
    case 48:    
      lcd.print("Timpani");
      break;
    case 49:    
      lcd.print("String Ens.1");
      break;
    case 50:    
      lcd.print("String Ens.2");
      break;
    case 51:    
      lcd.print("Synth Strings 1");
      break;
    case 52:    
      lcd.print("Synth Strings 2");
      break;
    case 53:    
      lcd.print("Choir Ahh");
      break;
    case 54:    
      lcd.print("Choir Ohh");
      break;
    case 55:    
      lcd.print("Synth Voice");
      break;
    case 56:    
      lcd.print("Orch. Hit");
      break;
    case 57:    
      lcd.print("Trumpet");
      break;
    case 58:    
      lcd.print("Trombone");
      break;
     case 59:    
      lcd.print("Tuba");
      break;
    case 60:    
      lcd.print("Muted Trumpet");
      break;
    case 61:    
      lcd.print("French Horno");
      break;
    case 62:    
      lcd.print("Brass Section");
      break;
    case 63:    
      lcd.print("Synth Brass 1");
      break;
    case 64:    
      lcd.print("Synth Brass 2");
      break;
    case 65:    
      lcd.print("Soprano Sax");
      break;
    case 66:    
      lcd.print("Alto Sax");
      break;
    case 67:    
      lcd.print("Tenor Sax");
      break;
    case 68:    
      lcd.print("Baritone Sax");
      break;
     case 69:    
      lcd.print("Oboe");
      break;
    case 70:    
      lcd.print("Engl. Horn");
      break; 
    case 71:    
      lcd.print("Bassoon");
      break;
    case 72:    
      lcd.print("Clarinet");
      break;
    case 73:    
      lcd.print("Piccolo");
      break;
    case 74:    
      lcd.print("Flute");
      break;
    case 75:    
      lcd.print("Recorder");
      break;
    case 76:    
      lcd.print("Pan Flute");
      break;
    case 77:    
      lcd.print("Blown Bottle");
      break;
    case 78:    
      lcd.print("Shakuhachi");
      break;
     case 79:    
      lcd.print("Whistle");
      break;
    case 80:    
      lcd.print("Ocarina");
      break; 
    case 81:    
      lcd.print("Lead 1");
      break;
    case 82:    
      lcd.print("Lead 2");
      break;
    case 83:    
      lcd.print("Lead 3");
      break;
    case 84:    
      lcd.print("Lead 4");
      break;
    case 85:    
      lcd.print("Lead 5");
      break;
    case 86:    
      lcd.print("Lead 6");
      break;
    case 87:    
      lcd.print("Lead 7");
      break;
    case 88:    
      lcd.print("Lead 8");
      break;
    case 89:    
      lcd.print("Pad 1");
      break;
    case 90:    
      lcd.print("Pad 2");
      break;
    case 91:    
      lcd.print("Pad 3");
      break;
    case 92:    
      lcd.print("Pad 4");
      break;
    case 93:    
      lcd.print("Pad 5");
      break;
    case 94:    
      lcd.print("Pad 6");
      break;
    case 95:    
      lcd.print("Pad 7");
      break;
    case 96:    
      lcd.print("Pad 8");
      break;
    case 97:    
      lcd.print("FX 1");
      break;
    case 98:    
      lcd.print("FX 2");
      break;
     case 99:    
      lcd.print("FX 3");
      break;
    case 100:    
      lcd.print("FX 4");
      break;
    case 101:    
      lcd.print("FX 5");
      break;
    case 102:    
      lcd.print("FX 6");
      break;
    case 103:    
      lcd.print("FX 7");
      break;
    case 104:    
      lcd.print("FX 8");
      break;
    case 105:    
      lcd.print("Sitar");
      break;
    case 106:    
      lcd.print("Banjo");
      break;
    case 107:    
      lcd.print("Shamisen");
      break;
    case 108:    
      lcd.print("Koto");
      break;
     case 109:    
      lcd.print("Kalimba");
      break;
    case 110:    
      lcd.print("Bag Pipe");
      break; 
    case 111:    
      lcd.print("Fiddle");
      break;
    case 112:    
      lcd.print("Shanai");
      break;
    case 113:    
      lcd.print("Tinkle Bell");
      break;
    case 114:    
      lcd.print("Agogo");
      break;
    case 115:    
      lcd.print("Steel Drums");
      break;
    case 116:    
      lcd.print("Woodblock");
      break;
    case 117:    
      lcd.print("Taiko");
      break;
    case 118:    
      lcd.print("Melodic Tom");
      break;
     case 119:    
      lcd.print("Synth Drum");
      break;
    case 120:    
      lcd.print("Rev. Cymbal");
      break; 
    case 121:    
      lcd.print("Gt. Fret Noise");
      break;
    case 122:    
      lcd.print("Breath Noise");
      break;
    case 123:    
      lcd.print("Seashore");
      break;
    case 124:    
      lcd.print("Bird Tweet");
      break;
    case 125:    
      lcd.print("Telephone");
      break;
    case 126:    
      lcd.print("Helicopter");
      break;
    case 127:    
      lcd.print("Applause");
      break;
    case 128:    
      lcd.print("Gunshot");
      break;
  } 
       delay(150);
   } else {
   }

int buttondownValue = digitalRead(buttondownPin);
   if (buttondownValue == LOW){
    if (encoder0Pos > 0) {
       encoder0Pos--;
       delay(100);
       }
else {
   }
   } else {
   }
lcd.setCursor(0,1);
lcd.print("Bank: ");
lcd.print(encoder0Pos);
}

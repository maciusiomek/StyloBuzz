#include "MIDIUSB.h"

#define BTN_OCTAVE 19
#define BTN_VIBRATO 20

const char ch = 0; // default channel
const char sp = 64; // defulat speed

char btn0state = 0;
char btn0prev_state = 0;
char btn1state = 0;
char btn1prev_state = 0;
char btn2state = 0;
char btn2prev_state = 0;
char btn3state = 0;
char btn3prev_state = 0;
char btn4state = 0;
char btn4prev_state = 0;
char btn5state = 0;
char btn5prev_state = 0;
char btn6state = 0;
char btn6prev_state = 0;
char btn7state = 0;
char btn7prev_state = 0;
char btn8state = 0;
char btn8prev_state = 0;
char btn9state = 0;
char btn9prev_state = 0;
char btn10state = 0;
char btn10prev_state = 0;
char btn11state = 0;
char btn11prev_state = 0;
char btn12state = 0;
char btn12prev_state = 0;
char btn13state = 0;
char btn13prev_state = 0;
char btn14state = 0;
char btn14prev_state = 0;
char btn15state = 0;
char btn15prev_state = 0;
char btn16state = 0;
char btn16prev_state = 0;
char btn17state = 0;
char btn17prev_state = 0;
char btn18state = 0;
char btn18prev_state = 0;
char btn19state = 0;
char btn19prev_state = 0;

const int btn0pitch = 45;
const int btn1pitch = 46;
const int btn2pitch = 47;
const int btn3pitch = 48;
const int btn4pitch = 49;
const int btn5pitch = 50;
const int btn6pitch = 51;
const int btn7pitch = 52;
const int btn8pitch = 53;
const int btn9pitch = 54;
const int btn10pitch = 55;
const int btn11pitch = 56;
const int btn12pitch = 57;
const int btn13pitch = 58;
const int btn14pitch = 59;
const int btn15pitch = 60;
const int btn16pitch = 61;
const int btn17pitch = 62;
const int btn18pitch = 63;
const int btn19pitch = 64;

int octave = 0;
int vibrato = 0;
int vibrato_freq = 0;

void noteOn(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
}

void noteOff(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(5, OUTPUT);
  pinMode(BTN_OCTAVE, INPUT_PULLUP);
  pinMode(BTN_VIBRATO, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  float V1 = analogRead(A8) *(5.0/1023.0);
  float V2 = analogRead(A7) *(5.0/1023.0);
  float V3 = analogRead(A6) *(5.0/1023.0);
  
  octave = digitalRead(BTN_OCTAVE);
  vibrato = digitalRead(BTN_VIBRATO);

  if(0.8>V1){     //check which key is pressed
    if(V1<0.85){  
      btn3state = 1;  
    }
    else if(V1<1.5){  
      btn2state = 1;
    }
    else if (V1<1.9){   
      btn4state = 1;
    }
    else if(V1<2.3){  
      btn1state = 1;
    }
    else if (V1<2.5){  
      btn5state = 1;
    }
    else if(V1<2.8){  
      btn0state = 1;  
    }
    else if (V1<2.95){  
      btn6state = 1;
    }

  }
  else if(0.8>V2){
    if(V2<0.85){  
      btn10state = 1;
    }
    else if(V2<1.5){  
      btn9state = 1;
    }
    else if (V2<1.9){ 
      btn11state = 1;
    }
    else if(V2<2.3){ 
      btn8state = 1;
    }
    else if (V2<2.5){ 
      btn12state = 1;
    }
    else if(V2<2.8){  
      btn7state = 1;
    }
    else if (V2<2.95){  
      btn13state = 1;
    }
  }
  else if(0.8>V3){
    if(V3<0.85){  
      btn17state = 1;
    }
    else if(V3<1.5){  
      btn16state = 1;
    }
    else if (V3<1.9){ 
      btn18state = 1;
    }
    else if(V3<2.3){  
      btn15state = 1;
    }
    else if (V3<2.5){ 
      btn19state = 1;
    }
    else if(V3<2.8){ 
      btn14state = 1;
    }
  }

  btnController(btn0state, btn0prev_state, btn0pitch);
  btnController(btn1state, btn1prev_state, btn1pitch);
  btnController(btn2state, btn2prev_state, btn2pitch);
  btnController(btn3state, btn3prev_state, btn3pitch);
  btnController(btn4state, btn4prev_state, btn4pitch);
  btnController(btn5state, btn5prev_state, btn5pitch);
  btnController(btn6state, btn6prev_state, btn6pitch);
  btnController(btn7state, btn7prev_state, btn7pitch);
  btnController(btn8state, btn8prev_state, btn8pitch);
  btnController(btn9state, btn9prev_state, btn9pitch);
  btnController(btn10state, btn10prev_state, btn10pitch);
  btnController(btn11state, btn11prev_state, btn11pitch);
  btnController(btn12state, btn12prev_state, btn12pitch);
  btnController(btn13state, btn13prev_state, btn13pitch);
  btnController(btn14state, btn14prev_state, btn14pitch);
  btnController(btn15state, btn15prev_state, btn15pitch);
  btnController(btn16state, btn16prev_state, btn16pitch);
  btnController(btn17state, btn17prev_state, btn17pitch);
  btnController(btn18state, btn18prev_state, btn18pitch);
  btnController(btn19state, btn19prev_state, btn19pitch); 

  delay(10);

  btn0prev_state = btn0state;
  btn1prev_state = btn1state;
  btn2prev_state = btn2state;
  btn3prev_state = btn3state;
  btn4prev_state = btn4state;
  btn5prev_state = btn5state;
  btn6prev_state = btn6state;
  btn7prev_state = btn7state;
  btn8prev_state = btn8state;
  btn9prev_state = btn9state;
  btn10prev_state = btn10state;
  btn11prev_state = btn11state;
  btn12prev_state = btn12state;
  btn13prev_state = btn13state;
  btn14prev_state = btn14state;
  btn15prev_state = btn15state;
  btn16prev_state = btn16state;
  btn17prev_state = btn17state;
  btn18prev_state = btn18state;
  btn19prev_state = btn19state;
}


void btnController(char state, char prev_state, int pitch) {
  if (state != prev_state) {
    if (state == HIGH) {
      if (octave == HIGH) {
        pitch = pitch + 12;
      }
      Serial.print(">>> TEST: sending note on: ");
      Serial.println(pitch);
      
      noteOn(ch, pitch, sp);
      MidiUSB.flush();

      if(vibrato == HIGH){
        if(vibrato_freq <=10){
          vibrato_freq=+5;
        }
        else if(vibrato_freq >= -10){
          vibrato_freq=-5;
        }
        tone(5, (440*2^((pitch-69)/12)) + vibrato_freq);
      }
      else{
        tone(5, (440*2^((pitch-69)/12)));
      }
    } 
    else {
      if(octave == HIGH) {
        pitch = pitch + 12;
      }
      Serial.print(">>> TEST: sending note off: ");
      Serial.println(pitch);
      noTone(5);
      noteOff(ch, pitch, sp);
      MidiUSB.flush();
    }
  }
}
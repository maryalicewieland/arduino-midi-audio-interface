//Force sensors by finger to Analog Pins.
const int THUMB = A1;
const int POINTER = A2;
const int MIDDLE = A3;
const int RING = A4;
const int PINKY = A5;


//MIDI notes, correspond to second octave C.
const int THUMB_MIDI   = 36; //C2
const int POINTER_MIDI = 38; //D2
const int MIDDLE_MIDI  = 40; //E2
const int RING_MIDI    = 41; //F2
const int PINKY_MIDI   = 43; //G2


const int startValue = 5; // Pressure threshhold.
const int VELOCITY = 30; // Hard-coded for now.


bool thumbOn = false;
bool pointerOn = false;
bool middleOn = false;
bool ringOn = false;
bool pinkyOn = false;


void setup() {
 Serial.begin(115200);
 delay(1000);
}


void loop() {
 int readThumb = analogRead(THUMB);
 int readPointer = analogRead(POINTER);
 int readMiddle = analogRead(MIDDLE);
 int readRing = analogRead(RING);
 int readPinky = analogRead(PINKY);


 // Serial.println(readThumb);
 // Serial.println(readPointer);
 // Serial.println(readMiddle);
 // Serial.println(readRing);
 // Serial.println(readPinky);


 // THUMB
 if (!thumbOn && readThumb > startValue) {
   noteOn(THUMB_MIDI, VELOCITY);
   thumbOn = true;
 } else if (thumbOn && readThumb < startValue) {
   noteOff(THUMB_MIDI);
   thumbOn = false;
 }


 // POINTER
 if (!pointerOn && readPointer > startValue) {
   noteOn(POINTER_MIDI, VELOCITY);
   pointerOn = true;
 } else if (pointerOn && readPointer < startValue) {
   noteOff(POINTER_MIDI);
   pointerOn = false;
 }


 // MIDDLE
 if (!middleOn && readMiddle > startValue) {
   noteOn(MIDDLE_MIDI, VELOCITY);
   middleOn = true;
 } else if (middleOn && readMiddle < startValue) {
   noteOff(MIDDLE_MIDI);
   middleOn = false;
 }


 // RING
 if (!ringOn && readRing > startValue) {
   noteOn(RING_MIDI, VELOCITY);
   ringOn = true;
 } else if (ringOn && readRing < startValue) {
   noteOff(RING_MIDI);
   ringOn = false;
 }


 // PINKY
 if (!pinkyOn && readPinky > startValue) {
   noteOn(PINKY_MIDI, VELOCITY);
   pinkyOn = true;
 } else if (pinkyOn && readPinky < startValue) {
   noteOff(PINKY_MIDI);
   pinkyOn = false;
 }


 delay(5);
}


// NOTE ON AND OFF
void noteOn(byte note, byte vel) {
 Serial.write(0x90); 
 Serial.write(note);
 Serial.write(vel);
}


void noteOff(byte note) {
 Serial.write(0x80); 
 Serial.write(note);
 Serial.write((byte)0);
}

#include <IRremote.h> // you can download this library directly in arduino program

const int RECV_PIN = 7; //connect your receiver ir to 7 pin in arduino
IRrecv irrecv(RECV_PIN);
decode_results results;
unsigned long key_value = 0;

int redled = 2;
int ledgreen = 3;
int ledblue = 4;


void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
  
  for(int i=2;i<5;i++){
    pinMode(i,OUTPUT);
  }

}

void loop() {
  
  if (irrecv.decode(&results)){
        
        
        if (results.value == 0XFFFFFFFF) //if you press contunualy one touch you will have 0XFFFFFFFF to delete iti use this condition
          results.value = key_value;
          Serial.println(results.value, HEX); // when i press command i have  FFA25D this but to use it wit arduino you will add 0x to it like this 0xFFA25D
          
        if(results.value == 0xFFA25D){
            ledred();
        }

        else if(results.value == 0xFF629D){ //command value to turn up green led
          greenled();
        }
        else if(results.value == 0xFFE21D){
          blueled();
        }
        else {
          down();
        }
        
        key_value = results.value;
        irrecv.resume();
        
  }


}


// my led function but you can use another function or cod here
void ledred(){
digitalWrite (redled,1);
digitalWrite(ledgreen,0);
digitalWrite(ledblue,0);
}

void greenled(){
digitalWrite (redled,0);
digitalWrite(ledgreen,1);
digitalWrite(ledblue,0);
}

void blueled(){
digitalWrite (redled,0);
digitalWrite(ledgreen,0);
digitalWrite(ledblue,1);
}

void down(){
digitalWrite (redled,0);
digitalWrite(ledgreen,0);
digitalWrite(ledblue,0);
}

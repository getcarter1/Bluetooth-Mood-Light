/*
Modified from Involt example sketch
http://involt.github.io/

Connect Bluetooth RX,TX to Arduino TX,RX

Requires NeoPixel Library
https://github.com/adafruit/Adafruit_NeoPixel
Included in libraries directory.


If you want to view the serial data via a Serial Monitor and have your Arduino connect to a BT module 
simultaneously, use Software Serial to setup a second serial port. Connect your Arduino via usb,which uses the hardware serial (pins 0 and 1 on UNO) and connect 
your Bluetooth module's TX and RX to the software serial pins you define in the sketch. Remeber to connect Bluetooth RX to Arduino TX and Bluetooth TX to Arduino RX. 

Read more here: https://www.arduino.cc/en/Reference/softwareSerial

This sketch compiles at 7540 bytes in Arduino IDE 1.8.1 (23% of memory on a Uno) 
309 bytes of Global variables (15% of dynamic memory on an Uno)
Lots of room for adding stuff.
*/

// Including....

//#include <SoftwareSerial.h>  Uncomment if you want to use a second software serial port.

//SoftwareSerial mySerial(3,4); // RX, TX  Use any 2 pins you like. Maybe stay away from 10,11 and 13 as they are used for SPI. Pin 6 is used for the data pin on the Neopixels    

#include <Adafruit_NeoPixel.h> // You will need the Neopixel library installed  


// Well now. I do declare !

Adafruit_NeoPixel strip = Adafruit_NeoPixel(8, 6, NEO_GRB + NEO_KHZ800);
int    involtPin[14] = {}; //equals involt.pin.P in app
String involtString[2] ={}; //equals involt.pin.S in app 

/*Buffer for received data. If you plan to receive more 
  at once just increase the array length. */

  char involt[16];

//String for responding to function received from app.
String fname;


//It's all a set up, Guv !

void setup() {
 //Connection speed must be same as app setting in settings.js
 Serial.begin(38400); //Default on most bluetooth modules is 9600. Check your documentation for your device for how to change baud rate.
 
 //Set up 2 extra pins to play with later.... add more if you want or comment them out if you don't think you'll want more stuff to control.
 pinMode(3,OUTPUT); //Make pin 3 an output
 pinMode(4,OUTPUT); //Make pin 4 an output
 
 
 int red,green,blue;  //sets up variables for the neopixel colours
strip.begin();
strip.show(); // Initialize all pixels to 'off'

}

// Looping ! endless looping that goes on and on and on.....

void loop() {
  involtReceive();  //This calls the Receive function defined below, after the loop.
  fname = ""; /*This clears the value of fname function that we might call later on. If we don't clear it
  it will keep triggering as the code loops.*/ 

digitalWrite(3, involtPin[3]); // writes the value of involtPin[3] to physical pin 3 on Arduino. Data payload will be 1 or 0 from app.
digitalWrite(4, involtPin[4]); // writes the value of involtPin[4] to physical pin 4 on Arduino. Data payload will be 1 or 0 from app.

  // if there's any serial available, read it:
  while (Serial.available() > 0) {
  
    // look for the next valid integer in the incoming serial stream: This data arrives in the form xxx,xxx,xxx from colour picker function in app.
    int red = Serial.parseInt(); // the first xxx in the comma separated stream from app

    // do it again:
    int green = Serial.parseInt(); // The second xxx in the stream
	
    // and again:
    int blue = Serial.parseInt(); //The third xxx in the stream

    // look for the newline. That's the end of your sentence. And this is the end of this sentence.
    //if (mySerial.read() == '\n') { //uncomment if you are using software serial 
    if (Serial.read() == '\n') {

      // sends confirmation. Roger that, Captain!
      //mySerial.println("received:"+String(red)+","+String(green)+","+String(blue)); //uncomment if you are using software serial

      /*Now we constrain the values for red, green and blue to between 0 and 255. 
      This is to make sure we don't try to process garbage data that is out of range 
      which would end badly with people screaming and the fires and gnashing teeth and the WAAAAILING. glaven. mmm Hey. Hey. */

      red = constrain(red, 0, 255);

      green = constrain(green, 0, 255);

      blue = constrain(blue, 0, 255);

      // fill strip
      colorSet(strip.Color(red, green, blue), 0);  /* Does what it says. Sets the neopixel strip RGB values 
      to the values we got from the serial stream. Not to be confused with "Phils trip" which is a complete other story... */

      // send some data back ! Just so you know it arrived home safely and is now tucked into bed...
      Serial.println("received:"+String(red)+","+String(green)+","+String(blue));

     

   }

}

}

/* That there, was the end of the loop routine. ....so to speak. The actual routine just keeps on looping.
Now we need to define some functions.
Unless you are playing about with other stuff, the only function we need to call for the neopixels is the very last one.
The others are the example Involt functions.*/

// First, the receive function we called earlier...

void involtReceive(){
  if(Serial.available()>0) {   //Look for serial data and read it.
    Serial.readBytesUntil('\n',involt,sizeof(involt)); //the value of "involt" will be whatever data is up untill a newline marker is sent
    int pin;    
	/*Involt doco says P is used to designate "PIN" data. 
	I think what they are getting at is that, as an example, "P3,x" is what would get sent to the serial port from the app 
	and is translated into involtPin[3] here.  Much less data to send over serial. */
    if (involt[0] == 'P'){   
      int value;
      sscanf(involt, "P%dV%d", &pin, &value);
      involtPin[pin] = value;
    }
	/* S is designated STRING. EG: You can send a string of text and create a function that sends a value to a pin if the string matches like this:
	if (involtString[0] == "password"){   //is the value of the sent string S0 is the word "password" ?
	analogWrite(5, 255);    //if it is, set pin 5 to the value of 255
	}
*/	
    else if (involt[0] == 'S'){ 
      char value[sizeof(involt)];
      sscanf(involt, "S%dV%s", &pin, &value);
      involtString[pin] = value;
    }
	/* F. F is for Function.... You can create your own function and you can trigger that 
	function by sending F[value]from the app where value is the name of your arduino function you are calling.*/
	
    else if (involt[0] == 'F'){ //if the first part of the 
      char value[sizeof(involt)];
      sscanf(involt, "F%s", &value);
      fname = value;
    };
    memset(involt,0,sizeof(involt));
  };
};
/* This will send A0,V255,E if the pin number is set to 0 with a value of 255*/
void involtSend(int pinNumber, int sendValue){
  Serial.print('A'); 
  Serial.print(pinNumber); 
  Serial.print('V'); 
  Serial.print(sendValue); 
  Serial.println('E');
  Serial.flush();
};
/* This will send A0 FRUITY  if the pin number is set to 0 and the string value is "FRUITY" */
void involtSendString(int pinNumber, String sendString){
  Serial.print('A'); 
  Serial.print(pinNumber); 
  Serial.print('V'); 
  Serial.print(sendString); 
  Serial.println('E'); 
  Serial.flush();

};
//This will send F func if the function name is set to func and you have already declared a function with that name.
void involtSendFunction(String functionName){
  Serial.print('F'); 
  Serial.print(functionName); 
  Serial.println('E'); 
  Serial.flush();
};


/* Fill strip with a color.  Does what it says. The last step in the whole thing is the bit we set out to achieve. Make LEDS go the colour I picked !
This is straight out of the Neopixel demo code. */

void colorSet(uint32_t c, uint8_t wait) {

  for(uint16_t i=0; i<strip.numPixels(); i++) {  /*a little loop of it's own. i is incremented until it reaches the number of pixels we have.
If you get creative, you could remove the increment loop and modify the value of i in the app somewhere to select an individual LED */  

      strip.setPixelColor(i, c); //set pixel number [i] to colour [c] obtained from colorset value that, in turn is set from our RED GREEN BLUE data.

  }

   strip.show(); //turn it on !

   delay(wait); //Wait for it !

}



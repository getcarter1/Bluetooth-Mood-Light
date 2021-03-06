
# Bluetooth Mood-Light
Arduino bluetooth +WS2182 LEDs + phonegap app

Android App to change colour of WS2182 adressable LEDs connected to an Arduino.

App can be built using Adobe PhoneGap Build  HTTP://build.phonegap.com

BLE is troublesome. Operational with Bluetooth 2.1


INSTALLATION

1. Download this repo.

2. From the downloaded Arduino\Mood_light\libraries directory, copy the Neopixel directory into your Arduino library directory.

3. Open the Mood_Light sketch and modify the serial baudrate, Serial.begin(57600) Change this to match your Bluetooth modules baud. Modify the line containing " Adafruit_NeoPixel(8, 6, NEO_GRB + NEO_KHZ800) ". 8 is the number of leds I am using and 6 is the Arduino pin I am connecting the led data pin to. Change the values to suit your setup. Save the sketch !!

4. Make sure you do not have the bluetooth module connected to your Arduino yet. Anything hanging off the TX and RX pins will interfere with the sketch upload.

5. Upload the sketch to your Arduino. Power off your Arduino and connect your bluetooth module's TX to Arduino's RX and Bluetooth RX to 
Arduino TX. Connect the power to your WS2182 LED strip and connect the LEDs data connection to digital pin 6 (or whatever you chose in step 3 above) on your Arduino

6. In the Phonegap_Android\www directory, edit settings.js and change the MAC address in the line starting with  var defaultBtAddress = 
and the UUID in the line starting with var uuid =   to match your own device details.

7. Create a zip file from the contents of the Phonegap_Android directory, create a free account on Phonegap Build http://build.phonegap.com follow their instructions and upload the zip file you created.

8. Copy the .apk file to your Android device

9. Power up your Arduino and check that you can see it from your Android device in bluetooth scan results. LED's should be off.

10. Pair your Android device to the Bluetooth module.

11. Start the app you built in Phonegap and select your bluetooth module from the list of discovered devices and click "connect"

12. The app should now show a colour picker.

13. Click or touch the colour picker on a colour of your choice and bask in the glory of blinding, colourful, LED light !

14. Modify the app.html file and create something better looking. Re-zip and re-submit to phonegap build to build your updated app.


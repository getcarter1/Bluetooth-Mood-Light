/*
		INVOLT CONNECTION SETTINGS
		Ernest Warzocha 2016
		involt.github.io
*/

//----------------------------------------------------------------------------------------------

	/*
		CONNECTION TYPE
		Select connection type, only ONE can be defined at once.
	*/
	var isSerial    = false; //Desktop
	var isBluetooth = true; //Desktop AND Mobile (BT 2.0)
	/*
		LOADING SCREEN
		Set loaderOnLaunch to false and skip loading screen on app launch. 
		Remember to set default connection settings because it's not possible when app is running.
	*/
	var loaderOnLaunch = true;
	/*
		DEFAULT SERIAL PORT
		Choose default serial port to set the connection port when loader is not used.

		PERSISTENT SERIAL CONNECTION
		Use isPersistent to hold the connection after app shutdown. The session is returned when
		relaunching. It's set to false by default because it blocks Arduino sketch upload process.
		Changes from chrome apps to node-webkit made this currently not working (?).
	*/
	var defaultSerialPort = "COM7";
	var isPersistent = false;
	/*
		BLUETOOTH DEFAULT ADDRESS
		Bluetooth default address. Use when loader is not used.

		BLUETOOTH DISCOVERY DURATION
		In some cases it will take more time for some devices to find them.
	*/
	 var defaultBtAddress = "30:14:12:03:16:79";  //firefox   Change to the MAC address of your module 
	//var defaultBtAddress = "74:DA:EA:AF:A7:CE";  //hmSoft     Second one because I have 2 bluetooth modules and uncommenting one is faster :p
	var discoveryDuration = 3000;
	/*
		CONNECTION UUID (Serial Port Profile)
	*/
	 var uuid = "00001101-0000-1000-8000-00805f9b34fb"; //FIREFOX  HC-05 Bluetooth 2.1
	//var uuid = "0000ffe0-0000-1000-8000-00805f9b34fb";    //HMSoft HM10 BLE. work in progress. BLE is not yet functional.
	/*
		BITRATE
		The bitrate should remain unchanged. 
		If you have to lower the speed, don't overload the port from arduino. READ: buffer overflow.
		Bitrate in software and hardware must be the same.
		115200 is a probably a bad option if you are using a 16Mhz MCU such as the Atmega328P on an Arduino Uno.
		We have to fit our baud rate into the clock cycles of the MCU. 
		115200 baud has 2.1% error rate on a 16MHz MCU
		230400 is outside of scope at 8.5% error
		The baud rates with best fit to a clock speed of 16MHz is either 38400 or 76800 both of which have an reror rate of 0.2%
		Here is a site with some nice tables of baud rate errors  http://wormfood.net/avrbaudcalc.php
	*/
	var bitrate = 38400;   //This needs to match both the Arduino sketch and your Bluetooth modules baud settings.
	/*
		RECEIVED VALUES UI UPDATE RATE
		Set update rate of read-only elements in miliseconds. 
		Lower value improves response of UI elements but increases CPU usage.
	*/
	var updateRate = 50;
	/*
		DEBUG MODE
		Debug mode logs more information to console.
	*/
	var debugMode = false;

//----------------------------------------------------------------------------------------------
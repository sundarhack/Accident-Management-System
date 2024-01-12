#include <SoftwareSerial.h>
#include <TinyGPS++.h>

// set up the GSM module serial communication
SoftwareSerial gsmSerial(2, 3); // RX, TX

// set up the GPS module serial communication
SoftwareSerial gpsSerial(4, 5); // RX, TX

// set up the GPS module
TinyGPSPlus gps;

// set the maximum vibration value (adjust this as needed)
const int maxVibration = 500;

void setup() {
  Serial.begin(9600);
  gsmSerial.begin(9600);
  gpsSerial.begin(9600);
  
  // wait for the SIM800L module to start up
  delay(2000);
  gsmSerial.println("AT");
  delay(1000);
  gsmSerial.println("AT+CMGF=1"); // set the SMS mode to text
  delay(1000);
  gsmSerial.println("AT+CNMI=1,2,0,0,0"); // set the SMS notification mode
  delay(1000);
  
  
}

void loop() {
  // read the GPS data
  while (gpsSerial.available() > 0) {
    if (gps.encode(gpsSerial.read())) {
      if (gps.location.isValid()) {
        float latitude = gps.location.lat();
        float longitude = gps.location.lng();
        
        // read the vibration sensor value
        int vibrationValue = analogRead(A0);
        
        
        // check if the vibration value exceeds the maximum value
        if (vibrationValue > maxVibration) {
          
          
          // send a request to the API to get the phone number
          String response = sendAPIRequest(latitude, longitude);
          
          // extract the phone number from the API response
          int phoneNumberStartIndex = response.indexOf("\"phone\":") + 8;
          int phoneNumberEndIndex = response.indexOf("\",", phoneNumberStartIndex);
          String phoneNumber = response.substring(phoneNumberStartIndex, phoneNumberEndIndex);
          
         
          
          // construct the SMS message with the coordinates and Google Maps link
         String message = "Accident occurred at: https://ift.tt/" + String(latitude, 6) + "," + String(longitude, 6);

          
          // send the SMS message using AT commands
          gsmSerial.print("AT+CMGS=\""); // set the recipient phone number
          gsmSerial.print(phoneNumber);
          gsmSerial.println("\"");
          delay(1000);
          gsmSerial.print(message); // send the message
          gsmSerial.write(26); // terminate the message with CTRL+Z
          delay(1000);
          
         
        }
      }
    }
  }
  
  delay(500);
}

String sendAPIRequest(float latitude, float longitude) {
  // set up the WiFi module serial communication
  SoftwareSerial wifiSerial(6, 7); // RX, TX
  
 // String apiKey = "YOUR_API_KEY"; 
  String endpoint = "https://fec-project.onrender.com/main/v1/loc"; 
  // construct the API request URL with the latitude and longitude
String url = endpoint + "?lat=" + String(latitude, 6) + "&lng=" + String(longitude, 6) ;



// connect to the WiFi network
String ssid = "WifiFTW"; 
String password = "sanjithsanjith"; 
wifiSerial.begin(9600);
delay(1000);

// connect to the WiFi network
wifiSerial.println("AT+CWJAP="" + ssid + "","" + password + """);
delay(5000);

// send the API request
wifiSerial.println("AT+CIPSTART=\"TCP\",\"216.24.57.253\",80");
delay(1000);
wifiSerial.println("AT+CIPSEND");
delay(1000);
wifiSerial.println("GET " + url + " HTTP/1.1\r\nHost:https://fec-project.onrender.com/main/v1/loc\r\n\r\n");
delay(5000);

// read the API response
String response = "";
while (wifiSerial.available() > 0) {
char c = wifiSerial.read();
response += c;
}

// disconnect from the WiFi network
wifiSerial.println("AT+CWQAP");
delay(1000);

return response;
}

#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>
#include <ArduinoJson.h>
SoftwareSerial s(D5,D6);


 
String apiKey = "LQWLUH8QQQG191AC";     //  Enter your Write API key from ThingSpeak

const char *ssid =  "Your Wifi Name";     // replace with your wifi ssid and wpa2 key
const char *pass =  "Your wifi password";
const char* server = "api.thingspeak.com";



WiFiClient client;
 
void setup() 
{
       
       Serial.begin(115200);
       delay(10);
  //     dht.begin();
 
       Serial.println("Connecting to ");
       Serial.println(ssid);
 
 
       WiFi.begin(ssid, pass);
 
      while (WiFi.status() != WL_CONNECTED) 
     {
            delay(500);
            Serial.print(".");
     }
      Serial.println("");
      Serial.println("WiFi connected");

      s.begin(115200);
 
}
 
void loop() 
{

      StaticJsonBuffer<1000> jsonBuffer;
      JsonObject& root = jsonBuffer.parseObject(s);
      if (root == JsonObject::invalid())
      {
        return;
      }

      Serial.println("JSON received and parsed");
  root.prettyPrintTo(Serial);
  Serial.println("");
  Serial.print("First Road First Sensor");
  int data1=root["in1"];
  Serial.println(data1);
  Serial.print("First Road Sencond Sensor");
  int data2=root["in2"];
  Serial.println(data2);
  Serial.print("Second Road First Sensor");
  int data3=root["in3"];
  Serial.println(data3);
  Serial.print("Second Road Second Sensor");
  int data4=root["in4"];
  Serial.println(data4);
  Serial.print("Third Road First Sensor");
  int data5 = root["in5"];
  Serial.println(data5);
  Serial.print("Third Road Second Sensor");
  int data6 = root["in6"];
  Serial.println(data6);
  
  Serial.println("");
  Serial.println("---------------------xxxxx--------------------");
 Serial.println("");
            

        if (client.connect(server,80))   //   "184.106.153.149" or api.thingspeak.com
        {  
                            
              String postStr = apiKey;
              postStr +="&field1=";
              postStr += String(data1);
              postStr +="&field2=";
              postStr += String(data2);
              postStr +="&field3=";
              postStr += String(data3);
              postStr +="&field4=";
              postStr += String(data4);
              postStr +="&field5=";
              postStr += String(data5);
              postStr +="&field6=";
              postStr += String(data6);
              postStr += "\r\n\r\n";
 
              client.print("POST /update HTTP/1.1\n");
              client.print("Host: api.thingspeak.com\n");
              client.print("Connection: close\n");
              client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
              client.print("Content-Type: application/x-www-form-urlencoded\n");
              client.print("Content-Length: ");
              client.print(postStr.length());
              client.print("\n\n");
              client.print(postStr);
 

              Serial.println("%. Send to Thingspeak.");
                        }
          client.stop();
 
          Serial.println("Waiting...");
  
  // thingspeak needs minimum 15 sec delay between updates, i've set it to 30 seconds
  delay(10000);
}

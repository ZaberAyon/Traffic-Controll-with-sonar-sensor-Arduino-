#include <ArduinoJson.h>

const int pingPin1 = 2; // Trigger Pin of Ultrasonic Sensor
const int echoPin1 = 3;
// Echo Pin of Ultrasonic Sensor
const int pingPin2 = 4; // Trigger Pin of Ultrasonic Sensor
const int echoPin2 = 5;

const int pingPin3 = 6; // Trigger Pin of Ultrasonic Sensor
const int echoPin3 = 7;

const int pingPin4 = 8; // Trigger Pin of Ultrasonic Sensor
const int echoPin4 = 9;

const int pingPin5 = 10; // Trigger Pin of Ultrasonic Sensor
const int echoPin5 = 11;

const int pingPin6 = 12; // Trigger Pin of Ultrasonic Sensor
const int echoPin6 = 13;


const int led1 = 31; // green1
const int led2 = 33; //yellow1
const int led3 = 35; //red1

const int led4 = 37; //green2
const int led5 = 39; //yellow2
const int led6 = 41; //red2

const int led7 = 43; //green3
const int led8 = 45; //yellow3
const int led9 = 47; //red3

int stat = 0;
int count1=0;
int count2 =0;
int count3 =0;

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}

void setup() {
   Serial.begin(9600); // Starting Serial Terminal
   Serial1.begin(115200);

   pinMode(pingPin1, OUTPUT);
   pinMode(pingPin2, OUTPUT);
   pinMode(pingPin3, OUTPUT);
   pinMode(pingPin4, OUTPUT);
   pinMode(pingPin5, OUTPUT);
   pinMode(pingPin6, OUTPUT);

   pinMode(echoPin1, INPUT);
   pinMode(echoPin2, INPUT);
   pinMode(echoPin3, INPUT);
   pinMode(echoPin4, INPUT);
   pinMode(echoPin5, INPUT);
   pinMode(echoPin6, INPUT);


   pinMode(led1, OUTPUT);
   pinMode(led2, OUTPUT);
   pinMode(led3, OUTPUT);
   pinMode(led4,OUTPUT);
   pinMode(led5,OUTPUT);
   pinMode(led6, OUTPUT);
   pinMode(led7,OUTPUT);
   pinMode(led8,OUTPUT);
   pinMode(led9, OUTPUT);

   
}

StaticJsonBuffer<1000> jsonBuffer;
JsonObject& root = jsonBuffer.createObject();

void loop() {
   long duration1, inche1, cm1;
   long duration2, inche2, cm2;
   long duration3, inche3, cm3;
   long duration4, inche4, cm4;
   long duration5, inche5, cm5;
   long duration6, inche6, cm6;

   float inches1,inches2,inches3,inches4,inches5,inches6;


   digitalWrite(led1,LOW);
   digitalWrite(led2,LOW);
   digitalWrite(led3,LOW);
   digitalWrite(led4,LOW);
   digitalWrite(led5,LOW);
   digitalWrite(led6,LOW);
   digitalWrite(led7,LOW);
   digitalWrite(led8,LOW);
   digitalWrite(led9,LOW);
   
   digitalWrite(pingPin1, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin1, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin1, LOW);
   duration1 = pulseIn(echoPin1, HIGH);
   inche1 = microsecondsToInches(duration1);
   inches1 = (float)inche1;
   
   digitalWrite(pingPin2, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin2, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin2, LOW);
   duration2 = pulseIn(echoPin2, HIGH);
   inche2 = microsecondsToInches(duration2);
   inches2 = (float)inche2;
   
   digitalWrite(pingPin3, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin3, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin3, LOW);
   duration3 = pulseIn(echoPin3, HIGH);
   inche3 = microsecondsToInches(duration3);
   inches3 = (float)inche3;
   
   digitalWrite(pingPin4, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin4, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin4, LOW);
   duration4 = pulseIn(echoPin4, HIGH);
   inche4 = microsecondsToInches(duration4);
   inches4 = (float)inche4;
   
   digitalWrite(pingPin5, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin5, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin5, LOW);
   duration5 = pulseIn(echoPin5, HIGH);
   inche5 = microsecondsToInches(duration5);
   inches5 = (float)inche5;
   
   digitalWrite(pingPin6, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin6, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin6, LOW);
   duration6 = pulseIn(echoPin6, HIGH);
   inche6 = microsecondsToInches(duration6);
   inches6 = (float)inche6;
  
   
   
   //cm1 = microsecondsToCentimeters(duration1);
   Serial.print(inches1);
   Serial.print("in1, ");
   Serial.print(inches2);
   Serial.print("in2, ");
   Serial.print(inches3);
   Serial.print("in3, ");
   Serial.print(inches4);
   Serial.print("in4, ");
   Serial.print(inches5);
   Serial.print("in5, ");
   Serial.print(inches6);
   Serial.print("in6, "); 
   //Serial.print(cm1);
   //Serial.print("cm1");

   //1,4,7 green, 2,5,8 yellow, 3,6,9 red
   
   Serial.println();

    if(isnan(inches1)||isnan(inches2)||isnan(inches3)||isnan(inches4)||isnan(inches5)||isnan(inches6))
  {
    return;
  }

  root["in1"] = inches1;
  root["in2"] = inches2;
  root["in3"] = inches3;
  root["in4"] = inches4;
  root["in5"] = inches5;
  root["in6"] = inches6;

  if(Serial1.available()>0)
  {
    root.printTo(Serial1);
  }
    



   

  //tripple condition
if((inches1>0 && inches1<7)&&(inches2>0 && inches2<7)&&(inches3>0 && inches3<7)&&(inches4>0 && inches4<7)&&(inches5>0 && inches5<7)&&(inches6>0 && inches6<7))
 {
  digitalWrite(led1,1); //enables the 1st set of signals
  digitalWrite(led6,1);
  digitalWrite(led9,1);
  digitalWrite(led3,0);
  digitalWrite(led2,0);  
  digitalWrite(led5,0);
  digitalWrite(led7,0);
  digitalWrite(led8,0);
  digitalWrite(led4,0);
  delay(3000);
 
  digitalWrite(led2,1); //enables the yellow lights
  digitalWrite(led5,1);
  digitalWrite(led1,0); 
  digitalWrite(led6,0);
  delay(500);
 
  digitalWrite(led3,1); //enables the 2nd set of signals
  digitalWrite(led4,1);
  digitalWrite(led9,1);
  digitalWrite(led1,0);
  digitalWrite(led2,0);  
  digitalWrite(led5,0);
  digitalWrite(led7,0);
  digitalWrite(led8,0);
  digitalWrite(led6,0);
  delay(3000);
 
  digitalWrite(led8,1); //enables the yellow lights
  digitalWrite(led5,1);
  digitalWrite(led9,0);
  digitalWrite(led4,0);  
  digitalWrite(led3,0);
  delay(500); 
   
  digitalWrite(led7,1); //enables the 3rd set of signals
  digitalWrite(led3,1);
  digitalWrite(led6,1);
  digitalWrite(led1,0);
  digitalWrite(led2,0);  
  digitalWrite(led4,0);
  digitalWrite(led5,0);
  digitalWrite(led8,0);
  digitalWrite(led9,0);
  delay(3000);
 
  digitalWrite(led8,1); //enables the yellow lights
  digitalWrite(led2,1); 
  digitalWrite(led6,0);
  digitalWrite(led7,0); 
  digitalWrite(led3,0);
  delay(500);   
}


   
   
   //double conditions
 
 else if((inches1>0 && inches1<7)&&(inches2>0 && inches2<7)&&(inches5>0 && inches5<7)&&(inches6>0 && inches6<7)) //for ultrasonic 1,2 and 5,6
  {
  digitalWrite(led1,1); //enables the 1st set of signals
  digitalWrite(led6,1);
  digitalWrite(led9,1);
  digitalWrite(led3,0);
  digitalWrite(led2,0);  
  digitalWrite(led5,0);
  digitalWrite(led7,0);
  digitalWrite(led8,0);
  digitalWrite(led4,0);
  delay(4000);
 
  digitalWrite(led2,1); //enables the yellow lights
  digitalWrite(led5,1);
  digitalWrite(led1,0); 
  digitalWrite(led6,0);
  delay(500);
  
  digitalWrite(led7,1); //enables the 3rd set of signals
  digitalWrite(led3,1);
  digitalWrite(led6,1);
  digitalWrite(led1,0);
  digitalWrite(led2,0);  
  digitalWrite(led4,0);
  digitalWrite(led5,0);
  digitalWrite(led8,0);
  digitalWrite(led9,0);
  delay(4000);
 
  digitalWrite(led8,1); //enables the yellow lights
  digitalWrite(led2,1); 
  digitalWrite(led6,0);
  digitalWrite(led7,0); 
  digitalWrite(led3,0);
  delay(500);   
  
 
  digitalWrite(led3,1); //enables the 2nd set of signals
  digitalWrite(led4,1);
  digitalWrite(led9,1);
  digitalWrite(led1,0);
  digitalWrite(led2,0);  
  digitalWrite(led5,0);
  digitalWrite(led7,0);
  digitalWrite(led8,0);
  digitalWrite(led6,0);
  delay(1000);
 
  digitalWrite(led8,1); //enables the yellow lights
  digitalWrite(led5,1);
  digitalWrite(led9,0);
  digitalWrite(led4,0);  
  digitalWrite(led3,0);
  delay(500); 
   
  }   
else if((inches1>0 && inches1<7)&&(inches2>0 && inches2<7)&&(inches3>0 && inches3<7)&&(inches4>0 && inches4<7))  //for ultrasonic 1,2 and 3,4
  {
  digitalWrite(led1,1); //enables the 1st set of signals
  digitalWrite(led6,1);
  digitalWrite(led9,1);
  digitalWrite(led3,0);
  digitalWrite(led2,0);  
  digitalWrite(led5,0);
  digitalWrite(led7,0);
  digitalWrite(led8,0);
  digitalWrite(led4,0);
  delay(4000);
 
  digitalWrite(led2,1); //enables the yellow lights
  digitalWrite(led5,1);
  digitalWrite(led1,0); 
  digitalWrite(led6,0);
  delay(500);
  
  digitalWrite(led3,1); //enables the 2nd set of signals
  digitalWrite(led4,1);
  digitalWrite(led9,1);
  digitalWrite(led1,0);
  digitalWrite(led2,0);  
  digitalWrite(led5,0);
  digitalWrite(led7,0);
  digitalWrite(led8,0);
  digitalWrite(led6,0);
  delay(4000);
 
  digitalWrite(led8,1); //enables the yellow lights
  digitalWrite(led5,1);
  digitalWrite(led9,0);
  digitalWrite(led4,0);  
  digitalWrite(led3,0);
  delay(500); 
  
  digitalWrite(led7,1); //enables the 3rd set of signals
  digitalWrite(led3,1);
  digitalWrite(led6,1);
  digitalWrite(led1,0);
  digitalWrite(led2,0);  
  digitalWrite(led4,0);
  digitalWrite(led5,0);
  digitalWrite(led8,0);
  digitalWrite(led9,0);
  delay(1000);
 
  digitalWrite(led8,1); //enables the yellow lights
  digitalWrite(led2,1); 
  digitalWrite(led6,0);
  digitalWrite(led7,0); 
  digitalWrite(led3,0);
  delay(500);   
   
  }   
else if((inches3>0 && inches3<7)&&(inches4>0 && inches4<7)&&(inches5>0 && inches5<7)&&(inches6>0 && inches6<7)) //for 3,4 and 5,6 ultrasonic
  {
  digitalWrite(led3,1); //enables the 2nd set of signals
  digitalWrite(led4,1);
  digitalWrite(led9,1);
  digitalWrite(led1,0);
  digitalWrite(led2,0);  
  digitalWrite(led5,0);
  digitalWrite(led7,0);
  digitalWrite(led8,0);
  digitalWrite(led6,0);
  delay(4000);
 
  digitalWrite(led8,1); //enables the yellow lights
  digitalWrite(led5,1);
  digitalWrite(led9,0);
  digitalWrite(led4,0);  
  digitalWrite(led3,0);
  delay(500); 
  
  digitalWrite(led7,1); //enables the 3rd set of signals
  digitalWrite(led3,1);
  digitalWrite(led6,1);
  digitalWrite(led1,0);
  digitalWrite(led2,0);  
  digitalWrite(led4,0);
  digitalWrite(led5,0);
  digitalWrite(led8,0);
  digitalWrite(led9,0);
  delay(4000);
 
  digitalWrite(led8,1); //enables the yellow lights
  digitalWrite(led2,1); 
  digitalWrite(led6,0);
  digitalWrite(led7,0); 
  digitalWrite(led3,0);
  delay(500);  
  digitalWrite(led1,1); //enables the 1st set of signals
  digitalWrite(led6,1);
  digitalWrite(led9,1);
  digitalWrite(led3,0);
  digitalWrite(led2,0);  
  digitalWrite(led5,0);
  digitalWrite(led7,0);
  digitalWrite(led8,0);
  digitalWrite(led4,0);
  delay(1000);
 
  digitalWrite(led2,1); //enables the yellow lights
  digitalWrite(led5,1);
  digitalWrite(led1,0); 
  digitalWrite(led6,0);
  delay(500); 
   
  }   

  
//single conditions
 else if((inches1>0 && inches1<7)&&(inches2>0 && inches2<7))
  {
  digitalWrite(led1,1); //enables the 1st set of signals
  digitalWrite(led6,1);
  digitalWrite(led9,1);
  digitalWrite(led3,0);
  digitalWrite(led2,0);  
  digitalWrite(led5,0);
  digitalWrite(led7,0);
  digitalWrite(led8,0);
  digitalWrite(led4,0);
  delay(3000);
 
  digitalWrite(led2,1); //enables the yellow lights
  digitalWrite(led5,1);
  digitalWrite(led1,0); 
  digitalWrite(led6,0);
  delay(500);
 
  digitalWrite(led3,1); //enables the 2nd set of signals
  digitalWrite(led4,1);
  digitalWrite(led9,1);
  digitalWrite(led1,0);
  digitalWrite(led2,0);  
  digitalWrite(led5,0);
  digitalWrite(led7,0);
  digitalWrite(led8,0);
  digitalWrite(led6,0);
  delay(1000);
 
  digitalWrite(led8,1); //enables the yellow lights
  digitalWrite(led5,1);
  digitalWrite(led9,0);
  digitalWrite(led4,0);  
  digitalWrite(led3,0);
  delay(500); 
   
  digitalWrite(led7,1); //enables the 3rd set of signals
  digitalWrite(led3,1);
  digitalWrite(led6,1);
  digitalWrite(led1,0);
  digitalWrite(led2,0);  
  digitalWrite(led4,0);
  digitalWrite(led5,0);
  digitalWrite(led8,0);
  digitalWrite(led9,0);
  delay(1000);
 
  digitalWrite(led8,1); //enables the yellow lights
  digitalWrite(led2,1); 
  digitalWrite(led6,0);
  digitalWrite(led7,0); 
  digitalWrite(led3,0);
  delay(500);  
  }
  
  else if((inches3>0 && inches3<7)&&(inches4>0 && inches4<7))
  {
   digitalWrite(led3,1); //enables the 2nd set of signals
  digitalWrite(led4,1);
  digitalWrite(led9,1);
  digitalWrite(led1,0);
  digitalWrite(led2,0);  
  digitalWrite(led5,0);
  digitalWrite(led7,0);
  digitalWrite(led8,0);
  digitalWrite(led6,0);
  delay(3000);
 
  digitalWrite(led8,1); //enables the yellow lights
  digitalWrite(led5,1);
  digitalWrite(led9,0);
  digitalWrite(led4,0);  
  digitalWrite(led3,0);
  delay(500); 
  
  digitalWrite(led7,1); //enables the 3rd set of signals
  digitalWrite(led3,1);
  digitalWrite(led6,1);
  digitalWrite(led1,0);
  digitalWrite(led2,0);  
  digitalWrite(led4,0);
  digitalWrite(led5,0);
  digitalWrite(led8,0);
  digitalWrite(led9,0);
  delay(1000);
 
  digitalWrite(led8,1); //enables the yellow lights
  digitalWrite(led2,1); 
  digitalWrite(led6,0);
  digitalWrite(led7,0); 
  digitalWrite(led3,0);
  delay(500);  
  
  digitalWrite(led1,1); //enables the 1st set of signals
  digitalWrite(led6,1);
  digitalWrite(led9,1);
  digitalWrite(led3,0);
  digitalWrite(led2,0);  
  digitalWrite(led5,0);
  digitalWrite(led7,0);
  digitalWrite(led8,0);
  digitalWrite(led4,0);
  delay(1000);
 
  digitalWrite(led2,1); //enables the yellow lights
  digitalWrite(led5,1);
  digitalWrite(led1,0); 
  digitalWrite(led6,0);
  delay(500);
  }

  else if((inches5>0 && inches5<7)&&(inches6>0 && inches6<7))
  {
  digitalWrite(led7,1); //enables the 3rd set of signals
  digitalWrite(led3,1);
  digitalWrite(led6,1);
  digitalWrite(led1,0);
  digitalWrite(led2,0);  
  digitalWrite(led4,0);
  digitalWrite(led5,0);
  digitalWrite(led8,0);
  digitalWrite(led9,0);
  delay(3000);
 
  digitalWrite(led8,1); //enables the yellow lights
  digitalWrite(led2,1); 
  digitalWrite(led6,0);
  digitalWrite(led7,0); 
  digitalWrite(led3,0);
  delay(500);  
  
  digitalWrite(led1,1); //enables the 1st set of signals
  digitalWrite(led6,1);
  digitalWrite(led9,1);
  digitalWrite(led3,0);
  digitalWrite(led2,0);  
  digitalWrite(led5,0);
  digitalWrite(led7,0);
  digitalWrite(led8,0);
  digitalWrite(led4,0);
  delay(1000);
 
  digitalWrite(led2,1); //enables the yellow lights
  digitalWrite(led5,1);
  digitalWrite(led1,0); 
  digitalWrite(led6,0);
  delay(500);
 
  digitalWrite(led3,1); //enables the 2nd set of signals
  digitalWrite(led4,1);
  digitalWrite(led9,1);
  digitalWrite(led1,0);
  digitalWrite(led2,0);  
  digitalWrite(led5,0);
  digitalWrite(led7,0);
  digitalWrite(led8,0);
  digitalWrite(led6,0);
  delay(1000);
 
  digitalWrite(led8,1); //enables the yellow lights
  digitalWrite(led5,1);
  digitalWrite(led9,0);
  digitalWrite(led4,0);  
  digitalWrite(led3,0);
  delay(500);  
  }
  
  else
  {
  digitalWrite(led1,1); //enables the 1st set of signals
  digitalWrite(led6,1);
  digitalWrite(led9,1);
  digitalWrite(led3,0);
  digitalWrite(led2,0);  
  digitalWrite(led5,0);
  digitalWrite(led7,0);
  digitalWrite(led8,0);
  digitalWrite(led4,0);
  delay(2000);
 
  digitalWrite(led2,1); //enables the yellow lights
  digitalWrite(led5,1);
  digitalWrite(led1,0); 
  digitalWrite(led6,0);
  delay(500);
 
  digitalWrite(led3,1); //enables the 2nd set of signals
  digitalWrite(led4,1);
  digitalWrite(led9,1);
  digitalWrite(led1,0);
  digitalWrite(led2,0);  
  digitalWrite(led5,0);
  digitalWrite(led7,0);
  digitalWrite(led8,0);
  digitalWrite(led6,0);
  delay(2000);
 
  digitalWrite(led8,1); //enables the yellow lights
  digitalWrite(led5,1);
  digitalWrite(led9,0);
  digitalWrite(led4,0);  
  digitalWrite(led3,0);
  delay(500); 
   
  digitalWrite(led7,1); //enables the 3rd set of signals
  digitalWrite(led3,1);
  digitalWrite(led6,1);
  digitalWrite(led1,0);
  digitalWrite(led2,0);  
  digitalWrite(led4,0);
  digitalWrite(led5,0);
  digitalWrite(led8,0);
  digitalWrite(led9,0);
  delay(2000);
 
  digitalWrite(led8,1); //enables the yellow lights
  digitalWrite(led2,1); 
  digitalWrite(led6,0);
  digitalWrite(led7,0); 
  digitalWrite(led3,0);
  delay(500);   
}

  delay(500);
}

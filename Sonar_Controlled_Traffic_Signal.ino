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


const int led1 = 32; // green1
const int led2 = 33; //yellow1
const int led3 = 34; //red1

const int led4 = 35; //green2
const int led5 = 36; //yellow2
const int led6 = 37; //red2

const int led7 = 38; //green3
const int led8 = 39; //yellow3
const int led9 = 40; //red3

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

void loop() {
   long duration1, inches1, cm1;
   long duration2, inches2, cm2;
   long duration3, inches3, cm3;
   long duration4, inches4, cm4;
   long duration5, inches5, cm5;
   long duration6, inches6, cm6;


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
   inches1 = microsecondsToInches(duration1);
   
   digitalWrite(pingPin2, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin2, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin2, LOW);
   duration2 = pulseIn(echoPin2, HIGH);
   inches2 = microsecondsToInches(duration2);
   
   digitalWrite(pingPin3, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin3, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin3, LOW);
   duration3 = pulseIn(echoPin3, HIGH);
   inches3 = microsecondsToInches(duration3);
   
   digitalWrite(pingPin4, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin4, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin4, LOW);
   duration4 = pulseIn(echoPin4, HIGH);
   inches4 = microsecondsToInches(duration4);
   
   digitalWrite(pingPin5, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin5, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin5, LOW);
   duration5 = pulseIn(echoPin5, HIGH);
   inches5 = microsecondsToInches(duration5);
   
   digitalWrite(pingPin6, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin6, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin6, LOW);
   duration6 = pulseIn(echoPin6, HIGH);
   inches6 = microsecondsToInches(duration6);
  
   
   
   
   
   
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

  if((inches1>0 && inches1<10)&&(inches2>0 && inches2<10))
  {
    stat =1;
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    digitalWrite(led5,HIGH);

    digitalWrite(led6,HIGH);
    //digitalWrite(led6,LOW);

    digitalWrite(led7,LOW);
    digitalWrite(led8,HIGH);
  
    digitalWrite(led9,HIGH);
    //digitalWrite(led9,LOW);
    
    
  }

  else if((inches3>0 && inches3<10)&&(inches4>0 && inches4<10))
  {
    stat =1;
    digitalWrite(led4,HIGH);
    digitalWrite(led5,LOW);
    digitalWrite(led6,LOW);
    digitalWrite(led1,LOW);
   
    digitalWrite(led3,HIGH);

    digitalWrite(led7,LOW);
    digitalWrite(led8,HIGH);
  
    digitalWrite(led9,HIGH);
    
    
  }

  else if((inches5>0 && inches5<10)&&(inches6>0 && inches6<10))
  {
    stat =1;
    digitalWrite(led7,HIGH);
    
    digitalWrite(led8,LOW);
    digitalWrite(led9,LOW);
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);

    digitalWrite(led3,HIGH);

    digitalWrite(led4,LOW);
    digitalWrite(led5,HIGH);

    digitalWrite(led6,HIGH);
    
    
  }
  else
  {
    digitalWrite(led1,HIGH);
   
    digitalWrite(led6,HIGH);
    
    
    digitalWrite(led9,HIGH);
    delay(200);

    digitalWrite(led1,LOW);
   
    digitalWrite(led6,LOW);
    
    
    digitalWrite(led9,LOW);

    
    digitalWrite(led4,HIGH);
    digitalWrite(led3,HIGH);
    digitalWrite(led9,HIGH);
    delay(200);
    digitalWrite(led4,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led9,LOW);
   
    digitalWrite(led7,HIGH);
    digitalWrite(led3,HIGH);
    digitalWrite(led6,HIGH);
    delay(200);
    digitalWrite(led7,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led6,LOW);

  }

  delay(1000);
}

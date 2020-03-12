#include <dht.h>


#define dht_apin A0 // Analog Pin sensor is connected to
 
dht DHT;
int LED1 = 13;
int smokeA0 = A5;
int sensorThreshold = 220;

const int trigPin = 9;
const int echoPin = 10;

float duration, distance;

 
void setup(){
 
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(smokeA0, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  //delay(500);//Delay to let system boot
  //Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  //delay(1000);//Wait before accessing Sensor
 
}//end "setup()"
 
void loop(){
  //Start of Program 
 
    DHT.read11(dht_apin);
    
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");


    int analogSensor = analogRead(smokeA0);
    Serial.print("Pin A0: ");
    Serial.println(analogSensor);
    if (analogSensor > sensorThreshold)
    {
    digitalWrite(LED1, HIGH);
 //   digitalWrite(LED2, LOW);
//    tone(buzzer, 1000, 200);
    }
    else
    {
    digitalWrite(LED1, LOW);
//    digitalWrite(LED2, HIGH);
//    noTone(buzzer);
    }

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = (duration*.0343)/2;
    Serial.print("Distance: ");
    Serial.println(distance);
    
    delay(2000);
    //Wait 5 seconds before accessing sensor again.
 
  //Fastest should be once every two seconds.
 
}

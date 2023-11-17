#include <Arduino.h>

#define trig 17
#define echo 15
#define led 2
#define DISTANCE 12

 
float  distance_us;
  float duration;

void setup() {
  
 Serial.begin (115200);
 //configure pin
 pinMode (echo, INPUT);
 pinMode(led , OUTPUT);
 pinMode(trig, OUTPUT);

}

void loop() {
  //generate 10-microsecond pulse
digitalWrite(trig , HIGH);
delayMicroseconds(10);
digitalWrite(trig , LOW);
//measure duration of pulse
 duration = pulseIn(echo,HIGH);

//calculate  the time into a distance in cm

distance_us=duration*0.017;
if (distance_us<DISTANCE)
digitalWrite(led,HIGH); //led on
else 
digitalWrite(led,LOW);//led off

Serial.println("The distance is ");
Serial.print(distance_us);
Serial.println ("cm");
delay(500);
}

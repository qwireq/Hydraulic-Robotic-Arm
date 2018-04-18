#include <Servo.h>  


const int finger0 = A1;
const int finger1 = A0;
const int finger2 = A3;
const int finger3 = A2;
const int finger4 = A4;
//a2 безимянный change// Pin connected to voltage divider output
//a4 мезинец
//a1 bolwoi
//a3 fak
//a0 ukaz





// variables will change:
Servo myservo1, myservo2, myservo3, myservo4;
long int count = 0, count1 = 0, sum0 = 0, work0, cur0;
long int sum1 = 0, work1, cur1;
long int sum2 = 0, work2, cur2;
long int sum3 = 0, work3, cur3;
long int sum4 = 0, work4, cur4;
int diff = 40;
boolean workDetermined = false;
int speedy = 5;


  

void moveIn(bool servo1, bool servo2, bool servo3, bool servo4){
 // delay(5);
  int current1 = myservo1.read();
  int current2 = myservo2.read();
  int current3 = myservo3.read();
  int current4 = myservo4.read();
  
  
  if(servo1 == true){
    current1+=speedy;
    myservo1.write(current1);
    //current++;
  }
   if(servo2 == true){
    current2+=speedy;
    myservo2.write(current2);
    //current++;
  }
   if(servo3 == true){
    current3+=speedy;
    myservo3.write(current3);
    //current++;
  }
   if(servo4 == true){
    current4+=speedy;
    myservo4.write(current4);
    //current++;
  }
  
  //delay(2);
  
 }

void moveOut(bool servo1, bool servo2, bool servo3, bool servo4){
  
  int current1 = myservo1.read();
  int current2 = myservo2.read();
  int current3 = myservo3.read();
  int current4 = myservo4.read();
  
  
  if(servo1 == true && current1 != 0){
    current1-=speedy;
    myservo1.write(current1);
    //current++;
  }
   if(servo2 == true){
    current2-=speedy;
    myservo2.write(current2);
    //current++;
  }
   if(servo3 == true ){
    current3-=speedy;
    myservo3.write(current3);
    //current++;
  }
   if(servo4 == true){
    current4-=speedy;
    myservo4.write(current4);
    //current++;
  }
  //delay(2);
 }

/* void move(Servo myservo, float val){
      if(val > 750){
        moveIn(myservo);
      }else if(val < 450){
        moveOut(myservo);  
      }else{
        
      }
  }*/

void setup() {
  // put your setup code here, to run once:
  myservo1.attach(6);
  myservo2.attach(9);
  myservo3.attach(10);
  myservo4.attach(11);
  Serial.begin(9600);
 // Serial.println("servo 1:");
      myservo1.write(0);
    //  delay(2000);
     myservo2.write(0);
   //   delay(2000);
     myservo3.write(0);
   //   delay(2000);
     myservo4.write(0);
  delay(2000);
  pinMode(finger0, INPUT);
  pinMode(finger1, INPUT);
  pinMode(finger2, INPUT);
  pinMode(finger3, INPUT);
  pinMode(finger4, INPUT);
  

}

void loop() {
  /* myservo1.write(180);
     myservo2.write(180);
     myservo3.write(180);
     myservo4.write(180);
     delay(2000);
//Serial.println("in loop");

Serial.print("servo 1:");
Serial.print(myservo1.read());
Serial.print(" ");

Serial.print("servo 2:");
Serial.print(myservo2.read());
Serial.print(" ");

Serial.print("servo 3:");
Serial.print(myservo3.read());
Serial.print(" ");

Serial.print("servo 4:");
Serial.print(myservo4.read());
Serial.print("\n");
    /*myservo1.write(0);
      //delay(2000);
     myservo2.write(0);
      // delay(2000);
     myservo3.write(0);
      //delay(2000);
     myservo4.write(0);*/
  /**/
  int read0 = analogRead(finger0);
  int read1 = analogRead(finger1);
  int read2 = analogRead(finger2);
  int read3 = analogRead(finger3);
  int read4 = analogRead(finger4);


  sum0 = sum0 + read0;
  sum1 = sum1 + read1;
  sum2 = sum2 + read2;
  sum3 = sum3 + read3;
  sum4 = sum4 + read4;
 
  
  count++;
  if(count == 100 && !workDetermined){
    myservo1.write(0);
    myservo2.write(0);
    myservo3.write(0);
    myservo4.write(0);
    work0 = sum0/count;
    work1 = sum1/count;
    work2 = sum2/count;
    work3 = sum3/count;
    work4 = sum4/count;
    sum0 = 0; sum1 = 0; sum2 = 0; sum3 = 0; sum4 = 0;
    workDetermined = true;
  }

  if(workDetermined){
    int state = myservo1.read();
  
    count1++;
    if(count1 == 100){
        cur0 = sum0/count1;
        cur1 = sum1/count1;
        cur2 = sum2/count1;
        cur3 = sum3/count1;
        cur4 = sum4/count1;
        if(work0 - cur0 >= 30){
          Serial.print("Bolshoy palec sognut: ");
          Serial.print(work0);
          Serial.print(" ");
          Serial.print(cur0);
          Serial.println();

          bool servo1=false; 
          bool servo2=false;
          bool servo3=false;
          bool servo4=false;
          if(work1 - cur1 >= 30){
            Serial.print(" Lower :\n");
            servo1 = true;
            
           // myservo1.write(cur1+speed);
            
          }
          if(work2 - cur2 >= 30){
            Serial.print(" Gripper :\n");
            servo2 = true;
           // myservo2.write(cur2+speed);
          }
          if(work3 - cur3 >= 30){
            Serial.print(" Found :\n");
            servo3 = true;
           // myservo3.write(cur3+speed);
          }
          if(work4 - cur4 >= 30){
            Serial.print(" Upper :\n");
            servo4 = true;
           // myservo4.write(cur4+speed);
          }
          moveIn(servo1,servo2,servo3,servo4);
          Serial.print("\n");
          
          //Serial.println(cur0);
          
        }
        else{
          Serial.print("Bolshoy palec razognut: ");
          Serial.print(work0);
          Serial.print(" ");
          Serial.print(cur0);
          Serial.println();
          bool servo1=false; 
          bool servo2=false;
          bool servo3=false;
          bool servo4=false;
          if(work1 - cur1 >= 30){
            Serial.print(" Lower :\n");
            servo1 = true;
           // myservo1.write(cur1-speed);
          //  
          }
          if(work2 - cur2 >= 30){
            Serial.print(" Gripper :\n");
            servo2 = true;
           /// myservo2.write(cur2-speed);
          }
          if(work3 - cur3 >= 30){
            Serial.print(" Found :\n");
            servo3 = true;
            //myservo3.write(cur3-speed);
          }
          if(work4 - cur4 >= 30){
            Serial.print(" Upper :\n");
            servo4 = true;
           // while(myservo4.read() != cur4 - speed)myservo4.write(cur4-speed);
          }
          moveOut(servo1,servo2,servo3,servo4);
          Serial.print("\n");
        }
        count1=0;
        sum0 = 0; sum1 = 0; sum2 = 0; sum3 = 0; sum4 = 0;
    }
  }
  
 // delay(5);*/
}

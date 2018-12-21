#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial Bluetooth(2, 3);

String inputString = "";         // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete

String message = "";

int val;
int LED = 13;

//левое колесо
int A_1A = 10;
int A_1B = 11;
//правое колесо
int B_1A = 6;
int B_1B = 9;

String msg = "";


/* void goForward(int speed){
  Serial.println("forward");
  analogWrite(A_1A, speed);
  analogWrite(B_1A, speed);
  analogWrite(A_1B, 0);
  analogWrite(B_1B, 0);
}

void stop(){
  Serial.println("stop");
  analogWrite(A_1A, 0);
  analogWrite(B_1A, 0);
  analogWrite(A_1B, 0);
  analogWrite(B_1B, 0);
}

void goBack(int speed){
  Serial.println("back");
  analogWrite(A_1A, 0);
  analogWrite(B_1A, 0);
  analogWrite(A_1B, speed);
  analogWrite(B_1B, speed);
}

void goLeft(int speed){
  Serial.println("left");
  analogWrite(A_1A, 0);
  analogWrite(B_1A, speed);
  analogWrite(A_1B, 0);
  analogWrite(B_1B, 0);
}

void goRight(int speed){
  Serial.println("right");
  analogWrite(A_1A, speed);
  analogWrite(B_1A, 0);
  analogWrite(A_1B, 0);
  analogWrite(B_1B, 0);
} */

void go2(int left, int right, int dir, String time){

  //Serial.println("go2 "+time);
  //Serial.flush();
  int A_1A_speed = 0, A_1B_speed = 0, B_1A_speed = 0, B_1B_speed = 0;

  

  if (left == 0 && right == 0) //stop
  {
    //Serial.println("STOP");
    digitalWrite(LED_BUILTIN, HIGH);
    analogWrite(A_1A, 0);
    analogWrite(B_1A, 0);
    analogWrite(A_1B, 0);
    analogWrite(B_1B, 0);
  }

  else if (dir == 0) //go to rear
  {
      digitalWrite(LED_BUILTIN, LOW);

    //right speed
    if (right == 0) 
    {
      A_1B_speed = 0;
    } else {
        A_1B_speed = map(right, 0, 100, 0, 255);
    }
    
    //left speed
    if (left == 0)
    {
      B_1B_speed = 0;
    } else {
        B_1B_speed = map(left, 0, 100, 0, 255);
    }
    
    analogWrite(A_1A, 0);
    analogWrite(B_1A, 0);
    analogWrite(A_1B, A_1B_speed);
    analogWrite(B_1B, B_1B_speed);
  } 
    else //go to forvard
  {
      digitalWrite(LED_BUILTIN, LOW);

    //right speed
    A_1A_speed = map(right, 0, 100, 0, 255);
    //left speed
    B_1A_speed = map(left, 0, 100, 0, 255);
    analogWrite(A_1A, A_1A_speed);
    analogWrite(B_1A, B_1A_speed);
    analogWrite(A_1B, 0);
    analogWrite(B_1B, 0);
  }
  Serial.println("$A1_A: " + String(A_1A_speed) + ", A1_B: " + String(A_1B_speed)+", B1_A: " + String(B_1A_speed)+", B1_B: " + String(B_1B_speed)+","+time);
  //Serial.flush();

  //message = "$"+message + ";A1_A: " + String(A_1A_speed) + ", A1_B: " + String(A_1B_speed)+", B1_A: " + String(B_1A_speed)+", B1_B: " + String(B_1B_speed)+";"+time;
  //Serial.println(message);
  //message = "";

}

void go(float l, float f, float b, float r){
  
  int A_1A_speed = 0, A_1B_speed = 0, B_1A_speed = 0, B_1B_speed = 0;

  //go forward, f - l, f - r
  if (f > 0){
    // Serial.println("Forward");
    // Serial.flush();
    //right speed
    A_1A_speed = map((f-r)*10, 0, 10, 0, 255);
    //left speed
    B_1A_speed = map((f-l)*10, 0, 10, 0, 255);
    analogWrite(A_1A, A_1A_speed);
    analogWrite(B_1A, B_1A_speed);
    analogWrite(A_1B, 0);
    analogWrite(B_1B, 0);

    

  } else if (b > 0){
    // Serial.println("Back");
    // Serial.flush();

    //right speed
    A_1B_speed = map((b-r)*10, 0, 10, 0, 255);
    //left speed
    B_1B_speed = map((b-l)*10, 0, 10, 0, 255);
    analogWrite(A_1A, 0);
    analogWrite(B_1A, 0);
    analogWrite(A_1B, A_1B_speed);
    analogWrite(B_1B, B_1B_speed);
  } 
  else if (b == 0 && f == 0)
  {
    // Serial.println("Stop");
    //     Serial.flush();

    analogWrite(A_1A, 0);
    analogWrite(B_1A, 0);
    analogWrite(A_1B, 0);
    analogWrite(B_1B, 0);
  }

  // Serial.print(A_1A_speed);
  // Serial.print(" ");
  // Serial.print(A_1B_speed);
  // Serial.print(" ");
  // Serial.print(B_1A_speed);
  // Serial.print(" ");
  // Serial.println(B_1B_speed);

  

  
}

void setup()
{

  // TCCR1A = TCCR1A & 0xe0 | 1;
  // TCCR1B = TCCR1B & 0xe0 | 0x0d;

  // TCCR0A = TCCR0A & 0xe0 | 1;
  // TCCR0B = TCCR0B & 0xe0 | 0x0d;

  // TCCR2A = TCCR2A & 0xe0 | 1;
  // TCCR2B = TCCR2B & 0xe0 | 0x0d;

  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(115200);

  Serial.println("Serial begin");

  
  for(int i=0;i<10;i++){
    delay(20);
    Serial.println("lkl hiuuop poiiuggc ggtuio;");
  }

  //Bluetooth.begin(115200);

  // Serial.println("Bluetooth begin");
  // Serial.flush();

  //pinMode(LED, OUTPUT);
  pinMode(A_1A, OUTPUT);
  pinMode(A_1B, OUTPUT);
  pinMode(B_1A, OUTPUT);
  pinMode(B_1B, OUTPUT);
  
  //digitalWrite(LED, HIGH);
  /* analogWrite(A_1A, 150);
  delay(2000);
  analogWrite(A_1A, 0);
  analogWrite(A_1B, 150);
  delay(2000);
  analogWrite(A_1B, 0); */
  /* goForward(150);
  delay(2000);
  stop();
  goBack(100);
  delay(2000);
  stop(); */
}




void loop()
{

  if (stringComplete) {
    //Serial.println("String:"+inputString);


    
    int ind1, ind2, ind3, ind4;
    float l, r, d;
    String t;
    ind1 = inputString.indexOf(',');
    l = inputString.substring(0, ind1).toFloat();
    ind2 = inputString.indexOf(',', ind1+1 ); 
    r = inputString.substring(ind1+1, ind2+1).toFloat();
    ind3 = inputString.indexOf(',', ind2+1 );
    d = inputString.substring(ind2+1, ind3+1).toFloat();
    ind4 = inputString.indexOf(';');
    t = inputString.substring(ind3+1, ind4);
    //Serial.println("$"+String(l)+","+String(r)+","+String(d)+","+t);

    //message = message + String(l)+","+String(r)+","+String(d)+","+t;
    go2(l, r, d, t);
    
    
    // clear the string:
    inputString = "";
    stringComplete = false;
    
  }

  /*if (Serial.available())
  {
    //считываем данные в виде l,t,b,r;
    // String l = Serial.readStringUntil(',');
    // String f = Serial.readStringUntil(',');
    // String b = Serial.readStringUntil(',');
    // String r = Serial.readStringUntil(',');
    // String msg_time = Serial.readStringUntil(';');

    // Serial.println(""+l+" "+f+" "+b+" "+r+" "+msg_time);
    //     Serial.flush();

    // //пишем в моторы
    // if (isDigit(l.charAt(0)) && isDigit(f.charAt(0)) && isDigit(b.charAt(0)) && isDigit(r.charAt(0))) {
    //     go(l.toFloat(), f.toFloat(), b.toFloat(), r.toFloat()); 
    // }

    ////////////
    String left = Serial.readStringUntil(',');
    String right = Serial.readStringUntil(',');
    String dir = Serial.readStringUntil(',');
    String time = Serial.readStringUntil(';');

    

    if (isDigit(left.charAt(0)) && isDigit(right.charAt(0)) && isDigit(dir.charAt(0)))
    {
      Serial.println("$"+left+","+right+","+dir+","+time);
      //Serial.flush();
      go2(left.toInt(), right.toInt(), dir.toInt(), time);
    }


    /*  val = Bluetooth.read();
     

    
    if ((char)val == ';') {
      Serial.println(msg);
      msg = "";
    } 
    else
    {
      msg = msg + (char)val;
    }  */
    
    

    // символ f - едем вперёд
    /* if (val == 'f')
    {
      digitalWrite(LED, HIGH);
      goForward(150);
    } else if (val == 's') 
    {
         digitalWrite(LED, LOW);
         stop();
    }
    else if ( val == 'l')
    {
      goLeft(150);
    } else if (val == 'b')
    {
      goBack(150);
    } else if (val == 'r')
    {
      goRight(150);
    } */
  /*}*/

}
void serialEvent() 
  {
    while (Serial.available()) {
      // get the new byte:
      char inChar = (char)Serial.read();
      // add it to the inputString:
      // if the incoming character is a newline, set a flag so the main loop can
      // do something about it:
      if (inChar == '\n') {
       stringComplete = true;
      } else {
          inputString += inChar;
          //Serial.println(inputString);
      }
      
      
  }
  }

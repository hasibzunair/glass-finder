int ldr = A0;
int buzzer = 7;
int red = 2;
int blue = 3;
int green = 4;
int s = 6;

int count = 0;
int time = 5;
int val_s,val_ldr = 0;
int limit = 400;
bool state = true;
void setup(){
  
  Serial.begin(9600);
  pinMode(ldr,INPUT);
  pinMode(s,INPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
  rgbOFF();
  
}

void loop(){
    
  val_ldr = analogRead(A0);
  val_s   = digitalRead(6);
  
  if(val_ldr >= limit){
    count++;
    delay(1000);
    Serial.println(count);
    if(count == 5) alarmON();
  }
  else offSTATE();
  
  //using swtich to toggle states
  if(val_s == 1){
    delay(100);
    state = !state;
    if(state == true) test_a();
    if(state == false) test_b();
    //Serial.println(state);
  }
}

//test functions
void test_a(){
 Serial.println("Yes");
}

void test_b(){
 Serial.println("No");
}

// first state when alarm is triggered
void alarmON(){
  
  count = 0;
  rgbOFF();
  digitalWrite(buzzer,HIGH);
  digitalWrite(red,HIGH);
  delay(1000);
  digitalWrite(buzzer,LOW);
  digitalWrite(red,LOW);
}

// state when alarm is off
void alarmOFF(){
  rgbOFF();
  digitalWrite(buzzer,LOW);
  digitalWrite(blue,HIGH);
}

//normal state
void offSTATE(){
  count = 0;
  rgbOFF();
  digitalWrite(green,HIGH);
  
}

void rgbOFF(){
  digitalWrite(red,LOW);
  digitalWrite(green,LOW);
  digitalWrite(blue,LOW);
}


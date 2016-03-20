// BANG BANG CODE

void setup() {
  // put your setup code here, to run once:
  pinMode(10,OUTPUT); // PWM PIN FOR LEFT MOTOR
  pinMode(11,OUTPUT); // PWM PIN FOR RIGHT MOTOR
  pinMode(5,OUTPUT); // left motor ctrl 1
  pinMode(6,OUTPUT); // left motor ctrl 2
  pinMode(8,OUTPUT); // right motor ctrl 1
  pinMode(9,OUTPUT); // right motor ctrl 2
  pinMode(A0,INPUT); // Analog or digital inputs
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
  digitalWrite(11,HIGH);
  digitalWrite(10,HIGH);
  Serial.begin(9600); //Set baud rate
}

int LastTurn=-1;

void drive(void)
{
  
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
  Serial.println("BOT GOING STRAIGHT");
}

void eleft(void)
{
  
  digitalWrite(8,LOW);
  digitalWrite(9,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  Serial.println("LEFT TURN EXECUTED");
  LastTurn=0;
}

void eright(void)
{
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  Serial.println("RIGHT TURN EXECUTED");
  LastTurn=1;
}

void sright(void)
{
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  Serial.println("SHARP RIGHT TURN EXECUTED");
  LastTurn=1;
}

void sleft(void)
{
  digitalWrite(8,LOW);
  digitalWrite(9,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  Serial.println("SHARP LEFT TURN EXECUTED");
  delay(100);
  LastTurn=0;
}




void loop() {

  int a,b,c,d,e,sum=0;
  a=digitalRead(A4);
  b=digitalRead(A3);
  c=digitalRead(A2);
  d=digitalRead(A1);
  e=digitalRead(A0);
  sum=31-((16*a)+(8*b)+(4*c)+(2*d)+e); // subtract from 31 for black on white arena
  // 16   8   4    2    1
  switch(sum)
  {
    case 0: { // to avoid overshooting
      if(LastTurn==0) sright();
      else if(LastTurn==1) sleft();
      break;
    }
    case 1: sleft(); break;
    case 2: eleft(); break;
    case 3: sleft(); break;
    case 4: drive(); break;
    case 5: sleft(); break;
    case 6: sleft(); break;
    case 7: sleft(); break;
    case 8: eright(); break;
    case 10: sright(); break;
    case 12: sright(); break;
    case 15: sleft(); break;
    case 16: sright(); break;
    case 20: sright(); break;
    case 24: sright(); break;
    case 28: sright(); break;
    case 30: sright(); break;
    case 31: sleft(); break; // for default left. You can change to default right as per track
    default: drive(); break;
  }
  
  

}

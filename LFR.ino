// BANG BANG CODE
/* Code has been tested practically on a real robot */

int LastTurn=-1,cli=-1;

void setup() {
  // put your setup code here, to run once:
  pinMode(10,OUTPUT); // PWM PIN FOR LEFT MOTOR
  pinMode(11,OUTPUT); // PWM PIN FOR RIGHT MOTOR
  pinMode(5,OUTPUT); // left motor ctrl 1
  pinMode(6,OUTPUT); // left motor ctrl 2
  pinMode(8,OUTPUT); // right motor ctrl 1
  pinMode(9,OUTPUT); // right motor ctrl 2
  pinMode(4,OUTPUT); // Auto-calibration indicator LED
  pinMode(3,OUTPUT); // LED GROUND
  pinMode(A0,INPUT); // Analog or digital inputs
  pinMode(A1,INPUT); // Analog or digital inputs
  pinMode(A2,INPUT); // Analog or digital inputs
  pinMode(A3,INPUT); // Analog or digital inputs
  pinMode(A4,INPUT); // Analog or digital inputs
  pinMode(A5,INPUT); // Analog or digital inputs
  digitalWrite(11,HIGH);
  digitalWrite(10,HIGH);
  
  /*Auto Calibration. To autocalibrate, place bot on the center of line, with middle sensor
  on it, wait for 5 seconds and wait for LED to glow to indicate calibration complete.*/
  
  for(int i=0;i<5;i++)
  {
    int in=digitalRead(A2);
    if(in==0)
      cli=0;
    else if(in==1)
      cli=1;
    delay(1000);
  }
  
  digitalWrite(4,HIGH);
  digitalWrite(3,LOW);
  Serial.println("Callibration complete");
  Serial.begin(9600); //Set baud rate
}


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

int BCD_to_INT(int a, int b, int c, int d, int e, int cal)
{
  int sum=0;
  if(cal==0)
    sum=31-((16*a)+(8*b)+(4*c)+(2*d)+e);
  else if (cal==1)
    sum=((16*a)+(8*b)+(4*c)+(2*d)+e);
  return sum;
}


void loop() {

  int a,b,c,d,e,sum=0;
  a=digitalRead(A4);
  b=digitalRead(A3);
  c=digitalRead(A2);
  d=digitalRead(A1);
  e=digitalRead(A0);
  sum=BCD_to_INT(a,b,c,d,e,cli);
  
  switch(sum)
  {
    case 0: 
    { /* to avoid overshooting*/
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
    case 31: sleft(); break; /* for default left. You can change to default right as per track */
    default: drive(); break;
  }
  
}

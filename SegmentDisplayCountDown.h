int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 12;
int f = 7;
int g = 8;
int GND1 = 6;
int GND2 = 11;
int GND3 = 10;
int GND4 = 9;
int dig1 = 0;
int dig2 = 0;
int dig3 = 0;
int dig4 = 0;
int sensor = A0;
int i;
int j;
int num;
int count;
void setup()
{
  Serial.begin(9600);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(GND1, OUTPUT);
  pinMode(GND2, OUTPUT);
  pinMode(GND3, OUTPUT);
  pinMode(GND4, OUTPUT);
}

void loop()
{
  count = 1024;
  Serial.println(count);
  MultiDigit(count);
//  delay(100);
}

void MultiDigit(int number){
  j = number;
  num = j;
  dig1 = num / 1000;
  num = num - (dig1 * 1000);
  dig2 = num / 100;
  num = num - (dig2 * 100);
  dig3 = num / 10;
  dig4 = num - (dig3 * 10);

  for (int i = 1; i <= 50; i++)
  {
    if (j >= 1000)
    {
     FirstDigitProcessing(dig1 ,dig2 ,dig3 , dig4);
    }
    else if  (j >= 100)
    {
      SecondDigitProcessing(dig2 , dig3 , dig4);
    }
    else if  (j >= 10)
    {
      ThirdDigitProcessing(dig3 , dig4);
    }
    else if  (j >= 0)
    {
      ForthDigitProcessing(dig4);
    }   
  }  
}



void DisplayNumber(int x) {
  switch (x) {
    case 0: zero(); break;
    case 1: one(); break;
    case 2: two(); break;
    case 3: three(); break;
    case 4: four(); break;
    case 5: five(); break;
    case 6: six(); break;
    case 7: seven(); break;
    case 8: eight(); break;
    case 9: nine(); break;
  }
}

void FirstDigitProcessing(int dig1 ,int dig2 ,int dig3 ,int dig4){
  digitalWrite( GND4, LOW);    //digit 4
  DisplayNumber(dig4);
  delay(4);
  digitalWrite( GND4, HIGH);

  digitalWrite( GND3, LOW);    //digit 3
  DisplayNumber(dig3);
  delay(4);
  digitalWrite( GND3, HIGH);

  digitalWrite( GND2, LOW);   //digit 2
  DisplayNumber(dig2);
  delay(4);
  digitalWrite( GND2, HIGH);

  digitalWrite( GND1, LOW);   //digit 1
  DisplayNumber(dig1);
  delay(9);
  digitalWrite( GND1, HIGH);  
}

void ForthDigitProcessing(int dig4)
{
   DisplayNumber(dig4);
   digitalWrite( GND3, HIGH);
   digitalWrite( GND2, HIGH);
   digitalWrite( GND1, HIGH);  
}

void ThirdDigitProcessing(int dig3 , int dig4)
{
        digitalWrite( GND2, HIGH);
        digitalWrite( GND1, HIGH); 

        digitalWrite( GND4, LOW);    //digit 4
        DisplayNumber(dig4);
        delay(1);
        digitalWrite( GND4, HIGH);

        digitalWrite( GND3, LOW);    //digit 3
        DisplayNumber(dig3);
        delay(10);
        digitalWrite( GND3, HIGH);
}

void SecondDigitProcessing(int dig2 , int dig3 , int dig4){
  digitalWrite( GND1, HIGH);    
  digitalWrite( GND4, LOW);
  DisplayNumber(dig4);
  delay(4);
  digitalWrite( GND4, HIGH);

  digitalWrite( GND3, LOW);
  DisplayNumber(dig3);
  delay(4);
  digitalWrite( GND3, HIGH);

  digitalWrite( GND2, LOW);   
  DisplayNumber(dig2);
  delay(4);
  digitalWrite( GND2, HIGH);  
}

void zero()
{
  digitalWrite( a, HIGH);
  digitalWrite( b, HIGH);
  digitalWrite( c, HIGH);
  digitalWrite( d, HIGH);
  digitalWrite( e, HIGH);
  digitalWrite( f, HIGH);
  digitalWrite( g, LOW);
}

void one()
{
  digitalWrite( a, LOW);
  digitalWrite( b, HIGH);
  digitalWrite( c, HIGH);
  digitalWrite( d, LOW);
  digitalWrite( e, LOW);
  digitalWrite( f, LOW);
  digitalWrite( g, LOW);
}

void two()
{
  digitalWrite( a, HIGH);
  digitalWrite( b, HIGH);
  digitalWrite( c, LOW);
  digitalWrite( d, HIGH);
  digitalWrite( e, HIGH);
  digitalWrite( f, LOW);
  digitalWrite( g, HIGH);
}

void three()
{
  digitalWrite( a, HIGH);
  digitalWrite( b, HIGH);
  digitalWrite( c, HIGH);
  digitalWrite( d, HIGH);
  digitalWrite( e, LOW);
  digitalWrite( f, LOW);
  digitalWrite( g, HIGH);
}

void four()
{
  digitalWrite( a, LOW);
  digitalWrite( b, HIGH);
  digitalWrite( c, HIGH);
  digitalWrite( d, LOW);
  digitalWrite( e, LOW);
  digitalWrite( f, HIGH);
  digitalWrite( g, HIGH);
}

void five()
{
  digitalWrite( a, HIGH);
  digitalWrite( b, LOW);
  digitalWrite( c, HIGH);
  digitalWrite( d, HIGH);
  digitalWrite( e, LOW);
  digitalWrite( f, HIGH);
  digitalWrite( g, HIGH);
}

void six()
{
  digitalWrite( a, HIGH);
  digitalWrite( b, LOW);
  digitalWrite( c, HIGH);
  digitalWrite( d, HIGH);
  digitalWrite( e, HIGH);
  digitalWrite( f, HIGH);
  digitalWrite( g, HIGH);
}

void seven()
{
  digitalWrite( a, HIGH);
  digitalWrite( b, HIGH);
  digitalWrite( c, HIGH);
  digitalWrite( d, LOW);
  digitalWrite( e, LOW);
  digitalWrite( f, LOW);
  digitalWrite( g, LOW);
}

void eight()
{
  digitalWrite( a, HIGH);
  digitalWrite( b, HIGH);
  digitalWrite( c, HIGH);
  digitalWrite( d, HIGH);
  digitalWrite( e, HIGH);
  digitalWrite( f, HIGH);
  digitalWrite( g, HIGH);
}

void nine()
{
  digitalWrite( a, HIGH);
  digitalWrite( b, HIGH);
  digitalWrite( c, HIGH);
  digitalWrite( d, HIGH);
  digitalWrite( e, LOW);
  digitalWrite( f, HIGH);
  digitalWrite( g, HIGH);
}
void oo()
{
  digitalWrite( a, LOW);
  digitalWrite( b, LOW);
  digitalWrite( c, HIGH);
  digitalWrite( d, HIGH);
  digitalWrite( e, HIGH);
  digitalWrite( f, LOW);
  digitalWrite( g, HIGH);
}   
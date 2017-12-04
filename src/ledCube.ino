#include "Rubiks3x3.h"
#include <FastLED.h>

#define NUM_LEDS 54 //Number of led's on 3x3 cube
#define DATA_PIN 3 //Din to led's

String a;// operation string to read from serial port
bool stat;//game mode -> false for free and true for solving

cube myCube;//from rubiks library to simulate the cube 

CRGB leds[NUM_LEDS];//leds array from fastled library

const String arr[5]={ //scramble moves for cube
"L2 D' F2 D2 B2 L2 U F2 R' F R' U2 L2 D' U' R' U B2 L'",
"R2 D2 B2 D2 F2 D R2 D L R F' L' D' F2 D2 B F2 L U",
"L2 B' D2 B' R2 B D2 U2 B2 R D2 U' L B' F2 L2 D2 U' B2",
"F B' L' U' R' F L2 F' R2 U R' F' R2 F U2 L2 F' U2 F",
"L' U' R2 B2 R' D' R U' F B R D2 B2 R' U2 R' B2 D2 L2 D2"
};

void setup() 
{
  delay(1000);
  Serial.begin(9600);
  Serial.println("Hello Cuber\n");
  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
  stat = false;//start game in free mode
}

void loop() 
{
  if(Serial.available()>0) 
  {
     a = Serial.readStringUntil('\n');// read the incoming data as string
     
     if(a == "P")
      pC();
      
     else if(a.length()<3)
     {
       mCub();
       updLedsFromCube();
       FastLED.show();
     }
     else if(a == "RESET")
     {
       stat = false;
       myCube.resetCube();
       updLedsFromCube();
       FastLED.show();
     }
      else if(a=="SCR")
      {
        stat = true;
        scr();
        updLedsFromCube();
        FastLED.show();
      }
      if(stat && myCube.isSolved())
      {
        Serial.println("You Have solved the cube");
        animate();
        myCube.resetCube();
        stat = false;// back to free mode after solving the cube
        updLedsFromCube();
        FastLED.show();
      }
  }
}
void mCub()
{
  if(a.length()==2 && a[1]=='\'')
    myCube.moveCube(3,a[0]);
    else   if(a.length()==2 && a[1]=='2')
    myCube.moveCube(2,a[0]);
  else
    myCube.moveCube(1,a[0]);
}
void pCF(char arr[][3])
{
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
        Serial.print(arr[i][j]);
        Serial.println();
  }
  Serial.println();
}
void pC()
{
  Serial.println("FRONT");
  pCF(myCube.f);
  Serial.println("BACK");
  pCF(myCube.b);
  Serial.println("UP");
  pCF(myCube.u);
  Serial.println("DOWN");
  pCF(myCube.d);
  Serial.println("RIGHT");
  pCF(myCube.r);
  Serial.println("LEFT");
  pCF(myCube.l);
}
void scr()
{
  randomSeed(1);
  int x = random(5);
  String v = arr[x];
  String p ="";
  for(int i =0; i<= v.length();i++)
  {
    if(v[i]==' ' || i==v.length())
    {
      a = p;
      mCub();
      //comment following lines for no animation
      updLedsFromCube();
      FastLED.show();
      delay(50);//check and modify delay accordingly
      //show move one by one while scrambling
      
      p = "";
    }
    else
      p = p+v[i];
  }
}
CRGB clcRGB(char ch)
{
  CRGB led;
  
  int r,g,b;//here one can change red,green,blue,orange,white,yellow
  
  if(ch == 'r')
  r = 255,g = 0, b = 0;
  
  else if(ch == 'b')
  r = 0, g =0, b = 255;
  
  else if(ch == 'g')
  r = 0, g = 255, b = 0;

  else if(ch == 'o')
  r = 255, g = 165, b = 0;

  else if(ch == 'y')
  r = 255, g = 255, b = 0;

  else if(ch == 'w')
  r = 255, g = 255, b= 255;

  led.r=r;
  led.g=g;
  led.b=b;
  
  return led;
}
void updLedsFromFace(int & pos,char face[][3])
{
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      {
        if(i&1)
        leds[pos] = clcRGB(face[i][2-j]);//trick for make the soldering easier
        else
        leds[pos] = clcRGB(face[i][j]);
         pos++;
      }
}
void updLedsFromCube()
{
  //depending on the soldering one has to check which led is which from the cube and the order
  int posLed=0;
  updLedsFromFace(posLed,myCube.d);
  updLedsFromFace(posLed,myCube.f);
  updLedsFromFace(posLed,myCube.r);
  updLedsFromFace(posLed,myCube.b);
  updLedsFromFace(posLed,myCube.l);
  updLedsFromFace(posLed,myCube.u);
}
void animate()
{

 for(int i=0;i<NUM_LEDS;i++)
      leds[i]=CRGB::Black;
    FastLED.show();
     
 randomSeed(analogRead(0));
 int list[NUM_LEDS];
 for(int i=0;i<NUM_LEDS;i++)list[i]=i;

  for (int i=0; i<NUM_LEDS; i++)
  {
   int r = random(i,NUM_LEDS);
   int temp = list[i];
   list[i] = list[r];
   list[r] = temp;
  } 

  for(int i=0;i<NUM_LEDS;i++)
  {
    bool v = (bool) random(2);
    if(v)
    leds[list[i]]=CRGB::Blue;
    else
    leds[list[i]]=CRGB::Red;
    FastLED.show();
    delay(200);
  }
  delay(3000);
  
 for(int i=0;i<NUM_LEDS;i++)
      leds[i]=CRGB::Black;
    FastLED.show();

  int n = NUM_LEDS;
  while(n)
  {
    for(int i=0;i<n;i++)
    {
      bool v = (bool) random(2);
      if(v)
      leds[i]=CRGB::Blue;
      else
      leds[i]=CRGB::Red;
      if(i>0)
      leds[i-1]=CRGB::Black;
      FastLED.show();
      delay(100);
    }
    n--;
  }
  delay(2000);
}


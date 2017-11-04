#include "Rubiks3x3.h"
#include <iostream>
#include <string>
using namespace std;
string scramble = "D' B U2 F L2 B' L2 U' R D' R' L B2 U' D R L' D R B L' U R2 L' B";
int main()
{
  //void moveCube(cube & myCube,int times,char mv)
    cube myCube;
    string read;

    while(true)
    {
      cin>>read;
      if(read == "exit")
        break;

      else if(read == "print")
      myCube.printCube();

      else if(read.size() == 2)
      {
        if((int)read[1] == 39)//39 in ascii -> '
          moveCube(myCube,3,read[0]);
        else if((int)read[1] == (int)'2')
            moveCube(myCube,2,read[0]);
      }
      else if(read.size()==1)
        moveCube(myCube,1,read[0]);

      else
        cout<<"Not valid option!\n";
    }
}

#ifndef _methods_h_                 
#define _methods_h_      
#include <iostream>
#include <vector>
#include <cmath>
// #include <wiringPi.h>

using namespace std;



class movementProfile{
private:
    bool mmFlag;
	bool inchesFlag;
	double feedrate;
public:
   
	void xmovement(int specifiedValue);
	void ymovement(int specifiedValue);
	void zmovement(int specifiedValue);
};

void xmovement(double specifiedValue){
	//implementation
	cout << "moving X by " << specifiedValue << endl;
	//change enable to 1
	//do specifiedValue squarewaves
	//change enable to 0
	
}

void ymovement(double specifiedValue){
	//implementation
	cout << "moving Y by " << specifiedValue << endl;
	//change enable to 1
	//do specifiedValue squarewaves
	//change enable to 0
	
}

void zmovement(int specifiedValue){
	//implementation
	cout << "moving Z by " << specifiedValue << endl;
}

#endif
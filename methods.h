#ifndef _methods_h_                 
#define _methods_h_      
#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h>
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
	
	// wiringPiSetup();
	// pinMode(0,OUTPUT);
	// pinMode(1,OUTPUT);
	// pinMode(2,OUTPUT);
	// double movementRatio = 5; //this will change depending on how far the gantry moves per motor step 

	// if(specifiedValue<0){
		// digitalWrite(2,HIGH);
	// }
	
	
	// digitalWrite(0,HIGH);
	// for(int i=0;i<(movementRatio*specifiedValue);i++){
		// digitalWrite(1,HIGH) ; delay (100);
		// digitalWrite(1,LOW)	; delay(100);
	// }
	// digitalWrite(0,LOW);
	
}

void ymovement(double specifiedValue){
	//implementation
	cout << "moving Y by " << specifiedValue << endl;
	//change enable to 1
	//do specifiedValue squarewaves
	//change enable to 0
	
	// wiringPiSetup();
	// pinMode(3,OUTPUT);
	// pinMode(4,OUTPUT);
	// pinMode(5,OUTPUT);
	// double movementRatio = 5; //this will change depending on how far the gantry moves per motor step 

	// if(specifiedValue<0){
		// digitalWrite(5,HIGH);
	// }
	
	
	// digitalWrite(3,HIGH);
	// for(int i=0;i<(movementRatio*specifiedValue);i++){
		// digitalWrite(4,HIGH) ; delay (100);
		// digitalWrite(4,LOW)	; delay(100);
	// }
	// digitalWrite(3,LOW);
	
	
	
	
	
}

void zmovement(int specifiedValue){
	//implementation
	cout << "moving Z by " << specifiedValue << endl;
}

#endif
//Need to add either fork() and execvp(), or multithreading
//to run motors simultaneously 

using namespace std;
#include "methods.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <thread>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <fstream>
// #include <wiringPi.h>

using namespace std;




bool contains(string inputWord, string desiredChar){
	//return 1 if string contains character
	//return 0 if string does not contain character
	if (inputWord.find(desiredChar) != std::string::npos){
		return 1; // found
	}else{
		return 0; // not found
	}
}


void parse(string inputLineToBeParsed){
	bool xflag = 0;
	bool yflag = 0;
	bool zflag = 0;
	int xindex;
	int yindex;
	//Sets mmFlag, Sets inchesFlag
	//While parsing it will run functions from "methods.h" 
	//break inputstring into vector of strings so we can evaluate each element
	cout << "InputLine:" << inputLineToBeParsed << endl;
	istringstream iss(inputLineToBeParsed);
	vector<string> tokens{istream_iterator<string>{iss},istream_iterator<string>{}};
	for(int i=0;i<tokens.size();i++){
		if(contains(tokens.at(i),"X")){
			xflag = 1;
			xindex = i;
			// // //Run x motor for specified value
			// cout << "X WAS IDENTIFIED" << endl;
			// char* value = (char*) tokens.at(i).c_str();
			// value = (value + 1);
			// double specifiedValue = atof( value);
			// xmovement(specifiedValue);
			
		}
		if(contains(tokens.at(i),"Y")){
			yflag = 1;
			yindex = i;
			// //Run y motor with specified movement style (G00 for max movement rate, G01 to move at feed rate)
			// cout << "Y WAS IDENTIFIED" << endl;
			// char* value = (char*) tokens.at(i).c_str();
			// value = (value + 1);
			
			// double specifiedValue = atof( value);
			
			// ymovement(specifiedValue);
			
		}
		
	}
		

		if(xflag == 1 && yflag == 1){
			
			
				cout << "X WAS IDENTIFIED" << endl;
				char* xvalue = (char*) tokens.at(xindex).c_str();
				xvalue = (xvalue + 1);
				double specifiedXValue = atof( xvalue);
				
				cout << "Y WAS IDENTIFIED" << endl;
				char* yvalue = (char*) tokens.at(yindex).c_str();
				yvalue = (yvalue + 1);
				double specifiedYValue = atof( yvalue);
				thread xthread(xmovement,specifiedXValue);
				thread ythread(ymovement,specifiedYValue);
				
		
				
				xthread.join();
				ythread.join();
				cout << "both threads have finished" << endl;
				
			}
		
		
		if(xflag == 1 && yflag == 0){
			//Run x motor for specified value
			cout << "X WAS IDENTIFIED" << endl;
			char* value = (char*) tokens.at(xindex).c_str();
			value = (value + 1);
			double specifiedValue = atof( value);
			xmovement(specifiedValue);
					
		
		}
		if(xflag == 0 && yflag == 1){
			//Run x motor for specified value
			cout << "X WAS IDENTIFIED" << endl;
			char* value = (char*) tokens.at(yindex).c_str();
			value = (value + 1);
			double specifiedValue = atof( value);
			xmovement(specifiedValue);
				
		
		}
		
		
		
	
}
			
	
int main(int argc, char *argv[]){
	
	
	
	
	string filename = "Sample_G_Code.gcode";
	
	
	fstream fs;
	fs.open(filename, ios::in);
	string line;
	while(!fs.eof()){
		getline(fs,line);
		parse(line);
		
	}
	
	fs.close();
	
	
	return 0;
}
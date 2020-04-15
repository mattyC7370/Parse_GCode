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
	//Sets mmFlag, Sets inchesFlag
	//While parsing it will run functions from "methods.h" 
	//break inputstring into vector of strings so we can evaluate each element
	cout << "InputLine:" << inputLineToBeParsed << endl;
	istringstream iss(inputLineToBeParsed);
	vector<string> tokens{istream_iterator<string>{iss},istream_iterator<string>{}};
	for(int i=0;i<tokens.size();i++){
		if(contains(tokens.at(i),"X")){
			// //Run x motor for specified value
			
			cout << "X WAS IDENTIFIED" << endl;
			char* value = (char*) tokens.at(i).c_str();
			value = (value + 1);
			
			double specifiedValue = atof( value);
			
			xmovement(specifiedValue);
			
		}
		if(contains(tokens.at(i),"Y")){
			// //Run y motor with specified movement style (G00 for max movement rate, G01 to move at feed rate)
			cout << "Y WAS IDENTIFIED" << endl;
			char* value = (char*) tokens.at(i).c_str();
			value = (value + 1);
			
			double specifiedValue = atof( value);
			
			ymovement(specifiedValue);
			
		}
		// if(contains(tokens.at(i),"Z")){
			// // //Run z motor with specified movement style (G00 for max movement rate, G01 to move at feed rate)
			// cout << "Z WAS IDENTIFIED" << endl;
			// char* value = (char*) tokens.at(i).c_str();
			// value = (value + 1);
			
			// double specifiedValue = atof( value);
			
			// zmovement(specifiedValue);
			
			
			
		// }
		// }else if(contains(tokens.at(i),"G20")){
			// bool inchesFlag = 1;
		// }else if(contains(tokens.at(i),"G21")){
			// bool mmFlag = 1;
		// }else if(contains(tokens.at(i),"F")){
			// //change feed rate
		// }
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
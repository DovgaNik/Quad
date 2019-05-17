#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

float xarr[3];
bool countable,
     verbose = false;
//string file_name;

/*void parser(string file){ //Masybe this code will never be used but i`ll leave it here
	string	line,
		tokena,
		tokenb,
		tokenc;
	fstream in(file);
	if(in.is_open()){
		while(getline(in, line)){
			//Started parsing
			

			//Start parsing
			//Parsing a
			tokena = line.substr(0, line.find("x^2 "));
			cout << tokena + " a" << endl;
			
			//Parsing b
			tokenb = line.substr(0, line.find("x "));
			cout << tokenb + " b tmp" << endl;
			tokenb = tokenb.substr(0, tokena + "x^2");
			cout << tokenb + " b" << endl;

			//tokenb = tokenb.substr(0, line.find(tokena));
			//token = line.substr(0, line.find("x "));
			//cout << tokenb + " b" << endl;
			token = line.substr(0, line.find("x^2"));
			//cout << token + " c" << endl;
		}
	}
	in.close();
}*/

void counter(float a, float b, float c){
	float 	d = (pow(b, 2) - 4 * a * c);//This line counts discriminant.
	float	num,
		num1,
		num2,
		denum;//This code will initialise variables that will count the solution.
	//Theese statesments will check number of avalible solutions.
	if(d > 0){//This statement will check if the diskriinant is bigger than zero. That means that there is two avalible solutions.
		num1 = b * -1 + sqrt(d);
		num2 = b * -1 - sqrt(d);
		denum = 2 * a;
		if(verbose){
			cout << "Discriminant is higher than 0" << endl;
			cout << "First num is " << num1 << endl;
			cout << "Second num is " << num2 << endl;
			cout << "denum is " << denum << endl;	
		}
		xarr[1] = num1 / denum;
		xarr[2] = num2 / denum;
		countable = true;
	}
	if(d == 0){//This statement will check if the diskriminant equals zero. That means that there is one solution.
		num = b * -1;
		denum = 2 * a;
		if(verbose){
			cout << "Discriminant is 0" << endl;
			cout << "num is " << num << endl;
			cout << "denum is " << denum << endl;	
		}
		xarr[1] = num / denum;
		countable = true;
	}
	if(d < 0){//This statement will check if diskriminat is lower than zero. That means that there isn't any solutions.
		if(verbose){
			cout << "Discriminant is lower than 0" << endl;
		}
		countable = false;
	}
	xarr[0] = d;
}

int main(int argc, char *argv[]){
	if(argc <= 2){
		cout << "Usage: quad [a] [b] [c] [options]" << endl << "\tv - verbose(only for developers)" << endl;
	}
	if(argc == 5){
		verbose = true;
		counter(atof(argv[1]), atof(argv[2]), atof(argv[3]));
		if(countable){
			if(xarr[2] != 0){
				cout << xarr[0] << " - Discriminant" << endl << xarr[1] << " - x1" << endl << xarr[2] << " - x2" << endl;
			}else{
				cout << xarr[0] << " - Discriminant" << endl << xarr[1] << " - x" << endl;
			}
		}else{
			cout << "Discriminant is lower than 0" << endl;	
		}
	}
	if(argc == 4){
		counter(atof(argv[1]), atof(argv[2]), atof(argv[3]));
		if(countable){
			if(xarr[2] != 0){
				cout << xarr[0] << " - Discriminant" << endl << xarr[1] << " - x1" << endl << xarr[2] << " - x2" << endl;
			}else{
				cout << xarr[0] << " - Discriminant" << endl << xarr[1] << " - x" << endl;
			}
		}else{
			cout << "Discriminant is lower than 0" << endl;	
		}
	}
}

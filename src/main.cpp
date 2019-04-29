#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

float xarr[3];
bool countable;

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
		xarr[1] = num1 / denum;
		xarr[2] = num2 / denum;
		countable = true;
	}
	if(d == 0){//This statement will check if the diskriminant equals zero. That means that there is one solution.
		num = b * -1;
		denum = 2 * a;
		xarr[1] = num / denum;
		countable = true;
	}
	if(d < 0){//This statement will check if diskriminat is lower than zero. That means that there isn't any solutions.
		countable = false;
	}
	xarr[0] = d;
}

int main(int argc, char *argv[]){
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

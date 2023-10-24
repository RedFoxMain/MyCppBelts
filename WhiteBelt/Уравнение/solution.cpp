#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
	int A,B,C;
	cin >> A >> B >> C;
	int D = pow(B, 2) - 4*A*C;
	float x1 = 0, x2 = 0;
	
	if(D>0 && A!=0){
		x1 = (-1*B - sqrt(D))/(2*A);
		x2 = (-1*B + sqrt(D))/(2*A);
	}
	else if(D<0){
		cout << "Корней нет!" << endl;
	}
	else if(D==0 && A!=0){
		x1 = (-1*B)/(2*A);
	}
	cout << x1 << " " << x2 << endl;
}

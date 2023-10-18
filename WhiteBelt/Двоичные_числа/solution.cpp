#include <iostream>
#include <cmath>
using namespace std;

void binary(int bin_num){
	string num = to_string(bin_num);
	int p = num.length()-1;
	int res = 0;
	for(int i = 0; i < num.size(); i++){
		res += (num[i]-'0') * pow(2, p);
		p--;
	}
	cout << res;
}

int main(int argc, char *argv[])
{
	binary(10110110);
}

#include <iostream>
#include <algorithm>
using namespace std;

void binary(int bin_num)
{
	string str;
	while (bin_num > 0)
	{
		int remainder = bin_num % 2;
		str += to_string(remainder);
		bin_num = bin_num / 2;
	}
	reverse(str.begin(), str.end());
	cout << str << endl;
}

int main(int argc, char *argv[])
{
	binary(182);
}

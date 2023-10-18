#include <iostream>
#include <algorithm>
using namespace std;

void binary(int bin_num)
{
	string str;
	while (bin_num > 0)
	{
		int ost = bin_num % 2;
		str += to_string(ost);
		bin_num = bin_num / 2;
	}
	reverse(str.begin(), str.end());
	cout << str << endl;
}

int main(int argc, char *argv[])
{
	binary(182);
}

#include <iostream>
#include <sstream>
using namespace std;

#define PRINT_VALUES(out, x, y) out << (x) << endl; out << (y) << endl;

int main(int argc, char *argv[])
{
	ostringstream os;
	PRINT_VALUES(os, 3, "hello");
	cout << os.str();
}

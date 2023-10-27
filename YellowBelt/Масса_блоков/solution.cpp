#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	unsigned int N, p, W,H,D, Sum=0;
	cin >> N >> p;
	for(int i = 0; i < N; i++){
		cin >> W >> H >> D;
		Sum += (W*H*D)*p;
	}
	cout << Sum << endl;
}

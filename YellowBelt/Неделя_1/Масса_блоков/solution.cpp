#include <iostream>

int main(){
	unsigned int N, p, W, H, D, Sum = 0;
	std::cin >> N >> p;
	for (size_t i = 0; i < N; ++i){
		std::cin >> W >> H >> D;
		Sum += (W * H * D) * p;
	}
	std::cout << Sum << std::endl;
}
#include <iostream>
#include <cmath>

int main(){
	int A, B, C;
	std::cin >> A >> B >> C;
	int D = std::pow(B, 2) - 4 * A * C;
	float x1 = 0, x2 = 0;

	if (D > 0 && A != 0){
		x1 = (-1 * B - sqrt(D)) / (2 * A);
		x2 = (-1 * B + sqrt(D)) / (2 * A);
	}
	else if (D < 0){
		std::cout << "Корней нет!" << std::endl;
	}
	else if (D == 0 && A != 0){
		x1 = (-1 * B) / (2 * A);
	}
	std::cout << x1 << " " << x2 << std::endl;
}
#include <iostream>
#include <fstream>
#include <vector>

int main(){
    std::ifstream file("test.txt"); // Читаем файл
    int row, col;
    std::string num;
    std::vector<std::vector<int>> matrix; // Таблица данных
    std::vector<int> line;
    if(file.is_open()){
    	file >> row >> col; // Записываем значение row и col
    	while(matrix.size() != row){ 
    		file >> num; // Читаем остальное
    		if(line.size() != col){ line.push_back(std::stoi(num)); }
    		else{ matrix.push_back(line); line.clear(); line.push_back(std::stoi(num)); }
    	}
    }
    // Вывод матрицы на печать
    for(int i=0; i < matrix.size(); ++i){
    	for(int j=0; j < matrix[i].size(); ++j){
    		printf("%i\t", matrix[i][j]);
    	}
    	std::cout << "\n";
    }
}
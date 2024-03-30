#include <iostream>
#include <fstream>

int main(){
        // Задания: Часть 1 и Часть 2
        std::string lines;
        std::ifstream file1("test1.txt");
        std::ofstream file2("copy_test1.txt");
        while (!file1.eof()){
        	std::getline(file1, lines);
            file2 << lines << std::endl;
        }
        file1.close();
}
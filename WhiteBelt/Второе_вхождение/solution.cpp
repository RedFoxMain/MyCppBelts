#include <iostream>

using namespace std;

// второе вхождение f
int find_symbol(string text, char symb){
        // если в тексте присутвует f мы возьмеём её позицию и от неё пробуем найти вторую f есои не нпходим возвращаем -1 если нет f вообще -2
        int target = (text.find(symb) != string::npos) ? text.find(symb, text.find(symb)+1) : -2;
		return target;
}

int main(int argc, char *argv[])
{
        string letter = "informative film";
        string letter2 = "film";
        string letter3 = "test";
        cout << find_symbol(letter, 'f') << endl;
        cout << find_symbol(letter2, 'f') << endl;
        cout << find_symbol(letter3, 'f') << endl;
}
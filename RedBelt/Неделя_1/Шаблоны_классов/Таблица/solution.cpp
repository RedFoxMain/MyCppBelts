#include <iostream>
#include <utility>
#include <vector>

template<typename T>
class Table{
public:
        Table(size_t row, size_t column): row_(row), col_(column){}

        std::vector<T>& operator[](int index){
                return table[index];
        }
        const std::vector<T>& operator[](int index) const{
                return table[index];
        }
        const std::pair<T, T> Size() const{
                return std::make_pair(row_, col_);
        }
        void Resize(size_t row, size_t column){
                table.resize(row);
                for(auto &elements: table){
                        elements.resize(column);
                }
                row_ = row;
                col_ = column;
        }
private:
        size_t row_, col_;
        std::vector<std::vector<T>> table;
};

int main(){
        Table<int> table(10,10);
        std::cout << table.Size().first << " " <<  table.Size().second;
        return 0;
}

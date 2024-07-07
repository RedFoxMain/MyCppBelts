#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <vector>

template<typename T>
class Deque{
public:
        Deque() = default; // Дефолтный конструктор
        bool Empty() const{ // Пуста ли очередь
                return front_part.empty() || back_part.empty();
        }
        int Size() const{ // Длина очереди
                return front_part.size()+back_part.size();
        }
        void PushFront(T element){ // Вставить элемент вперёд
                front_part.insert(front_part.begin(), element);
        }
        void PushBack(T element){ // Вставить элемент назад
                back_part.push_back(element);
        }
        // At
        T& At(size_t index){ // Получить элемент по индексу
                if(index >= front_part.size()+back_part.size()){
                        throw std::out_of_range("Большой индекс");
              }
                if(index < front_part.size()){
                        return front_part[front_part.size()-index];
                }else{
                        return back_part[index-front_part.size()];
                }
        }
        const T& At(size_t index) const{
                if(index >= front_part.size()+back_part.size()){
                        throw std::out_of_range("Большой индекс");
                }
                if(index < front_part.size()){
                        return front_part[front_part.size()-index];
                }else{
                        return back_part[index-front_part.size()];
                }
        }
        // Front и Back
        T& Front(){
                return front_part.front();
        }
        T& Back(){
                return back_part.back();
        }
        const T& Front() const{
                return front_part.front();
        }
        const T& Back() const{
                return back_part.back();
        }
        // перегрузка []
        T& operator[](size_t index){
           if (index < front_part.size()) {
              return front_part[front_part.size() - 1 - index];
           }
       	return back_part[index - front_part.size()];
        }
        const T& operator[](size_t index) const{
            if (index < front_part.size()) {
              return front_part[front_part.size() - 1 - index];
       	 }
       	 return front_part[index - front_part.size()];
        }
private:
        std::vector<T> front_part;
        std::vector<T> back_part;
};

int main(){
        Deque<int> deq;
        deq.PushBack(1);
        deq.PushFront(2);
        deq.PushBack(3);
        deq.PushFront(8);
        std::cout << "Empty: " << deq.Empty() << std::endl;
        std::cout << "Size: " << deq.Size() << std::endl;
        std::cout << "Элемент: " << deq.At(2) << std::endl;
        std::cout << "Первый: " << deq.Front() << std::endl;
        std::cout << "Последний: " << deq.Back() << std::endl;
}
#include <iostream>
#include <vector>
#include <algorithm>

enum State{ QUIET, WORRY }; // состояние

using Queue = std::vector<State>; // очередь(вектор)

void Worry(Queue &queue){
	int index;
    std::cin >> index;
    queue[index] = State::WORRY;
}

void Quiet(Queue &queue){
	int index;
    std::cin >> index;
    queue[index] = State::QUIET;
}

void Come(Queue &queue){
	int index, curr_index=0;
    std::cin >> index;
    if(index > 0){
	    for (size_t i = 0; i < index; ++i){ queue.push_back(State::QUIET); }
	    for (auto it = queue.begin(); it != queue.end(); ++it) {
	        if (*it == State::QUIET) {
	            queue.erase(it);
	            --index;
	            --it;
	            
	            if (index == 0) {
	                break;
	            }
	        }
	    }
    }else{
    	std::rotate(queue.begin(), queue.end()+index, queue.end());
    }
}

int WorryCount(Queue &queue){
	return count(queue.begin(), queue.end(), State::WORRY);
}

int main(){
        Queue queue;
        std::string command;
        int Q, k;
        std::cout << "Сколько людей в очереди: ";
        std::cin >> Q;
        for (size_t i = 0; i < Q; ++i){ queue.push_back(State::QUIET); }
        std::cout << "Сколько команд: ";
        std::cin >> k;
        for (size_t i = 0; i < k; ++i){
        	std::cin >> command;
        	if(command == "WORRY"){ Worry(queue); }
        	if(command == "QUIET"){ Quiet(queue); }
        	if(command == "COME"){ Come(queue); }
        	if(command == "WORRY_COUNT"){ std::cout << WorryCount(queue) << std::endl; }
        	for (size_t i = 0; i < queue.size(); ++i){ std::cout << queue[i] << " "; }
        	std::cout << std::endl;
        
        }
}
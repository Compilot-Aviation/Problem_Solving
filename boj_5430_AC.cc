#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <deque>

void test(std::deque<int> deque, std::queue<char> instruction) {
    bool direction = true;
    while(!instruction.empty()) {
        if(!deque.empty()){
        char c = instruction.front();
        instruction.pop();
        if(c == 'R') {
            direction = !direction;
        }
        if(c == 'D') {
            if(direction == true) {
                deque.pop_front();
            }else{
                deque.pop_back();
            }
        }
    } else{
        std::cout << "error";
    }
    }
    std::string str="[";
    while(!deque.empty()){
        if(direction){
            str += deque.front();
            str += ","; 
            deque.pop_front();
        }else{
            str += deque.back();
            str += ","; 
            deque.pop_back();
        }
    }
    str.back() = ']';
    std::cout << str;
}

int main() {
    int tc;
    std::string instructor;
    std::queue<char> instruction;
    int sizeOfArr;
    std::string arr;
    std::deque<int> deque;
    std::cin >> tc;
    for(int i = 0 ; i < tc ; i++){
        std::cin >> instructor;
        for(int j = 0 ; j < instructor.size() ; j ++){
            instruction.push(instructor.at(j));
        }
        std::cin >> sizeOfArr;
        std::cin >> arr;
        arr.erase(std::remove_if(arr.begin(), arr.end(), 
          [](char c) { return c == '[' || c == ']' || c == ','; }),
          arr.end());
        for(int j = 0 ; j < arr.size() ; j ++){
            deque.push_back(arr.at(j));
        }
        test(deque, instruction);
    }
}
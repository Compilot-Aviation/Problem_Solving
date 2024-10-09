#include <iostream>
#include <vector>
const int dx[8]{-1,0,1,-1,1,-1,0,1};
const int dy[8]{1,1,1,0,0,-1,-1,-1};
std::vector<std::pair<int,int>> coorder;
bool board[15][15];


int count(std::vector<bool> visited, int count) {
    bool ret = true;
    int index = 0;
    
    while(visited.at(index)) {
        index++;
    }
    
    if(index + 1 == visited.size()) {
        return count;
    }



}

int main() {

}

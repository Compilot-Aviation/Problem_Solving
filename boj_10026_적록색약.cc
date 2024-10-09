#include <iostream>
#include <queue>

char board[100][100];
char boardForColorBlindness[100][100];
const int dx[4] = {-1,1,0,0};
const int dy[4] = {0,0,-1,1};
std::queue<std::pair<int,int>> queue;

bool checkBound(int x, int y, int N) {
    bool ret = true;
    if(x<0 || x >= N || y < 0 || y >= N) {
        ret = false;
    }
    return ret;
}

int findSectorbb(char c, int size){
    int count = 0;
    for(int i = 0 ; i < size ; i ++) {
        for(int j = 0 ; j < size ; j ++) {
            if(boardForColorBlindness[i][j] == c){
                queue.push({i,j});
                while(!queue.empty()) {
                    int x = queue.front().first;
                    int y = queue.front().second;
                    for(int k = 0 ; k < 4; k ++) {
                     if(checkBound(x+dx[k],y+dy[k],size)){
                        if(boardForColorBlindness[x+dx[k]][y+dy[k]] == c){
                            queue.push({x+dx[k], y+dy[k]});
                        }
                    }
                }
                boardForColorBlindness[x][y] = 'X';
                queue.pop();
                }
                count++;
            }
        }
    }
    return count;
}

int findSectorb(char c, int size){
    int count = 0;
    for(int i = 0 ; i < size ; i ++) {
        for(int j = 0 ; j < size ; j ++) {
            if(board[i][j] == c){
                queue.push({i,j});
                while(!queue.empty()) {
                    int x = queue.front().first;
                    int y = queue.front().second;
                    for(int k = 0 ; k < 4; k ++) {
                     if(checkBound(x+dx[k],y+dy[k],size)){
                        if(board[x+dx[k]][y+dy[k]] == c){
                            queue.push({x+dx[k], y+dy[k]});
                        }
                    }
                }
                board[x][y] = 'X';
                queue.pop();
                }
                count++;
            }
        }
    }
    return count;
}

int main() {
    int size;
    std::cin >> size;
    for(int i = 0 ; i < size; i ++) {
        for(int j = 0 ; j < size ; j ++) {
            char input;
            std::cin >> input;
            board[i][j] = input;
            boardForColorBlindness[i][j] = input;
            if(input == 'R') {
                boardForColorBlindness[i][j] = 'G';
            }
        }
    }
    int br = findSectorb('R',size);
    int bg = findSectorb('G',size);
    int bb = findSectorb('B',size);
    int bbG = findSectorbb('G', size);
    int bbB = findSectorbb('B', size);
    std::cout<<br+bg+bb<<" "<<bbG+bbB;
    
}


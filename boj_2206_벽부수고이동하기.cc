#include <iostream>
#include <vector>
#include <queue>

const int dx[4]{-1,1,0,0};
const int dy[4]{0,0,-1,1};

std::queue<std::pair<int, int>> queue;
int board[1000][1000] = {-1,};

int checkBound(int i, int j, int N, int M) {
    bool ret = true;
    if(i >= N || i < 0 || j >=M || j < 0) {
        ret = false;
    }
    return ret;
}

int DFS(int N, int M, bool cond) {
    int curX = 0;
    int curY = 0;
    int ret = 0;
    queue.push({curX,curY});

    while(!queue.empty()) {
     if(curX == N && curY == M) {
      return ret;
     }
     for(int i = 0 ; i < 4 ; i ++) {
        if(checkBound(curX+dx[i], curY+dy[i], N, M)){
            if(board[curX + dx[i]][curY + dy[i]] == 0) {

            }
        }
     }
    
    };
}




int main() {
    int x,y;
    std::cin >> y >> x;

    for(int i = 0 ; i < y ; i ++) {
        for(int j = 0 ; j < x ; j ++) {
            std::cin >> board[i][j];
        }
    }

}


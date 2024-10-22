#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

const int dx[4]{-1,0,0,1};
const int dy[4]{0,-1,1,0};

bool accessBoard[4][10] = {false, };

std::vector<int> sumList;

bool checkBound(int y, int x, std::vector<std::vector<int>> board) {
  bool ok = true;
  if(y>=board.size() || y < 0 || x >= board[0].size() || x < 0) {
    ok = false;
  }
  if(accessBoard[y][x]) {
    ok = false;
  }  
  return ok;
}

void bfs(int y, int x, std::vector<std::vector<int>> board, int count, int sum) {
 accessBoard[y][x] = true;
 if(count == 4) {
    sumList.push_back(sum+board[y][x]);
    accessBoard[y][x] = false;
    return;
 }
 for(int i = 0 ; i < 4 ; i ++) {
  const int ny = y+dy[i];
  const int nx = x+dx[i];
  if(checkBound(ny, nx, board)) {
    bfs(ny, nx ,board, count+1, sum + board[y][x]);
  }
 }
 accessBoard[y][x] = false;
}

int findMax(std::vector<int> list) {
    int max = -1;
    for(int i : list) {
        max = std::max(max, i);
    }
    return max;
} 

int main(){
    int y, x;
    std::cin >> y >> x;
    std::vector<std::vector<int>> board(y, std::vector<int>(x));
    for(int i = 0 ; i < y ; i ++) {
     for(int j = 0 ; j < x; j ++) {
        std::cin >>board[i][j];
     }
    }
    
    for(int i = 0 ; i < y ; i ++) {
     for(int j = 0 ; j < x; j ++) {
        bfs(i,j,board,1,0);
     }
    }
    std::cout << findMax(sumList);


}
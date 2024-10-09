#include <iostream>
#include <queue>

#define D 4

const int dx[D] = {0,0,1,-1};
const int dy[D] = {-1,1,0,0};
int garrage[1000][1000]={{-1,}};
std::queue<std::pair<int, int>> coordinate;



bool checkBound(int x , int y, int N, int M) {
    if(x < 0 || x >= N || y < 0 || y >= M) {
        return false;
    }

    return true;
}

void BFS(int numberOfZero, int N, int M) {
    int count = 0; 
    while(numberOfZero!=0){ 
     if(coordinate.empty()) {
      std::cout <<-1;
      return;
     }
     int size = coordinate.size();
     while(size != 0){
        int nodeY = coordinate.front().first;
        int nodeX = coordinate.front().second;
        for(int i = 0 ; i < D ; i ++) {
            if(checkBound(nodeX+dx[i],nodeY+dy[i], N, M)) {
                if(garrage[nodeY+dy[i]][nodeX+dx[i]]==0) {
                    coordinate.push({nodeY+dy[i], nodeX+dx[i]});
                    garrage[nodeY+dy[i]][nodeX+dx[i]] = 1;
                    numberOfZero--;
                }
            }
        }
        coordinate.pop();
        size--;
     }
        count++;
    }
    std::cout << count;
}



int main() {
    int N, M;
    int numberOfZero = 0;
    std::cin >> N >> M;

    for(int y = 0 ; y < M ; y++) {
        for(int x = 0 ; x < N ; x++){
            std::cin >> garrage[y][x];

            if(garrage[y][x] == 0) {
                numberOfZero++;
            } 
            if(garrage[y][x] == 1) {
                coordinate.push({y,x});
            }
        }
    }
    BFS(numberOfZero,N,M);
}




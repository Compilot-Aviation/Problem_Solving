#include<iostream>
const int dx[3]{0,1,1};
const int dy[3]{1,0,1};
int paper [5][2] = {{1},{2},{3},{4},{5}};
int board[10][10];
bool visited[10][10];

int checkSize(int i, int j) {
    int size=0;
    if(board[i][j]==1){
        if(visited[i][j] = false){
            size++;
            visited[i][j] = true;
        }
        
    }
}  

bool checkBound(int i , int j) {
    bool ret = true;
    if(i>=10||j>=10){
        ret = false;
    }
    return ret;
}        
    
    

int cover(){
    int ret = 0;
    for(int i =0; i<10; i++) {
        for(int j = 0; j < 10 ; j++) {
            if(board[i][j]==1) {
                int size = checkSize(i,j);
                for(int a=0;a <size;a++){
                    board[i+a][j+a] = 0;
                }
                ret++;
        }
    }
}
return ret;
}

int main() {
    for(int i = 0; i <10; i++) {
        for(int j = 0 ; j < 10 ; j ++) {
            std::cin >> board[i][j];
        }
    }
    std::cout << cover();
     
}
#include <iostream>

char board[6561][6561];

void setBoard(int y, int x, int size){
 if(size == 3) {
    setBase(y,x);
    return;
 }
 int dn = size/3;
 setBoard(y,x,dn);
 setBoard(y,x+dn,dn);
 setBoard(y,x+2*dn,dn);
 setBoard(y+dn,x,dn);
 setNull(y+dn,x+dn,dn);
 setBoard(y+dn,x+2*dn,dn);
 setBoard(y+2*dn,x,dn);
 setBoard(y+2*dn,x+dn,dn);
 setBoard(y+2*dn,x+2*dn,dn);
}

void setNull(int y , int x, int size) {
    for(int i = y ; i < y+size ; i++) {
        for(int j = x; j<x+size; j++) {
            board[i][j] = ' ';
     }
    }
}

void setBase(int y, int x) {
    for(int i = y ; i < y+3 ; i++) {
        for(int j = x ; j < x+3 ; j++) {
            board[i][j] = '*';
        }
    }
    board[y+1][x+1] = ' ';
}

int main() {
    int size;
    std::cin >> size;
    
    for(int y = 0 ; y < size ; y++ ) {
        for(int x = 0 ; x < size ; x++) {
            std::cout << board[y][x];
        }
    }
}
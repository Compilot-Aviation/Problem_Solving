#include <iostream>
#include <string>
#include <math.h>

int board[64][64];
std::string quadTree="";

bool checkStatus(int y, int x, int size){
 int count = 0;
 for(int i = y ; i<y+size; i++) {
    for(int j = x; j < x+size ; j ++) {
        count+=board[i][j];
    }
 }
 if(count == 0 || count == pow(size,2)){
    return true; // 0 or 1 이면 참.
 }
 return false;
}

void quadTreeMaker(int y, int x, int size) {
 if(checkStatus(y,x,size)) {
  quadTree+=std::to_string(board[y][x]);
  return;
 } else{
   quadTree+="(";
   int half = size/2;
   quadTreeMaker(y,x,half);
   quadTreeMaker(y,x+half,half);
   quadTreeMaker(y+half,x,half);
   quadTreeMaker(y+half,x+half,half);
   quadTree+=")";
 }

}

int main() {
   int size;
   std::cin >> size;
   for(int y = 0 ; y < size ; y++) {
      for(int x= 0 ; x < size ; x++) {
         char c;
         std::cin >> c;
         board[y][x] = c - '0';
      }
   }
   quadTreeMaker(0,0,size);
   std::cout << quadTree;
}
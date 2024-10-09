#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

const int dx[4]{-1,0,0,1};
const int board[500][500];

int findMaxNumBlueRot0(int N, int M){
    int max = 0;
    for(int i = 0; i < N; i ++){
        for(int j = 0; j < M-3 ; j ++) {
            int sum = 0;
            for(int k = 0 ; k < 4; k ++) {
                sum += board[i][j+k];
            }
            max>sum? max=max:max=sum;
        }
    }
}
int findMaxNumBlueRot1(int N, int M){
    int max = 0;
    for(int i = 0; i < N-3; i ++){
        for(int j = 0; j < M ; j ++) {
            int sum = 0;
            for(int k = 0 ; k < 4; k ++) {
                sum += board[i+k][j];
            }
            max>sum? max=max:max=sum;
        }
    }
}

int findMaxNumYellowRot1(int N, int M){
    int max = 0;
    for(int i = 0; i < N-1; i ++){
        for(int j = 0; j < M-1 ; j ++) {
            int sum = 0;
            sum = board[i][j]+board[i+1][j]+board[i][j+1]+board[i+1][j+1];
            max>sum? max=max:max=sum;
        }
    }
}
int main{

}
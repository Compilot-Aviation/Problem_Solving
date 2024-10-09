#include<iostream>
#include<math.h>

int findQuadrant(int N,int & x,int & y){ //방문하는 사분면의 값을 얻어내는 함수.
 int ret = 0;
 int half = pow(2,N-1);
 if(half<=x) {
    ret+=1;
    x-=half;
 }
 if(half<=y) {
    ret+=2;
    y-=half;
 }
 return ret;
}

int findTraversalOrder(int N, int x, int y) { // 재귀적으로 방문할 순서를 알아내는 함수.
    int ret = findQuadrant(N,x,y);  // 우선 해당 사분면의 위치를 알아낸다. basecase이건, 아니건 동일하게 수행해야하는 과정임.
 if(N==1){
    return ret;
 } else {
    ret = ret*pow(4,N-1);
    return ret+findTraversalOrder(N-1,x,y);
 }
}

int main() {
    int N, x , y;

    std::cin >> N >> y >> x ;
    std::cout << findTraversalOrder(N,x,y);
}
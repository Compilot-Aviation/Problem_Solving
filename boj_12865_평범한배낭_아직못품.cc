#include <iostream>
#include <vector>

std::vector<int> bag;
void makeBag (std::vector<std::pair<int, int>> list, int maxWeight, int wcount, int vcount, int index) {
    if(list.empty()){
        return;
    }

    for(int i = index ; i < list.size(); i++){
        if(maxWeight >= wcount+list[i].first){
        wcount += list[i].first;
        vcount += list[i].second;
        bag.push_back(vcount);
        makeBag(list, maxWeight, wcount, vcount, i+1);
        wcount-= list[i].first;
        vcount -= list[i].second;
        }
    }
}

int findMax(std::vector<int> bag) {
    int max = -1 ;
    for(int i : bag) {
        if(max < i) {
            max = i;
        }
    }
    return max;
}

int main() {
    std::vector<std::pair<int, int>> list;
    int N, K;
    std::cin >> N >> K;
    for(int i = 0 ; i < N ; i ++) {
        int a,b;
        std::cin >> a >> b;
        list.push_back({a,b}); 
    }
    makeBag(list, K, 0,0,0);
    std::cout << findMax(bag);
} 
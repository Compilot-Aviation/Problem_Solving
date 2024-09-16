#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

std::vector<char> vowel {'a','e','i','o','u'};

bool conditionChecker(std::string s) {
    int counter;
    for(int i = 0 ; i < s.size(); i++) {
        for(int j = 0 ; j < vowel.size() ; j++) {
            if(s.at(i) == vowel.at(j)) counter++;
        }
    }
    if(counter<=0 || s.size()-counter < 2) {
        return false;
    }
    return true;
}

std::string stringPrinter(std::vector<char>& list, int L, std::string s, int starter){
    if(s.size() == L) {
        if(conditionChecker(s)) {
            std::cout << s << endl;
        }
        return s;
    }
    for(int i = starter ; i < list.size()-(L-s.size())+1; i++) {
      stringPrinter(list, L, s+list.at(i), ++starter);
    }
    return s;
}




int main(){
    int L,C;
    std::cin>> L >> C;
    std::vector<char> list;
    for(int i = 0 ; i < C ; i++) {
        char tmp;
        std::cin >> tmp;
        list.push_back(tmp);
    }
    sort(list.begin(), list.end());
    std::string s = "";
    stringPrinter(list, L, s, 0);

}



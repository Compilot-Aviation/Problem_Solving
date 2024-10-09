#include<iostream>
#include<vector>
#include<string>
#include<math.h>

std::vector<std::string> candidate;

void makeString(std::string s, const std::vector<char> & v) { //주어진 벡터로 문자열(숫자채널 만듦)
  if (v.size() == 0) {
    return;
  }

  if (s.size() == 6) {
    return;
  }

  for (char c : v) {
    s.push_back(c);
    candidate.push_back(s);
    makeString(s, v);
    s.pop_back();
  }
}

int findMin(int ch) {
    if (candidate.empty()) {
        return INT32_MAX; // 사용할 수 있는 숫자 조합이 없으면 큰 값 반환
    }

    int minClicks = INT32_MAX;
    for (const auto& num : candidate) {
        int val = stoi(num);
        int clicks = abs(val - ch) + num.size();  // 차이값 + 숫자 길이
        minClicks = std::min(minClicks, clicks);
    }
    return minClicks;
}

int findupdown(int ch) { // 목표채널을 업 다운 버튼으로만 계산함.
  return abs(ch-100);
}

int main() {
  std::string chan;
  int remoteNum[10]{0,1,2,3,4,5,6,7,8,9};
  std::vector<char> unbroken;
  int num;
  std::cin>> chan >> num;

  for(int i = 0; i < num; i++) {
    int input = 0;
    std::cin >> input;
    remoteNum[input] = 10;
  }

  for(int i = 0 ; i < 10 ; i ++) {
    if(remoteNum[i] != 10) {
      unbroken.push_back(static_cast<char>('0' + i)); // CPP가 DINAMIC CAST 되므로 
    }
  }

  makeString("", unbroken);
  
  int x = chan.size();
  std::cout << std::min(findMin(stoi(chan)),findupdown(stoi(chan)));
}
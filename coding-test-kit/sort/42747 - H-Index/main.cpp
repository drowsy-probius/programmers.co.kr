#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
  int answer = 0;

  sort(citations.begin(), citations.end(), greater<int>());




  return answer;
}


#include <iostream>
#include <cassert>
int main(){
  assert(solution({3, 0, 6, 1, 5}) == 3);

  assert(solution({0, 0, 0, 0, 0}) == 0);
  assert(solution({1}) == 1);
  assert(solution({0}) == 0);
  assert(solution({9, 10, 11}) == 3);
  assert(solution({0, 1, 9, 10, 11}) == 3);
  assert(solution({1, 3, 5, 7}) == 3);
  return 0;
}
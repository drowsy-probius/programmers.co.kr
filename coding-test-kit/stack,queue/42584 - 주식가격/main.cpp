#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
  vector<int> answer;
  for(int i=0; i<prices.size(); i++)
  {
    answer.push_back(prices.size() - 1 - i);
  }

  

  return answer;
}

#include <cassert>
#include <iostream>
int main(){
  // vector<int> test_case = solution({1,2,3,2,3});
  // vector<int> test_result = {4, 3, 1, 1, 0};
  // assert(test_case == test_result);

  // test_case = solution({1,2,3,4,5});
  // test_result = {4,3,2,1,0};
  // assert(test_case == test_result);
  
  // test_case = solution({5,4,3,2,1});
  // test_result = {0,0,0,0,0};
  // assert(test_case == test_result);

  vector<int> test_case = solution({1});
  vector<int> test_result = {0};
  assert(test_case == test_result);

  return 0;
}

/**
 * 
 * 
 * 
 */
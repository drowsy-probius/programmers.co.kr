#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

vector<string> split(string input, string delimiter)
{
  vector<string> result;

  char* token = strtok((char*)input.c_str(), delimiter.c_str());
  while(token != NULL)
  {
    result.push_back(token);
    token = strtok(NULL, delimiter.c_str());
  }

  return result;
}

vector<int> solution(vector<string> operations) {
  vector<int> answer;

  /**
   * multiset으로 하면 더 편함.
   */
  vector<int> list;

  for(string operation : operations)
  {
    /**
     * 굳이 split함수 구현 안해도
     * string.substr(start, end)로 할 수 있음. 
     */
    vector<string> commands = split(operation, " ");

    /**
     * string에 stoi함수 있음.
     */
    int value = atoi(commands[1].c_str());

    if(commands[0] == "I")
    {
      list.push_back(value);
    }
    else if(commands[0] == "D")
    {
      if(list.empty())
      {
        continue;
      }

      if(value == -1)
      {
        /**
         * exactly max(N-1, 0) comparions
         * https://en.cppreference.com/w/cpp/algorithm/min_element
         */
        auto del = min_element(list.begin(), list.end());
        list.erase(del);
      }
      else if(value == 1)
      {
        auto del = max_element(list.begin(), list.end());
        list.erase(del);
      }
    }
  }

  if(list.empty())
  {
    answer.push_back(0);
    answer.push_back(0);
  }
  else
  {
    auto max = max_element(list.begin(), list.end());
    auto min = min_element(list.begin(), list.end());
    answer.push_back(*max);
    answer.push_back(*min);
  }
  

  return answer;
}


#include<iostream>
#include <cassert>
int main(){
  vector<int> test_result;

  test_result = {0, 0};
  assert(solution({"I 16", "D 1"}) == test_result);

  test_result = {7, 5};
  assert(solution({"I 7", "I 5", "I -5", "D -1"}) == test_result);

  test_result = {0, 0};
  assert(solution({"I 1", "I 2", "I 3", "I 4", "D 1", "D 1", "D -1", "D -1"}) == test_result);

  test_result = {0, 0};
  assert(solution({"D 1", "D -1"}) == test_result);

  cout << "OK" << '\n';
  return 0;
}


/**
정확성  테스트
테스트 1 〉	통과 (0.02ms, 3.95MB)
테스트 2 〉	통과 (0.02ms, 3.96MB)
테스트 3 〉	통과 (0.02ms, 3.94MB)
테스트 4 〉	통과 (0.02ms, 3.94MB)
테스트 5 〉	통과 (0.02ms, 3.96MB)
테스트 6 〉	통과 (0.02ms, 3.94MB)

채점 결과
정확성: 100.0
합계: 100.0 / 100.0
 */
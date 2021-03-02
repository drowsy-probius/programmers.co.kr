#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
  vector<int> answer;
  
  for(vector<int> command : commands)
  {
    vector<int> partial_array;
    int start = command[0];
    int end = command[1];
    int k = command[2];

    for(int i=start - 1; i<end; i++)
    {
      partial_array.push_back(array[i]);
    }

    sort(partial_array.begin(), partial_array.end());

    answer.push_back(partial_array.at(k - 1));
  }

  return answer;
}


#include <iostream>
#include <cassert>
int main(){
  vector<int> test_result;

  test_result = {5, 6, 3};
  assert(solution({1, 5, 2, 6, 3, 7, 4}, {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}}) == test_result);
  return 0;
}

/**
정확성  테스트
테스트 1 〉	통과 (0.01ms, 3.77MB)
테스트 2 〉	통과 (0.01ms, 3.96MB)
테스트 3 〉	통과 (0.01ms, 3.96MB)
테스트 4 〉	통과 (0.01ms, 3.96MB)
테스트 5 〉	통과 (0.01ms, 3.95MB)
테스트 6 〉	통과 (0.01ms, 3.96MB)
테스트 7 〉	통과 (0.01ms, 3.93MB)

채점 결과
정확성: 100.0
합계: 100.0 / 100.0
 */
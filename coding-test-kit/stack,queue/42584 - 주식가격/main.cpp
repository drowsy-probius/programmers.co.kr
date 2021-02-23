#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
  vector<int> answer;
  
  /**
   * 스택에는 증가하는 가격의 인덱스만 저장
   * 만족하고자 하는 특성: 이 스택에 있는 인덱스는 항상 가격이 떨어지지 않음
   * 
   * 만약 top의 인덱스의 가격이 새로 들어오는 인덱스의 가격보다 크면 (지금 감소하는 중이면)
   * top의 인덱스의 가격이 떨어지지 않은 기간은 (새로 들어오는 인덱스 - top의 인덱스)가 된다.
   * 
   * top의 인덱스의 가격이 새로 들어오는 인덱스의 가격보다 작거나 같을 때까지 반복
   * 
   */ 
  stack<int> incresement_stack;
  int prices_idx = 0;

  answer.resize(prices.size(), 0);
  incresement_stack.push(prices_idx);
  prices_idx++;

  while(prices_idx < prices.size())
  {

    while(!incresement_stack.empty() && prices[incresement_stack.top()] > prices[prices_idx])
    {
      int top_idx = incresement_stack.top();
      incresement_stack.pop();
      answer[top_idx] = prices_idx - top_idx;
    }

    incresement_stack.push(prices_idx);
    prices_idx++;
  }

  while(!incresement_stack.empty())
  {
    int top_idx = incresement_stack.top();
    incresement_stack.pop();

    answer[top_idx] = prices_idx - top_idx - 1;
  }

  return answer;
}

#include <cassert>
#include <iostream>
int main(){
  vector<int> test_case;
  vector<int> test_result;

  test_case = solution({1, 2, 3, 2, 3});
  test_result = {4, 3, 1, 1, 0};
  assert(test_case == test_result);

  test_case = solution({1,2,3,4,5});
  test_result = {4,3,2,1,0};
  assert(test_case == test_result);
  
  test_case = solution({5,4,3,2,1});
  test_result = {1, 1, 1, 1, 0};
  assert(test_case == test_result);

  test_case = solution({1});
  test_result = {0};
  assert(test_case == test_result);

  return 0;
}

/** result
정확성  테스트
테스트 1 〉	통과 (0.01ms, 3.94MB)
테스트 2 〉	통과 (0.03ms, 3.96MB)
테스트 3 〉	통과 (0.17ms, 3.93MB)
테스트 4 〉	통과 (0.35ms, 3.98MB)
테스트 5 〉	통과 (0.23ms, 3.96MB)
테스트 6 〉	통과 (0.02ms, 3.96MB)
테스트 7 〉	통과 (0.14ms, 3.89MB)
테스트 8 〉	통과 (0.15ms, 3.93MB)
테스트 9 〉	통과 (0.02ms, 3.97MB)
테스트 10 〉	통과 (0.23ms, 3.91MB)

효율성  테스트
테스트 1 〉	통과 (26.64ms, 24.2MB)
테스트 2 〉	통과 (19.31ms, 18.9MB)
테스트 3 〉	통과 (30.15ms, 26.9MB)
테스트 4 〉	통과 (22.56ms, 21.3MB)
테스트 5 〉	통과 (15.61ms, 16.2MB)

채점 결과
정확성: 66.7
효율성: 33.3
합계: 100.0 / 100.0
 */
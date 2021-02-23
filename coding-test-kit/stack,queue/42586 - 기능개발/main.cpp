#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
  vector<int> answer;

  /**
   * 큐에서 작업을 꺼낼 때,
   * 제일 처음 원소보다 작거나 같은 것 까지만 꺼냄
   */ 
  queue<int> work_queue;

  for(int i=0; i<progresses.size(); i++)
  {
    work_queue.push(
      ceil( (100-progresses[i])/(double)speeds[i] )
    );
  }

  while(!work_queue.empty())
  {
    int numberReleased = 0;

    int functionReleased = work_queue.front();
    work_queue.pop();
    numberReleased += 1;

    while(!work_queue.empty() && work_queue.front() <= functionReleased)
    {
      work_queue.pop();
      numberReleased += 1;
    }

    answer.push_back(numberReleased);
  }

  return answer;
}


#include <iostream>
#include <cassert>
int main(){
  vector<int> test_input_1, test_input_2, test_output;

  test_input_1 = {93, 30, 55};
  test_input_2 = {1, 30, 5};
  test_output = {2, 1};
  assert(solution(test_input_1, test_input_2) == test_output);

  test_input_1 = {95, 90, 99, 99, 80, 99};
  test_input_2 = {1, 1, 1, 1, 1, 1};
  test_output = {1, 3, 2};
  assert(solution(test_input_1, test_input_2) == test_output);

  return 0;
}


/** 
42584와 비슷한 문제

정확성  테스트
테스트 1 〉	통과 (0.01ms, 3.96MB)
테스트 2 〉	통과 (0.01ms, 3.98MB)
테스트 3 〉	통과 (0.01ms, 3.96MB)
테스트 4 〉	통과 (0.02ms, 3.95MB)
테스트 5 〉	통과 (0.01ms, 3.97MB)
테스트 6 〉	통과 (0.01ms, 3.98MB)
테스트 7 〉	통과 (0.01ms, 3.98MB)
테스트 8 〉	통과 (0.01ms, 3.95MB)
테스트 9 〉	통과 (0.01ms, 3.94MB)
테스트 10 〉	통과 (0.01ms, 3.98MB)
테스트 11 〉	통과 (0.01ms, 3.9MB)

채점 결과
정확성: 100.0
합계: 100.0 / 100.0
 */
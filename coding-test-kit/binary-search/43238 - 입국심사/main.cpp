#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long passedPeople(long long currentTime, vector<int>& times)
{
  long long total = 0;
  for(int time: times)
  {
    total += currentTime/time;
  }
  return total;
}


long long solution(int n, vector<int> times) {
  long long answer = 0;
  int min_time = *min_element(times.begin(), times.end());
  int max_time = *max_element(times.begin(), times.end());
  long long left = (long long)n * min_time / times.size();
  long long right = (long long)n * max_time / times.size();
  long long currentTime = 0;
  long long people = 0;

  while(left <= right)
  {
    currentTime = (left + right)/2;
    people = passedPeople(currentTime, times);


    /**
      목표: 조건을 만족하는 최소 시간을 구하는 것
      현재 심사를 받은 사람들의 수가 목표 수보다 같거나 많을 때
      answer갱신, right 줄이기
     */
    if(people >= n)
    {
      answer = currentTime;
      right = currentTime - 1;
    }
    if(people < n)
    {
      left = currentTime + 1;
    }
  }
  
  return answer;
}


#include "cassert"
int main()
{
  assert(solution(1000000000, {1}) == 1000000000);
  assert(solution(6, {7, 10}) == 28);
  assert(solution(1, {1}) == 1);
  assert(solution(1234, {1, 2, 3, 4}));
  assert(solution(1000000000, {1000000000, 1000000}));
  return 0;
}

/**
정확성  테스트
테스트 1 〉	통과 (0.01ms, 3.84MB)
테스트 2 〉	통과 (0.02ms, 3.96MB)
테스트 3 〉	통과 (0.27ms, 3.89MB)
테스트 4 〉	통과 (23.25ms, 6.75MB)
테스트 5 〉	통과 (22.09ms, 6.82MB)
테스트 6 〉	통과 (18.29ms, 6.57MB)
테스트 7 〉	통과 (33.24ms, 6.76MB)
테스트 8 〉	통과 (32.37ms, 6.82MB)
테스트 9 〉	통과 (0.01ms, 3.79MB)

채점 결과
정확성: 100.0
합계: 100.0 / 100.0
 */
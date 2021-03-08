#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
  int answer = 0;

  int top = people.size() - 1;
  int bottom = 0;

  vector<int> sortedPeople = people;
  sort(sortedPeople.begin(), sortedPeople.end(), less<int>());

  while(bottom <= top)
  {
    int weightSum = 0;
    
    while(bottom <= top)
    {
      if(weightSum + sortedPeople[top] <= limit)
      {
        weightSum += sortedPeople[top];
        top--;
      }
      else if(weightSum + sortedPeople[bottom] <= limit)
      {
        weightSum += sortedPeople[bottom];
        bottom++;
      }
      else
      {
        break;
      } 
    }

    answer += 1;   
  }

  return answer;
}

#include "iostream"
#include "cassert"
int main()
{
  assert(solution({70, 50, 80, 50}, 100) == 3);
  assert(solution({70, 80, 50}, 100) == 3);

  assert(solution({10, 20, 30, 40, 20}, 50) == 3);
  assert(solution({20, 30, 10, 40}, 50) == 2);
  assert(solution({10, 10, 10, 10, 10}, 40) == 2);
  assert(solution({10, 10, 10, 10, 10}, 50) == 1);
  return 0;
}

/**
정확성  테스트
테스트 1 〉	통과 (0.22ms, 3.94MB)
테스트 2 〉	통과 (0.14ms, 3.95MB)
테스트 3 〉	통과 (0.16ms, 3.97MB)
테스트 4 〉	통과 (0.16ms, 3.98MB)
테스트 5 〉	통과 (0.09ms, 3.94MB)
테스트 6 〉	통과 (0.05ms, 3.83MB)
테스트 7 〉	통과 (0.08ms, 3.93MB)
테스트 8 〉	통과 (0.01ms, 3.95MB)
테스트 9 〉	통과 (0.02ms, 3.95MB)
테스트 10 〉	통과 (0.14ms, 3.84MB)
테스트 11 〉	통과 (0.14ms, 3.96MB)
테스트 12 〉	통과 (0.12ms, 3.82MB)
테스트 13 〉	통과 (0.16ms, 3.97MB)
테스트 14 〉	통과 (0.15ms, 3.96MB)
테스트 15 〉	통과 (0.02ms, 3.96MB)

효율성  테스트
테스트 1 〉	통과 (2.13ms, 5.05MB)
테스트 2 〉	통과 (1.85ms, 5.01MB)
테스트 3 〉	통과 (1.86ms, 4.74MB)
테스트 4 〉	통과 (1.60ms, 4.92MB)
테스트 5 〉	통과 (1.60ms, 4.65MB)

채점 결과
정확성: 75.0
효율성: 25.0
합계: 100.0 / 100.0
 */
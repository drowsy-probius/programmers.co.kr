#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
  int answer = 0;

  vector<int> currentHave(n, 1);
  for(int i : lost)
  {
    currentHave.at(i - 1)--;
  }

  for(int i : reserve)
  {
    currentHave.at(i - 1)++;
  }

  /**
   * 0번부터 체육복이 있으면 하나 사용하는 식으로 반복함.
   */
  for(int i=0; i<n; i++)
  {
    if(currentHave.at(i) >= 1)
    {
      currentHave.at(i)--;
      answer++;
    }
    else
    {
      int borrowFrom = -1;
      /**
       * 이전 번호 학생은 이미 체육복이 있으면 하나 사용했을 테니까
       * 1개 이상 있으면 빌려줄 수 있음.
       */
      if(i > 0 && currentHave.at(i-1) >= 1)
      {
        borrowFrom = i-1;
      }
      /**
       * 내 번호보다 뒤 학생은 아직 체육복을 사용하지 않은 상태니까
       * 2개 이상 있어야 빌려줄 수 있음.
       */
      else if(i < n-1 && currentHave.at(i+1) >= 2)
      {
        borrowFrom = i+1;
      }

      if(borrowFrom != -1)
      {
        currentHave.at(borrowFrom)--;
        answer++;
      }
    }
  }

  return answer;
}

#include "iostream"
#include "cassert"
int main()
{
  assert(solution(5, {2, 4}, {1, 3, 5}) == 5);
  assert(solution(5, {2, 4}, {3}) == 4);
  assert(solution(3, {3}, {1}) == 2);
  return 0;
}

/**
정확성  테스트
테스트 1 〉	통과 (0.01ms, 3.98MB)
테스트 2 〉	통과 (0.01ms, 3.83MB)
테스트 3 〉	통과 (0.01ms, 3.97MB)
테스트 4 〉	통과 (0.01ms, 3.95MB)
테스트 5 〉	통과 (0.02ms, 3.96MB)
테스트 6 〉	통과 (0.01ms, 3.96MB)
테스트 7 〉	통과 (0.01ms, 3.95MB)
테스트 8 〉	통과 (0.01ms, 3.96MB)
테스트 9 〉	통과 (0.01ms, 3.97MB)
테스트 10 〉	통과 (0.01ms, 3.82MB)
테스트 11 〉	통과 (0.01ms, 3.96MB)
테스트 12 〉	통과 (0.01ms, 3.78MB)

채점 결과
정확성: 100.0
합계: 100.0 / 100.0
 */
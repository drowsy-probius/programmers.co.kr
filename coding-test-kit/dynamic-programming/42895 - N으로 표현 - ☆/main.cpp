#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int N, int number) {
  int answer = -1;

  if(number == N) return 1;

  /**
   * dp(i) : N을 i번 사용해서 만들 수 있는 숫자
   */
  vector<set<int>> dp(9);
  dp[0].insert(N);
  dp[1].insert(N);

  for(int i=2; i<=8; i++)
  {
    int rawNum = 0;
    for(int j=0; j<i; j++)
    {
      rawNum *= 10;
      rawNum += N;
    }

    if(number == rawNum) return i;
    dp[i].insert(rawNum);

    int firstIdx = 1;
    int secondIdx = i-1;

    while(firstIdx < i && secondIdx >= 1)
    {
      for(int first: dp[firstIdx])
      {
        for(int second: dp[secondIdx])
        {
          if(number == first + second) return i;
          dp[i].insert(first + second);

          if(number == first * second) return i;
          dp[i].insert(first * second);

          if(number == first - second) return i;
          dp[i].insert(first - second);

          if(number == second - first )return i;
          dp[i].insert(second - first);

          if(second != 0)
          {
            if(number == first / second) return i;
            dp[i].insert(first / second);
          }
          if(first != 0)
          {
            if(number == second / first) return i;
            dp[i].insert(second / first);
          }
        }
      }

      firstIdx++;
      secondIdx--;
    }

  }

  return answer;
}

#include "cassert"
int main()
{
  assert(solution(5, 12) == 4);
  assert(solution(2, 11) == 3);

  // https://programmers.co.kr/questions/13580
  assert(solution(5, 5) == 1);
  assert(solution(5, 10) == 2);
  assert(solution(5, 31168) == -1);
  assert(solution(1, 1121) == 7);
  assert(solution(5, 1010) == 7);
  assert(solution(3, 4) == 3);
  assert(solution(5, 5555) == 4);
  assert(solution(5, 5550) == 5);
  assert(solution(5, 20) == 3);
  assert(solution(5, 30) == 3);
  assert(solution(6, 65) == 4);
  assert(solution(5, 2) == 3);
  assert(solution(5, 4) == 3);
  assert(solution(1, 1) == 1);
  assert(solution(1, 11) == 2);
  assert(solution(1, 111) == 3);
  assert(solution(1, 1111) == 4);
  assert(solution(1, 11111) == 5);
  assert(solution(7, 7776) == 6);
  assert(solution(7, 7784) == 5);
  assert(solution(2, 22222) == 5);
  assert(solution(2, 22223) == 7);
  assert(solution(2, 22224) == 6);
  assert(solution(2, 11111) ==  6);
  assert(solution(2, 11) == 3);
  assert(solution(2, 111) == 4);
  assert(solution(2, 1111) == 5);
  assert(solution(9, 36) == 4);
  assert(solution(9, 37) == 6);
  assert(solution(9, 72) == 3);
  assert(solution(3, 18) == 3);
  assert(solution(2, 1) == 2);
  assert(solution(4, 27) == 5);
  return 0;
}

/**
정확성  테스트
테스트 1 〉	통과 (0.18ms, 3.97MB)
테스트 2 〉	통과 (0.01ms, 3.96MB)
테스트 3 〉	통과 (0.04ms, 3.86MB)
테스트 4 〉	통과 (16.50ms, 4.34MB)
테스트 5 〉	통과 (3.41ms, 3.96MB)
테스트 6 〉	통과 (0.08ms, 3.97MB)
테스트 7 〉	통과 (0.10ms, 3.97MB)
테스트 8 〉	통과 (5.12ms, 4.09MB)
테스트 9 〉	통과 (0.01ms, 3.96MB)

채점 결과
정확성: 100.0
합계: 100.0 / 100.0
 */
#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
  int answer = 0;

  vector<vector<int>> dp(n, vector<int>(m, -1));
  for(vector<int> puddle: puddles)
  {
    dp.at(puddle[1] - 1).at(puddle[0] - 1) = 0;
  }
  
  dp.at(0).at(0) = 1;

  for(int i=0; i<n; i++)
  {
    for(int j=0; j<m; j++)
    {
      if( (i==0 && j==0) || dp[i][j] == 0) continue;

      int leftValue = j-1 >= 0 ? dp[i][j-1] : 0;
      int upValue = i-1 >= 0 ? dp[i-1][j] : 0;

      dp[i][j] = ( leftValue + upValue ) % 1000000007;
    }
  }

  answer = dp[n-1][m-1];

  return answer;
}

#include "cassert"
int main()
{
  assert(solution(4, 3, {{2, 2}}) == 4);

  assert(solution(4, 3, {{3, 3}, {4, 2}}) == 0);
  assert(solution(10, 1, {}) == 1);
  assert(solution(1, 10, {}) == 1);
  assert(solution(1, 10, {{1, 3}}) == 0);
  assert(solution(4, 4, {}) == 20);

  // https://programmers.co.kr/questions/15698
  assert(solution(2, 2, {}) == 2);
  assert(solution(3, 3, {}) == 6);
  assert(solution(3, 3, {{2, 2}}) == 2);
  assert(solution(3, 3, {{2, 3}}) == 3);
  assert(solution(3, 3, {{1, 3}}) == 5);
  assert(solution(3, 3, {{1, 3}, {3, 1}}) == 4);
  assert(solution(3, 3, {{1, 3}, {3, 1}, {2, 3}}) == 2);
  assert(solution(3, 3, {{1, 3}, {3, 1}, {2, 3}, {2, 1}}) == 1);
  assert(solution(7, 4, {{2, 1}, {2, 2}, {2, 3}, {4, 2}, {4, 3}, {4, 4}, {6, 2}, {6, 3}}) == 0);
  assert(solution(4, 4, {{3, 2}, {2, 4}}) == 7);
  assert(solution(100, 100, {}) == 690285631);
  return 0;
}

/**
정확성  테스트
테스트 1 〉	통과 (0.01ms, 3.96MB)
테스트 2 〉	통과 (0.01ms, 3.91MB)
테스트 3 〉	통과 (0.01ms, 3.93MB)
테스트 4 〉	통과 (0.01ms, 3.96MB)
테스트 5 〉	통과 (0.01ms, 3.94MB)
테스트 6 〉	통과 (0.01ms, 3.96MB)
테스트 7 〉	통과 (0.01ms, 3.94MB)
테스트 8 〉	통과 (0.01ms, 3.91MB)
테스트 9 〉	통과 (0.01ms, 3.98MB)
테스트 10 〉	통과 (0.01ms, 3.94MB)

효율성  테스트
테스트 1 〉	통과 (0.06ms, 3.84MB)
테스트 2 〉	통과 (0.03ms, 3.94MB)
테스트 3 〉	통과 (0.03ms, 3.94MB)
테스트 4 〉	통과 (0.05ms, 3.91MB)
테스트 5 〉	통과 (0.04ms, 3.94MB)
테스트 6 〉	통과 (0.06ms, 3.95MB)
테스트 7 〉	통과 (0.04ms, 3.97MB)
테스트 8 〉	통과 (0.05ms, 3.94MB)
테스트 9 〉	통과 (0.05ms, 3.93MB)
테스트 10 〉	통과 (0.05ms, 3.78MB)

채점 결과
정확성: 50.0
효율성: 50.0
합계: 100.0 / 100.0
 */
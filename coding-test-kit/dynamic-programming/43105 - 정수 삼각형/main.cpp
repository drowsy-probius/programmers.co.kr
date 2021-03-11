#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
  int answer = 0;

  int triangleHeight = triangle.size();
  vector<vector<int>> dp(triangleHeight);
  for(int i=0; i<triangleHeight; i++)
  {
    dp.at(i).resize(i + 1);
  }
  dp.at(0).at(0) = triangle.at(0).at(0);

  for(int i=0; i<triangleHeight; i++)
  {
    for(int j=0; j<triangle.at(i).size(); j++)
    {
      int val1 = 0;
      int val2 = 0;

      if(i-1 >= 0)
      {
        if(j-1 >= 0)
        {
          val1 = dp[i-1][j-1];
        }

        if(j < triangle.at(i-1).size())
        {
          val2 = dp[i-1][j];
        }
      }

      dp[i][j] = max(val1, val2) + triangle[i][j];
    }
  }

  answer = *max_element(dp.at(triangleHeight - 1).begin(), dp.at(triangleHeight - 1).end());

  return answer;
}

#include "iostream"
#include "cassert"
int main()
{
  assert(solution({{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}}) == 30);
  return 0;
}

/**
정확성  테스트
테스트 1 〉	통과 (0.01ms, 3.91MB)
테스트 2 〉	통과 (0.01ms, 3.95MB)
테스트 3 〉	통과 (0.01ms, 3.92MB)
테스트 4 〉	통과 (0.01ms, 3.96MB)
테스트 5 〉	통과 (0.04ms, 3.96MB)
테스트 6 〉	통과 (0.03ms, 3.95MB)
테스트 7 〉	통과 (0.04ms, 3.95MB)
테스트 8 〉	통과 (0.04ms, 3.97MB)
테스트 9 〉	통과 (0.01ms, 3.94MB)
테스트 10 〉	통과 (0.01ms, 3.96MB)

효율성  테스트
테스트 1 〉	통과 (0.78ms, 8.09MB)
테스트 2 〉	통과 (0.54ms, 6.85MB)
테스트 3 〉	통과 (0.83ms, 8.68MB)
테스트 4 〉	통과 (0.83ms, 8.01MB)
테스트 5 〉	통과 (0.73ms, 7.81MB)
테스트 6 〉	통과 (0.90ms, 8.66MB)
테스트 7 〉	통과 (0.85ms, 8.41MB)
테스트 8 〉	통과 (0.73ms, 7.54MB)
테스트 9 〉	통과 (0.74ms, 7.89MB)
테스트 10 〉	통과 (0.84ms, 8.45MB)

채점 결과
정확성: 64.3
효율성: 35.7
합계: 100.0 / 100.0
 */
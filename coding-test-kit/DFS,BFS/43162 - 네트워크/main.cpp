#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
  int answer = 0;
  vector<bool> isVisited(computers.size(), false);
  queue<int> q;
  q.push(0);
  answer += 1;

  while(!q.empty())
  {
    int idx = q.front();
    q.pop();

    isVisited[idx] = true;
    for(int to=0; to<computers[idx].size(); to++)
    {
      if(computers[idx][to] == 1 && !isVisited[to])
      {
        q.push(to);
      }
    }

    if(q.empty())
    {
      for(int i=0; i<isVisited.size(); i++)
      {
        if(!isVisited[i])
        {
          q.push(i);
          answer += 1;
          break;
        }
      }
    }
  }

  return answer;
}

#include "cassert"
int main()
{
  assert(solution(3, {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}}) == 2);
  assert(solution(3, {{1, 1, 0}, {1, 1, 1}, {0, 1, 1}}) == 1);
  return 0;
}

/**
first code:

정확성  테스트
테스트 1 〉	통과 (0.01ms, 3.9MB)
테스트 2 〉	통과 (0.01ms, 3.95MB)
테스트 3 〉	통과 (0.02ms, 3.96MB)
테스트 4 〉	통과 (0.02ms, 3.96MB)
테스트 5 〉	통과 (0.01ms, 3.94MB)
테스트 6 〉	통과 (0.05ms, 3.92MB)
테스트 7 〉	통과 (0.01ms, 3.96MB)
테스트 8 〉	통과 (0.03ms, 3.95MB)
테스트 9 〉	통과 (0.02ms, 3.93MB)
테스트 10 〉	통과 (0.03ms, 3.96MB)
테스트 11 〉	통과 (0.18ms, 4.16MB)
테스트 12 〉	통과 (0.09ms, 3.96MB)
테스트 13 〉	통과 (0.05ms, 3.96MB)
채점 결과
정확성: 100.0
합계: 100.0 / 100.0
 */
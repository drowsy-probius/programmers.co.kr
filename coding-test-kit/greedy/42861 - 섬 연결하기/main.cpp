#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isConnectedFromTo(int start, int end, int n, vector<vector<bool>> isConnected)
{
  vector<bool> visited(n, false);
  vector<int> queue;
  queue.push_back(start);

  while(!queue.empty())
  {
    int idx = queue.front();
    queue.erase(queue.begin());

    if(idx == end)
    {
      return true;
    }

    visited[idx] = true;
    for(int i=0; i<n; i++)
    {
      if(!visited[i] && isConnected[idx][i])
      {
        queue.push_back(i);
      }
    }
  }

  return false;
}

int solution(int n, vector<vector<int>> costs) {
  int answer = 0;

  int count = 0;
  vector<vector<bool>> isConnected(n, vector<bool>(n, false));

  sort(costs.begin(), costs.end(), [](vector<int> a, vector<int> b){
    return a[2] < b[2];
  });
  
  for(vector<int> cost : costs)
  {
    int from = cost[0];
    int to = cost[1];

    if(!isConnectedFromTo(from, to, n, isConnected))
    {
      answer += cost[2];
      isConnected[from][to] = true;
      isConnected[to][from] = true;
      count++;
    }

    if(count == n)
    {
      break;
    }
  }

  return answer;
}

#include "cassert"
int main()
{
  assert(solution(4, {{0, 1, 1}, {0, 2, 2}, {1, 2, 5}, {1, 3, 1}, {2, 3, 8}}) == 4);
  assert(solution(5, {{0, 4, 1}, {1, 4, 2}, {2, 4, 3}, {3, 4, 4}, {0, 1, 9}, {1, 2, 3}, {0, 2, 5}, {1, 3, 10}}) == 10);
  return 0;
}

/**
정확성  테스트
테스트 1 〉	통과 (0.01ms, 3.93MB)
테스트 2 〉	통과 (0.01ms, 3.68MB)
테스트 3 〉	통과 (0.04ms, 3.97MB)
테스트 4 〉	통과 (0.08ms, 3.94MB)
테스트 5 〉	통과 (0.03ms, 3.93MB)
테스트 6 〉	통과 (0.14ms, 3.95MB)
테스트 7 〉	통과 (0.17ms, 3.95MB)
테스트 8 〉	통과 (0.02ms, 3.79MB)

채점 결과
정확성: 100.0
합계: 100.0 / 100.0
 */
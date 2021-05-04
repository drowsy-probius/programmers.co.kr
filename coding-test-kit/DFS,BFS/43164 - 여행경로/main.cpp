#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool doesAllUsed(vector<bool> used)
{
  bool done = true;
  for(bool v: used)
  {
    done = done && v;
  }
  return done;
}

bool dfs(int currentIdx, vector<string>& answer, vector<bool>& used, vector<vector<string>>& tickets)
{
  string current = currentIdx == -1 ? "ICN" : tickets[currentIdx][1];

  if(doesAllUsed(used))
  {
    answer.push_back(current);
    return true;
  }

  vector<pair<int, string>> nextAirports;
  for(int i=0; i<tickets.size(); i++)
  {
    if(used[i]) continue;
    if(current.compare(tickets[i][0]) != 0) continue;
    nextAirports.push_back(make_pair(i, tickets[i][1]));
  }

  sort(nextAirports.begin(), nextAirports.end(), [](auto a, auto b){return a.second < b.second;});

  for(auto airport: nextAirports)
  {
    used[airport.first] = true;
    if(dfs(airport.first, answer, used, tickets))
    {
      answer.push_back(current);
      return true;
    }
    used[airport.first] = false;
  }

  return false;
}

vector<string> solution(vector<vector<string>> tickets) {
  vector<string> answer;
  int ticketsLength = tickets.size();
  
  vector<bool> used(ticketsLength, false);

  dfs(-1, answer, used, tickets);
  reverse(answer.begin(), answer.end());

  return answer;
}

#include "cassert"
int main()
{
  vector<string> test_answer, test_output;

  test_answer = {"ICN", "JFK", "HND", "IAD"};
  test_output = solution({
    {"ICN", "JFK"},
    {"HND", "IAD"},
    {"JFK", "HND"}
  });
  assert(test_output == test_answer);

  test_answer = {"ICN", "ATL", "ICN", "SFO", "ATL", "SFO"};
  assert(solution({
    {"ICN", "SFO"},
    {"ICN", "ATL"}, 
    {"SFO", "ATL"},
    {"ATL", "ICN"},
    {"ATL", "SFO"}
  }) == test_answer);

  return 0;
}

/**
정확성  테스트
테스트 1 〉	통과 (0.04ms, 3.89MB)
테스트 2 〉	통과 (0.01ms, 3.96MB)
테스트 3 〉	통과 (0.01ms, 3.96MB)
테스트 4 〉	통과 (0.02ms, 3.96MB)

채점 결과
정확성: 100.0
합계: 100.0 / 100.0
 */
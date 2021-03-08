#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isOverlapped(vector<int> a, vector<int> b)
{
  if( (a[0] <= b[0] && b[0] <= a[1]) || (a[0] <= b[1] && b[1] <= a[1]) || 
      (b[0] <= a[0] && a[0] <= b[1]) || (b[0] <= a[1] && a[1] <= b[1]))
  {
    return true;
  }
  return false;
}

bool isAllInstalled(vector<bool> installed)
{
  for(bool f : installed)
  {
    if(f == false)
    {
      return false;
    }
  }
  return true;
}

int solution(vector<vector<int>> routes) {
  int answer = 0;

  int routesLength = routes.size();
  vector<bool> installed(routesLength, false);
  vector<pair<int, vector<int>>> routesWithIndex;

  for(int i=0; i<routesLength; i++)
  {
    routesWithIndex.push_back(make_pair(i, routes[i]));
  }

  // sort by length between entry and exit;
  sort(routesWithIndex.begin(), routesWithIndex.end(), [](pair<int, vector<int>> a, pair<int, vector<int>> b){
    return a.second[1] - a.second[0] < b.second[1] - b.second[0];
  });

  while(!isAllInstalled(installed))
  {
    pair<int, vector<int>> route = routesWithIndex.front();
    routesWithIndex.erase(routesWithIndex.begin());

    int idx = route.first;

    if(installed.at(idx))
    {
      continue;
    }

    installed.at(idx) = true;
    answer++;

    for(auto otherRoute: routesWithIndex)
    {
      if(isOverlapped(otherRoute.second, route.second))
      {
        installed.at(otherRoute.first) = true;
      }
    }
  }

  return answer;
}

#include "cassert"
int main()
{
  assert(solution({{-20, 15}, {-14, -5}, {-18, -13}, {-5, -3}}) == 2);

  assert(solution({{1, 10}, {2, 4}, {6, 8}}) == 2);
  assert(solution({{1, 20}, {2, 20}, {3, 20}, {4, 10}, {5, 6}}) == 1);
  assert(solution({{1, 2}, {3, 4}, {5, 6}, {7, 8}}) == 4);
  assert(solution({{1, 2}, {2, 3}, {3, 4}, {4, 5}}) == 2);
  return 0;
}

/**
 * 트리구조로 만들어서 leaf 노드 개수 세도 될 듯
 * 
 */
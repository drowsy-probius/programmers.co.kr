#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool inRange(int key, vector<int> route)
{
  return (key >= route[0] && key <= route[1]);
}

/**
 * 진출 지점으로 오름차순 정렬해도 되고
 * 진입 지점으로 내림차순 정렬해도 됨.
 */
int solution(vector<vector<int>> routes) {
  int answer = 0;

  int lastCameraPosition = __INT_MAX__;
  sort(routes.begin(), routes.end(), [](vector<int> a, vector<int> b){
    return a[0] > b[0];
  });

  for(int i=0; i<routes.size(); i++)
  {
    if(!inRange(lastCameraPosition, routes[i]))
    {
      answer++;
      lastCameraPosition = routes[i][0];
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
  assert(solution({{-10, 1}, {1, 5}, {5, 20}}) == 2);

  // https://programmers.co.kr/questions/16027
  assert(solution({{0,2},{2,3},{3,4},{4,6}}) == 2);
  assert(solution({ {-20, 15}, {-14, -5}, {-18, -13}, {-5, -3} }) == 2);
  assert(solution({ {-2, -1}, {1, 2}, {-3, 0} }) == 2);
  assert(solution({{0, 0}}) == 1);
  assert(solution({ {0, 1}, {0, 1}, {1, 2} }) == 1);
  assert(solution({ {0, 1}, {2, 3}, {4, 5}, {6, 7} }) == 4);
  assert(solution({ {-20, -15}, {-14, -5}, {-18, -13}, {-5, -3} }) == 2);
  assert(solution({ {-20, 15}, {-20, -15}, {-14, -5}, {-18, -13}, {-5, -3} }) == 2);
  assert(solution({ {2,2},{0,1},{-10,9} }) == 2);
  assert(solution({ {-7, 0}, {-6, -4}, {-5, -3}, {-3, -1}, {-1, 4}, {1, 2}, {3, 4} }) == 4);
  assert(solution({ {-5, -3}, {-4, 0}, {-4, -2}, {-1, 2}, {0, 3}, {1, 5}, {2, 4} }) == 2);
  assert(solution({ {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}, {7, 8}, {8, 9}, {9, 10}, {10, 11}, {11, 12}, {12, 13}, {13, 14}, {14, 15} }) == 8);
  assert(solution({ {0, 12}, {1, 12}, {2, 12}, {3, 12}, {5, 6}, {6, 12}, {10, 12} }) == 2);
  assert(solution({ {-191, -107}, { -184,-151 }, { -150,-102 }, { -171,-124 }, { -120,-114 } }) == 2);
  assert(solution({{0, 0}, {0, 0}, {2, 2}}) == 2);
  assert(solution({{0, 1}, {0, 1}, {2, 2}}) == 2);
  

  return 0;
}

/** 다시풀기
정확성  테스트
테스트 1 〉	통과 (0.04ms, 3.97MB)
테스트 2 〉	통과 (0.07ms, 3.86MB)
테스트 3 〉	통과 (0.04ms, 3.96MB)
테스트 4 〉	통과 (0.05ms, 3.97MB)
테스트 5 〉	통과 (0.06ms, 3.95MB)

효율성  테스트
테스트 1 〉	통과 (1.60ms, 4.05MB)
테스트 2 〉	통과 (0.96ms, 3.82MB)
테스트 3 〉	통과 (7.49ms, 3.95MB)
테스트 4 〉	통과 (0.13ms, 3.96MB)
테스트 5 〉	통과 (4.04ms, 4.02MB)

채점 결과
정확성: 50.0
효율성: 50.0
합계: 100.0 / 100.0
 */
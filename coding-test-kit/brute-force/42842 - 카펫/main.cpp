#include <string>
#include <vector>
#include <cmath>

using namespace std;

/**
 * 가로: x, 세로: y
 * brown = 2*(x + y - 2)
 * yellow = (x-2)(y-2) 
 */
vector<int> solution(int brown, int yellow) {
  vector<int> answer;

  int height = 3;
  int width = 3;

  while(true)
  {
    if(height*width == (brown + yellow) && brown == 2*(width + height - 2) && yellow == (width - 2)*(height - 2))
    {
      answer = {width, height};
      break;
    }

    if(height*width > (brown + yellow))
    {
      height++;
      width = height;
    }
    else
    {
      width++;
    }
  }

  return answer;
}

#include "iostream"
#include "cassert"
int main()
{
  vector<int> test_result;

  test_result = {4, 3};
  assert(solution(10, 2) == test_result);

  test_result = {3, 3};
  assert(solution(8, 1) == test_result);

  test_result = {8, 6};
  assert(solution(24, 24) == test_result);
  return 0;
}

/** brute-force
정확성  테스트
테스트 1 〉	통과 (0.01ms, 3.93MB)
테스트 2 〉	통과 (0.01ms, 3.96MB)
테스트 3 〉	통과 (8.54ms, 3.89MB)
테스트 4 〉	통과 (0.02ms, 3.96MB)
테스트 5 〉	통과 (0.03ms, 3.95MB)
테스트 6 〉	통과 (2.56ms, 3.95MB)
테스트 7 〉	통과 (11.01ms, 3.92MB)
테스트 8 〉	통과 (8.60ms, 3.96MB)
테스트 9 〉	통과 (10.92ms, 3.95MB)
테스트 10 〉	통과 (13.18ms, 3.96MB)
테스트 11 〉	통과 (0.01ms, 3.95MB)
테스트 12 〉	통과 (0.01ms, 3.95MB)
테스트 13 〉	통과 (0.01ms, 3.93MB)

채점 결과
정확성: 100.0
합계: 100.0 / 100.0
 */
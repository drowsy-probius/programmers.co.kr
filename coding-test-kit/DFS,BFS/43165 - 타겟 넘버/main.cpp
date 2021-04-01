#include <string>
#include <vector>

using namespace std;

void dfs(vector<int> numbers, int depth, int sum, int target, int* answer)
{
  if(depth == numbers.size())
  {
    if(sum == target)
    {
      *answer += 1;
    }
    return;
  }

  dfs(numbers, depth + 1, sum + numbers[depth], target, answer);
  dfs(numbers, depth + 1, sum - numbers[depth], target, answer);
}

int solution(vector<int> numbers, int target) {
  int answer = 0;

  dfs(numbers, 0, 0, target, &answer);

  return answer;
}

#include "cassert"
int main()
{
  assert(solution({1, 1, 1, 1, 1}, 3) == 5);
  return 0;
}

/**
 * 최적화 안함
정확성  테스트
테스트 1 〉	통과 (70.38ms, 3.94MB)
테스트 2 〉	통과 (70.43ms, 3.95MB)
테스트 3 〉	통과 (0.08ms, 3.97MB)
테스트 4 〉	통과 (0.31ms, 3.97MB)
테스트 5 〉	통과 (2.44ms, 3.98MB)
테스트 6 〉	통과 (0.14ms, 3.98MB)
테스트 7 〉	통과 (0.09ms, 3.98MB)
테스트 8 〉	통과 (0.56ms, 3.97MB)

채점 결과
정확성: 100.0
합계: 100.0 / 100.0 
 *
 * 
 */
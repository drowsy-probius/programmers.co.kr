#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
  int answer = 0;

  sort(citations.begin(), citations.end(), greater<int>());

  int maxCitation = citations.front();
  /**
   * citations가 정렬된 상태이므로
   * index + 1은 citations[index]보다 인용수가 많은 논문의 수로 계산할 수 있음.
   */
  int index = 0;
  while(maxCitation)
  {
    if(index + 1 >= maxCitation)
    {
      answer = maxCitation;
      break;
    }

    // 현재 인용 수가 다음으로 많이 인용된 수와 같으면
    if(index+1 < citations.size() && citations[index + 1] == maxCitation)
    {
      index++;
    }
    else
    {
      maxCitation--;
    }
    
  }


  return answer;
}


#include <iostream>
#include <cassert>
int main(){
  assert(solution({3, 0, 6, 1, 5}) == 3);

  assert(solution({0, 0, 0, 0, 0}) == 0);
  assert(solution({1}) == 1);
  assert(solution({0}) == 0);
  assert(solution({9, 10, 11}) == 3);
  assert(solution({0, 1, 9, 10, 11}) == 3);
  assert(solution({1, 3, 5, 7}) == 3);
  return 0;
}


/**
정확성  테스트
테스트 1 〉	통과 (0.04ms, 3.98MB)
테스트 2 〉	통과 (0.05ms, 3.91MB)
테스트 3 〉	통과 (0.05ms, 3.97MB)
테스트 4 〉	통과 (0.06ms, 3.96MB)
테스트 5 〉	통과 (0.05ms, 3.92MB)
테스트 6 〉	통과 (0.06ms, 3.95MB)
테스트 7 〉	통과 (0.03ms, 3.77MB)
테스트 8 〉	통과 (0.02ms, 3.89MB)
테스트 9 〉	통과 (0.03ms, 3.96MB)
테스트 10 〉	통과 (0.03ms, 3.96MB)
테스트 11 〉	통과 (0.07ms, 3.96MB)
테스트 12 〉	통과 (0.02ms, 3.95MB)
테스트 13 〉	통과 (0.06ms, 3.92MB)
테스트 14 〉	통과 (0.05ms, 3.96MB)
테스트 15 〉	통과 (0.06ms, 3.89MB)
테스트 16 〉	통과 (0.01ms, 3.94MB)

채점 결과
정확성: 100.0
합계: 100.0 / 100.0
 */
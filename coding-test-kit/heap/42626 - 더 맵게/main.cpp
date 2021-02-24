#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
  int answer = 0;
  
  priority_queue<int, vector<int>, greater<int>> minHeap(scoville.begin(), scoville.end());

  while(minHeap.top() < K)
  {
    if(minHeap.size() < 2)
    {
      return -1;
    }

    int smallest = minHeap.top();
    minHeap.pop();
    int secondSmallest = minHeap.top();
    minHeap.pop();
    
    minHeap.push(
      smallest + (secondSmallest * 2)
    );

    answer++;
  }


  return answer;
}


#include <iostream>
#include <cassert>
int main(void)
{
  assert(solution({1, 2, 3, 9, 10, 12}, 7) == 2);
  assert(solution({1, 1, 1, 1, 1}, 1) == 0);
  assert(solution({1, 2, 3, 4, 5}, 10000) == -1);
  return 0;
}


/**
정확성  테스트
테스트 1 〉	통과 (0.01ms, 3.96MB)
테스트 2 〉	통과 (0.02ms, 3.94MB)
테스트 3 〉	통과 (0.01ms, 3.96MB)
테스트 4 〉	통과 (0.01ms, 3.95MB)
테스트 5 〉	통과 (0.01ms, 3.94MB)
테스트 6 〉	통과 (0.08ms, 3.96MB)
테스트 7 〉	통과 (0.07ms, 3.94MB)
테스트 8 〉	통과 (0.02ms, 3.91MB)
테스트 9 〉	통과 (0.01ms, 3.96MB)
테스트 10 〉	통과 (0.06ms, 3.96MB)
테스트 11 〉	통과 (0.04ms, 3.96MB)
테스트 12 〉	통과 (0.12ms, 3.96MB)
테스트 13 〉	통과 (0.07ms, 3.96MB)
테스트 14 〉	통과 (0.01ms, 3.95MB)
테스트 15 〉	통과 (0.09ms, 3.95MB)
테스트 16 〉	통과 (0.01ms, 3.97MB)

효율성  테스트
테스트 1 〉	통과 (26.19ms, 8.9MB)
테스트 2 〉	통과 (54.17ms, 14.1MB)
테스트 3 〉	통과 (210.45ms, 39.3MB)
테스트 4 〉	통과 (20.75ms, 7.75MB)
테스트 5 〉	통과 (218.47ms, 40.9MB)

채점 결과
정확성: 76.2
효율성: 23.8
합계: 100.0 / 100.0
 */
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
  int answer = 0;

  int documentsSize = priorities.size();
  int documentIdx = 0;
  vector<bool> printed;

  printed.resize(documentsSize, false);

  // answer를 인쇄한 문서 수로 사용했음.
  // 전체 문서를 다 인쇄 할 때까지 반복
  while(answer < documentsSize){

    if(printed.at(documentIdx) == false)
    {
      /**
       * priorities을 원형으로 생각해서 탐색함.
       * 
       * 반복문을 거치면 documentIdx는 아직 인쇄 안한 것중에서
       * 가장 큰 원소의 인덱스가 됨.
       * 
       * 다시 documentIdx에서 부터 탐색하므로 원래 priorities 배열의 순서가 유지됨. 
       * 
       */
      for(int i=(documentIdx+1)%documentsSize; i != documentIdx; i = (i+1)%documentsSize)
      {
        if(printed[i] == false && priorities[i] > priorities[documentIdx])
        {
          documentIdx = i;
        }
      }

      printed[documentIdx] = true;
      answer++;
      if(documentIdx == location)
      {
        break;
      }
    }
    documentIdx = (documentIdx + 1)%documentsSize;
  }

  return answer;
}


#include <iostream>
#include <cassert>
int main(){
  assert(solution({2, 1, 3, 2}, 2) == 1);
  assert(solution({1, 1, 9, 1, 1, 1}, 0) ==  5); 
  assert(solution({5, 4, 3, 2, 1}, 4) == 5);
  assert(solution({1, 2, 3, 4, 5}, 4) == 1);
  return 0;
}

/**
정확성  테스트
테스트 1 〉	통과 (0.06ms, 3.94MB)
테스트 2 〉	통과 (0.12ms, 3.94MB)
테스트 3 〉	통과 (0.01ms, 3.96MB)
테스트 4 〉	통과 (0.01ms, 3.86MB)
테스트 5 〉	통과 (0.01ms, 3.91MB)
테스트 6 〉	통과 (0.02ms, 3.9MB)
테스트 7 〉	통과 (0.02ms, 3.94MB)
테스트 8 〉	통과 (0.08ms, 3.87MB)
테스트 9 〉	통과 (0.01ms, 3.84MB)
테스트 10 〉	통과 (0.02ms, 3.96MB)
테스트 11 〉	통과 (0.06ms, 3.96MB)
테스트 12 〉	통과 (0.01ms, 3.89MB)
테스트 13 〉	통과 (0.05ms, 3.94MB)
테스트 14 〉	통과 (0.01ms, 3.9MB)
테스트 15 〉	통과 (0.01ms, 3.95MB)
테스트 16 〉	통과 (0.01ms, 3.94MB)
테스트 17 〉	통과 (0.06ms, 3.91MB)
테스트 18 〉	통과 (0.01ms, 3.94MB)
테스트 19 〉	통과 (0.06ms, 3.94MB)
테스트 20 〉	통과 (0.01ms, 3.9MB)

채점 결과
정확성: 100.0
합계: 100.0 / 100.0
 */
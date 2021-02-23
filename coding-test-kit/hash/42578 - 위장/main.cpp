#include <string>
#include <vector>
#include <map>

using namespace std;


/**
 * 서로 다른 N개의 주머니에서 꺼낼 수 있는 조합의 수 (최소 1개)
 *  = (A1 + 1) * (A2 + 1) * ... * (An + 1) - 1 //(0개인 경우 제외)
 */ 
int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> closet;

    for(vector<string> cloth: clothes)
    {
      const string type = cloth[1];

      if(closet[type])
      {
        closet[type]++;
      }
      else
      {
        closet[type] = 1;
      }
    }

    for(const auto& [key, value] : closet)
    {
      answer *= (value + 1);
    }

    return answer - 1;
}


#include <cassert>
int main(){
  assert(solution({
    {"yellow_hat", "headgear"},
    {"blue_sunglasses", "eyewear"},
    {"green_turban", "headgear"}
  }) == 5);
  assert(solution({
    {"crow_mask", "face"},
    {"blue_sunglasses", "face"},
    {"smoky_makeup", "face"}
  }) == 3);
  return 0;
}

/** result
정확성  테스트
테스트 1 〉	통과 (0.04ms, 3.94MB)
테스트 2 〉	통과 (0.02ms, 3.9MB)
테스트 3 〉	통과 (0.02ms, 3.95MB)
테스트 4 〉	통과 (0.03ms, 3.94MB)
테스트 5 〉	통과 (0.02ms, 3.97MB)
테스트 6 〉	통과 (0.02ms, 3.78MB)
테스트 7 〉	통과 (0.03ms, 3.96MB)
테스트 8 〉	통과 (0.02ms, 3.97MB)
테스트 9 〉	통과 (0.01ms, 3.71MB)
테스트 10 〉	통과 (0.03ms, 3.95MB)
테스트 11 〉	통과 (0.01ms, 3.96MB)
테스트 12 〉	통과 (0.03ms, 3.95MB)
테스트 13 〉	통과 (0.02ms, 3.96MB)
테스트 14 〉	통과 (0.01ms, 3.96MB)
테스트 15 〉	통과 (0.01ms, 3.96MB)
테스트 16 〉	통과 (0.01ms, 3.96MB)
테스트 17 〉	통과 (0.01ms, 3.95MB)
테스트 18 〉	통과 (0.02ms, 3.94MB)
테스트 19 〉	통과 (0.02ms, 3.96MB)
테스트 20 〉	통과 (0.01ms, 3.96MB)
테스트 21 〉	통과 (0.01ms, 3.96MB)
테스트 22 〉	통과 (0.01ms, 3.95MB)
테스트 23 〉	통과 (0.02ms, 3.97MB)
테스트 24 〉	통과 (0.01ms, 3.95MB)
테스트 25 〉	통과 (0.02ms, 3.94MB)
테스트 26 〉	통과 (0.03ms, 3.95MB)
테스트 27 〉	통과 (0.01ms, 3.96MB)
테스트 28 〉	통과 (0.02ms, 3.84MB)

채점 결과
정확성: 100.0
합계: 100.0 / 100.0
 */
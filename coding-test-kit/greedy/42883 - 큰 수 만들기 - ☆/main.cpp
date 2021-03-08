#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 
// https://programmers.co.kr/questions/11211
string solution(string number, int k) {
  string answer = "";

  int answerLength = number.size() - k;

  int startIdx = 0;

  while(answer.size() < answerLength)
  {
    auto maxValue = max_element(number.begin() + startIdx, number.end() - (answerLength - 1 - answer.size()));
    answer += *maxValue;
    startIdx = maxValue - number.begin() + 1;
  }

  return answer;
}

#include "iostream"
#include "cassert"
int main()
{
  assert(solution("1924", 2) == "94");
  assert(solution("1231234", 3) == "3234");
  assert(solution("4177252841", 4) == "775841");

  assert(solution("123496785", 8) == "9");
  assert(solution("111222111", 6) == "222");
  assert(solution("987654321", 3) == "987654");
  assert(solution("10000", 2) == "100");

  assert(solution("10", 1) == "1");

  assert(solution("123123123", 3) == "323123");

  assert(solution("123123123123123123123123123123123123", 33) == "333"); // length = 9*4 = 36
  assert(solution("321321321321321321321321321321321321", 33) == "333");

  assert(solution("123123123123123123123123123123123123", 3) == "323123123123123123123123123123123"); // length = 9*4 = 36
  assert(solution("321321321321321321321321321321321321", 3) == "332321321321321321321321321321321");

  assert(solution("123454321", 3) == "454321");
  assert(solution("12343211234321", 10) == "4432"); // length = 7*2 = 14
  assert(solution("9", 0) == "9");

  assert(solution("12345678901872635490", 2) == "345678901872635490");
  return 0;
}

/**
정확성  테스트
테스트 1 〉	통과 (0.01ms, 3.9MB)
테스트 2 〉	통과 (0.01ms, 3.9MB)
테스트 3 〉	통과 (0.01ms, 3.93MB)
테스트 4 〉	통과 (0.02ms, 3.95MB)
테스트 5 〉	통과 (0.02ms, 3.93MB)
테스트 6 〉	통과 (2.43ms, 3.83MB)
테스트 7 〉	통과 (5.19ms, 3.94MB)
테스트 8 〉	통과 (49.45ms, 3.95MB)
테스트 9 〉	통과 (1.64ms, 5.54MB)
테스트 10 〉	통과 (1852.99ms, 5.73MB)
테스트 11 〉	통과 (0.01ms, 3.94MB)
테스트 12 〉	통과 (0.01ms, 3.77MB)

채점 결과
정확성: 100.0
합계: 100.0 / 100.0
 */
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
  string answer = "";

  vector<string> stringNumbers;

  for(int number : numbers)
  {
    stringNumbers.push_back(to_string(number));
  }

  sort(stringNumbers.begin(), stringNumbers.end(), [](string a, string b){
    /**
     * 처음에 이걸 생각 못해서
     * a, b인덱스 하나하나 비교하면서 정렬했는데 틀렸음.
     * 근데 왜틀리지
     * while(i<a.size() && j<b.size() && a[i] == b[j]) {i++;j++}
     */
    return a+b > b+a;
  });

  for(string stringNumber : stringNumbers)
  {
    if(stringNumber != "0") break;

    return "0";
  }

  for(string stringNumber : stringNumbers)
  {
    answer += stringNumber;
  }

  return answer;
}


#include <iostream>
#include <cassert>
int main()
{
  assert(solution({6, 10, 2}) == "6210");
  assert(solution({3, 30, 34, 5, 9}) == "9534330");

  assert(solution({1, 3, 20, 2}) == "32201");
  assert(solution({11111, 11110, 11112, 11113}) == "11113111121111111110");
  assert(solution({0, 0, 0}) == "0");
  assert(solution({1, 11, 111, 1111}) == "1111111111");
  return 0;
}


/**
정확성  테스트
테스트 1 〉	통과 (61.14ms, 9.99MB)
테스트 2 〉	통과 (32.63ms, 6.72MB)
테스트 3 〉	통과 (78.07ms, 10.8MB)
테스트 4 〉	통과 (1.70ms, 3.93MB)
테스트 5 〉	통과 (51.84ms, 7.81MB)
테스트 6 〉	통과 (46.67ms, 7.38MB)
테스트 7 〉	통과 (0.03ms, 3.98MB)
테스트 8 〉	통과 (0.03ms, 3.83MB)
테스트 9 〉	통과 (0.04ms, 3.98MB)
테스트 10 〉	통과 (0.03ms, 3.98MB)
테스트 11 〉	통과 (0.03ms, 3.97MB)

채점 결과
정확성: 100.0
합계: 100.0 / 100.0
 */
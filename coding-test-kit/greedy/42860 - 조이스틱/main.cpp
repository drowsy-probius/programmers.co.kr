#include <string>
#include <vector>

using namespace std;

int solution(string name) {
  int answer = 0;

  int cursor = 0;
  int length = name.size();
  int notDone = 0;

  for(char i : name)
  {
    notDone += i - 'A';
  }


  while(true)
  {
    answer += name.at(cursor) < 'N' ? name.at(cursor) - 'A' : 'Z' - name.at(cursor) + 1;
    notDone += -(name.at(cursor) - 'A');
    name.at(cursor) = 'A';  // It is bad to manipulate parameter.

    if(!notDone)
    {
      break;
    }

    /**
     * steps = (number of A's) + 1;
     */
    int before = (cursor - 1 + length)%length;
    int beforeAs = 0;

    int next = (cursor + 1)%length;
    int nextAs = 0;

    while(name.at(next) == 'A' && nextAs < length)
    {
      nextAs += 1;
      next = (next + 1)%length;
    }

    while(name.at(before) == 'A' && beforeAs < length)
    {
      beforeAs += 1;
      before = (before - 1 + length)%length;
    }

    if(beforeAs < nextAs)
    {
      cursor = before;
      answer += beforeAs + 1;
    }
    else
    {
      cursor = next;
      answer += nextAs + 1;
    }
  }

  return answer;
}

#include "iostream"
#include "cassert"
int main()
{
  assert(solution("JEROEN") == 56);
  assert(solution("JAN") == 23);
  assert(solution("BAAA") == 1);
  assert(solution("AAAAA") == 0);
  assert(solution("AAABA") == 3);
  cout << solution("CANAAAAANAN") << '\n'; // 48? 49?
  return 0;
}


/**
정확성  테스트
테스트 1 〉	통과 (0.01ms, 3.93MB)
테스트 2 〉	통과 (0.01ms, 3.92MB)
테스트 3 〉	통과 (0.01ms, 3.94MB)
테스트 4 〉	통과 (0.01ms, 3.96MB)
테스트 5 〉	통과 (0.01ms, 3.96MB)
테스트 6 〉	통과 (0.01ms, 3.91MB)
테스트 7 〉	통과 (0.01ms, 3.84MB)
테스트 8 〉	통과 (0.01ms, 3.94MB)
테스트 9 〉	통과 (0.01ms, 3.96MB)
테스트 10 〉	통과 (0.01ms, 3.93MB)
테스트 11 〉	통과 (0.01ms, 3.96MB)

채점 결과
정확성: 100.0
합계: 100.0 / 100.0
 */
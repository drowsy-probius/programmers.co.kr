#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
  /**
   * participant_list
   * (participant_name, number of participant_name)
   */
  map<string, int> participant_list;
  string answer = "";

  for(const auto runner : participant)
  {
    if(participant_list[runner])
    {
      participant_list[runner]++;
    }
    else
    {
      participant_list[runner] = 1;
    }
  }

  for(const auto winner : completion)
  {
    participant_list[winner]--;
  }

  for(const auto& [key, value] : participant_list)
  {
    if(value != 0)
    {
      answer = key;
    }
  }

  return answer;
}


// for debug
#include <cassert>
//

int main(void)
{
  assert(solution({"leo", "kiki","eden"} , {"eden", "kiki"}) == "leo");
  assert(solution({"marina", "josipa","nikola", "vinko", "filipa"} , {"josipa", "filipa", "marina", "nikola"}) == "vinko");
  assert(solution({"mislav", "stanko", "mislav", "ana"} , {"stanko", "ana", "mislav"}) == "mislav");

  return 0;
}

/** result
정확성  테스트
테스트 1 〉	통과 (0.02ms, 3.97MB)
테스트 2 〉	통과 (0.02ms, 3.94MB)
테스트 3 〉	통과 (0.45ms, 3.93MB)
테스트 4 〉	통과 (0.90ms, 3.97MB)
테스트 5 〉	통과 (0.90ms, 3.93MB)

효율성  테스트
테스트 1 〉	통과 (64.34ms, 18.1MB)
테스트 2 〉	통과 (107.12ms, 25.4MB)
테스트 3 〉	통과 (132.21ms, 30.2MB)
테스트 4 〉	통과 (144.28ms, 32.9MB)
테스트 5 〉	통과 (142.71ms, 32.9MB)
 */
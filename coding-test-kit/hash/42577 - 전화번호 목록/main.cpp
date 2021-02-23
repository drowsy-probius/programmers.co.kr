#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end(), [](string a, string b){
      return a.length() < b.length();
    });

    // 정렬을 길이로 했으니 이중 반복문
    for(int prefix_i=0; prefix_i<phone_book.size()-1; prefix_i++)
    {
      for(int str_i=prefix_i+1; str_i<phone_book.size(); str_i++)
      {
        /**
         * >= c++ 20
         */
        // if(phone_book[str_i].starts_with(phone_book[prefix_i]))
        // {
        //   return false;
        // }

        if(phone_book[prefix_i] == phone_book[str_i].substr(0, phone_book[prefix_i].length()))
        {
          return false;
        }
      }
    }

    return answer;
}


#include <assert.h>
int main(void)
{
  assert(solution({"119", "97674223", "1195524421"}) == false);
  assert(solution({"123", "456", "789"}) == true);
  assert(solution({"12", "123", "1235", "567", "88"}) == false);
  return 0;
}

/** result
정확성  테스트
테스트 1 〉	통과 (0.01ms, 3.96MB)
테스트 2 〉	통과 (0.01ms, 3.84MB)
테스트 3 〉	통과 (0.01ms, 3.94MB)
테스트 4 〉	통과 (0.01ms, 3.96MB)
테스트 5 〉	통과 (0.01ms, 3.97MB)
테스트 6 〉	통과 (0.01ms, 3.97MB)
테스트 7 〉	통과 (0.01ms, 3.95MB)
테스트 8 〉	통과 (0.01ms, 3.95MB)
테스트 9 〉	통과 (0.01ms, 3.97MB)
테스트 10 〉	통과 (0.01ms, 3.95MB)
테스트 11 〉	통과 (0.01ms, 3.95MB)

효율성  테스트
테스트 1 〉	통과 (3.83ms, 4.13MB)
테스트 2 〉	통과 (3.86ms, 4.5MB)

채점 결과
정확성: 84.6
효율성: 15.4
합계: 100.0 / 100.0
 */
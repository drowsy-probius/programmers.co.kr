#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
  int answer = 0;

  int houseLength = money.size();
  vector<int> skipFirst(houseLength - 1, 0);
  vector<int> skipLast(houseLength - 1, 0);

  skipFirst[0] = money[1];
  skipFirst[1] = max(skipFirst[0], money[2]);

  skipLast[0] = money[0];
  skipLast[1] = max(skipLast[0], money[1]);

  for(int i=2; i<houseLength - 1; i++)
  {
    skipFirst[i] = max(skipFirst[i-1], skipFirst[i-2] + money[i + 1]);
    skipLast[i] = max(skipLast[i-1], skipLast[i-2] + money[i]);
  }

  answer = max(skipFirst.back(), skipLast.back());

  return answer;
}


#include "cassert"
int main()
{
  // assert(solution({1, 2, 3, 1}) == 4);
  
  // assert(solution({1, 1, 1, 1, 1}) == 2);
  // assert(solution({1, 12, 12, 10, 10, 1}) == 23);
  // assert(solution({9, 10, 9, 1, 4, 1}) == 22);
  assert(solution({9, 10, 9, 1, 4}) == 18);
  assert(solution({4, 3, 1, 3}) == 6);
  assert(solution({10, 9, 1, 5}) == 14);
  assert(solution({10, 9, 1, 1, 3}) == 12);
  assert(solution({1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0}) == 4);

  assert(solution({1, 1, 4, 1, 4}) == 8);
  assert(solution({1000, 0, 0, 1000, 0, 0, 1000, 0, 0, 1000}) == 3000);
  assert(solution({1000, 1, 0, 1, 2, 1000, 0}) == 2001);
  assert(solution({1000, 0, 0, 0, 0, 1000, 0, 0, 0, 0, 0, 1000}) == 2000);
  assert(solution({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) == 30);
  assert(solution({0, 0, 0, 0, 100, 0, 0, 100, 0, 0, 1, 1}) == 201);
  assert(solution({11, 0, 2, 5, 100, 100, 85, 1}) == 198);
  assert(solution({1, 2, 3}) == 3);
  assert(solution({91, 90, 5, 7, 5, 7}) == 104);
  assert(solution({90, 0, 0, 95, 1, 1}) == 185);

  return 0;
}
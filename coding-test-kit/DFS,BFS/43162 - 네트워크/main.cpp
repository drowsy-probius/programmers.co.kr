#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    return answer;
}

#include "cassert"
int main()
{
  assert(solution(3, {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}}) == 2);
  assert(solution(3, {{1, 1, 0}, {1, 1, 1}, {0, 1, 1}}) == 1);
  return 0;
}
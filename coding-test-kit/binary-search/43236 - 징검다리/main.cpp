#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
  /**
   * i-th idx: distance from i-th rock to (i+1)-th rock
   */
  vector<int> spaces;
  
  sort(rocks.begin(), rocks.end());
  rocks.push_back(distance);
  for(int i=0; i<rocks.size(); i++)
  {
    int before = i>0 ? rocks.at(i-1) : 0;
    spaces.push_back(rocks.at(i) - before);
  }

  while(n--)
  {
    int min_idx = min_element(spaces.begin(), spaces.end()-1) - spaces.begin();
    int min_value = spaces.at(min_idx);
    
    if(min_idx > 0 && spaces.at(min_idx - 1) < spaces.at(min_idx + 1))
    {
      spaces.at(min_idx - 1) += min_value;
    }
    else
    {
      spaces.at(min_idx + 1) += min_value;
    }
    spaces.erase(spaces.begin() + min_idx);
  }


  return *min_element(spaces.begin(), spaces.end());
}

#include "cassert"
int main(void)
{
  // assert(solution(25, {2, 14, 11, 21, 17}, 2) == 4);
  // assert(solution(20, {15, 16, 17, 18, 19}, 2) == 1);
  assert(solution(10, {3, 5, 7}, 2) == 5);
  return 0;
}
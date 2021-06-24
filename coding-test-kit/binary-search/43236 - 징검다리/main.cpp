#include <string>
#include <vector>
#include <algorithm>

#include "iostream"

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
  int answer = 0;
  vector<int> space;

  sort(rocks.begin(), rocks.end(), less<int>());

  for(int i=0; i<rocks.size(); i++)
  {
    if(i==0) space.push_back(rocks.at(i));
    else space.push_back(rocks.at(i) - rocks.at(i-1));
  }

  while(n--)
  {
    vector<int>::iterator minimal = min_element(space.begin(), space.end());
    int min_idx = std::distance(space.begin(), minimal);
    
    if(min_idx + 1 == space.size())
    {
      space.at(min_idx - 1) += space.at(min_idx);
    }
    else
    {
      space.at(min_idx + 1) += space.at(min_idx);
    }
    space.erase(minimal);
  }

  return *min_element(space.begin(), space.end());
}

#include "cassert"
int main(void)
{
  // assert(solution(25, {2, 14, 11, 21, 17}, 2) == 4);
  assert(solution(20, {15, 16, 17, 18, 19}, 2) == 2);
  return 0;
}
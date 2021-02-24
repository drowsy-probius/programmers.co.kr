#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp{
  bool operator()(vector<int> a, vector<int> b)
  {
    return (a[1] - a[0]) < (b[1] - b[0]);
  }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int jobsLength = jobs.size();

    priority_queue<vector<int>, vector<vector<int>>, cmp> otherJobs;

    vector<int> firstJob = *min_element(jobs.begin(), jobs.end(), [](vector<int> a, vector<int> b){
      return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
    });
    answer += firstJob[0] + firstJob[1];
    
    return answer;
}

#include <iostream>
#include <cassert>
int main(){
  cout << solution({{0, 3}, {1, 9}, {2, 6}}) << '\n'; 
  assert(solution({{0, 3}, {1, 9}, {2, 6}}) == 9);
  return 0;
}
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct jobsCompare{
  bool operator()(vector<int> a, vector<int> b)
  {
    return a[0] == b[0] ? a[1] > b[1] : a[0] > b[0];
  }
};

struct pendingCompare{
  bool operator()(vector<int> a, vector<int> b)
  {
    /**
     * 여기서 다른사람 풀이 봤음.
     * 
     * 내가 처음에 생각하기로는
     * 
     * 겹치는 작업이 여러개 있다면
     * 현 시점에서 가장 빠른 완료시간을 가지는 작업을 
     * 선택하면 해결 될 거라고 생각했다.
     * 
     * 그래서 아래와 같이 비교함수를 작성했는데 아래 테스트케이스에서 계속 막혔다.
     * // 현 시점에서의 작업의 완료시간은 (현재 시간 + 실행 시간 - 요청 시간)
     * (a[1] - a[0]) == (b[1] - b[0]) ? a[0] < b[0] : (a[1] - a[0]) > (b[1] - b[0]); 
     * 
     * {{24, 10}, {28, 39}, {43, 20}, {37, 5}, {47, 22}, {20, 47}, {15, 2}, {15, 34}, {35, 43}, {26, 1}}) == 72 // 나는 78이 나왔음.
     * 
     * 
     * 하루 이틀 생각해도 답을 모르겠어서 다른 사람의 풀이를 봤더니
     * 큐 정렬을 작업의 실행 시간이 작은 순대로 한 것이다.
     * 내 생각이 맞을 지는 모르지만, 그 이유는 아마도
     * 
     * 현 시점에서 이전에 요청된 작업이 여러 개일 때, 
     * 먼저 실행되는 작업의 실행시간이 다른 작업의 완료시간에 계속 더해진다.
     * 그러면 실행시간이 긴 작업이 남아 있을 수록 전체 완료시간이 더 길어진다.
     * 따라서 실행시간이 짧은 작업을 먼저 선택하는게 전체 완료시간을 최소화 할 수 있다.
     * 
     * 라는 것같다.
     */
    //
    return a[1] > b[1];
  }
};


/**
 * job(시작 시간, 실행 시간)
 * 전체 jobs은 두가지 경우로 구분할 수 있음.
 * 
 * 1. 서로 겹치지 않는 작업
 * 작업 시간 = 작업 시간 + job[1]
 * 현재 시간 = job[0] + job[1]
 * 
 * 2. 서로 겹치는 것이 있는 작업.
 * 작업 시간 = 작업 시간 + 현재 시간 + job[1] - job[0]
 * 현재 시간 = 현재 시간 + job[1]
 */
int solution(vector<vector<int>> jobs) {
  // 전체 작업 시간
  int totalTime = 0;

  // 어떤 작업이 시행 될 때의 시간
  int currentTime = 0;

  int jobsSize = jobs.size();

  // 전체 작업 큐. 요청 시간이 빠를 수록, 실행 시간이 빠를 수록 앞에 위치함.
  priority_queue<vector<int>, vector<vector<int>>, jobsCompare> jobsQueue;

  // 어떤 작업이 시행 될 때, 그 전에 실행요청이 들어온 작업 큐. 실행 시간이 빠를 수록 앞에 위치함.
  // 여기에 있는 작업은 서로 겹치는 작업임.
  priority_queue<vector<int>, vector<vector<int>>, pendingCompare> pendingJobs;

  for(vector<int> job : jobs)
  {
    jobsQueue.push(job);
  }

  while(!jobsQueue.empty() || !pendingJobs.empty())
  {
    vector<int> job;

    // 실행할 작업을 선택 할 때, pendingJobs큐에서 먼저 선택함.
    if(!pendingJobs.empty())
    {
      job = pendingJobs.top();
      pendingJobs.pop();

      totalTime += currentTime + job[1] - job[0];
      currentTime += job[1];
    }
    else
    {
      job = jobsQueue.top();
      jobsQueue.pop();

      totalTime += job[1];
      currentTime = job[0] + job[1];
    }

    while(!jobsQueue.empty() && jobsQueue.top()[0] < currentTime)
    {
      pendingJobs.push(jobsQueue.top());
      jobsQueue.pop();
    }
  }

  return totalTime / jobsSize;
}

#include <iostream>
#include <cassert>
int main(){
  assert(solution({{0, 3}, {1, 9}, {2, 6}}) == 9);
  assert(solution({{0, 1}, {1, 2}, {2, 3}}) == 2);
  assert(solution({{0, 1}, {1, 1}, {2, 1}}) == 1);
  assert(solution({{0, 10}, {1, 7}, {2, 8}, {3, 5}, {8, 2}}) == 16);

  // test cases from
  // https://programmers.co.kr/questions/14955
  assert(solution({{0, 10}, {2, 10}, {9, 10}, {15, 2}}) == 14);
  assert(solution({{0, 10}, {2, 12}, {9, 19}, {15, 17}}) == 25);
  assert(solution({{0, 3}, {1, 9}, {2, 6}}) == 9);
  assert(solution({{0, 1}}) == 1);
  assert(solution({{1000, 1000}}) == 1000);
  assert(solution({{0, 1}, {0, 1}, {0, 1}}) == 2);
  assert(solution({{0, 1}, {0, 1}, {0, 1}, {0, 1}}) == 2);
  assert(solution({{0, 1}, {1000, 1000}}) == 500);
  assert(solution({{100, 100}, {1000, 1000}}) == 550);
  assert(solution({{10, 10}, {30, 10}, {50, 2}, {51, 2}}) == 6);
  assert(solution({{0, 3}, {1, 9}, {2, 6}, {30, 3}}) == 7);
  

  // test cases from 
  // https://programmers.co.kr/questions/14114
  assert(solution({{0, 3}, {1, 9}, {2, 6}}) == 9);
  assert(solution({{1, 10}, {3, 3}, {10, 3}}) == 9);
  assert(solution({{0, 10}, {4, 10}, {5, 11}, {15, 2}}) == 15);
  assert(solution({{0, 10}}) == 10);
  assert(solution({{0, 3}, {1, 9}, {2, 6}, {4, 3}}) == 9);
  assert(solution({{0, 1}, {1, 2}, {500, 6}}) == 3);
  assert(solution({{0, 3}, {1, 9}, {500, 6}}) == 6);
  assert(solution({{0, 1}, {0, 1}, {1, 0}}) == 1);
  assert(solution({{0, 3}, {4, 3}, {8, 3}}) == 3);
  assert(solution({{0, 3}, {4, 3}, {10, 3}}) == 3);
  assert(solution({{0, 5}, {6, 1}, {6, 2}}) == 3);
  assert(solution({{0, 5}, {2, 2}, {5, 3}}) == 5);
  assert(solution({{0, 5}, {2, 2}, {4, 2}}) == 5);
  assert(solution({{0, 3}, {0, 1}, {4, 7}}) == 4);
  assert(solution({{0, 2}, {3, 6}, {3, 1}}) == 3);
  assert(solution({{0, 5}, {1, 2}, {5, 5}}) == 6);
  assert(solution({{0, 9}, {0, 4}, {0, 5}, {0, 7}, {0, 3}}) == 13);
  assert(solution({{24, 10}, {28, 39}, {43, 20}, {37, 5}, {47, 22}, {20, 47}, {15, 2}, {15, 34}, {35, 43}, {26, 1}}) == 72);
  assert(solution({{24, 10}, {28, 39}, {43, 20}, {37, 5}, {47, 22}, {20, 47}, {15 ,34}, {15, 2}, {35, 43}, {26, 1}}) == 72);
  assert(solution({{1, 9}, {1, 4}, {1, 5}, {1, 7}, {1, 3}}) == 13);

  cout << "OK" << '\n';
  return 0;
}
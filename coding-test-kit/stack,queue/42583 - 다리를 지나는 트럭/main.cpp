#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
  int answer = 0;

  int truckIndex = 0;
  int weightTrucksOnBridge = 0;

  queue<int> bridge;

  for(int i=0; i<bridge_length; i++)
  {
    bridge.push(0);
  }
  
  while(true)
  {
    answer++;

    weightTrucksOnBridge -= bridge.front();
    bridge.pop();

    if(truckIndex < truck_weights.size())
    {
      if(weightTrucksOnBridge + truck_weights[truckIndex] <= weight)
      {
        bridge.push(truck_weights[truckIndex]);
        weightTrucksOnBridge += truck_weights[truckIndex];
        truckIndex++;
      }
      else
      {
        bridge.push(0);
      }
    }
    else
    {
      if(weightTrucksOnBridge == 0)
      {
        break;
      }
      else
      {
        bridge.push(0);
      }
      
    }
  }

  return answer;
}


#include <cassert>
#include <iostream>
int main(){
  assert(solution(2, 10, {7, 4, 5, 6}) == 8);
  assert(solution(100, 100, {10}) == 101);
  assert(solution(10, 10, {1, 1, 1, 1, 1, 1, 1, 1, 1 ,1}) == 20);
  assert(solution(100, 100, {10, 10, 10, 10, 10, 10, 10, 10, 10, 10}) == 110);
  assert(solution(1, 1, {1}) == 2);
  
  // test cases from
  // https://programmers.co.kr/questions/9058
  assert(solution(1, 2, {1, 1, 1}) == 4);
  assert(solution(1, 1, {1, 1, 1}) == 4);
  assert(solution(4, 2, {1, 1, 1, 1}) == 10);
  assert(solution(3, 3, {1, 1, 1}) == 6);
  assert(solution(3, 1, {1, 1, 1}) == 10);
  assert(solution(5, 5, {1, 1, 1, 1, 1, 2, 2}) == 14);
  assert(solution(7, 7, {1, 1, 1, 1, 1, 3, 3}) == 18);
  assert(solution(5, 5, {1, 1, 1, 1, 1, 2, 2, 2, 2}) == 19);
  assert(solution(5, 5, {2, 2, 2, 2, 1, 1, 1, 1, 1}) == 19);
  return 0;
}

/** current solution
정확성  테스트
테스트 1 〉	통과 (0.02ms, 3.73MB)
테스트 2 〉	통과 (0.15ms, 3.97MB)
테스트 3 〉	통과 (0.01ms, 3.96MB)
테스트 4 〉	통과 (0.10ms, 3.98MB)
테스트 5 〉	통과 (0.90ms, 3.96MB)
테스트 6 〉	통과 (0.24ms, 3.98MB)
테스트 7 〉	통과 (0.02ms, 3.85MB)
테스트 8 〉	통과 (0.01ms, 3.73MB)
테스트 9 〉	통과 (0.06ms, 3.86MB)
테스트 10 〉	통과 (0.01ms, 3.96MB)
테스트 11 〉	통과 (0.01ms, 3.97MB)
테스트 12 〉	통과 (0.03ms, 3.97MB)
테스트 13 〉	통과 (0.02ms, 3.93MB)
테스트 14 〉	통과 (0.01ms, 3.96MB)

채점 결과
정확성: 100.0
합계: 100.0 / 100.0
 */ 




/**
// old solution 1

#include <vector>

using namespace std;

int weightOnBridge(int bridge[], int bridge_length, vector<int> truck_weights)
{
  int sum = 0;
  for(int i=0; i<bridge_length; i++)
  {
    int index = bridge[i];
    if(index != -1)
    {
      sum += truck_weights[index];
    }
  }
  return sum;
}

int solution(int bridge_length, int weight, vector<int> truck_weights) {
  int answer = 0;

  int truckIndex = 0;
  int weightTrucksOnBridge = 0;
  int bridge[bridge_length];

  for(int i=0; i<bridge_length; i++)
  {
    bridge[i] = -1;
  }
  
  while(true)
  {
    answer++;

    int arrived = bridge[0];
    for(int i=1; i<bridge_length; i++)
    {
      bridge[i-1] = bridge[i];
    }
    bridge[bridge_length - 1] = -1;

    if(truckIndex < truck_weights.size() && weightOnBridge(bridge, bridge_length, truck_weights) + truck_weights[truckIndex] <= weight)
    {
      bridge[bridge_length - 1] = truckIndex;
      truckIndex++;
    }
    

    if(truckIndex >= truck_weights.size() && weightOnBridge(bridge, bridge_length, truck_weights) == 0)
    {
      break;
    }
  }

  return answer;
}

정확성  테스트
테스트 1 〉	통과 (2.77ms, 3.92MB)
테스트 2 〉	통과 (212.37ms, 3.97MB)
테스트 3 〉	통과 (0.03ms, 3.97MB)
테스트 4 〉	통과 (42.91ms, 3.95MB)
테스트 5 〉	통과 (1153.76ms, 3.93MB)
테스트 6 〉	통과 (206.05ms, 3.96MB)
테스트 7 〉	통과 (1.04ms, 3.97MB)
테스트 8 〉	통과 (0.05ms, 3.72MB)
테스트 9 〉	통과 (1.39ms, 3.97MB)
테스트 10 〉	통과 (0.06ms, 3.91MB)
테스트 11 〉	통과 (0.01ms, 3.96MB)
테스트 12 〉	통과 (0.07ms, 3.92MB)
테스트 13 〉	통과 (0.39ms, 3.97MB)
테스트 14 〉	통과 (0.03ms, 3.97MB)

채점 결과
정확성: 100.0
합계: 100.0 / 100.0
 */ 
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// Sieve of Eratosthenes
vector<bool> buildPrimeNumber()
{
  vector<bool> isPrime(10000000, true);
  isPrime[0] = false;
  isPrime[1] = false;

  // sqrt(10000000)
  for(int i=2; i<3163; i++)
  {
    for(int j=i+i; j<10000000; j += i)
    {
      isPrime[j] = false;
    }
  }

  return isPrime;
}

/*
calculate combination of input
in range [start, end)
*/
void combination(int depth, int size, int start, int end, string input, vector<string>& result, string& temp, vector<bool>& visited)
{
  if(depth == size)
  {
    result.push_back(temp);
    return;
  }

  for(int i=start; i<end; i++)
  {
    if(!visited[i])
    {
      visited[i] = true;
      temp += input.at(i);

      combination(depth + 1, size, i, end, input, result, temp, visited);

      visited[i] = false;
      temp = temp.substr(0, temp.size() - 1);
    }
  }
}

// calculate premutation. nPr 
set<int> buildNumbers(string numbers)
{
  set<int> result;
  
  vector<bool> visited(numbers.size(), false);
  vector<string> combinationResult;
  string temp = "";
  vector<string> permutationResult;

  for(int i=1; i<=numbers.size(); i++)
  {
    combination(0, i, 0, numbers.size(), numbers, combinationResult, temp, visited);
  }

  for(string numberString : combinationResult)
  {
    sort(numberString.begin(), numberString.end());
    do
    {
      permutationResult.push_back(numberString);
    }
    while(next_permutation(numberString.begin(), numberString.end()));
  }

  for(string numberString : permutationResult)
  {
    result.insert(stoi(numberString));
  }

  return result;
}


vector<bool> isPrime = buildPrimeNumber();
int solution(string numbers) {
  int answer = 0;

  set<int> allPossibleNumbers = buildNumbers(numbers);

  for(int number : allPossibleNumbers)
  {
    if(isPrime[number])
    {
      answer++;
    }
  }

  return answer;
}


#include "iostream"
#include "cassert"
int main()
{
  assert(solution("17") == 3);
  assert(solution("011") == 2);
  assert(solution("013") == 4); // 3, 13, 31, 103
  return 0;
}

/**
길이 0부터 n까지의 모든 순열 만드는게 어려웠음.
다른사람은 처음에 길이 n인 문자열에 next_permutation적용해서
next_permutation 반복문 안에서
1부터 n까지 for문 만들고 거기서 문자열.substr(0, i) 가져오는 식으로 했음.

정확성  테스트
정확성  테스트
테스트 1 〉	통과 (0.04ms, 3.95MB)
테스트 2 〉	통과 (0.37ms, 4.66MB)
테스트 3 〉	통과 (0.02ms, 3.93MB)
테스트 4 〉	통과 (0.08ms, 3.96MB)
테스트 5 〉	통과 (0.05ms, 3.94MB)
테스트 6 〉	통과 (0.02ms, 3.93MB)
테스트 7 〉	통과 (0.03ms, 3.8MB)
테스트 8 〉	통과 (0.05ms, 3.94MB)
테스트 9 〉	통과 (0.02ms, 3.83MB)
테스트 10 〉	통과 (0.38ms, 4.75MB)
테스트 11 〉	통과 (0.09ms, 3.96MB)
테스트 12 〉	통과 (0.06ms, 3.96MB)

채점 결과
정확성: 100.0
합계: 100.0 / 100.0
 */
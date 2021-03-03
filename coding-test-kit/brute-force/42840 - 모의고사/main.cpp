#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
  vector<int> answer;

  pair<int, int> highestStudent;
  vector<pair<int, int>> correctAnswers;
  vector<vector<int>> students(3, vector<int>(0, 0));

  for(int i=0; i<3; i++)
  {
    correctAnswers.push_back(make_pair(i+1, 0));
  }

  students[0] = {1, 2, 3, 4, 5};
  students[1] = {2, 1, 2, 3, 2, 4, 2, 5};
  students[2] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

  for(int i=0; i<answers.size(); i++)
  {
    for(int studentIdx=0; studentIdx<3; studentIdx++)
    {
      vector<int> student = students[studentIdx];
      if(answers[i] == student[i % student.size()])
      {
        correctAnswers[studentIdx].second++;
      }
    }
  }

  sort(correctAnswers.begin(), correctAnswers.end(), [](pair<int, int> a, pair<int, int> b){
    return a.second > b.second;
  });

  highestStudent = correctAnswers[0];
  answer.push_back(highestStudent.first);
  for(int i=1; i<3; i++)
  {
    if(correctAnswers[i].second == highestStudent.second)
    {
      answer.push_back(correctAnswers[i].first);
    }
  }

  return answer;
}

#include "iostream"
#include "cassert"
int main()
{
  vector<int> test_result;

  test_result = {1};
  assert(solution({1, 2, 3, 4, 5}) == test_result);

  test_result = {1, 2, 3};
  assert(solution({1, 3, 2, 4, 2}) == test_result);
  return 0;
}

/**
정확성  테스트
테스트 1 〉	통과 (0.02ms, 3.97MB)
테스트 2 〉	통과 (0.01ms, 3.98MB)
테스트 3 〉	통과 (0.01ms, 3.78MB)
테스트 4 〉	통과 (0.01ms, 3.84MB)
테스트 5 〉	통과 (0.02ms, 3.97MB)
테스트 6 〉	통과 (0.02ms, 3.98MB)
테스트 7 〉	통과 (0.61ms, 3.97MB)
테스트 8 〉	통과 (0.21ms, 3.97MB)
테스트 9 〉	통과 (1.14ms, 3.98MB)
테스트 10 〉	통과 (0.54ms, 3.96MB)
테스트 11 〉	통과 (1.19ms, 3.97MB)
테스트 12 〉	통과 (1.05ms, 3.98MB)
테스트 13 〉	통과 (0.09ms, 3.97MB)
테스트 14 〉	통과 (1.26ms, 3.97MB)

채점 결과
정확성: 100.0
합계: 100.0 / 100.0
 */
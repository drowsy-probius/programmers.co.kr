#include <string>
#include <vector>
#include <queue>

using namespace std;

bool isConvertable(string a, string b)
{
  int count;
  for(int i=0; i<a.size(); i++)
  {
    if(a.at(i) != b.at(i))
    {
      count++;
    }
  }
  return count == 1;
}

int solution(string begin, string target, vector<string> words) {
  int answer = 0;
  int depth = 0;
  string current = "";

  queue<pair<int, string>> q;
  vector<int> visited(words.size()+1, false);

  q.push(make_pair(0, begin));
  while(!q.empty())
  {
    depth = q.front().first;
    current = q.front().second;
    q.pop();

    if(current.compare(target) == 0)
    {
      answer = depth;
      break;
    }

    for(int i=0; i<words.size(); i++)
    {
      if(visited[i])
      {
        continue;
      }
      if(!isConvertable(current, words[i]))
      {
        continue;
      }
      
      visited[i] = true;
      q.push(make_pair(depth + 1, words[i]));
    }
  }

  return answer;
}

#include "cassert"
#include "iostream"
int main(void)
{
  assert(solution("hit", "cog", {"hot", "dot", "dog", "lot", "log"}) == 0);
  assert(solution("hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"}) ==  4);
  // assert(solution("asdf", "ffff", {"addf", "dddf", "fddf", "fdff", "ffff"}) == 4);

  assert(solution("0000", "1234", {"1111", "0010", "0100", "0020", "1000", "1200", "1030", "1300", "1234", "1204"}) == 4);
  // assert(solution("000", "333", {"001", "011", "020", "031", "032", "133", "233", "030", "033", "333"}) == 3);

  return 0;
}
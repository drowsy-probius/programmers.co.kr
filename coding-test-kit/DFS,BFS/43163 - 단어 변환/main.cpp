#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool isConvertable(string a, string b)
{
  int count;
  for(int i=0; i<a.size(); i++)
  {
    if(a.at(i) != b.at(i)) count++;
  }
  return count == 1;
}


int solution(string begin, string target, vector<string> words) {
  auto it = find(words.begin(), words.end(), begin);
  if(it == words.end()) return 0;

  int answer = __INT_MAX__;
  for(string word: words)
  {
    if(!isConvertable(begin, word)) continue;

    queue<pair<int, string>> q;
    vector<string> visited;
    q.push(make_pair(1, word));
    while(!q.empty())
    {
      auto front = q.front();
      q.pop();
      int depth = front.first;
      string current = front.second;

      if(current.compare(target) == 0)
      {
        answer = min(depth, answer);
        continue;
      }

      for(string _word: words)
      {
        if(!isConvertable(current, _word)) continue;
        auto it = find(visited.begin(), visited.end(), _word);
        if(it != visited.end()) continue;

        q.push(make_pair(depth+1, _word));
      }
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
  return 0;
}
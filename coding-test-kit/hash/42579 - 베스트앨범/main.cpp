#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
  vector<int> answer;

  // store sum of plays per genre
  map<string, int> countPerGenre;
  vector<pair<string, int>> countPerGenreVector;

  // store song index and plays per genre
  map<string, vector< pair<int, int> > > songsPerGenre;

  for(int i=0; i<genres.size(); i++)
  {
    if(countPerGenre[genres[i]])
    {
      countPerGenre[genres[i]] += plays[i];
    }
    else
    {
      countPerGenre[genres[i]] = plays[i];
    }
    
    songsPerGenre[genres[i]].push_back(make_pair(i, plays[i]));
  }

  // covert map to vector in order to sort
  for(const pair<string, int> genre: countPerGenre)
  {
    countPerGenreVector.push_back(genre);
  }

  sort(countPerGenreVector.begin(), countPerGenreVector.end(), [](pair<string, int> a, pair<string, int> b){
    return a.second > b.second;
  });


  for(const pair<string, int> genre: countPerGenreVector)
  {
    vector<pair<int, int>> songs = songsPerGenre[genre.first];

    // sort song vector by it's plays
    sort(songs.begin(), songs.end(), [](pair<int, int> a, pair<int, int> b){
      return a.second > b.second;
    });

    // append songs maximum 2 to answer
    for(auto it = songs.begin(); it != songs.end() && (it - songs.begin()) < 2; it++)
    {
      answer.push_back(it->first);
    }
  }

  return answer;
}

#include <assert.h>
int main()
{
  vector<int> test_answer_1 = {4, 1, 3, 0};
  assert(solution({"classic", "pop", "classic", "classic", "pop"}, {500, 600, 150, 800, 2500}) == test_answer_1);
  return 0;
}


/**
 * 
정확성  테스트
테스트 1 〉	통과 (0.03ms, 3.94MB)
테스트 2 〉	통과 (0.02ms, 3.94MB)
테스트 3 〉	통과 (0.02ms, 3.93MB)
테스트 4 〉	통과 (0.01ms, 3.83MB)
테스트 5 〉	통과 (0.06ms, 3.95MB)
테스트 6 〉	통과 (0.05ms, 3.95MB)
테스트 7 〉	통과 (0.06ms, 3.93MB)
테스트 8 〉	통과 (0.03ms, 3.93MB)
테스트 9 〉	통과 (0.04ms, 3.93MB)
테스트 10 〉	통과 (0.04ms, 3.95MB)
테스트 11 〉	통과 (0.03ms, 3.89MB)
테스트 12 〉	통과 (0.03ms, 3.93MB)
테스트 13 〉	통과 (0.04ms, 3.93MB)
테스트 14 〉	통과 (0.06ms, 3.93MB)
테스트 15 〉	통과 (0.02ms, 3.77MB)

채점 결과
정확성: 100.0
합계: 100.0 / 100.0
 */
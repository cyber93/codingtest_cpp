#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool compareGenre(const pair<string, int>& a, const pair<string, int>& b) {
  return a.second > b.second;
}

bool compareSong(const pair<int, int>& a, const pair<int, int>& b) {
  if (a.second == b.second) return a.first < b.first;
  return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
  vector<int> answer;
  unordered_map<string, vector<pair<int, int>>> genres_dict;
  unordered_map<string, int> play_dict;

  //???貫?ㅸ퉪?????源???쏅땾?? 揶??ⓥ돦????源???쏅땾 ????
  for (int i = 0; i < genres.size(); ++i) {
    genres_dict[genres[i]].push_back({i, plays[i]});
    play_dict[genres[i]] += plays[i];
  }

  //??????源???쏅땾揶쎛 筌띾‘? ?貫???뽰몵嚥??類ｌ졊
  vector<pair<string, int>> sorted_genres(play_dict.begin(), play_dict.end());
  sort(sorted_genres.begin(), sorted_genres.end(), compareGenre);

  //??揶??貫????곷퓠???紐껋삋????源???쏅땾 ??뽰몵嚥??類ｌ졊??筌ㅼ뮆? 2??繹먮슣? ?醫뤾문
  for (auto& genre : sorted_genres) {
    auto& songs = genres_dict[genre.first];
    sort(songs.begin(), songs.end(), compareSong);

    for (int i = 0; i < min(2, (int)songs.size()); ++i) {
      answer.push_back(songs[i].first);
    }
  }

  return answer;
}

//?袁⑥삋 ?꾨뗀諭?????뮞???꾨뗀諭???낅빍??
#include <iterator>
#include <iostream>
void print(vector<int> vec)
{
    copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main()
{
    print(solution({"classic", "pop", "classic", "classic", "pop"}, {500, 600, 150, 800, 2500})); //?곗뮆?겼첎?:  1 0 0 1
    return 0;

}

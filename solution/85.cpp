#include <vector>

using namespace std;

int solution(int N, vector<int> stations, int W) {
  int answer = 0;
  int location = 1; // ???꾩옱 ?먯깋?섎뒗 ?꾪뙆?몄쓽 ?꾩튂
  int idx = 0; // ???ㅼ튂??湲곗?援?쓽 ?몃뜳??

  while (location <= N) {
    // ??湲곗?援?씠 ?ㅼ튂???꾩튂???꾨떖??寃쎌슦
    if (idx < stations.size() && location >= stations[idx] - W) {
      location = stations[idx] + W + 1;
      idx++;
    }
    // ??湲곗?援?씠 ?ㅼ튂?섏? ?딆? ?꾩튂??寃쎌슦
    else {
      // ??湲곗?援?쓣 ?ㅼ튂?섍퀬 ?대떦 踰붿쐞瑜??섏뼱媛?
      location += 2 * W + 1;
      answer++;
    }
  }

  return answer;
}

//?꾨옒 肄붾뱶???뚯뒪??肄붾뱶 ?낅땲??
#include <iostream>

int main()
{
    cout << solution(11, {4, 11}, 1) << endl; // 3
    cout << solution(16, {9}, 1) << endl;   // 5
    return 0;
}

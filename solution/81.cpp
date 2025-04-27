#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

//??媛?臾쇨굔???⑥쐞 臾닿쾶??媛移섎? 怨꾩궛?섏뿬 items 踰≫꽣??異붽?
void calculate_unit_value(vector<vector<double>> &items) {
  for (auto &item : items) {
    item.push_back(item[1] / item[0]);
  }
}

//???⑥쐞 臾닿쾶??媛移섍? ?믪? ?쒖쑝濡?臾쇨굔???뺣젹
void sort_by_unit_value(vector<vector<double>> &items) {
  sort(items.begin(), items.end(), [](const vector<double> &a, const vector<double> &b) {
    return a[2] > b[2];
  });
}

double knapsack(vector<vector<double>> &items, double weight_limit) {
  double total_value = 0; //???좏깮??臾쇨굔?ㅼ쓽 珥?媛移섎? ???
  double remaining_weight = weight_limit; //?밸궓? 臾닿쾶 ?쒕룄瑜????

  //??items???쒗쉶?섎ŉ 臾쇨굔???좏깮
  for (const auto &item : items) {
    if (item[0] <= remaining_weight) {
      //???⑥? 臾닿쾶 ?쒕룄 ?댁뿉??臾쇨굔???듭㎏濡??좏깮
      total_value += item[1];
      remaining_weight -= item[0];
    } else {
      //???⑥? 臾닿쾶 ?쒕룄媛 臾쇨굔??臾닿쾶蹂대떎 ?묒쑝硫?履쇨컻???쇰?遺꾨쭔 ?좏깮
      double fraction = remaining_weight / item[0];
      total_value += item[1] * fraction;
      break; //???대? 諛곕궘??臾닿쾶 ?쒕룄瑜?紐⑤몢 ?ъ슜??寃쎌슦
    }
  }
  return total_value;
}

double solution(vector<vector<double>> items, double weight_limit) {
  calculate_unit_value(items);
  sort_by_unit_value(items);
  //??諛곕궘??臾닿쾶 ?쒕룄 ?댁뿉???댁쓣 ???덈뒗 臾쇨굔?ㅼ쓽 理쒕? 媛移섎? 諛섑솚(?뚯닔???섏㎏?먮━ 源뚯?留??섑???
  return round(knapsack(items, weight_limit) * 100) / 100;
}

//?꾨옒 肄붾뱶???뚯뒪??肄붾뱶 ?낅땲??
#include <iostream>

int main()
{
  cout << solution({{10, 19}, {7, 10}, {6, 10}}, 15) << endl; //異쒕젰媛?: 27.3333
  cout << solution({{10, 60}, {20, 100}, {30, 120}}, 50) << endl; //異쒕젰媛?: 240
  
  return 0;
}

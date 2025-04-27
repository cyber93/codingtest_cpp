#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int n = progresses.size();
    vector<int> days_left(n); 

    //??媛??묒뾽??????꾨즺源뚯? ?⑥? ?쇱닔 怨꾩궛
    for (int i = 0; i < n; ++i) {
        days_left[i] = ceil((100.0 - progresses[i]) / speeds[i]);
    }

   int count = 0; //??諛고룷 ???묒뾽????
    int max_day = days_left[0]; // ???꾩옱 諛고룷???묒뾽 以?媛????쾶 諛고룷???묒뾽??媛?μ씪
    

    for (int i = 0; i < n; ++i) {
        if (days_left[i] <= max_day) { //??諛고룷 媛?μ씪??媛????? 諛고룷?쇰낫??鍮좊Ⅴ硫?
            count++;
        } else { //??諛고룷 ?덉젙?쇱씠 湲곗? 諛고룷?쇰낫???먮━硫?
            answer.push_back(count);
            count = 1;
            max_day = days_left[i];
        }
    }

    answer.push_back(count); //??留덉?留됱쑝濡?移댁슫?몃맂 ?묒뾽?ㅼ쓣 ?④퍡 諛고룷
    return answer;
}






//?꾨옒 肄붾뱶???뚯뒪??肄붾뱶 ?낅땲??
#include <iostream>
#include <iterator>

void print(vector<int> vec)
{
    copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main()
{
    
    print(solution({93, 30, 55}, {1, 30, 5})); // 2 1
    print(solution({95, 90, 99, 99, 80, 99}, {1, 1, 1, 1, 1, 1})); // 1 3 2
    
    return 0;

}

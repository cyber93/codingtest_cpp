#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
   //??participant瑜??섑????댁떆?뚯씠釉?
    unordered_map<string, int> ph;

   //??媛?李멸??먮뱾???댁떆 ?뚯씠釉붿뿉 異붽?( ??: ?대쫫, 媛?: ?대떦 ?대쫫??紐???
    for (int i = 0; i < participant.size(); i++)
        ph[participant[i]]++;

 
    //??李멸????뺣낫媛 ??λ맂 ?댁떆 ?뚯씠釉붿뿉?? ?꾩＜???좎닔?ㅼ쓣 ?쒖쇅
    for (int i = 0; i < completion.size(); i++)
    {
        ph[completion[i]]--;
        //???댁떆?뚯씠釉붿뿉???뱀젙 ?대쫫???몄썝??0紐낆씠硫? ?댁떆 ?뚯씠釉붿뿉????젣
        if (ph[completion[i]] == 0)
            ph.erase(ph.find(completion[i]));
    }
   //??留덉?留??⑥? ???좎닔???대쫫??諛섑솚 
    return ph.begin()->first;
}



//?꾨옒 肄붾뱶???뚯뒪??肄붾뱶 ?낅땲??

#include <iostream>

int main()
{
    cout << solution({"leo", "kiki", "eden"}, {"eden", "kiki"}) << endl; // "leo"
    cout << solution({"marina", "josipa", "nikola", "vinko", "filipa"}, {"josipa", "filipa", "marina", "nikola"}) << endl; // "vinko"
    cout << solution({"mislav", "stanko", "mislav", "ana"}, {"stanko", "ana", "mislav"}) << endl; // "mislav"
    return 0;

}

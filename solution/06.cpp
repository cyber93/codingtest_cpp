#include <vector>
#include <algorithm>

using namespace std;

// ??臾몄젣?먯꽌 ?붽뎄?섎뒗 議곌굔?濡??ㅽ뙣?⑥쓣 ?뺣젹?섎뒗 ?⑥닔 
bool compare(pair<int, float>& a, pair<int, float>& b) {
    if (a.second == b.second) 
        return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {

    vector<int> answer; // ??answer??理쒖쥌 ??
    vector<float> challenger(N + 2, 0.0);  // ??challenger??媛??ㅽ뀒?댁????꾨떖???곸씠 ?덈뒗 ?꾩쟾?먯쓽 ?? 
    vector<float> fail(N + 2, 0.0); // ??fail???뱀젙 ?ㅽ뀒?댁????ㅽ뙣???꾩쟾?먯쓽 ??

 // ??媛??ㅽ뀒?댁????몄썝??湲곗??쇰줈 ?뱀젙 ?ㅽ뀒?댁??먯꽌 ?ㅽ뙣???몄썝?섏?, 媛??ㅽ뀒?댁????꾩쟾???곸씠 ?덈뒗 ?몄썝?섎? 援ы븿 
    for (int i = 0; i < stages.size(); i++) {
        for (int j = 1; j <= stages[i]; j++)
            challenger[j]++;

        fail[stages[i]]++;
    }
  // ??failRatio???ㅽ뙣?⑥쓣 ??? first??stage?뺣낫?닿퀬 second???ㅽ뙣??
    vector<pair<int, float>> failRatio(N);

 // ???ㅽ뀒?댁? ?뺣낫 諛??ㅽ뙣?⑥쓣 ??? 
  for (int i = 0; i < N; i++) {
        failRatio[i].first = i + 1;

        if (challenger[i + 1] == 0)
            failRatio[i].second = 0;
        else
            failRatio[i].second = fail[i + 1] / challenger[i + 1];
    }

// ??怨꾩궛???ㅽ뙣?⑥쓣 臾몄젣?먯꽌 ?쒖떆??議곌굔??留욊쾶 ?뺣젹
    sort(failRatio.begin(), failRatio.end(), compare);

// ??理쒖쥌 ?듭쓣 諛섑솚?섍린 ?꾪빐 ?ㅽ뙣?⑥쓣 ???
    for (int i = 0; i < N; i++) {
        answer.push_back(failRatio[i].first);
    }

    return answer;
}



//?꾨옒 肄붾뱶???뚯뒪??肄붾뱶 ?낅땲??

#include <iterator>
#include <iostream>
void print(vector<int> vec)
{
    copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main()
{
    print(solution(5, {2, 1, 2, 6, 2, 4, 3, 3})); // 3 4 2 1 5
    print(solution(4, {4, 4, 4, 4, 4}));          // 4 1 2 3 

    return 0;
}

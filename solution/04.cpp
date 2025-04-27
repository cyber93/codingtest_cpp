#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ??媛??섑룷?먭? 李띾뒗 ?⑦꽩???뺤쓽
vector<int> firstPattern  = {1,2,3,4,5};
vector<int> secondPattern = {2,1,2,3,2,4,2,5};
vector<int> thirdPattern  = {3,3,1,1,2,2,4,4,5,5};

vector<int> solution(vector<int> answers) {
   // ??理쒖쥌?곸쑝濡?媛??留롮씠 臾몄젣瑜?留욏엺 ?щ엺????λ맆 踰≫꽣
    vector<int> answer;
    
   // ??媛??섑룷?먮뱾???⑦꽩?濡??듭븞???묒꽦?좊븣 臾몄젣瑜?留욏엺 媛?닔媛 ??λ맆 踰≫꽣
    vector<int> matchCnt(3);

    // ???ㅼ젣 ?뺣떟怨?媛??섑룷?먮뱾???⑦꽩??鍮꾧탳?댁꽌 留욎텣 媛?닔
      for(int i=0; i<answers.size(); i++) {
        if(answers[i] == firstPattern[i % firstPattern.size()]) matchCnt[0]++;
        if(answers[i] == secondPattern[i % secondPattern.size()]) matchCnt[1]++;
        if(answers[i] == thirdPattern[i % thirdPattern.size()]) matchCnt[2]++;
    }
    // ??媛??留롮씠 留욎텣 ?섑룷?먭? ?살? ?먯닔
    int max_score = *max_element(matchCnt.begin(),matchCnt.end());
    
    // ??媛??留롮씠 留욎텣 ?섑룷?먯쓽 踰덊샇瑜????
    for(int i = 0; i< 3; i++) {
        if(matchCnt[i] == max_score) answer.push_back(i+1);
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
    print(solution({1, 2, 3, 4, 5}));     // 1 
    print(solution({1, 3, 2, 4, 2}));     // 1 2 3 
    
    return 0;
}

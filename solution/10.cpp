#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

// ???ロ엺 愿꾪샇??吏앹쓣 諛붾줈 ?뺤씤?????덈룄濡?留??좎뼵 
unordered_map<char, char> bracketPair = {
        {')', '('},
        {']', '['},
        {'}', '{'}
};

//?룻쁽???몄옄濡?諛쏆? 臾몄옄??湲곗? 愿꾪샇吏앹씠 留욌뒗吏 ?뺤씤
bool isValid(string& s, int start) {
    stack<char> stk;
    unsigned int  sz = s.size();
    
//??臾몄옄?댁쓣 ?쒗쉶?섎㈃??
    for(int i = 0 ; i < sz ; i++) {
      char ch = s[(start + i) % sz];
      //??ch媛 ?ロ엺 愿꾪샇 ?멸꼍??
        if(bracketPair.count(ch)) {
           // ???ㅽ깮??鍮꾩뿀嫄곕굹 top ?먯냼媛 ch? 吏앹씠 留욌뒗 ?대┛愿꾪샇媛 ?꾨땶 寃쎌슦 false 諛섑솚
            if(stk.empty() || stk.top() != bracketPair[ch]) return false;
           //??ch? 吏앹씠 留욌뒗 ?대┛愿꾪샇?쇨꼍???대떦 ?대┛愿꾪샇瑜??쒓굅
            stk.pop();
        } else {
           //???대┛ 愿꾪샇?쇨꼍???ㅽ깮???몄떆
            stk.push(ch);
        }
    }
   //?쎌뒪?앹씠 鍮꾩뿀?쇰㈃ true瑜?諛섑솚(鍮꾩뿀?ㅻ뒗寃껋? 愿꾪샇 吏앹씠 留욌떎??寃껋쓣 ?섎?)
    return stk.empty();
}

int solution(string s) {
    int answer = 0;
    int n = s.size();
    
   //??臾몄옄?댁쓣 rotation?섎㈃??愿꾪샇吏앹씠 留욎쑝硫?answer瑜?1利앷? ?쒗궡
    for(int i = 0; i < n; i++) {
        answer += isValid(s,i);
    }
    return answer;
}


//?꾨옒 肄붾뱶???뚯뒪??肄붾뱶 ?낅땲??
#include <iostream>
int main()
{
    cout << solution("[](){}") << endl; // 3
    cout << solution("}]()[{") << endl; // 2 
    cout << solution("[)(]") << endl;   // 0 
    cout << solution("}}}") << endl;    // 0   
    return 0;
}

#include<string>
#include<stack>
using namespace std;

int solution(string s)
{
     stack<char> st;

    for(int i=0;i<s.length();i++){
       //?띠뒪?앹씠 鍮꾩뿀嫄곕굹 ?꾩옱臾몄옄?媛숈? 臾몄옄媛 ?꾨땶 寃쎌슦 ?몄떆
        if(st.empty() || st.top() != s[i]) st.push(s[i]);
      //???꾩옱臾몄옄? ?ㅽ깮??媛??理쒓렐 臾몄옄媛 媛숈? 寃쎌슦 ??
        else st.pop();
    }
   

   //???꾩옱 ?ㅽ깮??鍮꾩뿀嫄곕굹, 臾몄옄?댁쓽 吏앹씠 留욌떎???섎??대?濡?true諛섑솚, ?꾨땲硫?false 諛섑솚
    return st.empty();
}



//?꾨옒 肄붾뱶???뚯뒪??肄붾뱶 ?낅땲??
#include <iostream>

int main()
{
    cout << solution("baabaa") << endl; // 1
    cout << solution("cdcd") << endl;   // 0 
    return 0;
}

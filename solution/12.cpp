#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
   //??媛寃⑹씠 ?⑥뼱吏吏 ?딆? 湲곌컙????ν븳 踰≫꽣    
    vector<int> answer(prices.size());
  // ?ㅽ깮?먮뒗 prices???몃뜳?ㅺ? ?ㅼ뼱媛? ?댁쟾 媛寃⑷낵 ?꾩옱 媛寃⑹쓣 鍮꾧탳?섍린 ?꾪븳 ?⑸룄濡??ъ슜?? 
   stack<int> s;
    
    int priceNum = prices.size();
    
    for(int i=0;i<priceNum;i++){
        while(!s.empty()&&prices[s.top()]>prices[i]){
           //??媛寃⑹씠 ?⑥뼱議뚯쑝誘濡??댁쟾 媛寃⑹쓽 湲곌컙 怨꾩궛 
            answer[s.top()] = i-s.top();
            s.pop();
        }
        s.push(i);
    }
    //???ㅽ깮???⑥븘?덈뒗 媛寃⑸뱾? 媛寃⑹씠 ?⑥뼱吏吏 ?딆? 寃쎌슦
    while(!s.empty()){
        answer[s.top()] = priceNum-s.top()-1;
        s.pop();
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
    print(solution({1, 2, 3, 2, 3})); // 4 3 1 1 0
    return 0;

}

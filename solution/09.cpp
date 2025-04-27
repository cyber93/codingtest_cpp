#include <stack>
#include <string>
using namespace std;

string solution(int decimal) {
   //?띠엯??媛믪씠  0??寃쎌슦 諛붾줈 泥섎━
    if (decimal == 0) return "0"; 

    stack<int> stack;
    while (decimal > 0) {
        //??2濡??섎늿 ?섎㉧吏瑜??ㅽ깮???쎌엯
        stack.push(decimal % 2);  
        decimal /= 2;
    }

    string binary = "";
    while (!stack.empty()) {
       //???ㅽ깮?먯꽌 李⑤??濡?top()???대떦?섎뒗 媛믪쓣 binary??異붽?
        binary += to_string(stack.top());  
        stack.pop();
    }
    return binary;
}


//?꾨옒 肄붾뱶???뚯뒪??肄붾뱶 ?낅땲??
#include <iostream>
int main()
{
    cout << solution(10) << endl;       // 1010
    cout << solution(27) << endl;       // 11011 
    cout << solution(12345) << endl;    // 11000000111001 
   
    return 0;
}

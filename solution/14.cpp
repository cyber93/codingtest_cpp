#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
   
   //?띠궘?????됱쓽 ?몃뜳?ㅻ? ???
    stack<int> deleted;
   //??媛??됱쓽 ?꾩븘?섏뿉 ?덈뒗 ?됱쓽 ?몃뜳?ㅻ? ???
    vector<int> up;
    vector<int> down;

    for (int i = 0; i < n + 2; i++) {
        up.push_back(i - 1);
        down.push_back(i + 1);
    }
  //???꾩떆怨듦컙??怨좊젮???꾩옱?꾩튂 
  k++;

  //??二쇱뼱吏?紐낅졊?대? ?쒗쉶  
  for (int i = 0; i < cmd.size(); i++) {
        //???꾩옱 ?꾩튂瑜???젣?섍퀬 洹??ㅼ쓬 ?꾩튂濡??대룞
        if (cmd[i][0] == 'C') {
            deleted.push(k);
            down[up[k]] = down[k];
            up[down[k]] = up[k];

            if (down[k] == n + 1) k = up[k];
            else k = down[k];
        }

        //??媛??理쒓렐????젣???됱쓣 蹂듭썝
        else if (cmd[i][0] == 'Z') {
            int r = deleted.top();
            down[up[r]] = r;
            up[down[r]] = r;
            deleted.pop();
        } 

        //?? ?꾩옱 ?됱쓣 二쇱뼱吏?媛?留뚰겮 ?꾪샊? ?꾨옒濡??대룞
        else { 
            int sz = stoi(cmd[i].substr(2));
            
            if (cmd[i][0] == 'U') {
                for (int j = 0; j < sz; j++) {
                    k = up[k];
                }
            }
                  
            else if (cmd[i][0] == 'D') {
                for (int j = 0; j < sz; j++) {
                    k = down[k];
                }
            }
        }
        
    }

    string answer;
   
    //????젣???됱쓽 ?꾩튂???쏼?? 洹몃젃吏 ?딆? ?됱쓽 ?꾩튂???쏼??濡??쒖떆??臾몄옄??諛섑솚
    answer.append(n, 'O');
    while (!deleted.empty()) {
        answer[deleted.top() - 1] = 'X';
        deleted.pop();
    }

    return answer;
}

//?꾨옒 肄붾뱶???뚯뒪??肄붾뱶 ?낅땲??
#include <iostream>

int main()
{
    
    cout << solution(8, 2, {"D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z"}) << endl;              //OOOOXOOO
    cout << solution(8, 2, {"D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z", "U 1", "C"}) << endl;  //OOXOXOOO
    return 0;
}

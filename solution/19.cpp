#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

// ???ㅽ빆 ?댁떆 ?⑥닔 援ы쁽
long long polynomial_hash(const string& str) {
    const int p = 31;  // ?뚯닔
    const long long m = 1000000007;  // 踰꾪궥 ?ш린
    long long hash_value = 0;
    
    for (char c : str) {
        hash_value = (hash_value * p + c) % m;
    }
    
    return hash_value;
}

vector<bool> solution(vector<string> string_list, vector<string> query_list) {
    unordered_set<long long> hash_set;
    
    //??string_list??媛?臾몄옄?댁뿉 ????ㅽ빆 ?댁떆媛믪쓣 怨꾩궛?섍퀬 ???
    for (const string& str : string_list) {
        long long hash = polynomial_hash(str);
        hash_set.insert(hash);
    }
    
    vector<bool> result;
    
    //?? query_list??媛?臾몄옄?댁씠 string_list???덈뒗吏 ?뺤씤?섍퀬 result??異붽?
    for (const string& query : query_list) {
        long long query_hash = polynomial_hash(query);
        bool found = (hash_set.find(query_hash) != hash_set.end());
        result.push_back(found);
    }
    // ??query_list??臾몄옄?댁씠 hash???덈뒗吏 寃곌낵媛 ??λ맂 result瑜?諛섑솚
    return result;
}


//?꾨옒 肄붾뱶???뚯뒪??肄붾뱶 ?낅땲??
#include <iterator>
#include <iostream>
void print(vector<bool> vec)
{
    copy(vec.begin(), vec.end(), std::ostream_iterator<bool>(cout, " "));
    cout << endl;
}

int main()
{
    //true瑜?異쒕젰?섎㈃ 1?대릺怨?false瑜?異쒕젰?섎㈃ 0
    print(solution({"apple", "banana", "cherry"}, {"banana", "kiwi", "melon", "apple"})); // 1 0 0 1
    return 0;

}

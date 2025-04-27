#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) { 
    set<int> sum; // ?????섏쓽 ?⑹쓣 ??ν븷 ??κ났媛??좎뼵

    for(int i = 0;i<numbers.size();++i)  // ??諛섎났臾몄쓣 ?섑뻾?섎㈃?????섏쓽 ?⑹쓣 ???
        for(int j = i+1 ; j< numbers.size();++j)
           sum.insert(numbers[i] + numbers[j]); 

    vector<int> answer(sum.begin(), sum.end()); // ??諛섑솚??낆쓣 留욎텛湲??꾪뿤 踰≫꽣濡?蹂??
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
    print(solution({2, 1, 3, 4, 1}));     // 2 3 4 5 6 7 
    print(solution({5, 0, 2, 7}));        // 2 5 7 9 12 
    
    return 0;
}

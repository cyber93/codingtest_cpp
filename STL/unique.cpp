﻿//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################
#include <iostream>
#include <vector>
#include <algorithm> // for std::unique and std::sort
using namespace std;

/*
std::unique 함수는 주어진 범위에서 인접한 중복 요소를 재배치합니다.
이 함수는 정렬된 상태에서 사용하면 모든 중복 요소를 올바르게 처리할 수 있습니다.

주의해야 할 점:
1. 정렬된 상태에서 사용: unique 함수는 인접한 중복 요소만 재배치하므로, 
   중복 요소를 완전히 제거하기 위해서는 범위가 정렬된 상태여야 합니다.
2. 반환값: 새로운 끝 부분을 반환합니다. 실제로 중복 요소를 제거하는 것이 아니라,
   중복되지 않은 요소를 앞으로 재배치합니다.
3. 벡터 크기 조정: 중복 요소를 재배치한 후, 반환된 새로운 끝 부분까지 벡터를 잘라내어야 합니다.
4. 새로운 범위: 반환된 반복자는 중복되지 않은 요소로 이루어진 새로운 범위의 끝을 나타냅니다.
   이 범위는 벡터의 시작부터 반환된 반복자 전까지입니다.

시간복잡도:
- std::unique 함수의 시간복잡도는 O(N)입니다. 여기서 N은 범위 내의 요소 수입니다.
- std::vector::erase 함수의 시간복잡도도 O(N)입니다. 범위의 요소들을 제거하고 나머지 요소들을 앞으로 이동시키기 때문입니다.

예제:
벡터가 {1, 2, 2, 3, 3, 3, 4, 4, 5}로 주어졌을 때,
unique(v.begin(), v.end())를 호출하면,
벡터는 {1, 2, 3, 4, 5, 3, 4, 4, 5}로 변환되고, 반환된 new_end는 첫 번째 5를 가리킵니다.
v.erase(new_end, v.end())를 호출하면, 벡터는 {1, 2, 3, 4, 5}로 변환됩니다.
*/

int main() {
    // 예시 벡터 생성 (정렬되지 않은 상태)
    vector<int> v1 = {3, 1, 2, 3, 2, 4, 1, 5, 3};

    // 중복 요소 재배치 (정렬되지 않은 상태에서)
    auto last1 = unique(v1.begin(), v1.end());

    // 결과 출력 (정렬되지 않은 상태에서 unique 사용 후)
    cout << "정렬되지 않은 상태에서 unique 사용 후:\n";
    for (auto it = v1.begin(); it != last1; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // 벡터를 정렬된 상태로 만들기
    vector<int> v2 = {3, 1, 2, 3, 2, 4, 1, 5, 3};
    sort(v2.begin(), v2.end());

    // 중복 요소 재배치 (정렬된 상태에서)
    auto last2 = unique(v2.begin(), v2.end());

    // 새로운 끝 부분까지 벡터를 잘라내기
    v2.erase(last2, v2.end());

    // 결과 출력 (정렬된 상태에서 unique 사용 후)
    cout << "정렬된 상태에서 unique 사용 후:\n";
    for (int num : v2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

/*
출력값:

정렬되지 않은 상태에서 unique 사용 후:
3 1 2 3 2 4 1 5 3 

정렬된 상태에서 unique 사용 후:
1 2 3 4 5
*/

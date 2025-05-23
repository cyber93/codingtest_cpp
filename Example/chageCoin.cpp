﻿#include <iostream>
#include <vector>

using namespace std;

// 문제의 정의:
// 주어진 거스름돈을 1원, 5원, 10원, 50원, 100원, 500원의 동전을 사용하여
// 최소 개수의 동전으로 거슬러 주는 문제입니다.

// 왜 그리디로 풀리는지:
// 탐욕적 선택 속성: 매 단계에서 가장 큰 단위의 동전을 선택하여,
// 나머지 금액을 거슬러 줍니다. 큰 단위의 동전을 선택하는 것이 항상
// 최적의 해를 보장합니다.
// 최적 부분구조: 현재 금액을 가장 큰 단위로 거슬러 준 후,
// 남은 금액에 대해 같은 문제를 반복하여 해결할 수 있습니다.
// 즉, 부분 문제의 최적해가 전체 문제의 최적해로 이어집니다.

// 왜 최적의 해를 보장하는가:
// 1. 탐욕적 선택 속성: 가장 큰 단위의 동전을 선택하는 것이
//    최적의 해를 보장하는 이유는, 큰 단위의 동전이 작은 단위의 동전보다
//    더 많은 금액을 커버할 수 있기 때문입니다. 예를 들어, 500원을 선택하면
//    100원을 5개 사용하는 것보다 적은 개수의 동전으로 같은 금액을 커버할 수 있습니다.
// 2. 최적 부분구조: 주어진 문제를 작은 부분 문제로 나눌 수 있으며,
//    각 부분 문제의 최적해가 전체 문제의 최적해를 구성합니다. 예를 들어,
//    837원을 거슬러 줄 때, 500원을 선택하면 남은 337원을 거슬러 주는 문제로
//    축소됩니다. 이때, 337원을 최적으로 거슬러 주는 방법이 전체 문제를 최적으로
//    해결하는 방법이 됩니다.

int main() {
    // 거스름돈 변수 (예: 837원)
    int change = 837;

    // 동전 단위 배열 (큰 단위부터)
    vector<int> coins = {500, 100, 50, 10, 5, 1};
    vector<int> count(coins.size(), 0);

    // 코드 상세 동작:
    // 큰 단위의 동전부터 차례로 거스름돈을 나누어 줍니다.
    for (int i = 0; i < coins.size(); i++) {
        if (change >= coins[i]) {
            // 현재 동전 단위로 거슬러 줄 수 있는 최대 개수를 계산합니다.
            count[i] = change / coins[i];
            // 거슬러 준 금액을 제외한 나머지 금액을 계산합니다.
            change %= coins[i];
        }
    }

    // 결과 출력: 각 동전 단위별로 사용된 개수를 출력합니다.
    cout << "최소 동전 개수: " << endl;
    for (int i = 0; i < coins.size(); i++) {
        if (count[i] != 0) {
            cout << coins[i] << "원: " << count[i] << "개" << endl;
        }
    }

    return 0;
}

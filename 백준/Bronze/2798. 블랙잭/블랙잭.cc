#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<int> cards(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> cards[i];
    }

    sort(cards.begin(), cards.end());

    int closest_sum = 0;

    // 첫 번째 카드의 인덱스
    for (int i = 0; i < N - 2; ++i) {
        // 두 번째 카드의 포인터
        for (int j = i + 1; j < N - 1; ++j) {
            int left = j + 1; // 세 번째 카드의 시작 포인터
            int right = N - 1; // 세 번째 카드의 끝 포인터

            while (left <= right) {
                int current_sum = cards[i] + cards[j] + cards[left];
                
                if (current_sum <= M) {
                    closest_sum = max(closest_sum, current_sum);
                    left++; // 합을 증가시키기 위해 왼쪽 포인터 이동
                } else {
                    right--; // 합을 줄이기 위해 오른쪽 포인터 이동
                }
            }
        }
    }

    cout << closest_sum << '\n';
    return 0;
}
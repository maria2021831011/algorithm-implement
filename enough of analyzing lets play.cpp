
#include <iostream>
#include <vector>
 using namespace std;
int calculateNimSum(const vector<int>& piles) {
    int nimSum = 0;
    for (int pile : piles) {
        nimSum ^= pile;
    }
    return nimSum;
}
int countWinningMoves(const vector<int>& piles) {
    int nimSum = calculateNimSum(piles);
    int count = 0;
    for (int pile : piles) {
        int targetNimSum = nimSum ^ pile;
        if ((targetNimSum < pile) || (pile == targetNimSum && pile != 0)) {
            count++;
        }
    }
    return count;
}
 int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        int n;
        cin >> n;

        vector<int> piles(n);
        for (int i = 0; i < n; ++i) {
            cin >> piles[i];
        }

        int winningMoves = countWinningMoves(piles);
        cout << "Case " << t << ": " << winningMoves << endl;
    }

    return 0;
}

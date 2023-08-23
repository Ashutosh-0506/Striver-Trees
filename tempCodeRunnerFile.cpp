#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int m, k, a1, ak;
        cin >> m >> k >> a1 >> ak;

        int max_regular = min(a1, (m - ak + k - 1) / k);
        int num_fancy = max(0, (m - max_regular * 1 + k - 1) / k);

        cout << num_fancy + max_regular << endl;
    }

    return 0;
}

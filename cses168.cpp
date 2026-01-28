#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int MAX = 1e6;
    vector<int> cnt(MAX + 1, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }


    vector<int> freq(MAX + 1, 0);
    for (int d = 1; d <= MAX; d++) {
        for (int m = d; m <= MAX; m += d) {
            freq[d] += cnt[m];
        }
    }

    vector<int> mu(MAX + 1, 1);
    vector<bool> isprime(MAX + 1, true);
    vector<int> prime;

    isprime[0] = false;
    isprime[1] = false;

    for (int i = 2; i <= MAX; i++) {
        if (isprime[i]) {
            prime.push_back(i);
            mu[i] = -1;
        }
        for (int p : prime) {
            if (1LL * p * i > MAX) break;
            isprime[p * i] = false;
            if (i % p == 0) {
                mu[p * i] = 0;
                break;
            } else {
                mu[p * i] = -mu[i];
            }
        }
    }

    long long answer = 0;
    for (int d = 1; d <= MAX; d++) {
        if (mu[d] != 0 && freq[d] >= 2) {
            answer += 1LL * mu[d] * freq[d] * (freq[d] - 1) / 2;
        }
    }

    cout << answer << '\n';
    return 0;
}

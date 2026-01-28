#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

vector<bool> prime(N + 1, true);
vector<int> spf(N + 1);

void sieve() {
    prime[0] = prime[1] = false;

    for (int i = 2; i * i <= N; i++) {
        if (spf[i] == i) { 
            for (int j = i * i; j <= N; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
                prime[j] = false;
            }
        }
    }
}

int solve(int a) {
    unordered_map<int, int> mpp;

    while (a > 1) {
        mpp[spf[a]]++;
        a = a / spf[a];
    }

    int ans = 1;
    for (auto &it : mpp) {
        ans *= (it.second + 1);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 1; i <= N; i++) {
        spf[i] = i;
    }

    sieve();

    int n;
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        cout << solve(a) << '\n';
    }
}

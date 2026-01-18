#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long x;
    cin >> n >> x;

    vector<pair<long long,int>> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i + 1; // original index
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++) {
        // skip duplicate i
        if(i > 0 && v[i].first == v[i-1].first) continue;

        for(int j = i + 1; j < n; j++) {
            // skip duplicate j
            if(j > i + 1 && v[j].first == v[j-1].first) continue;

            int l = j + 1, r = n - 1;
            while(l < r) {
                long long sum =
                    v[i].first + v[j].first +
                    v[l].first + v[r].first;

                if(sum == x) {
                    cout << v[i].second << " "
                         << v[j].second << " "
                         << v[l].second << " "
                         << v[r].second << endl;
                    return 0;
                }
                else if(sum < x) {
                    l++;
                    // skip duplicate l
                    while(l < r && v[l].first == v[l-1].first) l++;
                }
                else {
                    r--;
                    // skip duplicate r
                    while(l < r && v[r].first == v[r+1].first) r--;
                }
            }
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}

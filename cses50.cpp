#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long x;
    cin >> n >> x;

    vector<pair<long long,int>> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i + 1;  // original index
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++) {

        if(i > 0 && v[i].first == v[i-1].first) continue;

        int j = i + 1, k = n - 1;
        while(j < k) {
            long long sum = v[i].first + v[j].first + v[k].first;

            if(sum == x) {
                cout << v[i].second << " "
                     << v[j].second << " "
                     << v[k].second << endl;
                return 0;
            }
            else if(sum < x) {
                j++;
                while(j < k && v[j].first == v[j-1].first) j++;
            }
            else {
                k--;
                while(j < k && v[k].first == v[k+1].first) k--;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}

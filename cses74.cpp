#include<bits/stdc++.h>
using namespace std;
vector<vector<long long>> dp;

long long func(int ind1, int ind2, vector<long long>& v) {

    if (ind1 > ind2) {
        return 0;
    }
    if (ind1 == ind2) {
        return v[ind1];
    }


    if (dp[ind1][ind2] != -1) {
        return dp[ind1][ind2];
    }

    long long choice1 = v[ind1] - func(ind1 + 1, ind2, v);
    long long choice2 = v[ind2] - func(ind1, ind2 - 1, v);

   
    return dp[ind1][ind2]=max(choice1,choice2);

   
}

int main() {
    int n;
    cin >> n;
    vector<long long> v(n);
    long long total=0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        total+=v[i];
    }
    dp.assign(n, vector<long long>(n, -1));
    long long ans=func(0, n - 1, v);
    cout << (total+ans)/2 << endl;
    return 0;
}

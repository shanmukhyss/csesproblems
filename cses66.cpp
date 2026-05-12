#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cin>>n>>x;

    vector<int> prices(n), pages(n);
    for(int i=0;i<n;i++) cin>>prices[i];
    for(int i=0;i<n;i++) cin>>pages[i];

    vector<vector<int>> dp(n+1 , vector<int>(x+1 , 0));

    for(int ind=n-1; ind>=0; ind--){
        for(int target=0; target<=x; target++){
            int nottake = dp[ind+1][target];
            int take = 0;

            if(target >= prices[ind]){
                take = pages[ind] + dp[ind+1][target - prices[ind]];
            }

            dp[ind][target] = max(take, nottake);
        }
    }

    cout<<dp[0][x]<<endl;
    return 0;
}
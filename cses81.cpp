#include<bits/stdc++.h>
using namespace std;
string s;
map<vector<int>,long long>mpp;
long long func(int ind, int prev, bool equal, bool empty){
    if(ind==s.size()){
        return 1;
    }
    if(mpp.count({ind,prev,equal,empty})){
        return mpp[{ind,prev,equal,empty}];
    }
    long long result=0;
    for(int d=0;d<=9;d++){
        if(equal && d>s[ind]-'0'){
            break;
        }
        if(!empty && d==prev){
           continue;
        }
        result+=func(ind+1,d,equal && d==s[ind]-'0',empty && d==0);
        
    }
    return mpp[{ind,prev,equal,empty}]=result;
}
long long count(long long x){
    mpp.clear();
    s= to_string(x);
    return func(0,0,true,true);
}
int main(){
    long long a,b;
    cin>>a>>b;
    if(a>=b){
        swap(a,b);
    }
    cout<< count(b)-count(a-1)<<endl;
    return 0;
}
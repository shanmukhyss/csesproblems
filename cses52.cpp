#include<bits/stdc++.h>
using namespace std;

vector<long long> pse(vector<long long>v){
    int n=v.size();
    stack<long long>st;
    vector<long long>arr(n,0);
    for(int i=0;i<n;i++){
        while(!st.empty()&&v[st.top()-1]>=v[i]){
            st.pop();
        }
        if(st.empty()){
            arr[i]=0;

        }
        else{
            arr[i]=st.top();
        }
        st.push(i+1);
    }
    return arr;
}
int main(){
    int n;
    cin>>n;
    vector<long long>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<long long>arr=pse(v);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;

   
}
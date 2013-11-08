#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long n,m,k,i,s;
    long long a[20001],ans[20001];
    cin>>n;
    for (i=0;i<n;i++){
        cin>>k;
        a[k+10000]+=1;
    }
    cin>>m;
    for (i=0;i<m;i++){
        cin>>k;
        if (a[k+10000]>0)
            a[k+10000]-=1;
        else{
            ans[k+10000]=1;
        }
    }
    for(i=0;i<20001;i++) 
        if (ans[i]==1) cout<<i-10000<<" ";
    cout<<endl;
    return 0;
}


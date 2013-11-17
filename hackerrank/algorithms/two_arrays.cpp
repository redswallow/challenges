#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t,n,i,j;
    long long k;
    long long a[1000],b[1000];
    bool flag;
    cin>>t;
    while (t--){
        cin>>n>>k;
        for (i=0;i<n;i++) cin>>a[i];
        for (i=0;i<n;i++) cin>>b[i];
        sort(a,a+n);
        sort(b,b+n);
        flag=true;
        for (i=0;i<n;i++)
            if (a[i]+b[n-1-i]<k){
                flag=false;break;
            }
        if (flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}


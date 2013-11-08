#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n,i,s;
    long long k;
    long long a[100000];
    cin>>n>>k;
    for (i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    s=0;
    for (i=0;i<n;i++){
        s+=a[i];
        if (s>k){
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}

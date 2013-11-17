#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    long long n,i,j;
    int a[1000002];
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    cout<<a[n/2]<<endl;
    return 0;
}


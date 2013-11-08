#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    long long n,k,i,j,diff,result=0;
    long long a[100001];
    cin>>n>>k;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            diff=a[j]-a[i];
            if (diff>k) break;
            else if (diff==k){
                result++;
                break;
            }
        }
    }
    cout<<result<<endl;
    return 0;
}



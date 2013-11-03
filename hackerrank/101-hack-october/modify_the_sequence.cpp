#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const long long maxn=1000001;
const long long oo=0x3fffffff;

long long a[maxn],lis[maxn],pos[maxn];

int main() {
    long long n,i;
    cin>>n;
        for (i=1;i<=n;i++)
            cin>>a[i];
        long long top=0;lis[0]=-oo;
        for (i=1;i<=n;i++){
            if (a[i]>lis[top] && a[i]-lis[top]-1>=i-pos[top]-1){
                lis[++top]=a[i];
                pos[top]=i;
            }else{
                long long l=0,r=top,tp=-1;
                while(l<=r){
                    long long mid=(l+r)>>1;
                    if (a[i]-lis[mid]-1>=i-pos[mid]-1){
                        tp=mid;
                        l=mid+1;
                    }else r=mid-1;
                }
                if (tp!=1) lis[tp+1]=a[i],pos[tp+1]=i;
            }
        }
        cout<<n-top<<endl;
    return 0;
}


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long f(long long a,long long b){
    return 2*a+b;
}

int main() {
    int i,j,t;
    long long x,temp,len,a,b,num4[10000],num0[10000],num[10000];
    bool done;
    cin>>t;
    for (i=0;i<t;i++){
        cin>>x;
        len=1;done=false;
        temp=1;num0[0]=1;
        for (j=1;j<1000;j++){
            temp=(temp*10)%x;
            num0[j]=temp;
        }
        temp=0;
        for (j=1;j<1000;j++){
            temp=(temp*10+4)%x;
            num4[j]=temp;
        }
        while (!done){
            for (a=1;a<=len;a++){
                b=len-a;
                if (((num4[a]%x)*(num0[b]%x))%x==0){
                    cout<<f(a,b)<<endl;
                    done=true;
                    break;
                }
            }
            len+=1;
        }

    }
    return 0;
}


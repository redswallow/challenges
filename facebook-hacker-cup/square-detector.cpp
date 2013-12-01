#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>

using namespace std;

ofstream fout ("square-dectector.out");
ifstream fin ("square_detector.txt");
int t,ti,n,i,j,nBlackCell,squareLen;
int a[20][20],sum[20][20];
char ch;

int squareCheck(int l){
    int i,j;
    for(i=1;i<=n-l+1;i++)
    for(j=1;j<=n-l+1;j++)
        if (l*l==sum[i+l-1][j+l-1]-sum[i+l-1][j-1]-sum[i-1][j-l+1]+sum[i-1][j-1])
            return 1;
    return 0;
}

int main() {
    fin>>t;
    for(ti=0;ti<t;ti++){
        fin>>n;
        nBlackCell=0;
        for(i=1;i<=n;i++)
        for(j=1;j<=n;j++){
            fin>>ch;
            if(ch=='.') a[i][j]=0;
            else {
                a[i][j]=1;
                nBlackCell+=1;
            }
        }
        squareLen=int(sqrt(nBlackCell));
        fout<<"Case #"<<ti+1<<": "; 
        if (pow(squareLen,2)==nBlackCell){
            memset(sum,0,sizeof(sum));
            for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                sum[i][j]=a[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
            if (squareCheck(squareLen)) fout<<"YES"<<endl;
            else fout<<"NO"<<endl;
        }
        else fout<<"NO"<<endl;
    }
    return 0;
}

#include <iostream.h>
using namespace std;

int main(){
    int t,n,c,m,i,ans;
    cin>>t;
    for(i=1;i<=t;i++){
        cin>>n>>c>>m;
        n=n/c;ans=n;
        while(n>=m){
            ans+=n/m;n=n%m+n/m;
        }
        cout<<ans<<endl;
    }
    return 0;
}

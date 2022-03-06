#include <iostream>
using namespace std;
int n,k;
int res=0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    while(n--){
        cin>>k;
        int cnt=0;
        for(int i=1;i<=k;i++){
            if(k%i==0){
                cnt++;
            }
        }
        if(cnt==2){
            res++;
        }
    }
    cout<<res;
}

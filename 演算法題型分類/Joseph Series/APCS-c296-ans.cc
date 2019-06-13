// 動態規劃解法(請參考投影片找規律)
#include<bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;
    while(cin>>n>>m>>k){
        int lucky=0;
        for(int i=n-k+1;i<=n;i++)
            lucky=(lucky+m)%i;
        cout<<lucky+1<<'\n';
    }
    return 0;
}
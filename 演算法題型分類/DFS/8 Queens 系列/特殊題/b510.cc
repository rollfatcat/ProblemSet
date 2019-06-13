// 有趣的題型：擺城堡和擺皇后的判斷方式不同,每次DFS時兩種都嘗試擺(如果還有數量)
#include<iostream>
using namespace std;

int M, N, K, cnt;
int pos_x[10], type[10], tnum;
int Lslash[21], Rslash[21], col[10];
int *ls=&Lslash[0];  //=== /  範圍變化：x+y =   0 ~ 20
int *rs=&Rslash[10]; //=== \  範圍變化：x-y = -10 ~ 10

void DFS(int y,int m,int n){
  if(y==K){
    cnt++;
    //for(int i=0;i<K;i++,cout<<endl)
    //  for(int j=0;j<K;j++)
    //    if(pos_x[i]==j) cout<<((type[i])?'Q':'C');
    //    else        cout<<'-';
    //cout<<endl;
    return;
  }
  for(int i=0;i<K;i++){ //擺哪邊
    if(col[i]==0){
      //pos_x[y]=i;
      //===放皇后, 把兩側的對角線方程式數值設定成K
      if(m>0 and ls[i+y]==0 and rs[i-y]==0){
        //type[y]=1;
        ls[i+y]=rs[i-y]=K,  col[i]=1;
        DFS(y+1,m-1,n);
        ls[i+y]=rs[i-y]=col[i]=0;
      }
      //===放城堡, 把兩側的對角線方程式數值+1, 這樣回朔時-1
      //===實現：對角線都沒有城堡或是皇后時可以任意放置的情況
      if(n>0 and ls[i+y]<K and rs[i-y]<K){
        //type[y]=0;
        ls[i+y]++,  rs[i-y]++,  col[i]=1;
        DFS(y+1,m,n-1);
        ls[i+y]--,  rs[i-y]--,  col[i]=0;
      }
    }
  }
}
int main(){
  while(cin>>M>>N){
    K=M+N;
    // Initial
    cnt=0;
    fill(col,col+K,0);
    fill(ls,ls+2*K,0);
    fill(rs-K,rs+K,0);
    // GoMap
    DFS(0,M,N);
    cout<<cnt<<endl;
  }
}
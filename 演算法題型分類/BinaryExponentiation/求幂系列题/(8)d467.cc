// 以位數為單位, 壓在極限時間: 6.4s
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

vector<int> base[2], num[2];
int Blen[2], Nlen[2];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  for(int Pn,x,st,cnt, len; cin>>x>>Pn>>st>>cnt; ){
    base[0].clear(), num[0].assign(1,1), Nlen[0]=1;
    for(Blen[0]=0; x>0; x/=10)
      base[0].push_back(x%10), Blen[0]++;

    bool now=0, nxt=1, Nnow=0, Nnxt=1;
    for(; true;now=nxt, nxt^=1){
      if(Pn%2){
        Nlen[Nnxt]=Nlen[Nnow]+Blen[now];
        num[Nnxt].clear(), num[Nnxt].resize(Nlen[Nnxt]);
        for(int i=0; i<Nlen[Nnow]; i++)
          for(int j=0; j<Blen[now]; j++)
            num[Nnxt][i+j]+=(num[Nnow][i]*base[now][j]);
        for(int i=0, carry=0;i<Nlen[Nnxt];i++)
          num[Nnxt][i]+=carry, carry=num[Nnxt][i]/10, num[Nnxt][i]%=10;
        for(Nlen[Nnxt]--; Nlen[Nnxt]>=0 and num[Nnxt][Nlen[Nnxt]]==0; Nlen[Nnxt]--);
        Nlen[Nnxt]++;
        Nnow=Nnxt, Nnxt^=1;
      }
      Pn/=2;
      if(Pn==0) break;
      // 底數相乘
      Blen[nxt]=2*Blen[now];
      base[nxt].clear(), base[nxt].resize(Blen[nxt]);
      for(int i=0; i<Blen[now]; i++)
        for(int j=0; j<Blen[now]; j++)
          base[nxt][i+j]+=base[now][i]*base[now][j];
      for(int i=0,carry=0; i<Blen[nxt]; i++)
        base[nxt][i]+=carry, carry=(base[nxt][i]/10), base[nxt][i]%=10;
      for(Blen[nxt]--; base[nxt][Blen[nxt]]==0;Blen[nxt]--);
      Blen[nxt]++;
    }
    for(int i=0, j=Nlen[Nnow]-st; i<cnt and j-i>=0; i++)
      cout<<num[Nnow][j-i];
    cout<<endl;
  }
  puts("From tomcat6 Fri Mar 15 09:53:56 2013\nTo: world\"\nSubject: \"Hello");
}
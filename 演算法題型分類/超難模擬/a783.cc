// 題目給予一堆建築物的資訊，在二維平面上畫出天際線

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int main(){
  int N, Bs, Bw, Bh, MaxH;
  char ss[51][21];

  while(cin>>N){
    int h[51]={};
    memset(ss,' ',sizeof(ss));
    // 重疊區域保留最高的
    while(N--){
      cin>>Bs>>Bw>>Bh, Bw++, Bh++;
      for(int i=0;i<=Bw and Bs+i<=50;i++)
        h[Bs+i]=max(h[Bs+i],Bh);
    }
    MaxH=h[0]=h[1];
    for(int i=1;i<=50;i++){
      MaxH=max(MaxH,h[i]);
      if(h[i-1]==h[i])
        ss[i][h[i]]='-';
      else if(h[i-1]<h[i]){
        ss[i][h[i-1]]='+';
        for(int Th=h[i-1]+1; Th<h[i]; Th++)
          ss[i][Th]='|';
        ss[i][h[i]]='+';
      } else {
        ss[i-1][h[i-1]]='+';
        for(int Th=h[i-1]-1; Th>h[i]; Th--)
          ss[i-1][Th]='|';
        ss[i-1][h[i]]='+';
        ss[i][h[i]]='-';
      }
    }
    for(int i=MaxH;i>=0;i--,cout<<endl)
      for(int j=1;j<=50;j++)
        cout<<ss[j][i];
    for(int j=1;j<=50;j++)
        cout<<j%10;
    cout<<endl;
  }
}
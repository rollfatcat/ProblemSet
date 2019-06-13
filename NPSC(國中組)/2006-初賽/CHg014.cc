// 簡單但是值得練習的模擬題目!!
#include<iostream>
#include<cstring>
using namespace std;

int x, cnt[14], point;
bool SSToDo(string ss){
  if(ss.length()==1){
    if(ss[0]<='9'){ // 2-9, 注意4,5不會增加點數
      x=ss[0]-'0';
      if(x!=4 and x!=5)
        point+=x;
    }
    else if(ss[0]=='A') x=1,  point=0;
    else if(ss[0]=='J') x=11;
    else if(ss[0]=='K') x=13, point=99;
  } else { // 10和Q
    int sign=(ss[0]=='-')?-1:1;
    if(ss[1]=='Q')  x=12, point+=(sign*20);
    else x=10, point+=(sign*10);
    if(point<0) point=0; //扣完之後分數低於0要調整回0
  }
  cnt[x]++;
  return (cnt[x]<=4)and(point<=99);
}
int main(){
  int N, M;
  string act;

  while(cin>>N>>M and N){
    memset(cnt,0,sizeof(cnt));
    bool isLegal=true;
    for(point=0;M--;){
      cin>>act;
      if(isLegal)
        isLegal&=SSToDo(act);
    }
    if(isLegal) cout<<point<<endl;
    else cout<<"Unfair game"<<endl;
  }
}
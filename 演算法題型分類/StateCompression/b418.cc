// 自定義的 struct ＋狀態壓縮實作聯集和交集，用暴力法枚舉所有的組合即可。

#include<bits/stdc++.h>
using namespace std;

const int B=64;
struct UNIT{
  int sz=0;
  long n[8]={};
  void init(char *ss){
    for(sz=0;ss[sz]!='\0';sz++)
      n[sz/B]|=(long)(ss[sz]-'0')<<sz%B;
    sz=(sz-1)>>6;
  }
  int count(int ret=0){
    for(int i=0;i<=sz;i++)
      ret+=__builtin_popcountl(n[i]);
    return ret;
  }
  UNIT operator&(const UNIT &rhs)const{
    UNIT ret=*this;
    for(int i=0;i<=sz;i++)
      ret.n[i]&=rhs.n[i];
    return ret;
  }
  UNIT operator|(const UNIT &rhs)const{
    UNIT ret=*this;
    for(int i=0;i<=sz;i++)
      ret.n[i]|=rhs.n[i];
    return ret;
  }
};
int main(){
  int N, M;
  char ss[1030];
  while(scanf("%d %d",&N,&M)==2){

    UNIT attr[1024];
    for(int i=0; i<N; i++)
      scanf("%s",ss),
      attr[i].init(ss);

    int ret=0;
    for(int i=0;i<N;i++)
      for(int j=i+1;j<N;j++){
        UNIT cross =attr[i]&attr[j];
        UNIT unions=attr[i]|attr[j];
        if( cross.count()*5>=(unions.count()<<2) )
          ret++;
      }
    printf("%.2lf\n",2.0*100.0*ret/N/(N-1));
  }
}
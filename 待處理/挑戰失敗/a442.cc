// 取子字串做比對會TLE
// Morris 的寫法可以降到47ms
#include<iostream>
#include<cstring>
using namespace std;

int MinExp(char *s1,char *s2,int L){
  int i=0, j=0, k=0, x, y;
  while(i<L and j<L and k<L){
    x=i+k; if(x>=L)  x-=L;
    y=j+k; if(y>=L)  y-=L;
    if(s1[x]==s2[y])  k++;
    else{
      if(s1[x]>s2[y]) i+=k+1;
      else  j+=k+1;
      k=0;
    }
    if(k==L)  return true;
  }
  return false;
}
int main(){

  for(char ss[2][10001]; scanf("%s %s",ss[0],ss[1])==2;){
    bool Issame=MinExp(ss[0],ss[1],strlen(ss[0]));
    // 字串反轉
    if(!Issame){
      for(int i=0,L=strlen(ss[0])-1;i<L;i++,L--)
        swap(ss[0][i],ss[0][L]);
      Issame=MinExp(ss[0],ss[1],strlen(ss[0]));
    }
    if(Issame) puts("same");
    else puts("difference");
  }
}
/*
4263
6234
4263
4362
*/
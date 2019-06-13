// STL map應用
#include<bits/stdc++.h>
using namespace std;

map<int,int> table;
inline void scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
int main(){
  int N;
  scanInt(N);
  for(int x,i=0;i<N;i++){
    scanInt(x);
    if(table.find(x)==table.end())
      table[x]=1;
    else
      table[x]++;
  }
  for(map<int,int>::iterator it=table.begin();it!=table.end();it++)
    printf("%d %d\n",it->first,it->second);
}
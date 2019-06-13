// Nim
#include<bits/stdc++.h>
using namespace std;

const int maxS=1000001;
bool Nim[maxS]={};
int main(){
  int N, Q, P, step[20];

  scanf("%d",&N);
  for(int i=0;i<N;i++)
    scanf("%d",&step[i]);
  for(int nowS=1;nowS<maxS;nowS++)
    for(int i=0;i<N;i++)
      if(nowS-step[i]>=0)
        Nim[nowS]|=( !Nim[nowS-step[i]] );
  char ss[2][10]={"Kitty","OpenChan"};
  for(scanf("%d",&Q); Q--; )
    scanf("%d",&P), printf("%s\n",ss[ Nim[P] ]);
}
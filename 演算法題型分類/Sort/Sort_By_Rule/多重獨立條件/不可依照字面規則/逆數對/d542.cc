// 題目要輸出『交換的次數』，觀察Ｎ=5e5個必需DivideAndConquer(N㏒N)

#include<iostream>
using namespace std;
#define MAXN 500001

int cnt;
int num[MAXN];
int tmp[MAXN];
inline bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return x>0;}
long MergeSort(int l,int r){
  if(l==r) return 0;
  // Divide
  int m=(l+r)>>1;
  long subans=0;
  subans+=MergeSort(l,m),
  subans+=MergeSort(m+1,r);
  // Merge
  int i,j,k;
  for(i=k=l,j=m+1;i<=m and j<=r; )
    if(num[i]<=num[j])
      tmp[k++]=num[i++];
    else
      tmp[k++]=num[j++], subans+=(m-i+1);
  while(i<=m) tmp[k++]=num[i++];
  while(j<=r) tmp[k++]=num[j++];
  for(i=l;i<=r;i++) num[i]=tmp[i];
  return subans;
}
int main(){
  for(int N; scanInt(N);){
    for(int i=0;i<N;i++)
      scanInt(num[i]);
    printf("%ld\n",MergeSort(0,N-1));
  }
}
// 可以練習Qsort

#include<iostream>
#include<cstdlib>
using namespace std;
#define MaxN 1000

struct Player{
  string name;
  int num1, num2;
  double num3;
}b[MaxN], p[MaxN];

int compare_p(const void*a,const void*b){
  struct Player *c=(struct Player*)a;
  struct Player *d=(struct Player*)b;
  if(c->num1!=d->num1)
    return d->num1-c->num1;
  if(c->num2!=d->num2)
    return c->num2-d->num2;
  double tmp=c->num3-d->num3;
  return (tmp>0.0)?1: ((tmp<0.0)?-1:0);
}
int compare_b(const void*a,const void*b){
  struct Player *c=(struct Player*)a;
  struct Player *d=(struct Player*)b;
  if(c->num1!=d->num1)
    return d->num1-c->num1;
  if(c->num2!=d->num2)
    return d->num2-c->num2;
  double tmp=c->num3-d->num3;
  return (tmp>0.0)?-1: ((tmp<0.0)?1:0);
}
int main(){
  int K, N, bNum, pNum;
  string ss;
  cin>>K;
  while(K--){
    cin>>N;
    bNum=pNum=0;
    while(N-- and cin>>ss){
      if(ss[0]=='P')
        cin>>p[pNum].name>>p[pNum].num1>>p[pNum].num2>>p[pNum].num3,  pNum++;
      if(ss[0]=='B')
        cin>>b[bNum].name>>b[bNum].num1>>b[bNum].num2>>b[bNum].num3,  bNum++;
    }
    qsort(p,pNum,sizeof(p[0]),compare_p);
    qsort(b,bNum,sizeof(b[0]),compare_b);
    for(int i=0;i<pNum;i++)
      cout<<"P "<<p[i].name<<endl;
    for(int i=0;i<bNum;i++)
      cout<<"B "<<b[i].name<<endl;
    if(K)
      cout<<"====="<<endl;
  }
}
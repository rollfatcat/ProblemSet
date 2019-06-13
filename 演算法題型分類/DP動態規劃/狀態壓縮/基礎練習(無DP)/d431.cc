#include<bits/stdc++.h>
using namespace std;

int pos[12][5]={
  { 0, 1, 2, 3, 4},
  { 5, 6, 7, 8, 9},
  {10,11,12,13,14},
  {15,16,17,18,19},
  {20,21,22,23,24},
  { 0, 5,10,15,20},
  { 1, 6,11,16,21},
  { 2, 7,12,17,22},
  { 3, 8,13,18,23},
  { 4, 9,14,19,24},
  { 0, 6,12,18,24},
  { 4, 8,12,16,20}};
int check_S[12]={};
int main(){
  for(int i=0;i<12;i++)
    for(int j=0;j<5;j++)
      check_S[i]+=(1<<pos[i][j]);
  int A[25], B[25], C[25];
  for(int i=0,x;i<25;i++)
    scanf("%d",&x), A[x-1]=i;
  for(int i=0,x;i<25;i++)
    scanf("%d",&x), B[x-1]=i;
  for(int i=0;i<25;i++)
    scanf("%d",&C[i]);
  //至少要17個數才會Bingo => 前16次不用檢查
  int n, turn=0, As=0, Bs=0, winner=0;
  for(turn=0;turn<=15;turn++)
    n=C[turn]-1, As|=(1<<A[n]), Bs|=(1<<B[n]);
  for(turn=16;winner==0;turn++){
    n=C[turn]-1, As|=(1<<A[n]), Bs|=(1<<B[n]);
    int Acnt=0, Bcnt=0;
    for(int i=0;i<12;i++){
      if((As&check_S[i])==check_S[i]) Acnt++;
      if((Bs&check_S[i])==check_S[i]) Bcnt++;
    }
    if(Acnt>=5) winner|=1;
    if(Bcnt>=5) winner|=2;
  }
  turn--;
  if((winner&1)==1) printf("A");
  if((winner&2)==2) printf("B");
  printf(" %d\n",C[turn]);
}
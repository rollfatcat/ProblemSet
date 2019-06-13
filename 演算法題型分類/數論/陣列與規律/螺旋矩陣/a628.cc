#include<iostream>
using namespace std;

int num[19][19]={};
int main(){
  for(int n; cin>>n;){
    int c=(n>>1), number=n*n-1;
    num[c][c]=0;
    for(int w=c;w>=0;w--){
      int x=c+w, y=c+w, len=w<<1;
      for(int i=len;i>0;i--)
        num[x][y--]=number--;
      for(int i=len;i>0;i--)
        num[x--][y]=number--;
      for(int i=0;i<len;i++)
        num[x][y++]=number--;
      for(int i=0;i<len;i++)
        num[x++][y]=number--;
    }
    for(int i=0;i<n;i++,printf("\n"))
      for(int j=0;j<n;j++)
        printf("%4d",num[i][j]);
  }
}
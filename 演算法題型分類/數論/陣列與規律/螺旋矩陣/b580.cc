#include<iostream>
using namespace std;

int num[100][100]={};
int main(){
  int caseT, n;
  cin>>caseT;
  while(caseT--){
    cin>>n;
    int c=(n>>1), number=n*n;
    num[c][c]=1;
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
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++){
        printf("%4d",num[i][j]);
        putchar((j==n-1)?'\n':' ');
      }
  }
}
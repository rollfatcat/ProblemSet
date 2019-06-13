//矩陣相乘的練習
#include<iostream>
using namespace std;
#define MaxN 100

int main(){
  long matrix[3][MaxN][MaxN];
  for(int r1,c1,r2,c2; cin>>r1>>c1>>r2>>c2; ){
    if(c1!=r2){ cout<<"Error"<<endl; continue; }
    for(int i=0;i<r1;i++)
      for(int j=0;j<c1;j++)
        cin>>matrix[0][i][j];
    for(int i=0;i<r2;i++)
      for(int j=0;j<c2;j++)
        cin>>matrix[1][i][j];
    for(int i=0;i<r1;i++)
      for(int j=0;j<c2;j++){
        matrix[2][i][j]=0;
        for(int k=0;k<c1;k++)
          matrix[2][i][j]+=(matrix[0][i][k]*matrix[1][k][j]);
      }
    for(int i=0;i<r1;i++,cout<<endl)
      for(int j=0;j<c2;j++)
        cout<<matrix[2][i][j]<<' ';
  }
}
// O(n4)可以過(60ms), 但可以用O(n3)過(8ms)
// 題目的意思是至少得選一個數字, 雖然沒說每個數字大小但整體加總都在int極限內
#include<iostream>
using namespace std;
#define MaxN 101

int main(){
  int n, N, maxNum;
  int num[MaxN][MaxN];
  int rowSum[MaxN][MaxN]={0};
  int allSum[MaxN][MaxN]={0};

  while(cin>>n){
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        cin>>num[i][j];
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        rowSum[i][j+1]=rowSum[i][j]+num[i][j];
    for(int i=1;i<=n;i++)
      for(int j=0;j<n;j++)
        allSum[j+1][i]=allSum[j][i]+rowSum[j][i];
    maxNum=0xffffffff;
    for(int edx=1;edx<=n;edx++)
      for(int edy=1;edy<=n;edy++)
        for(int stx=0;stx<edx;stx++)
          for(int sty=0;sty<edy;sty++){
            int areaSum=allSum[edx][edy]+allSum[stx][sty]-allSum[stx][edy]-allSum[edx][sty];
            if(maxNum<areaSum)
              maxNum=areaSum;
          }
    cout<<maxNum<<endl;
  }
}

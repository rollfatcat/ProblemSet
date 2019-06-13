// 難在理解題目提到的『損壞』定義：只要Row和Column各自有兩個以上的1個數是奇數

#include<iostream>
#include<vector>
using namespace std;

int main(){
  for(int n, x; cin>>n;){
    int Row[100]={}, Col[100]={};
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++){
        cin>>x;
        if(x)
          Row[i]++, Col[j]++;
      }
    vector<int> R, C;
    for(int i=0;i<n;i++){
      if(Row[i]&1)  R.push_back(i);
      if(Col[i]&1)  C.push_back(i);
    }
    if(R.size()==0 and C.size()==0) puts("OK");
    else if(R.size()==1 and C.size()==1) printf("Change bit (%d,%d)\n",R[0]+1,C[0]+1);
    else puts("Corrupt");

  }
}
// 陣列位置轉換, 輸出成2^n, 練習shift的寫法
#include<iostream>
using namespace std;

int main(){
  for(int r,c; cin>>r>>c; )
    cout<<((long)1<<(8*r+c-9) )<<endl;
}
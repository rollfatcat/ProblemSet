// 模擬鬼腳圖(交換陣列元素)，注意輸出的方式(第三筆的答案不是 1 3 2 4而是1 4 2 3)
// 讀取字串時有意義的交換符號落在奇數的位置
// 若該符號是'-'代表要交換陣列位置， 若是'.'代表就不用做什麼

#include<iostream>
#include<vector>
using namespace std;

int main(){
  for(int W,H; cin>>W>>H;){
    vector<int> num, pos;
    for(int i=0;i<W;i++)
      num.push_back(i);
    string ss;
    for(int i=0;i<H;i++){
      cin>>ss;
      for(int j=1;j<W;j++)
        if(ss[2*j-1]=='-')
          swap(num[j-1],num[j]);
    }
    pos.resize(W);
    for(int i=0;i<W;i++)
      pos[ num[i] ]=i+1;
    for(int i=0;i<W;i++)
      cout<<pos[i]<<' ';
    cout<<endl;
  }
}
/*
3 3
|-|.|
|-|.|
|.|-|
5 6
|.|.|-|.|
|.|.|.|.|
|.|.|.|.|
|.|-|.|.|
|.|.|-|.|
|.|.|.|.|
4 9
|.|.|-|
|-|.|.|
|.|.|-|
|.|-|.|
|-|.|.|
|.|-|.|
|.|.|-|
|-|.|.|
|.|.|.|
*/
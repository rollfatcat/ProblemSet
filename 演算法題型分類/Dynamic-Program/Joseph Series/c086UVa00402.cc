// 題目先給兩個數字，代表一開始存活的總人數和最後剩餘的人數
// 再給滿20個數字，每張卡片上的號碼代表：每數Ｋ個人就會淘汰一個直到指標位置超過人數
// 或是剩餘人數剛好是題目的要求。
// 詳細說明：https://zerojudge.tw/ShowThread?postid=10867
// 規則與經典的 Josephus 不同需要用vector模擬
#include<iostream>
#include<vector>
using namespace std;

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  int K[20], cnt;
  for(int N,X,caseNum=1; cin>>N>>X;caseNum++){
    for(int i=0;i<20;i++)
      cin>>K[i], K[i]--;
    vector<int> num;
    for(int i=1;i<=N;i++)
      num.push_back(i);
    cnt=N;
    for(int Ki=0, idx=K[Ki]; cnt>X;){
      if(idx<cnt)
        cnt--,
        num.erase(num.begin()+idx),
        idx+=K[Ki];
      else{
        if(Ki<=18) idx=K[++Ki];
        else  break;
      }
    }
    cout<<"Selection #"<<caseNum<<endl<<num[0];
    for(int i=1;i<cnt;i++)
      cout<<" "<<num[i];
    cout<<endl<<endl;
  }
}
/*
10 2 3 5 4 3 2 9 6 10 10 6 2 6 7 3 4 7 4 5 3 2
47 6 11 2 7 3 4 8 5 10 7 8 3 7 4 2 3 9 10 2 5 3
*/
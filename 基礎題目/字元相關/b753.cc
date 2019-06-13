// 利用一維陣列的性質將輸入的字元轉換為對應的數字(權重)
// 身分證合法判斷
#include<iostream>
#include<map>
using namespace std;

int ChatInt[26]={1,10,19,28,37,46,55,64,39,73,82,2,11,20,48,29,38,47,56,65,74,83,21,3,12,30};
int main(){
  for(int N; cin>>N;){
    int T=0, O=0, F=0;
    map<string,bool> Bag;
    string ss;
    for(int i=0;i<N;i++){
      cin>>ss;
      int num=ChatInt[ss[0]-'A']+((ss[1]=='1')?8:16);
      for(int j=2,k=7; k>0;j++,k--)
        num+=k*(ss[j]-'0');
      num+=ss[9]-'0';
      if(num%10==0){
        if(Bag.find(ss)==Bag.end()) T++, Bag[ss]=true;
        else  O++;
      } else  F++;
    }
    cout<<T<<','<<O<<','<<F<<endl;
  }
}
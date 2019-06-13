// nAnB的重複版本
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int main(){
  int caseNum=1, len, Ans[1000], Gue;
  int A, B, endIO, cnt[2][10];

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);cout.tie(NULL);

  for(cin>>len; len; cin>>len, caseNum++){
    cout<<"Game "<<caseNum<<":"<<endl;
    for(int i=0;i<len;i++)
      cin>>Ans[i];
    while(true){
      A=B=endIO=0;
      memset(cnt,0,sizeof(cnt));
      for(int i=0;i<len;i++){
        cin>>Gue, endIO+=Gue;
        if(Gue==Ans[i]) A++;
        else  cnt[0][Gue]++, cnt[1][Ans[i]]++;
      }
      if(!endIO)  break;
      for(int i=1;i<=9;i++)
        B+=min(cnt[0][i],cnt[1][i]);
      cout<<"    ("<<A<<","<<B<<")"<<endl;
    }
  }
}
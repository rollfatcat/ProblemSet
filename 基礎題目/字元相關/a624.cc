// 根據字串中有沒有包含『數字』『大寫』『小寫』...做為密碼強度的判斷，輸出密碼強度的等級
// 字元判斷
#include<iostream>
#include<cstring>
using namespace std;

int main(){
  char ss[31];
  string level[4]={"WEAK","ACCEPTABLE","GOOD","STRONG"};
  while(scanf("%s",ss)!=EOF){
    int num=(strlen(ss)>=8)?1:0;
    int cnt[3]={0,0,0};
    for(int i=0;ss[i]!='\0';i++)
      if('A'<=ss[i] and ss[i]<='Z') cnt[1]++;
      else if('a'<=ss[i] and ss[i]<='z') cnt[2]++;
      else cnt[0]++;
    if(cnt[1] and cnt[2]) num++;
    if(cnt[0] and (cnt[1] or cnt[2])) num++;
    cout<<"This password is "<<level[num]<<endl;
  }
}
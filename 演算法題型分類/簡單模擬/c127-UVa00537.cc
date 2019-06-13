// 讀取字串，抓出關鍵字做簡單的運算
#include<bits/stdc++.h>
using namespace std;

int main(){
  int T;
  scanf("%d",&T); getchar();
  for(int caseN=0;caseN<T;){
    if(caseN++) puts("");
    printf("Problem #%d\n",caseN);
    string ss;
    getline(cin,ss);
    bool Is[3]={};
    double num[3]={}; // P/U/I
    for(int i=0;i<ss.length();i++)
      if(ss[i]=='='){
        // 類型判斷
        int t=ss[i-1]=='U';
        if(t==0 and ss[i-1]=='I') t=2;
        // 轉換數字時必須支援『負數』『小數』『科學記號』
        Is[t]=1;
        bool sign=ss[++i]=='-';
        num[t]=sign?0.0:(ss[i]-'0');
        for(i++;ss[i]>='0' and ss[i]<='9';i++)
          num[t]=10.0*num[t]+ss[i]-'0';
        if(ss[i]=='.'){
          double base=0.1;
          for(i++;ss[i]>='0' and ss[i]<='9';i++,base*=0.1)
            num[t]+=base*(ss[i]-'0');
        }
        if(sign) num[t]*=-1;
        if(ss[i]=='m') num[t]*=0.001;
        else if(ss[i]=='k') num[t]*=1000.0;
        else if(ss[i]=='M') num[t]*=1000000.0;
      }
    // 根據缺失的數據輸出格式
    if(Is[0]==0)
      printf("P=%.2lfW\n",num[1]*num[2]);
    else if(Is[1]==0)
      printf("U=%.2lfV\n",num[0]/num[2]);
    else
      printf("I=%.2lfA\n",num[0]/num[1]);

  }
}

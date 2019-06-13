// 練習找子字串/字串替換/大小寫字元轉換的基礎練習
#include<iostream>
#include<cstring>
using namespace std;

string ss;
bool compare(int idx,string target){
  for(int i=0;i<target.length();i++)
    if(ss[idx+i]!=target[i])
      return false;
  return true;
}
int main(){
  for(int up='a'-'A'; cin>>ss; ){
    int m, n,repeat;
    cin>>m>>n>>repeat;
    if(n==1){
      for(int i=0;i<ss.length();i++)
        if('A'<=ss[i] and ss[i]<='Z')
          ss[i]=(char)(ss[i]+up);
        else if('a'<=ss[i] and ss[i]<='z')
          ss[i]=(char)(ss[i]-up);
      ss+="Immorta1";
    }else if(n==2){
      string target=ss.substr(m-1), tmpSS="";
      for(int i=0;i<=ss.length()-target.length();){
        if(compare(i,target)) i+=target.length();
        else  tmpSS+=ss[i++];
      }
      ss="";
      for(int i=0;i<=tmpSS.length()-4;){
        if(compare(i,"1013")) ss+="hh4742", i+=4;
        else  ss+=tmpSS[i++];
      }
      ss+=tmpSS.substr(tmpSS.length()-3);
    }else{
      string ssA=ss.substr(0,m-1);
      int pos=abs(n-m)-1;
      ss=ssA.substr(0,pos)+ss.substr(m-1)+ssA.substr(pos);
    }
    for(int i=0; i<ss.size(); i++)
			for(int j=0; j<=repeat; j++)
				putchar(ss[i]);
		putchar('\n');
  }
}
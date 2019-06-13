// 16進位與10進位轉換，RGB對應HEX
#include<iostream>
using namespace std;

char HEX(int x){ return(x<=9)?(x+'0'):(x-10+'A'); }
int Int(char ch){ return(ch<='9')?(ch-'0'):(ch-'A'+10); }
int main(){
  int R,G,B;
  for(string ss; cin>>ss;){
    if(ss[0]>='0'){
      cin>>G>>B,  R=0;
      for(int i=0;i<ss.length();i++)
        R=10*R+ss[i]-'0';
      cout<<"#"<<HEX(R/16)<<HEX(R%16)<<HEX(G/16)<<HEX(G%16)<<HEX(B/16)<<HEX(B%16)<<endl;;
    } else {
      cout<<16*Int(ss[1])+Int(ss[2])<<' '<<16*Int(ss[3])+Int(ss[4])<<' '<<16*Int(ss[5])+Int(ss[6])<<endl;
    }
  }
}
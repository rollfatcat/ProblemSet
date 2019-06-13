// 判斷被2的N次方, 只要看末端的N位數能不能被2^N整除即可
#include<iostream>
using namespace std;

int power2[11]={1,2,4,8,16,32,64,128,256,512,1024};
int main(){
  int N, st;
  long M; // 最大取到10位元
  string Mss, Msub;

  while(cin>>Mss>>N){
    st=Mss.length()-N, st=(st>=0)?st:0;
    Msub=Mss.substr(st);
    for(M=0,st=0;st<Msub.length();st++)
      M=10*M+Msub[st]-'0';
    if(M%power2[N]==0)  cout<<"YA!!終於算出"<<Mss<<"可被2的"<<N<<"次整除了!!"<<endl;
    else cout<<"可惡!!算了這麼久"<<Mss<<"竟然無法被2的"<<N<<"次整除"<<endl;
  }
}

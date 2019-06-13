// 測資範圍：1 ≤ T ≤ 10，1 ≤ N < 10100000，2 ≤ M ≤ 11且M≠ 7
// 讀取時用字串讀取，判斷是否能『被整除』，根據除數性質處理即可

#include<iostream>
using namespace std;

string Nss;
bool DivideTwo(int L,int num=0){ // 將末Ｌ位的字串轉成數字
  int B=1<<L;
  int ten=1;
  for(int i=Nss.length()-1; i>=0 and L>0; i--,L--,ten*=10)
    num+=(Nss[i]-'0')*ten;
  return num%B==0;
}
bool DivideThree(int L,int num=0){ // 把每位數加起來
  for(int i=0;i<Nss.length();i++)
    num+=Nss[i]-'0';
  return (L==1)? (num%3==0): (num%9==0);
}
int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  int caseT, M;
  cin>>caseT;
  while(caseT--){
    cin>>Nss>>M;
    if(M==11){
      int numO=0, numE=0;
      for(int i=0;i<Nss.length();i++)
        (i&1)? (numE+=Nss[i]-'0'): (numO+=Nss[i]-'0');
      cout<< ((numO-numE)%11==0? "Yes":"No") <<'\n';
    }
    else {
      int L=0;
      bool success=true;
      for(L=0; (M%2)==0; L++,M/=2);
      if(L)  success&=DivideTwo(L);
      for(L=0; (M%3)==0; L++,M/=3);
      if(L)  success&=DivideThree(L);
      if(M%5==0) success&=( (Nss[Nss.length()-1]-'0')%5==0 );
      cout<<( (success)?"Yes":"No" )<<'\n';
    }
  }
}
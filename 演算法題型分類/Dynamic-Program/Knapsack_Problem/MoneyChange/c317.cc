//其實是窮舉, 因為(X,Y)解必須保證 X>=0 and Y>=0 的前提下求得 min(X+Y)
#include<iostream>
using namespace std;

int GCD(int a, int b){ return (b)? GCD(b,a%b):a; }
int main(){
  int caseNum, x, a, b;
  scanf("%d",&caseNum);
  while(caseNum--){
    scanf("%d%d%d", &x, &a, &b);
    int gcd=GCD(a,b);
    if(x%gcd)
      printf("-1\n");
    else{
      x/=gcd, a/=gcd, b/=gcd;
      int min_cnt=1001;
      for(int s=x/a;s>=0;s--){
        int tmp=x-a*s;
        if( tmp%b==0 ){
            int tmp_cnt=s+tmp/b;
            if(min_cnt>tmp_cnt)
              min_cnt=tmp_cnt;
        }
      }
      if(min_cnt==1001)
        printf("-1\n");
      else
        printf("%d\n",min_cnt);
    }
  }
}
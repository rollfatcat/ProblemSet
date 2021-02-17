/*  Extended Euclid Algorithm
 * a*x  +     b*y  = gcd ---(1) :  x and  y are results for inputs a and b
 * b*x1 + (a%b)*y1 = gcd ---(2) : x1 and y1 are results for inputs b and a%b
 * when we put a%b = a-⌊a/b⌋*b in above, note that ⌊a/b⌋ is floor(a/b)
 * b*x1 + (a-⌊a/b⌋*b)*y1 = gcd = b*(x1-⌊a/b⌋*y1) + a*y1 --- (3)
 * after comparing coefficients of 'a' and 'b' in (1) and (3), we get following 
 *    x = y1
 *    y = x1 - ⌊a/b⌋*y1
 */

#include<bits/stdc++.h>
using namespace std;

int gcdExtended(int a,int b,int& x,int& y){
  if(b==0){ // Stop Condition 
    x=1; y=0;  
    return a; 
  }
  int x1, y1, gcd=gcdExtended(b, a%b, x1, y1);
  x=y1;
  y=x1-a/b*y1;
  return gcd;
}
// x 是 a 的模反元素( 模反元素存在的前提是 a, b 互質 )
int ModInverse(int a,int b){
  int x, y, gcd=gcdExtended(a,b,&x,&y);
  // there is one-to-one x mod_inverse of a , if and only if gcd is 1
  return (gcd==1)? (x<0)?(x+b):x : -1;
}
int main(){
  // a÷b ≡ a×inv(b) ≡ x (mod m)
  int a, m; 
  while(scanf("%d %d\n",&a,&b)!=EOF)
    printf("%d\n",ModInverse(a,m));
}


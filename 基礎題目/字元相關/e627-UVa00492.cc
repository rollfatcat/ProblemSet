/* 難在抓規律，需要有udebug提供的測資才能偵錯
 */
#include<bits/stdc++.h>
using namespace std;

char ss[102], ch;
inline bool IsLetter(char c){
	return ('a'<=c and c<='z') or ('A'<=c and c<='Z');
}
inline bool IsVowel(char c){
	return c=='a' or c=='e' or c=='i' or c=='o' or c=='u' or c=='A' or c=='E' or c=='I' or c=='O' or c=='U';
}
int main(){
	char ch, keep;
	bool IsWord=false, FirstIsVowel=false;
  while((ch=getchar())!=EOF){
  	bool IsChar=IsLetter(ch);
		if(IsWord^IsChar==0) putchar(ch);
		else if(IsWord==0 and IsChar){ 
  		IsWord=1;
  		FirstIsVowel=IsVowel(ch);
  		(FirstIsVowel)? putchar(ch): keep=ch;  
  	}
  	else { // IsWord and IsChar==0
  		if(FirstIsVowel==0) putchar(keep);
  		putchar('a'); putchar('y');
  		putchar(ch);
  		IsWord=0;
  		FirstIsVowel=0;
  	}
  }
  if(IsWord){ // 讀取到 EOF 時要判斷『剛好斷在單字』的點
  	if(FirstIsVowel==0) putchar(keep);
  	putchar('a'); putchar('y');
  	IsWord=0;
  	FirstIsVowel=0;
  }
}
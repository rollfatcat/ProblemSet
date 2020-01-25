/* 題目給定摩斯密碼的碼表，將整行的字串轉譯
 * 給定的碼表不需要自己Key，直接寫個小程式印出符合『陣列的格式』
 * 整行的密碼中如果存在連續兩個空白的字元則需一個空白
 *   => dict[""]=' ' 的意思
 */
#include<bits/stdc++.h>
using namespace std;

map<string,char> dict;
int main(){
	dict[".-"]='A';   dict[".---"]='J'; dict["..."]='S';
	dict["-..."]='B';	dict["-.-"]='K';  dict["-"]='T';
	dict["-.-."]='C'; dict[".-.."]='L'; dict["..-"]='U';
	dict["-.."]='D';	dict["--"]='M';		dict["...-"]='V';
	dict["."]='E';		dict["-."]='N';		dict[".--"]='W';
	dict["..-."]='F'; dict["---"]='O';	dict["-..-"]='X';
	dict["--."]='G';	dict[".--."]='P'; dict["-.--"]='Y';
	dict["...."]='H'; dict["--.-"]='Q'; dict["--.."]='Z';
	dict[".."]='I';		dict[".-."]='R';	dict["-----"]='0';
	
	dict[".----"]='1'; dict[".-.-.-"]='.'; dict["---..."]=':';
	dict["..---"]='2'; dict["--..--"]=','; dict["-.-.-."]=';';
	dict["...--"]='3'; dict["..--.."]='?'; dict["-...-"]='=';
	dict["....-"]='4'; dict[".----."]='\''; dict[".-.-."]='+';
	dict["....."]='5'; dict["-.-.--"]='!'; dict["-....-"]='-';
	dict["-...."]='6'; dict["-..-."]='/';  dict["..--.-"]='_';
	dict["--..."]='7'; dict["-.--."]='(';  dict[".-..-."]='"';
	dict["---.."]='8'; dict["-.--.-"]=')'; dict[".--.-."]='@';
	dict["----."]='9'; dict[".-..."]='&';  dict[""]      =' ';
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int caseT;
	string line, word;
	cin>>caseT; getline(cin,line);
	for(int caseI=1;caseI<=caseT;caseI++){
		getline(cin,line);
		if(caseI>1) cout<<'\n'<<'\n';
		cout<<"Message #"<<caseI<<'\n';
		for(int i=0;i<line.length();i++)
			if(line[i]==' '){ 
				cout<<dict[word]; word="";
			}else 
				word+=line[i];
		if(word!="")
			cout<<dict[word], word="";
	}
}
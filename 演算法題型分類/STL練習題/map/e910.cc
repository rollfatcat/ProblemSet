/* 解密：給定一串01構成的密文和解碼表，將其翻譯回明文
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	map<string,char> dict;
	dict["00"]=' ', dict["010010"]='.', dict["01011101000"]='!', dict["01011110"]=',', dict["0101111100100"]='?';
	dict["010111011"]='0', dict["110111100"]='1', dict["010111000"]='2', dict["11011110111"]='3', dict["010111110011"]='4', dict["0101110101"]='5', dict["11011110100"]='6' , dict["01011101001"]='7', dict["11011110101"]='8', dict["0101111100101"]='9'; 
	dict["1000"]='A', dict["110110"]='B', dict["10110"]='C', dict["11010"]='D', dict["1111"]='E', dict["01010"]='F', dict["010110"]='G', dict["10101"]='H', dict["0110"]='I', dict["01011111000"]='J', dict["010111111"]='K', dict["10100"]='L', dict["01000"]='M', dict["0111"]='N', dict["1001"]='O', dict["010011"]='P', dict["010111001"]='Q', dict["11100"]='R', dict["11101"]='S', dict["1100"]='T', dict["101111"]='U', dict["11011111"]='V', dict["1101110"]='W', dict["0101111101"]='X', dict["101110"]='Y', dict["11011110110"]='Z';
	for(string ss;cin>>ss;){
		string nowss="";
		for(char ch:ss){
			nowss+=ch;
			if(dict.find(nowss)!=dict.end()){
				cout<<dict[nowss]; nowss="";
			}
		}
		cout<<'\n';
	}
}

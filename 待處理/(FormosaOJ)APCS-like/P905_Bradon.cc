#include <iostream>
#include <vector>
using namespace std;
struct val{long long int num;bool used;};
struct optor{int cord;char op;};
int main(){
	int turn;
	cin>>turn;
	for(int k=0;k<=turn;k++){
	    vector <optor> vec;
	    vector <long long int> arr;
	    val numbers;
	    numbers.num=0;
	    numbers.used=false;

		//int dele;
		//cin>>dele;
		string line;
		optor tmp;
		//for(int del=0;del<dele;del++){
		    //cin>>line;
		while(cin>>line){
    	    for(int i=0;i<line.length();i++){
    		    if(line[i]>='0'){
    			    numbers.num=numbers.num*10+(line[i]-'0');
    			    numbers.used=true;
    			    if(i==line.length()-1){
    			        arr.push_back(numbers.num);
    			        numbers.num=0;
	                    numbers.used=false;
    			    }
    		    }else{
    		        if(numbers.used){
    		            arr.push_back(numbers.num);
    			        numbers.num=0;
	                    numbers.used=false;
    		        }
    				arr.push_back(-1);
    				tmp.op=line[i];
    				tmp.cord=arr.size()-1;
    				vec.push_back(tmp);
    		    }
    	    }
		}

		int start=vec[0].cord-1;
		long long int ans=arr[start];
		arr[start]=-1;
		for(int i=0;i<vec.size();i++){
			for(int j=vec[i].cord-1;j>=0;j--){
                if(arr[j]!=-1){
                    if(vec[i].op=='+'){
                        ans+=arr[j];
                    }else{
                        ans*=arr[j];
                    }
                    arr[j]=-1;
                    break;
                }
			}
		}
		cout<<ans<<endl;

		/*cout<<arr.size()<<endl;
        for(int i=0;i<arr.size();i++){
        	cout<<arr[i]<<" ";
        }
        cout<<endl<<vec.size()<<endl;
        for(int i=0;i<vec.size();i++){
            cout<<"cord:"<<vec[i].cord<<" op:"<<vec[i].op<<endl;
        }*/
	}
}
/*
3
1000000000 1000000000 *
1 2 3+4**
2 3 4   + *
*/
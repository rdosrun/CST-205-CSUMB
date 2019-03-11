#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
int main(){
	cout<<"enter public key of receiver";
	int y;
	int public_key;
	cin >>public_key;
	string x;
	y = (int)(sin(public_key*public_key)*10000000);
	if(y<0){
		y = y*-1;
	}
	cout<<y;
	cout<<"enter message";
	cin.ignore();
	getline(cin,x);
	for(int i = 0;i<y;i++){
		for (int i = 0; i < x.length(); ++i)
		{
			if(i+1 <x.length()){
				x[i] = x[i]+x[i+1];
			}else{
				x[i] = x[i]+x[0];
			}
		}
	}
	/*ofstream myfile;
  	myfile.open (public_key +".txt",fstream::app);
  	myfile<<endl<<endl;
	myfile<<x;*/
	cout<<x;
}

#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
using namespace std;
string int2string(int x){
	string y;
	char z;
	while(x!=0){
		z = (x%10)+'0';
		x = x/10;
		y = z+y;
	}
	return y;
}
void encrypt(int public_key){
	string x;
	int y = (int)(sin(public_key*public_key)*10000000);
	if(y<0){
		y = y*-1;
	}
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
	string p = int2string(public_key);
	ofstream write ((p+".txt").c_str(), std::ofstream::app);
	if ((!write))
	{
		cout<<"error please contact room 707 between 4-6PM M-F";
		return;
	}else{
		write<<x;
		write<<endl;
		write.close();
		cout<<"message sent"<<endl;
	}
}

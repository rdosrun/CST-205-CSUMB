#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
using namespace std;
string decrypt(string x, int key){
	if(key<0){
		key = key*-1;
	}
	for(int i = 0;i<key;i++){
		for (int i = x.length()-1; i >= 0; --i)
		{
			if(i < x.length()-1){
				x[i] = x[i]-x[i+1];
			}else{
				x[i] = x[i]-x[0];
			}
		}
	}
	return x;
}
void print(string w,int key){
	ifstream read ((w+".txt").c_str());
	if ((!read))
	{
		cout<<"error please contact room 707 between 4-6PM M-F";
		return;
	}
	if (read.is_open()){
		string x;
		while(getline (read,x)){
			cout<<decrypt(x,key);
		}
	}
	read.close();
}
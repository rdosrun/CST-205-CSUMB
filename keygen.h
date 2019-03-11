#include <iostream>
#include <cmath>
using namespace std;
int key(int ID){
	int public_key = (int)(cos(ID*ID)*10000000);
	cout<<"this is your public key "<<public_key<<endl;
	int private_key = (int)(sin(public_key*public_key)*10000000);
	if(private_key<0){
		private_key = private_key*-1;
	}
	cout<<"this is your private key "<< private_key<<endl;
	return public_key;
}
int start(){
	cout<<"enter the last five of your student ID or a five digit gen key"<<endl;
	int u;
	cin >>u;
	key(u);
	return (int)(cos(u*u)*10000000);
}

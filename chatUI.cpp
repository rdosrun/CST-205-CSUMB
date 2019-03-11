#include <iostream>
#include "chatd.h"
#include "chate.h"
#include "keygen.h"
using namespace std;
void UI(int file,int key);
int main()
{
	bool running = true;
	int returning = 1;
	int private_key = 0;
	while(running){
		if (returning == 1)
		{
			cout<<"Welcome to UI dorm chat"<<endl;
			cout<<"Please enter your public key if you do not have one enter 0"<<endl;
			cin>>returning;
		}
		if(returning!=0&&private_key != 0){
			cout<<"please enter your private key";
			cin>>private_key;
			UI(returning, private_key);
		}else{
			returning = start();
			cout<<endl<<returning;
		}
		cout<<"if you would like to continue enter (1)";
		cin>>running;
		if(running == 1){
		}else{
			running = 0;
		}
	}
	return 0;
}
void UI(int file,int key){
	int choice = 0;
	cout<<"To read your messages enter (1) to send messages enter (2)"<<endl;
	cout<<"To leave enter (0)"<<endl;
	cin >>choice;
	if (choice == 1)
	{
		string p = int2string(file);
		print(p,key);
	}else if(choice == 2){
		cout<<"enter public key of receiver";
		int public_key;
		cin>>public_key; 
		encrypt(public_key);
	}else if(choice ==0){
		return;
	}else{
		UI(file,key);
	}

}

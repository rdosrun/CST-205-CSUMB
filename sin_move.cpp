#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
int factor(int & key);
int factor2(int & key);
double rand_gen_x(int p);
double rand_gen_y(int p);
int main(int argc, char const *argv[])
{
	int key = 70;
	ifstream file;
	file.open("test.txt");
	string tmp;
	int num_lines = 0;
	int longest_line=0;
	//file length count
	while(getline(file,tmp)){
		num_lines++;
		//cout<<tmp<<endl;
		if (tmp.length()>longest_line)
		{
			longest_line=tmp.length();
		}
	}
	
	//creating strucutre 
	char ** board;
	board = new char *[num_lines];
	//reset file pointer
	file.clear();
	file.seekg(0,file.beg);

	int curr_line =0;
	while(getline(file,tmp)){
		board[curr_line] = new char [longest_line];
		for (int i = 0; i < longest_line; ++i)
		{
			board[curr_line][i] = 'o';
		}
		for (int i = 0; i < tmp.length(); ++i)
		{
			board[curr_line][i] = tmp[i];
		}
		curr_line++;
	}

	for (int i = 0; i < num_lines; ++i)
	{
		for (int j = 0; j < longest_line; ++j)
		{
			cout<<board[i][j];
		}
		cout<<endl;
	}

	cout<<endl;


	int tmp_key = key;
	while(tmp_key!= 1){
		int tmp_fac = factor(tmp_key);
		for (int i = 0; i < num_lines; ++i)
		{
			for (int j = 0; j < longest_line; ++j)
			{
				char tmp_char ='o';
				tmp_char = board[i][j];
				int x_pos = (longest_line-1)*rand_gen_x(tmp_fac*j);
				cout<<x_pos<<" ";
				int y_pos = num_lines*rand_gen_y(tmp_fac*j);
				cout<<y_pos <<" "<<tmp_fac<<endl;
				//cout<<"swap "<<board[y_pos][x_pos]<<" "<<board[i][j]<<endl;
				board[i][j] = board[y_pos][x_pos];
				//cout<<"line 62"<<endl;
				board[y_pos][x_pos] = tmp_char;
			}
		}
	}
	for (int i = 0; i < num_lines; ++i)
	{
		for (int j = 0; j < longest_line; ++j)
		{
			cout<<board[i][j];
		}
		cout<<endl;
	}



	cout<<"div"<<endl;
	tmp_key = key;
	while(tmp_key!= 1){
		int tmp_fac = factor2(tmp_key);
		for (int i = num_lines-1; i >=0 ; --i)
		{
			for (int j = longest_line-1; j >=0; --j)
			{
				char tmp_char =board[i][j];
				int x_pos = (longest_line-1)*rand_gen_x(tmp_fac*j);
				cout<<x_pos<<" ";
				int y_pos = num_lines*rand_gen_y(tmp_fac*j);
				cout<<y_pos<<" "<<tmp_fac<<" "<<endl;
				board[i][j] = board[y_pos][x_pos];
				//cout<<"line 62"<<endl;
				board[y_pos][x_pos] = tmp_char;
			}
		}
	}
	//cout<<"working"<<endl;
	for (int i = 0; i < num_lines; ++i)
	{
		for (int j = 0; j < longest_line; ++j)
		{
			cout<<board[i][j];
		}
		cout<<endl;
	}

	cout<<"it works"<<endl;
	
	return 0;
}
int factor2(int & key){
	if (key==1)
	{
		return 1;
	}
	int i = 2;
	int tmp_i = i;
	int tmp_key = key;
	while(i<=tmp_key){
		if (tmp_key%i==0)
		{
			tmp_key = tmp_key/i;
			tmp_i = i;
		}
		i++;
	}
	key = key/tmp_i;
	return tmp_i;
}
int factor(int & key){
	int i = 2;
	if (key==1)
	{
		return 1;
	}
	while(i<=key){
		if (key%i==0)
		{
			key = key/i;
			return i;
		}
		i++;
	}
	return 1;
}
double rand_gen_x(int p){
	double w = cos(p);
	return w*w;
}
double rand_gen_y(int p){
	double w = sin(p);
	return w*w;
}
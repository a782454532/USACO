/*
ID:Loving Young
LANG: C++
TASK:transform
*/
#include<fstream>
#include<vector>
using namespace std;
bool fun1(vector<vector<char> >,vector<vector<char> >);
bool fun2(vector<vector<char> >,vector<vector<char> >);
bool fun3(vector<vector<char> >,vector<vector<char> >);
bool fun4(vector<vector<char> >,vector<vector<char> >);
bool fun5(vector<vector<char> >,vector<vector<char> >);
bool fun6(vector<vector<char> >,vector<vector<char> >);
bool fun7(vector<vector<char> >,vector<vector<char> >);
int main(){
	ifstream fin("transform.in");
	ofstream cout("transform.out");
	int N;
	fin>>N;
	char ch;
	vector<vector<char> > mat(N);
	vector<vector<char> > ter(N);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			fin>>ch;
			mat[i].push_back(ch);
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			fin>>ch;
			ter[i].push_back(ch);
		}
	}
	if(fun1(mat,ter)){
		cout<<1<<endl;
		return 0;
	}
	if(fun2(mat,ter)){
		cout<<2<<endl;
		return 0;
	}
	if(fun3(mat,ter)){
		cout<<3<<endl;
		return 0;
	}
	if(fun4(mat,ter)){
		cout<<4<<endl;
		return 0;
	}
	if(fun5(mat,ter)){
		cout<<5<<endl;
		return 0;
	}
	if(fun6(mat,ter)){
		cout<<6<<endl;
		return 0;
	}
	if(fun7(mat,ter)){
		cout<<7<<endl;
		return 0;
	}
	return 0;
}

bool fun1(vector<vector<char> > mat,vector<vector<char> > ter){
	int N=mat.size()-1;
	for(int i=0;i<=N;i++){
		for(int j=0;j<=N;j++){
			if(mat[i][j]!=ter[j][N-i]) return false;
		}
	}
	return true;
}

bool fun2(vector<vector<char> > mat,vector<vector<char> > ter){
	int N=mat.size()-1;
	for(int i=0;i<=N;i++){
		for(int j=0;j<=N;j++){
			if(mat[i][j]!=ter[N-i][N-j]) return false;
		}
	}
	return true;
}

bool fun3(vector<vector<char> > mat,vector<vector<char> > ter){
	int N=mat.size()-1;
	for(int i=0;i<=N;i++){
		for(int j=0;j<=N;j++){
			if(mat[i][j]!=ter[N-j][i]) return false;
		}
	}
	return true;
}

bool fun4(vector<vector<char> > mat,vector<vector<char> > ter){
	int N=mat.size()-1;
	for(int i=0;i<=N;i++){
		for(int j=0;j<=N;j++){
			if(mat[i][j]!=ter[i][N-j]) return false;
		}
	}
	return true;
}

bool fun5(vector<vector<char> > mat,vector<vector<char> > ter){
	int N=mat.size()-1;
	vector<vector<char> > tem(N+1);
	for(int i=0;i<=N;i++){
		for(int j=0;j<=N;j++)
			tem[i].push_back(mat[i][N-j]);
	}
	if(fun1(tem,ter)) return true;
	if(fun2(tem,ter)) return true;
	if(fun3(tem,ter)) return true;
	return false;
}


bool fun6(vector<vector<char> > mat,vector<vector<char> > ter)
{
	int N=mat.size()-1;
	for(int i=0;i<=N;i++){
		for(int j=0;j<=N;j++){
			if(mat[i][j]!=ter[i][j]) return false;
		}
	}
	return true;
}

bool fun7(vector<vector<char> > mat,vector<vector<char> > ter){
	return true;
}

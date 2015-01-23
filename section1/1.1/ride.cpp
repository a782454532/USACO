/*
ID: Αυ μΎ
LANG: C++
TASK: ride
*/
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
	ifstream fin("ride.in");
	ofstream fout("ride.out");
	if(!fin)
	{
		fout<<"ERROR!"<<endl;
		return -1;
	}
	if(!fout)
	{
		fout<<"ERROR!"<<endl;
		return -1;
	}
	string A,B;
	unsigned long long int num_A(0),num_B(0);
	fin>>A>>B;
	int i(1);
	num_A=A[0]-64;
	num_B=B[0]-64;
	for(;i<A.length();i++)
	{
		num_A*=(A[i]-64);
	}
	for(i=1;i<B.length();i++)
	{
		num_B*=(B[i]-64);
	}
	num_A%=47;
	num_B%=47;
	if(num_A==num_B) 
	{
		fout<<"GO"<<endl;
		return 0;
	}
	fout<<"STAY"<<endl;
	return 0;
}

/*
ID:Loving Young
LANG: C++
TASK:milk2
*/
#include<fstream>
#include<iostream>
#include<vector>
using namespace std;

class Person{
	public:
		int begin;
		int end;
};

class Time{
	public:
		int begin;
		int end;
};
void quickSort(vector<Person>& ,int,int);

int main()
{
	ifstream fin("milk2.in");
	ofstream fout("milk2.out");

	int num;
	fin>>num;

	vector<Person> farmer(num);
	vector<Time>time;
	Time last_time;
	for(int i=0;i<num;i++){
		fin>>farmer[i].begin;
		fin>>farmer[i].end;
	}
	//输入完成

	quickSort(farmer,0,num-1);
	last_time.begin=farmer[0].begin;
	last_time.end=farmer[0].end;
	for(int i=1;i<num;i++){
		if(farmer[i].begin<=last_time.end){
			if(farmer[i].end>last_time.end) last_time.end=farmer[i].end;
		}
		else{
			time.push_back(last_time);
			last_time.begin=farmer[i].begin;
			last_time.end=farmer[i].end;
		}
	}
	time.push_back(last_time);

	int max_last_time=time[0].end-time[0].begin;
	int max_no_time=0;
	for(int i=1;i<time.size();i++){
		if(time[i].end-time[i].begin>max_last_time) max_last_time=time[i].end-time[i].begin;
		if(time[i].begin-time[i-1].end>max_no_time) max_no_time=time[i].begin-time[i-1].end;
	}
	fout<<max_last_time<<' '<<max_no_time<<endl;
	return 0;
}

void quickSort(vector<Person> & farmer,int l,int r){
	if(l<r){
		int i=l,j=r;
		Person key=farmer[l];
		while(i<j){
			while(i<j&&farmer[j].begin>key.begin) j--;
			if(i<j){
				farmer[i]=farmer[j];
				i++;
			}
			while(i<j&&farmer[i].begin<key.begin) i++;
			if(i<j){
				farmer[j]=farmer[i];
				j--;
			}
		}
		farmer[i]=key;
		quickSort(farmer,l,i-1);
		quickSort(farmer,i+1,r);
	}
}

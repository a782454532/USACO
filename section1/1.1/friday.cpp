/*
ID: Αυ μΎ
LANG: C++
TASK:friday 
*/
#include<fstream>
using namespace std;

int main()
{
	ifstream fin("friday.in");
	ofstream fout("friday.out");
	int n, year, result[8] = { 0 },i;
	int last=3;
	int dayOfMonth[12] = { 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
	fin >> n;

	for (year = 1900; year < 1900 + n; year++)
	{
		if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) dayOfMonth[2] = 29;
		for (int month = 0; month < 12; month++)
		{
			last = (last + dayOfMonth[month])%7;
			result[last+1]++;
		}
		dayOfMonth[2] = 28;
	}

	fout << result[7] << ' ';
	for (i = 1; i <= 5; i++) fout << result[i] << ' ';
	fout << result[6]<<endl;
	return 0;
}
/*
ID:ΑυμΎ
LANG: C++
TASK:beads 
*/

#include<fstream>
#include<vector>
using namespace std;

int main()
{
	ifstream fin("beads.in");
	ofstream fout("beads.out");

	int left(vector<char>,int,int);
	int right(vector<char>,int,int);

	int count;
	int result(0);
	int oldresult(0);
	fin >> count;
	vector<char> beads(count);

	for (int i(0); i < count; i++)
	{
		fin >> beads[i];
	}

	for (int i(0); i < count; i++)
	{
		result = left(beads,i,count) + right(beads,i,count);
		if (result>=count)
		{
			oldresult = count;
			break;
		}
		if (result>oldresult) oldresult = result;
	}
	fout <<oldresult<<endl;
	return 0;
}

int left(vector<char> beads, int i, int count)
//count the result from left
{
	int result_left(0);
	char basic_color('w');
	int site(i-1);
	while (site < 0)site += count;
	for (;;)
	{
		if (basic_color == 'w')
		{
			result_left++;
			basic_color = beads[site];
			site--;
			while (site < 0) site += count;
			if (result_left >= count) return count;
		}
		else
		{
			if (beads[site] == basic_color||beads[site]=='w')
			{
				site--;
				while (site < 0) site += count;
				result_left++;
				if (result_left >= count) return count;
			}
			else
			{
				return result_left;
			}
		}
	}
}

int right(vector<char> beads, int i, int count)
//count the result from left
{
	int result_right(0);
	char basic_color('w');
	int site(i);
	for (;;)
	{
		if (basic_color == 'w')
		{
			result_right++;
			basic_color = beads[site];
			site++;
			while (site>=count ) site -= count;
			if (result_right>= count) return result_right;
		}
		else
		{
			if (beads[site] == basic_color||beads[site]=='w')
			{
				site++;
				while (site >=count) site -= count;
				result_right++;
				if (result_right >= count) return count;
			}
			else
			{
				return result_right;
			}
		}
	}
}

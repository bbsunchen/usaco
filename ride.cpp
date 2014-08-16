/*
ID: bbsunch2
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
	string a, b;
	int la, lb;
	int ra, rb;
	while(fin >> a >> b)
	{
		la = a.length();
		lb = b.length();
		ra = 1;
		rb = 1;
		for(int i = 0;i < la;i++)
		{
			ra *= a[i] - 64;
		}
		for(int j = 0;j < lb;j++)
		{
			rb *= b[j] - 64;
		}
		ra = ra - static_cast<int>(ra/47)*47;
		rb = rb - static_cast<int>(rb/47)*47;
		if(ra == rb)
		{
			fout << "GO" << endl;
		}else
		{
			fout << "STAY" << endl;
		}
	}
	return 0;
}

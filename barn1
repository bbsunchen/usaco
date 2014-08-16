/*
ID: bbsunch2
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main()
{
    ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");

    int boardNum = 0;
    int stallNum = 0;
    int cowStall = 0;
    fin >> boardNum >> stallNum >> cowStall;
    //cout << boardNum << stallNum << cowStall << endl;
    vector <int> stall;
    vector<int> gap;
    for(int i = 0; i < cowStall; i++)
    {
        int s;
        fin >> s;
        stall.push_back(s);
    }
    sort(stall.begin(), stall.end());
    int former = 0;
    former = stall[0];
    for(int i = 1; i < stall.size(); i++)
    {
        int latter = stall[i];

        if(latter - former > 1)
        {
            //cout << former << " " << latter << endl;
            gap.push_back(latter - former - 1);
        }
        former = latter;
    }
    //cout << gap.size() << endl;
    //for(int i = 0; i < gap.size(); i++)
    //{
    //    cout << gap[i] << endl;
    //}
    sort(gap.begin(), gap.end());
    //cout << "test" << endl;
    //cout << gap.size() << endl;

    int gapNum = boardNum - 1;

    if(gapNum > gap.size())
    {
        gapNum = gap.size();
    }
    for(int i = 0; i < gapNum; i++)
    {
        gap.erase(gap.end()-1);
    }

    for(int i = 0; i < gap.size(); i++)
    {
        cowStall += gap[i];
    }
    fout << cowStall << endl;
    return 0;
}

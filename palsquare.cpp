/*
ID: bbsunch2
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

string changeBase(int formerNum, int baseNum)
{
    string latterNumString;
    while(formerNum)
    {
        char c;
        int num = formerNum % baseNum;
        if(num < 10)
        {
            c = (char)(num+48);
        }else
        {
            c = (char)(num+55);
        }
        latterNumString.insert(latterNumString.begin(),c);
        formerNum =  (int)(formerNum / baseNum);
    }
    return latterNumString;
}

bool checkPals(string input)
{
    bool pals = true;
    int inputLength = input.length();
    int halfLength = (int)(inputLength/2);
    for(int i = 0; i < halfLength; i++)
    {
        int k = inputLength - i - 1;
        if(input[i] != input[k])
        {
            pals = false;
            break;
        }
    }
    return pals;
}

int main()
{
    ofstream fout ("palsquare.out");
    ifstream fin ("palsquare.in");

    int baseNum = 0;
    fin >> baseNum;
    for(int i = 1; i <= 300; i++)
    {
        int square = i * i;
        string result = changeBase(square, baseNum);
        bool pals = checkPals(result);
        if(pals)
        {
            fout << changeBase(i, baseNum) << " " << result << endl;
        }
    }

    return 0;
}

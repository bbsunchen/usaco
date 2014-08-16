/*
ID: bbsunch2
PROG: dualpal
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
    ofstream fout ("dualpal.out");
    ifstream fin ("dualpal.in");

    int N = 0;
    int S = 0;
    fin >> N >> S;
    int printNum = 0;

    while(printNum < N)
    {
        S ++;
        int palsNum = 0;
        bool dualpal = false;
        for(int baseNum = 2; baseNum <= 10; baseNum++)
        {
            string result = changeBase(S, baseNum);
            bool pals = checkPals(result);
            if(pals)
            {
                palsNum ++;
                if(palsNum >= 2)
                {
                    dualpal = true;
                    break;
                }
            }
        }
        if(dualpal)
        {
            fout << S << endl;
            printNum ++;
        }
    }
    return 0;
}

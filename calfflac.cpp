/*
ID: bbsunch2
PROG: calfflac
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
    ofstream fout ("calfflac.out");
    ifstream fin ("calfflac.in");
    string input = "";
    while(fin.good() && !fin.eof())
    {
        string line;
        getline(fin,line,'\n');
        input = input + line + "\n";
    }
    //cout << input << endl;
    //建立字符串中的字母和原始字符串位置对应关系
    int charIndicator = -1;
    vector<int> correspondingPosition;
    string letterString = "";
    for(int i = 0; i < input.size(); i++)
    {
        char single = input[i];
        if(single >= 'A' && single <= 'Z')
        {
            charIndicator++;
            letterString += single;
            correspondingPosition.push_back(charIndicator);
        }else if(single >= 'a' && single <='z')
        {
            single = single - 32;
            charIndicator++;
            letterString += single;
            correspondingPosition.push_back(charIndicator);
        }else
        {
            charIndicator++;
        }
    }
    vector<int> f;
    f.push_back(0);
    for(int i = 1; i < letterString.size(); i++)
    {
        if(letterString[i] == letterString[f[i-1]])
        {
            f.push_back(i-1);
            if(letterString[i] == letterString[f[i-1]-1])
            {
                f[i] = (f[i-1]-1);
            }
        }else if(f[i-1] - 1 >=0)
        {
            if(letterString[i] == letterString[f[i-1]-1])
            {
                f.push_back(f[i-1]-1);
            }else
            {
                f.push_back(i);
            }
        }else
        {
            f.push_back(i);
        }
    }
    int maxI = 0;
    int maxStep = 0;
    for(int i = 1; i < letterString.size(); i++)
    {
        if(maxStep < i-f[i]+1)
        {
            maxStep = i - f[i]+1;
            maxI = i;
        }
    }
    /*string reverseLetterString = "";
    for(int i = letterString.size()-1; i >= 0; i--)
    {
        reverseLetterString += letterString[i];
    }
    //vector<vector<int> > matrix;
    int maxI = 0;
    int maxStep = 0;
    vector<int> line1;
    vector<int> line2;
    for(int i = 0; i < letterString.size(); i++)
    {
        line1.push_back(0);
        line2.push_back(0);
    }



    for(int i = 0; i < letterString.size(); i++)
    {
        vector<int> lineInMatrix;
        for(int k = 0; k < letterString.size(); k++)
        {
            lineInMatrix.push_back(0);
        }
        matrix.push_back(lineInMatrix);
    }


    for(int k = 0; k < reverseLetterString.size(); k++)
    {
        for(int i = 0; i < letterString.size(); i++)
        {
            line2[i] = 0;
            if(letterString[i] == reverseLetterString[k])
            {
                if(i == 0 || k == 0)
                {
                    line2[i] = 1;
                }else
                {
                    line2[i] = line1[i-1] + 1;
                }
                if(maxStep <= line2[i])
                {
                    maxStep = line2[i];
                    maxI = i;
                }
            }
        }
        for(int index = 0; index < letterString.size(); index++)
        {
            line1[index] = line2[index];
        }

    }*/
    fout << maxStep << endl;
    int startLetterPosition = maxI - maxStep + 1;
    int startPosition = correspondingPosition[startLetterPosition];
    int endPosition = correspondingPosition[maxI];

    string sub = input.substr(startPosition, endPosition - startPosition + 1);

    fout << sub << endl;

    return 0;
}

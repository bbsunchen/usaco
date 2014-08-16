/*
ID: bbsunch2
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

char number_letter[10][3] = {
                            {},// 0
                            {},// 1
                            {'A','B','C'}, // 2
                            {'D','E','F'}, // 3
                            {'G','H','I'}, // 4
                            {'J','K','L'}, // 5
                            {'M','N','O'}, // 6
                            {'P','R','S'}, // 7
                            {'T','U','V'}, // 8
                            {'W','X','Y'}  // 9
                            };

int main()
{
    ofstream fout ("namenum.out");
    ifstream fin ("namenum.in");
    ifstream fdict ("dict.txt");
    string word;
    vector <string> dicts;
    while(fdict.good() && !fdict.eof())
    {
        getline(fdict,word,'\n');
        dicts.push_back(word);
    }

    string num;
    fin >> num;
    int numSize = num.size();

    for(vector<string>::iterator iter=dicts.begin();iter!=dicts.end();)
    {
        word = *iter;
        int wordSize = word.size();
        if(wordSize != numSize)
        {
            dicts.erase(iter);
            continue;
        }
        ++iter;
    }

    for(int i = 0; i < numSize; i++)
    {
        int rightNum = (int)num[i] - 48;

        for(vector<string>::iterator iter=dicts.begin();iter!=dicts.end();)
        {
            word = *iter;
            char rightLetter = word[i];
            bool key = false;
            for(int j = 0; j < 3; j++)
            {
                char letter = number_letter[rightNum][j];
                if(letter == rightLetter)
                {
                    key = true;
                    break;
                }
            }
            if(key)
            {
                ++iter;
            }else
            {
                dicts.erase(iter);
                continue;
            }
        }

    }

    if(dicts.size() == 0)
    {
        fout << "NONE" << endl;
    }else
    {
        for(vector<string>::iterator iter=dicts.begin();iter!=dicts.end();++iter)
        {
            word = *iter;
            fout << word << endl;
        }
    }

    return 0;
}

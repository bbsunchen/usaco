/*
ID: bbsunch2
PROG: crypt1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>


using namespace std;

int main()
{
    ofstream fout ("crypt1.out");
    ifstream fin ("crypt1.in");

    int digitNum;
    vector<int> digits;

    fin >> digitNum;
    for(int i = 0; i < digitNum; i++)
    {
        int d = 0;
        fin >> d;
        digits.push_back(d);
    }
    int a1 = 0;
    int a2 = 0;
    int a3 = 0;
    int b1 = 0;
    int b2 = 0;

    int c1 = 0;
    int c2 = 0;
    int c3 = 0;
    int d1 = 0;
    int d2 = 0;
    int d3 = 0;

    int e1 = 0;
    int e2 = 0;
    int e3 = 0;
    int e4 = 0;

    int A = 0;
    int B = 0;
    int C = 0;
    int D = 0;
    int E = 0;

    int caseNum = 0;
    for(int a1i = 0; a1i < digits.size(); a1i++)
    {
        a1 = digits[a1i];
        for(int a2i = 0; a2i < digits.size(); a2i++)
        {
            a2 = digits[a2i];
            for(int a3i = 0; a3i < digits.size(); a3i++)
            {
                a3 = digits[a3i];
                A = a1*100 + a2*10 + a3;
                for(int b2i = 0; b2i < digits.size(); b2i++)
                {
                    b2 = digits[b2i];
                    C = b2 * A;
                    if(C < 100 || C > 999)
                    {
                        continue;
                    }
                    c1 = (int)(C / 100);
                    c2 = (int)((C % 100)/10);
                    c3 =  C % 10;
                    bool containC1 = false;
                    bool containC2 = false;
                    bool containC3 = false;
                    for(int i = 0; i < digits.size(); i++)
                    {
                        if(c1 == digits[i])
                        {
                            containC1 = true;
                        }
                        if(c2 == digits[i])
                        {
                            containC2 = true;
                        }
                        if(c3 == digits[i])
                        {
                            containC3 = true;
                        }
                    }
                    if(!(containC1 && containC2 && containC3))
                    {
                        continue;
                    }
                    for(int b1i = 0; b1i < digits.size(); b1i++)
                    {
                        b1 = digits[b1i];
                        D = b1 * A;
                        if(D < 100 || D > 999)
                        {
                            continue;
                        }
                        d1 = (int)(D / 100);
                        d2 = (int)((D % 100)/10);
                        d3 =  D % 10;
                        bool containD1 = false;
                        bool containD2 = false;
                        bool containD3 = false;
                        for(int i = 0; i < digits.size(); i++)
                        {
                            if(d1 == digits[i])
                            {
                                containD1 = true;
                            }
                            if(d2 == digits[i])
                            {
                                containD2 = true;
                            }
                            if(d3 == digits[i])
                            {
                                containD3 = true;
                            }
                        }
                        if(!(containD1 && containD2 && containD3))
                        {
                            continue;
                        }
                        B = b1 * 10 + b2;
                        E = A * B;
                        if(E < 1000 || E > 9999)
                        {
                            continue;
                        }
                        e1 = (int)(E / 1000);
                        e2 = (int)(E / 100) - e1 * 10;
                        e3 = (int)((E % 100) / 10);
                        e4 = (int)E%10;
                        bool containE1 = false;
                        bool containE2 = false;
                        bool containE3 = false;
                        bool containE4 = false;
                        for(int i = 0; i < digits.size(); i++)
                        {
                            if(e1 == digits[i])
                            {
                                containE1 = true;
                            }
                            if(e2 == digits[i])
                            {
                                containE2 = true;
                            }
                            if(e3 == digits[i])
                            {
                                containE3 = true;
                            }
                            if(e4 == digits[i])
                            {
                                containE4 = true;
                            }
                        }
                        if(containE1 && containE2 && containE3 && containE4)
                        {
                            caseNum ++;
                        }else
                        {
                            continue;
                        }
                    }
                }
            }
        }
    }

    fout << caseNum << endl;

    return 0;
}

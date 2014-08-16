/*
ID: bbsunch2
PROG: transform
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<vector<char> > rotate90(vector<vector<char> > formerMatrix, int num)
{
    vector<vector<char> > latterMatrix;
    for(int i = 0; i < num; i++)
    {
        vector<char> lineA;
        for(int j = 0; j < num; j++)
        {
            char a = formerMatrix[num-j-1][i];
            lineA.push_back(a);
        }
        latterMatrix.push_back(lineA);
    }
    return latterMatrix;
}

vector<vector<char> > rotate180(vector<vector<char> > formerMatrix, int num)
{
    vector<vector<char> > latterMatrix;
    for(int i = 0; i < num; i++)
    {
        vector<char> lineA;
        for(int j = 0; j < num; j++)
        {
            char a = formerMatrix[num-i-1][num-j-1];
            lineA.push_back(a);
        }
        latterMatrix.push_back(lineA);
    }
    return latterMatrix;
}

vector<vector<char> > rotate270(vector<vector<char> > formerMatrix, int num)
{
    vector<vector<char> > latterMatrix;
    for(int i = 0; i < num; i++)
    {
        vector<char> lineA;
        for(int j = 0; j < num; j++)
        {
            char a = formerMatrix[j][num-i-1];
            lineA.push_back(a);
        }
        latterMatrix.push_back(lineA);
    }
    return latterMatrix;
}

vector<vector<char> > reflection(vector<vector<char> > formerMatrix, int num)
{
    vector<vector<char> > latterMatrix;
    for(int i = 0; i < num; i++)
    {
        vector<char> lineA;
        for(int j = 0; j < num; j++)
        {
            char a = formerMatrix[i][num-j-1];
            lineA.push_back(a);
        }
        latterMatrix.push_back(lineA);
    }
    return latterMatrix;
}

bool compareMatrix(vector<vector<char> > formerMatrix, vector<vector<char> > latterMatrix, int num)
{
    bool matrixEqual = true;
    for(int i = 0; i < num; i++)
    {
        bool lineEqual = true;
        for(int j = 0; j < num; j++)
        {

            if(formerMatrix[i][j] != latterMatrix[i][j])
            {
                lineEqual = false;
                break;
            }
        }
        if(lineEqual == false)
        {
            matrixEqual = false;
        }
    }
    return matrixEqual;
}

int main() {
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");
    vector<vector<char> > matrixA;
    vector<vector<char> > matrixB;
    int num = 0;
    fin >> num;
    for(int i = 0; i < num; i++)
    {
        vector<char> lineA;
        for(int j = 0; j < num; j++)
        {
            char a;
            fin >> a;
            lineA.push_back(a);
        }
        matrixA.push_back(lineA);
    }
    for(int i = 0; i < num; i++)
    {
        vector<char> lineB;
        for(int j = 0; j < num; j++)
        {
            char b;
            fin >> b;
            lineB.push_back(b);
        }
        matrixB.push_back(lineB);
    }
    vector<vector<char> > matrixRotate = rotate90(matrixA, num);
    if(compareMatrix(matrixRotate,matrixB,num))
    {
        fout << 1 << endl;
        return 0;
    }
    matrixRotate = rotate180(matrixA,num);
    if(compareMatrix(matrixRotate,matrixB,num))
    {
        fout << 2 << endl;
        return 0;
    }
    matrixRotate = rotate270(matrixA,num);
    if(compareMatrix(matrixRotate,matrixB,num))
    {
        fout << 3 << endl;
        return 0;
    }
    vector<vector<char> > Matrixreflaction = reflection(matrixA,num);
    if(compareMatrix(Matrixreflaction,matrixB,num))
    {
        fout << 4 << endl;
        return 0;
    }
    matrixRotate = rotate90(Matrixreflaction, num);
    if(compareMatrix(matrixRotate,matrixB,num))
    {
        fout << 5 << endl;
        return 0;
    }
    matrixRotate = rotate180(Matrixreflaction,num);
    if(compareMatrix(matrixRotate,matrixB,num))
    {
        fout << 5 << endl;
        return 0;
    }
    matrixRotate = rotate270(Matrixreflaction,num);
    if(compareMatrix(matrixRotate,matrixB,num))
    {
        fout << 5 << endl;
        return 0;
    }
    if(compareMatrix(matrixA,matrixB,num))
    {
        fout << 6 << endl;
        return 0;
    }
    fout << 7 << endl;
	return 0;
}

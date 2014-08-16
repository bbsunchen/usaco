/*
ID: bbsunch2
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main() {
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    map<int, int> startPoint_endPoint;
    int pairNum = 0;
    fin >> pairNum;

    for(int i = 0; i < pairNum; i++)
    {
        int startPoint;
        int endPoint;
        fin >> startPoint >> endPoint;
        startPoint_endPoint.insert(pair<int, int>(startPoint, endPoint));
    }
    //cout << startPoint_endPoint.size() << endl;
    map<int,int>::iterator it;
    int formerStart = 0;
    int formerEnd = 0;
    int currentStart = 0;
    int currentEnd = 0;
    bool firstLine = true;

    for(it = startPoint_endPoint.begin(); it!=startPoint_endPoint.end(); it++)
    {
        if(firstLine)
        {
            firstLine = false;
            formerStart = it->first;
            formerEnd = it->second;
            continue;
        }
        currentStart = it->first;
        currentEnd = it->second;
        if(currentStart <= formerEnd)
        {
            startPoint_endPoint.erase(formerStart);
            startPoint_endPoint.erase(currentStart);
            int toInsertEnd = currentEnd;
            if(toInsertEnd < formerEnd)
            {
                toInsertEnd = formerEnd;
            }
            formerEnd = toInsertEnd;
            startPoint_endPoint.insert(pair<int, int>(formerStart,toInsertEnd));
        }else
        {
            formerStart = currentStart;
            formerEnd = currentEnd;
        }
    }

    formerEnd = 0;
    firstLine = true;
    int maxBusy = 0;
    int maxLeisure = 0;
    for(it = startPoint_endPoint.begin(); it!=startPoint_endPoint.end(); it++)
    {
        //cout << it->first << " " << it->second << endl;
        if(firstLine)
        {
            firstLine = false;
            formerEnd = it->second;
            maxBusy = it->second - it->first;
            continue;
        }
        int currentBusy = it->second - it->first;
        if(maxBusy < currentBusy)
        {
            maxBusy = currentBusy;
        }
        int currentLeisure = it->first - formerEnd;
        if(maxLeisure < currentLeisure)
        {
            maxLeisure = currentLeisure;
        }
        formerEnd = it->second;
    }
    fout << maxBusy << " " << maxLeisure << endl;
	return 0;
}

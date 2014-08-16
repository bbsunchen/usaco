/*
ID: bbsunch2
PROG: milk
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <map>

using namespace std;

int main()
{
    ofstream fout ("milk.out");
    ifstream fin ("milk.in");
    map<int, int> price_farmerAmount;

    int totalAmount = 0;
    int farmerNum = 0;
    int totalPrice = 0;

    fin >> totalAmount >> farmerNum;

    for(int i = 0; i < farmerNum; i++)
    {
        int price;
        int farmerAmount;
        fin >> price >> farmerAmount;
        pair<map<int,int>::iterator,bool> ret = price_farmerAmount.insert(pair<int, int>(price, farmerAmount));
        if(!ret.second)
        {
            ret.first->second += farmerAmount;
        }
    }

    map<int, int>::iterator it;

    for( it = price_farmerAmount.begin(); it != price_farmerAmount.end(); it++)
    {
        int price = it->first;
        int farmerAmount = it->second;

        if(totalAmount > farmerAmount)
        {
            totalPrice = totalPrice + price * farmerAmount;
            totalAmount -= farmerAmount;
        }else
        {
            totalPrice = totalPrice + price * totalAmount;
            break;
        }
    }

    fout << totalPrice << endl;
    return 0;
}

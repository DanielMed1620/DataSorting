#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include <vector>
#include <chrono>
using namespace chrono;
#include "hashLinear.hpp"

float insertCheck(vector<string> list, int sTA[], int interval, int quant, HashTableLinear table, int stamp, int insertColl[])
{
    int val;
    for (int x = 0; x < quant; x++)
    {
        val = stoi(list[x]);
        sTA[x] = val;
    }
    auto start = high_resolution_clock::now();
    for (int j = interval; j < quant; j++)
    {
        table.insertItem(sTA[j]);
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start); 
    float totalTime = duration.count();
    float avg = totalTime/quant;
    insertColl[stamp] = table.getNumOfCollision();
    return avg;
}

float searchCheck(vector<string> list, int sTA[], int quant, HashTableLinear table, int stamp, int searchColl[])
{
    int num;
    for (int x = 0; x < quant; x++)
    {
        num = stoi(list[x]);
        sTA[x] = num;
    }
    int n = quant / sizeof(sTA[0]);

    auto start = high_resolution_clock::now();
    for (int j = 0; j < quant; j++)
    {
        table.searchItem(sTA[j]);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start); 
    float totalTime = duration.count();
    float avg = totalTime/quant;
    searchColl[stamp] = table.getNumOfCollision();
    return avg;
}



int main(int argc, char* argv[])
{
    ifstream inFile;
    vector<string> list;
    float insert[400];
    float search[400];
    int insertColl[400];
    int searchColl[400];
    string num;
    inFile.open(argv[1]);
    if (!inFile)
    {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    else
    {
        while (getline(inFile, num, ','))
        {
            list.push_back(num);
        }
    }
    inFile.close();
    HashTableLinear htl = HashTableLinear(10009);
    int val;
    int quant = 100;
    int i = 0;
    int interval = 0;
    int stamp = 0;
    while (i != list.size() + 1)
    {
        if (i == quant)
        {
            int sTA[quant];
            float avgITime = insertCheck(list, sTA, interval, quant, htl, stamp, insertColl);
            float avgSTime = searchCheck(list, sTA, quant, htl, stamp, searchColl);
            interval = quant;
            insert[stamp] = avgITime;
            search[stamp] = avgSTime;
            stamp = stamp+1;
            quant = quant + 100;
        }
        i++;
    }
    for (int x = 0; x < 400; x++)
    {
        cout << searchColl[x] << endl;
    }
    ofstream outdata;
    outdata.open("HashLinInsert.txt");
    for (int i = 0; i < 400; i++)
    {
        outdata << insert[i] << endl;
    }
    outdata.close();
    outdata.open("HashLinSearch.txt");
    for (int i = 0; i < 400; i++)
    {
        outdata << search[i] << endl;
    }
    outdata.close();
    outdata.open("HashLinInsertColl.txt");
    for (int i = 0; i < 400; i++)
    {
        outdata << insertColl[i] << endl;
    }
    outdata.close();
    outdata.open("HashLinSearchColl.txt");
    for (int i = 0; i < 400; i++)
    {
        outdata << searchColl[i] << endl;
    }
    outdata.close();
    return 0;
}
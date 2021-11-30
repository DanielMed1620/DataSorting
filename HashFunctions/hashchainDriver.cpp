#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include <vector>
#include <chrono>
using namespace chrono;
#include "hashchain.hpp"

float insertCheck(vector<string> list, int sTA[], int interval, int quantity, HashTable table, int stamp, int insertColl[])
{
    int val;
    for (int x = 0; x < quantity; x++)
    {
        val = stoi(list[x]);
        sTA[x] = val;
    }
    auto start = high_resolution_clock::now();
    for (int j = interval; j < quantity; j++)
    {
        table.insertItem(sTA[j]);
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start); 
    float totalTime = duration.count();
    float avg = totalTime/quantity;
    insertColl[stamp] = table.getNumOfCollision();
    return avg;
}

float searchCheck(vector<string> list, int sTA[], int quantity, HashTable table, int stamp, int searchColl[])
{
    int num;
    for (int x = 0; x < quantity; x++)
    {
        num = stoi(list[x]);
        sTA[x] = num;
    }

    auto start = high_resolution_clock::now();
    for (int j = 0; j < quantity; j++)
    {
        table.searchItem(sTA[j]);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start); 
    float totalTime = duration.count();
    float avg = totalTime/quantity;
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
    HashTable ht = HashTable(10009);
    int val;
    int quantity = 100;
    int i = 0;
    int interval = 0;
    int stamp = 0;
    while (i != list.size() + 1)
    {
        if (i == quantity)
        {
            int sTA[quantity];
            float avgITime = insertCheck(list, sTA, interval, quantity, ht, stamp, insertColl);
            float avgSTime = searchCheck(list, sTA, quantity, ht, stamp, searchColl);
            interval = quantity;
            insert[stamp] = avgITime;
            search[stamp] = avgSTime;
            stamp = stamp+1;
            quantity = quantity + 100;
        }
        i++;
    }
    for (int x = 0; x < 400; x++)
    {
        cout << "average insert time: " << insert[x] << " Nanoseconds with " << insertColl[x] << " colliosions" << endl;
        cout << "average search time: " << search[x] << " Nanoseconds with " << searchColl[x] << " colliosions" << endl;
    }
    ofstream outdata;
    outdata.open("HashInsert.txt");
    for (int i = 0; i < 400; i++)
    {
        outdata << insert[i] << endl;
    }
    outdata.close();
    outdata.open("HashSearch.txt");
    for (int i = 0; i < 400; i++)
    {
        outdata << search[i] << endl;
    }
    outdata.close();
    outdata.open("HashInsertColl.txt");
    for (int i = 0; i < 400; i++)
    {
        outdata << insertColl[i] << endl;
    }
    outdata.close();
    outdata.open("HashSearchColl.txt");
    for (int i = 0; i < 400; i++)
    {
        outdata << searchColl[i] << endl;
    }
    outdata.close();
    return 0;
}

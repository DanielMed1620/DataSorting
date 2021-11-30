#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include <vector>
#include <chrono>
using namespace chrono;
#include "bst.hpp"
BST T;

float insertCheck(vector<string> list, int sTA[], int interval, int quantity)
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
        T.addNode(sTA[j]);
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start); 
    float totalTime = duration.count();
    float avg = totalTime/100;
    return avg;
}

float searchCheck(vector<string> list, int sTA[], int quantity)
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
        T.searchNode(sTA[j]);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start); 
    float totalTime = duration.count();
    float avg = totalTime/quant;
    return avg;
}


int main(int argc, char* argv[])
{
    ifstream inFile;
    vector<string> list;
    float insert[400];
    float search[400];
    string num;
    inFile.open(argv[1]);
    if (!inFile)
    {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    else
    {
        int place = 0;
        int dig;
        while (getline(inFile, num, ','))
        {
            list.push_back(num);
        }
    }
    inFile.close();

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
            float avgITime = insertCheck(list, sTA, interval, quantity);
            float avgSTime = searchCheck(list, sTA, quantity);
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
        cout << "average insert time: " << insert[x] << endl;
        cout << "average search time: " << search[x] << endl;
    }
    ofstream outdata;
    outdata.open("BSTInsert.txt");
    for (int i = 0; i < 400; i++)
    {
        outdata << insert[i] << endl;
    }
    outdata.close();
    outdata.open("BSTSearch.txt");
    for (int i = 0; i < 400; i++)
    {
        outdata << search[i] << endl;
    }
    outdata.close();
    return 0;
}
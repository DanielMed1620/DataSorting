#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include <vector>
#include <chrono>
using namespace std::chrono;
#include "SLL.hpp"
LinkList LL;


float insertCheck(vector<string> list, int sTA[], int interval, int quantity) //This helper function times how long it takes to imput every 100 numbers from the data set
{
    int val;
    for (int x = 0; x < quantity; x++) 
    {
        val = stoi(list[x]);
        sTA[x] = val;
    }
    auto start = high_resolution_clock::now(); //starts the clock
    for (int j = interval; j < quantity; j++) //starts clock
    {
        LL.insertNode(LL.lastNode(), sTA[j]); 
    }

    auto stop = high_resolution_clock::now(); //stops the clock
    auto duration = duration_cast<nanoseconds>(stop - start); //finds how long the insert function took to insert the 100 numbers into the link list and timed in nanoseconds
    float totalTime = duration.count(); //sets the float total time to how long it took for the imput to take
    float avg = totalTime/100; 
    return avg; 
}

float searchCheck(vector<string> list, int sTA[], int quantity) 
{
    int num;
    for (int x = 0; x < quantity; x++) //converts all the string numbers into integers and stores them into a temporary array
    {
        num = stoi(list[x]);
        sTA[x] = num; 
    }
    auto start = high_resolution_clock::now(); //starts clock
    for (int j = 0; j < quantity; j++)
    {
        LL.searchNode(sTA[j]); //looks for the number in the link list that's givin form the temporary array which we know that every number from it can be found
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start); //finds the how long the timer when for
    float totalTime = duration.count(); //sets the total time to a float
    float avg = totalTime/quantity; 
    return avg;
}

int main(int argc, char* argv[])
{
    ifstream inFile;
    vector<string> list; //this is the main list that the data set numbers are stored
    float insert[400]; 
    float search[400];
    string num;
    inFile.open(argv[1]); 
    if (!inFile) //check if files open
    {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    else
    {
        while (getline(inFile, num, ',')) //puts all the numbers from the data list file into a vector list
        {
            list.push_back(num);
        }
    }
    inFile.close(); //close the data file

    int quantity = 100; //the 100 iderations marker
    int i = 0; 
    int interval = 0; 
    int pos = 0; 
    while (i != list.size() + 1) //while the loop check size isn't the same size as the 40001 then keep doing the loop
    {
        if (i == quantity) //if the loop is at an intervall of 100 run this if statement
        {
            int sTA[quantity]; //sets the temporary to the theoretical amount of numbers that should be in this array
            float avgITime = insertCheck(list, sTA, interval, quantity); //run the insert time check with the full list of numbers the temporary array, the what interval start position is, and how many numbers should be in the temp array
            float avgSTime = searchCheck(list, sTA, quantity); 
            interval = interval + 100; 
            insert[pos] = avgITime; //sets the insert average time
            search[pos] = avgSTime; 
            pos = pos+1; 
            quantity = quantity + 100; 
        }
        i++; 
    }
    ofstream outdata; 
    outdata.open("LinkInsert.txt");
    for (int i = 0; i < 400; i++) 
    {
        outdata << insert[i] << endl;
    }
    outdata.close();
    outdata.open("LinkSearch.txt");
    for (int i = 0; i < 400; i++)
    {
        outdata << search[i] << endl;
    }
    outdata.close();
    return 0;
}


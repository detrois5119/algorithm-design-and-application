#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main(int argc, char **argv)
{
	ifstream fin;
    fin.open(argv[1], fstream::in);
    if(!fin.is_open())
    {
        cout << "Error: the input file is not opened!!" << endl;
        exit(1);
    }
    vector<int> scores;
//    int score;
    while (getline(fin,scores)) {
            cout << scores << "\n";
            scores.push_back(scores);
        }
    fin.close();
    return 0;
//	vector < vector<int> > sleep;
//	sleep.resize(1000);
//	for(int i=0; i < 1000; ++i)
//	{
//		sleep[i].resize(2);
//	} 
}
void getIndex(vector<int> v, int K)
{
    auto it = find(v.begin(), v.end(), K);
 
    // If element was found
    if (it != v.end())
    {
     
        // calculating the index
        // of K
        int index = it - v.begin();
        cout << index << endl;
    }
    else {
        // If the element is not
        // present in the vector
        cout << "-1" << endl;
    }
}

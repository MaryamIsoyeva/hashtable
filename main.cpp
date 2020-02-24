#include <iostream>
#include <cstdlib>
#include <vector>
#include <time.h>
#include "HashTable.h"
using namespace std;
int main(int argc, const char * argv[])
{
    string s;
    vector<string> strings;
    s = "stringtobehashed";
    strings.push_back(s);
    HashTable hashTable (50);
    for(auto i = strings.begin(); i!= strings.end(); ++i){
        hashTable.add(*i);
    }
    
    
    cout << hashTable.maxLen();
    
    cout << "\n" << hashTable.check(s);
    
    
    return 0;
}


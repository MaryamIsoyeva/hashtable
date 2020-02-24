#ifndef __basecampHashTables__HashTable__
#define __basecampHashTables__HashTable__

#include <iostream>
#include <vector>
#include <string>

struct Node {
    Node* next;
    std::string key;
    int hash;
};
class List {
    Node* head;
    Node* tail;
    int count_;
public:
    List();
    List(int n);
    Node* addNode(int n, int mod);
    Node* addNode(std::string n, int mod);
    Node* addNode(Node* node);
    void printList();
    int count();
    int getCount();
    ~List();
    int deleteNode(int n);
    bool find (std::string s);
};

class HashTable{
private:
    std::vector<List*> table ;
    int size;
public:
    HashTable();
    HashTable(int N);
    int add(int n);
    int add(std::string n);
    int maxLen();
    int minLen();
//    int search();
    int getSize();
    void printHashTable();
    int hashFuncStr(std::string s);
    bool check(std::string value);
    
};

int hashFunc(int n, int mod);


#endif /* defined(__basecampHashTables__HashTable__) */

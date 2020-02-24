#include "HashTable.h"
#include <math.h>
using namespace std;

List::List(): head(nullptr), tail(nullptr), count_(0) {}

void List::printList() {
    Node*ptr = head;
    while(ptr){
        std::cout << ptr->key; //value ;
        ptr = ptr -> next;
        std::cout<<" ";
    }
}
int List::count(){
    Node* ptr = head;
    if(! ptr)return 0;
    int c = 0;
    while(ptr){
        ptr = ptr->next;
        ++c;
    }
    return c;
}
int List::getCount() {return count_;}

int HashTable::hashFuncStr(std::string s){
    int p = 11;
    int hashv = 0;
    int pow = 1;
    int curVal = 0;
    for(int i = 0; i < s.length(); ++i){
        curVal = (s[i]-'a'+1);
        hashv = (hashv+curVal*pow)%size;
        pow = (pow*p)%size;
    }
    return 0;
    
}

HashTable::HashTable(int N){
    size = N;
    for(int i = 0; i < size ; ++i){
        List* l = new List();
        table.push_back(l);
    }
}

Node* List::addNode(Node* node){
    if(!head) {head = node; tail = head; return node;}
    tail -> next = node;
    ++count_;
    return node;
}
int HashTable::getSize(){
    return size;
}
int HashTable::maxLen(){
    int maxlen = -1; //if table is empty
    int len;
    for(int i = 0; i < size; ++i){
        len = table[i] -> getCount();
        if(len > maxlen) maxlen = len;
    }
    return maxlen;
}
int HashTable::minLen(){
    int minlen = size;
    int len;
    for(int i = 0; i < size; ++i){
        len = table[i] -> getCount();
        if(len < minlen) minlen = len;
    }
    return minlen;
}
void HashTable::printHashTable(){
    for(int i = 0; i < size; ++i){
        table[i]->printList();
        std::cout << "\n";
    }
}
List::~List(){
    while(head){
        Node* h = head -> next;
        delete head;
        head = h;
    }
}
bool HashTable::check(std::string value){
    int has = hashFuncStr(value);
    return ((table[has]) -> find(value));
}
bool List::find(std::string s){
    Node*ptr = head;
    while(ptr){
        if((ptr -> key) == s) return true;
        ptr = ptr -> next;
       
    }
    return false;
}
int HashTable::add(string n){
    int hash = hashFuncStr(n);
    Node* node = new Node{nullptr, n, hash};
    (table[hash]) -> addNode(node);
    return 0;
}
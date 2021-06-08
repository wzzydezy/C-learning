#include <iostream>
#include <vector>
#include <string.h>
#include <unordered_map>
#include <sstream>
#include <queue>
#include <stack>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <limits.h>
#include <list>
#include <stdlib.h>
using namespace std;

struct dlinknode
{
    int key, value;
    dlinknode* prev;
    dlinknode* next;
    dlinknode():key(0), value(0), prev(nullptr), next(nullptr){};
    dlinknode(int _key, int _value):key(_key), value(_value), prev(nullptr), next(nullptr){};
};

class LRUcache{
private:
    unordered_map<int,dlinknode*> map;
    int size;
    int capacity;
    dlinknode* head;
    dlinknode* tail;

public:
    LRUcache(int _capacity):capacity(_capacity), size(0){
        head = new dlinknode();
        tail = new dlinknode();
        head->next=tail;
        tail->prev=head;
    }

    int get(int key){
        if(!map.count(key)){
            return -1;
        }
        dlinknode* node = map[key];
        movetohead(node);
        return node->value;
    }

    void put(int key, int value){
        if(!map.count(key)){
            dlinknode* node = new dlinknode(key, value);
            addtohead(node);
            map[key] = node;
            size++;
            if(size>capacity){
                dlinknode* removed = removetail();
                map.erase(removed->key);
                delete removed;
                --size;
            }
        }
    }

    void addtohead(dlinknode* node){
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void removenode(dlinknode* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void movetohead(dlinknode* node){
        removenode(node);
        addtohead(node);
    }

    dlinknode* removetail(){
        dlinknode* node = tail->prev;
        removenode(node);
        return node;
    }

};

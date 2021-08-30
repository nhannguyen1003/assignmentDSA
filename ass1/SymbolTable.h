#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H
#include "main.h"

class SymbolTable
{
public:
    SymbolTable() {}
    void run(string filename);
};
struct Information
{
    string name;
    string type;
    int scope;
    Information(string name) :name(name), type("number")
    {
        this->scope=LinkedList::getScope();
    }
    Information(string name,string type) :name(name), type(type)
    {
        this->scope=LinkedList::getScope();
    } 
};

class Node{
    public:
    Information data;
    Node* next;
    Node(Information data,Node* next);
    Node(Information data);
};

class LinkedList{
    Node* head;
    static int spn;
    public:
    LinkedList() :head(nullptr) {}
    LinkedList(Node* head) :head(head) {}
    static int getScope()
    {
        return spn;
    }
    Node* getHead();
    void setHead(Node* head);
};


bool isValidLine(LinkedList* LL,string s);

#endif
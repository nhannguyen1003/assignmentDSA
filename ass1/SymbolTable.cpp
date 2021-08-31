#include "SymbolTable.h"

int LinkedList::spn=0;
void LinkedList::modifiedScope(string str="-")
    {
        if(str=="+") spn++;
        else spn--;
    }

Node* LinkedList::getHead()
{
    return this->head;
}
void LinkedList::setHead(Node* head)
{
    this->head=head;
}


bool LinkedList::push(Node* node)
{
    if(head==nullptr)
    {
        head=node;
        return true;
    }
    Node* ptr= head;
    while(!head->next) ptr=ptr->next;
    ptr->next=node;
    return true;

}

bool LinkedList::pop()
{
    if(head== nullptr) return false;
    Node* pre=head;
    if(head->next=nullptr)
    {
        delete pre;
        head=nullptr;
    }
    while(!pre->next->next)
    {
        pre=pre->next;
    }
    Node* temp=pre->next;
    delete temp;
    pre->next=nullptr;
    return true;

}

vector<string> splitString(string s)
{
    vector<string> str;
    string temp="";
    for(int i=0;i<s.length();i++)
    {
        if(s[i]==' ') 
            {
                str.push_back(temp);
                temp="";
            }
        else{
            temp+=s[i];
        }
    }
    return str;
}

bool isValidDemand(vector<string> str)
{
    if(str[0]=="INSERT")
        {
            if(str.size()==3 && (str[3]=="number" || str[3]=="string"))
                return true;
            else return false;
        }
    if(str[0]=="BEGIN" && str.size()==1) return true;
    if(str[0]=="END" && str.size()==1) return true;
    if(str[0]=="LOOKUP" && str.size()==2) return true;
    if(str[0]=="ASSIGN" && str.size()==3) return true;
    if(str[0]=="PRINT" && str.size()==1) return true;
    if(str[0]=="RPRINT" && str.size()==1) return true;
    return false;
}

bool Insert(LinkedList* LL,string name, string type)
{
    Node* node=new Node(Information(name,type),nullptr);
    Node* head=LL->getHead();
    while(head!=nullptr)
    {
       if(head->data.name==node->data.name)
        {
            if (head->data.scope==node->data.scope)
                throw Redeclared("INSERT "+ name + " " + type);
        }
        head=head->next;
    }
    return LL->push(node);
}

bool Assign(LinkedList* LL, string name, string value)
{
    Node* head=LL->getHead();
    while(head!=nullptr)
    {
        if(name==head->data.name) break;
        head=head->next;
    }
    if(head==nullptr) throw Undeclared("ASSIGN "+name+" "+value);
    if(head->data.type=="number")
        for(int i=0;i<value.size();i++)
        {
            if(value[i]<48 || value[i]>57) throw TypeMismatch("ASSIGN "+name+" "+value);   
        }
    else
    {
        if(value[0]!=27 && value[value.size()-1] !=27)
            throw TypeMismatch("ASSIGN "+name+" "+value);  
        for (int i = 1; i < value.size()-1; i++)
        {
            if(value[i]==20) continue;
            if(value[i]<48)  throw TypeMismatch("ASSIGN "+name+" "+value);  
            if(value[i]>57 &&value[i]<65) throw TypeMismatch("ASSIGN "+name+" "+value);  
            if(value[i]>90 && value[i]<97) throw TypeMismatch("ASSIGN "+name+" "+value);  
            if(value[i]>122) throw TypeMismatch("ASSIGN "+name+" "+value);
        }
    }
        
    return true;
}

int LookUp(LinkedList* LL,string name)
{
    Node* head= LL->getHead();
    while(head!=nullptr)
    {
        if(head->data.name== name)
        {
            return head->data.scope;
        }
        head=head->next;
    }
}

bool isValidLine(LinkedList* LL,string s)
{
    vector<string> str=splitString(s);
    if(!isValidDemand(str)) 
        return false;
    switch (s[0])
    {
    case 'I':
    {
        Insert(LL,str[1],str[2]);
        break;
    }
    case 'B':
    {
        LL->modifiedScope("+");
        break;
    }
    case 'E':
    {
        LL->modifiedScope();
        //check UnknowBlock
        if(LL->getScope()<0) throw UnknownBlock();
        break;
    }
    case 'A':
    {
        Assign(LL,str[1],str[2]);
        break;
    }
    case 'L':
    {

        break;
    }
    
    default:
        break;
    }
    return true;
}





void SymbolTable::run(string filename)
{
    //like a main 
    LinkedList* LL=new LinkedList();
    fstream fl;
    fl.open(filename,ios::in | ios::out);
    while(!fl.eof())
    {
        string s;
        getline(fl,s);
       // if(isValidline(LL,s);
    }
}


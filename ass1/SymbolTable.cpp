#include "SymbolTable.h"

int LinkedList::spn=0;
Node* LinkedList::getHead()
{
    return this->head;
}
void LinkedList::setHead(Node* head)
{
    this->head=head;
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
    if(str[0]=="PRINT" && str.size()==1) return true;
    if(str[0]=="RPRINT" && str.size()==1) return true;

}
bool isValidLine(LinkedList* LL,string s)
{
    vector<string> str=splitString(s);
    if(!isValidDemand(str)) 
        throw Undeclared(s);
    switch (s[0])
    {
    case 'I':
    {
        
    }

        break;
    
    default:
        break;
    }

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


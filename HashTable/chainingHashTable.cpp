#include <iostream>
#include <list>
using namespace std;

#define LOAD_FACTOR 20

struct Node{
    int data; // address
    struct Node* next;
};

struct HashNode{
    int key;
    int count;
    struct Node* list;
};

struct HashTable{
    int size;
    int numOfData;
    struct HashNode** table;
};

struct HashTable* CreateHashTable(int tableSize);
int GetKey(int data, int tableSize);
bool HashSearch(struct HashTable* hTable, int data);
void HashInsert(struct HashTable* hTable, int data);
void HashDelete(struct HashTable* hTable, int data);
void DeleteHashTable(struct HashTable* hTable);
void PrintHashTable(struct HashTable* hTable);
struct HashTable* ReHash(struct HashTable* hTable);


int main(){
    int tableSize=10;
    struct HashTable* hTable = CreateHashTable(tableSize);
    for(int i=0; i<10; i++){
        HashInsert(hTable,i);
    }
    PrintHashTable(hTable);
    for(int i=0; i<10; i++){
        HashDelete(hTable, i);
    }
    PrintHashTable(hTable);
    DeleteHashTable(hTable);
    return 0;
}

struct HashTable* CreateHashTable(int tableSize){
    struct HashTable* hTable;
    hTable = new HashTable;
    if(!hTable)return NULL;
    hTable->size=tableSize;
    hTable->numOfData=0;
    hTable->table=new HashNode*[tableSize];
    
    if(!hTable->table)return NULL; //memory allocation fail
    
    for(int i=0; i<tableSize; i++){
        hTable->table[i]=new HashNode;
        if(!hTable->table[i])return NULL; //memory allocation fail
        hTable->table[i]->key=i;
        hTable->table[i]->count=0;
        hTable->table[i]->list=NULL; //memory allocation fail
    }
    return hTable; // hashtable created
};

int GetKey(int data, int tableSize){
    return data % tableSize;
}

bool HashSearch(struct HashTable* hTable, int data){
    struct Node* temp = NULL;
    temp=hTable->table[GetKey(data,hTable->size)]->list;
    if(!temp){
        return false;
    }
    while(temp){
        if(temp->data==data){
            return true;
        }
        temp=temp->next;
    }
    return false;
}

void HashInsert(struct HashTable* hTable, int data){
    struct HashNode* first;
    first = hTable->table[GetKey(data,hTable->size)];
    struct Node* temp;
    temp=first->list;
    struct Node* node = new Node;
    if(!node)return ;//memory allocation fail
    node->data = data;
    node->next = NULL;
    if(!temp){
        first->list=node;
    }else{
        struct Node* temp2;
        temp2=first->list;
        first->list = node;
        node->next=temp2;
    }
    first->count++;
    if((first->count / hTable->size)>LOAD_FACTOR){
        hTable=ReHash(hTable);
    }
}

void HashDelete(struct HashTable* hTable, int data){
    struct HashNode* first;
    first = hTable->table[GetKey(data,hTable->size)];
    struct Node* temp;
    temp=first->list;
    struct Node* before = temp;
    if(!temp)return ;
    while(temp){
        if(temp->data==data){
            if(before==temp){
                first->list = temp->next;
            }else{
                before->next = temp->next;
            }
            free(temp);
            break;
        }
        before = temp;
        temp=temp->next;
    }
    first->count--;
}

void DeleteHashTable(struct HashTable* hTable){
    for(int i=0; i<hTable->size; i++){
        struct Node* temp=NULL;
        struct Node* before=NULL;
        temp=hTable->table[i]->list;
        before=temp;
        while(temp){
            before=temp;
            temp=temp->next;
            free(before);
        }
    }
    for(int i=0; i<hTable->size; i++){
        free(hTable->table[i]);
    }
    free(hTable); // hashtable deleted
}

void PrintHashTable(struct HashTable* hTable){
    for(int i=0; i<hTable->size; i++){
        struct HashNode* first = hTable->table[i];
        struct Node* temp=first->list;
        while(temp){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
}

struct HashTable* ReHash(struct HashTable* hTable){
    struct HashTable* oldTable = hTable;
    hTable = CreateHashTable(hTable->size*2);
    if(!hTable)return NULL; // memory allocation fail;
    for(int i=0; i<oldTable->size; i++){
        struct HashNode* first = oldTable->table[i];
        struct Node* temp = first->list;
        while(temp){
            HashInsert(hTable, temp->data);
            temp=temp->next;
        }
    }
    DeleteHashTable(oldTable);
    return hTable;
}

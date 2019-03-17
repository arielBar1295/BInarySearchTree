#include<iostream>
#include<exception>
#include<exception>
using namespace std;
namespace ariel{
class Tree{
struct node
    {
        int key;
        node* left;
        node* right;
       
       node(){
           left=NULL;
           right=NULL;
       }
};

node* rootP;
node* helpRemove(int key,node* r);
node* getRoot();
node* findMin(node* t);
node* helpinsert(int key,node* r);
int helpParent(int key,node* r);
int sizeHelp(node* t);
int containsHelp(int i,node* r);
int leftHelp(int i,node* r);
int rightHelp(int i,node* r);
void printHelp(node* r);
public:
Tree(){
    rootP=NULL; 
}
int parent(int i);
int left(int i);
int right(int i);
int contains(int i);
void insert(int i);
int root();
void remove (int i);
 int size();
 void print();
};
}

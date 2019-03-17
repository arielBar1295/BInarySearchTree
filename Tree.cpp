#include<iostream>
#include "Tree.hpp"
#include<exception>
int ariel::Tree::sizeHelp(Tree::node* t){
if(t==NULL)
      return 0;
   else
   return sizeHelp(t->left)+1+sizeHelp(t->right); 
}
int ariel::Tree::size(){

return sizeHelp(this->rootP);
}


ariel::Tree::node* ariel::Tree::helpinsert(int key,ariel::Tree::node* r){
       
if(r==NULL){
       r=new node;
       r->key=key;
       r->left=NULL;
       r->right=NULL;
    }
     
    else{
        if(r->key>key){
           r->left= helpinsert(key,r->left);
        }
        else{
            if(r->key<key)
          r->right= helpinsert(key,r->right); 
        else
          {
              throw " already exists";
          }
        }  
         
    }
    return r;
 
}

void ariel::Tree::insert(int x){
    
      
    rootP=helpinsert(x,this->rootP);
  
}  
   


int ariel::Tree::containsHelp(int i,ariel::Tree::node* r){
  if(r==NULL)
  return 0;
  if(i==r->key)
  return 1;
  
  else
  {
    if(i>r->key)
      return containsHelp(i,r->right);
      else
      return containsHelp(i,r->right);
  }
  
  
}
ariel::Tree::node* ariel::Tree::findMin(ariel::Tree::node* r){
  ariel::Tree::node* curr=r;
  while(curr->left!=NULL){
    curr=curr->left;
  }
  return curr;
}
ariel::Tree::node* ariel::Tree::helpRemove(int key,ariel::Tree::node* r){
 if((containsHelp(key,r))==0){
   throw " is not in the tree!";
   
 }
 ariel::Tree::node* temp;
  if(r==NULL){
    return rootP;
  }
  else if(key<r->key){
    r->left=helpRemove( key,r->left);
  }
  
  
   else if(key>r->key)
    r->right=helpRemove( key,r->right);
  
     else if(r->left && r->right)
        {
            temp = findMin(r->right);
            r->key = temp->key;
            r->right = helpRemove(r->key, r->right);
        }
        else
        {
            temp = r;
            if(r->left == NULL)
                r = r->right;
            else if(r->right == NULL)
                r= r->left;
            delete temp;
        }

        return r;
}
  

  
void ariel::Tree::remove(int key){
  
  rootP=helpRemove(key,this->rootP);

   

}

int ariel::Tree::contains(int i){
  return containsHelp(i,this->rootP);
}
int ariel::Tree::helpParent(int key,ariel::Tree::node* r){
 
 if(r==NULL)
   return 0;
  if(r->key==key)
     return 0;
    else
    { 
      while(r->right->key!=key!=NULL && r->left->key!=key!=NULL &&r!=NULL){
            if(r->key<key)
             r=r->right;
             else
             r=r->left;
      }
    }
   return r->key; 
}

int ariel::Tree::parent(int i){
  
  return helpParent(i,this->rootP);
  
  
}
int ariel::Tree::root(){
  return this->rootP->key;
}
int ariel::Tree::leftHelp(int i,ariel::Tree::node* r){
  if(r==NULL)
    return NULL;
    while(r->key!=i){
      if(i>r->key)
      r=r->right;
      else
        r=r->left;
    }
    if(r->left==NULL)
      return NULL;
      else
      {
        return r->left->key;
      }
      
}
int ariel::Tree::left(int i){
  return leftHelp(i,this->rootP);
}
int ariel::Tree::rightHelp(int i,ariel::Tree::node* r){
  if(r==NULL)
    return NULL;
    while(r->key!=i){
      if(i>r->key)
      r=r->right;
      else
        r=r->left;
    }
    if(r->right==NULL)
      return NULL;
      else
      {
        return r->right->key;
      }
      
}
int ariel::Tree::right(int i){
  return rightHelp(i,this->rootP);
}
void ariel::Tree::printHelp(ariel::Tree::node* r){
if(r == NULL)
    return;
  printHelp(r->left);
  cout << r->key << " ";
  printHelp(r->right);
}
void ariel::Tree::print(){
  printHelp(this->rootP);
}

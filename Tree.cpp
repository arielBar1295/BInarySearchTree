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
              throw "already exists";
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
      return containsHelp(i,r->left);
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
   throw "is not in the tree!";
   
 } 
    if (r == NULL) return r; 
  
    if (key < r->key) 
        r->left = helpRemove(key,r->left); 
  
    else if (key > r->key) 
        r->right = helpRemove(key,r->right); 
  
    else
    { 
          if (r->left == NULL) 
        { 
            ariel::Tree::node* temp = r->right; 
            delete r; 
            return temp; 
        } 
        else if (r->right == NULL) 
        { 
            ariel::Tree::node* temp = r->left; 
            delete r; 
            return temp; 
        } 
  
         ariel::Tree::node* temp = findMin(r->right); 
  
        r->key = temp->key; 
  
        r->right = helpRemove(temp->key,r->right); 
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
  if((containsHelp(key,r))==0){
   throw "is not in the tree!";
   
 }
 int ri=0;
 int l=0;
 if(r==NULL || r->key==key)
    throw "no parent";
    if(r->left!=NULL){
        l=1;
      if(r->left->key==key)
         return r->key;
    }
     if(r->right!=NULL){
       ri=1;
      if(r->right->key==key)
         return r->key;
    }
     if(ri==1){
      if(key>r->key)
         return helpParent(key,r->right);
    }
    if(l==1){
      if(key<r->key)
         return helpParent(key,r->left);
    }
              
        return NULL;
       
}
      // }
    //   while(r->right->key!=key!=NULL && r->left->key!=key!=NULL &&r!=NULL){
    //         if(r->key<key)
    //          r=r->right;
    //          else
    //          r=r->left;
    //   }
    // }
//     }
//    return NULL; 

// }

int ariel::Tree::parent(int i){
  
  return helpParent(i,this->rootP);
  
  
}
int ariel::Tree::root(){
  if(rootP==NULL)
  throw "no tree!";
  else 
  return this->rootP->key;
}
int ariel::Tree::leftHelp(int i,ariel::Tree::node* r){
  if(r==NULL)
    throw "no tree";
    while(r->key!=i){
      if(i>r->key)
          r=r->right;
      else
           r=r->left;
    }
    if(r->left==NULL)
      throw "not exsits";
    return r->left->key;
      
      
}
int ariel::Tree::left(int i){
  return leftHelp(i,this->rootP);
}
int ariel::Tree::rightHelp(int i,ariel::Tree::node* r){
  if(r==NULL)
    throw "no tree";
    while(r->key!=i){
      if(i>r->key)
      r=r->right;
      else
        r=r->left;
    }
    if(r->right==NULL)
     throw "exception!";
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
void ariel::Tree::destroy(ariel::Tree::node* r)
{
  if(r!=NULL){
    destroy(r->left);
    destroy(r->right);
    delete r;
  }
}
ariel::Tree::~Tree(){
  destroy(this->rootP);
}

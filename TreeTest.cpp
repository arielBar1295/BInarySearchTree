/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
using std::cout, std::endl;
#include "badkan.hpp"
#include "Tree.hpp"

int main() {
  ariel::Tree emptytree;
  ariel::Tree threetree;
  ariel::Tree MyTree; 
ariel::Tree MyEmptyTree;  
  threetree.insert(5);
  threetree.insert(7);
  threetree.insert(3);
  MyTree.insert(10);
 MyTree.insert(5);
MyTree.insert(6);
MyTree.insert(4);
MyTree.insert(3);
MyTree.insert(15);
MyTree.insert(14);
MyTree.insert(20);
  badkan::TestCase tc("Binary tree");
  tc
  .CHECK_EQUAL (emptytree.size(), 0)
  .CHECK_OK    (emptytree.insert(5))
  .CHECK_EQUAL (emptytree.size(), 1)
  .CHECK_EQUAL (emptytree.contains(5), true)
  .CHECK_OK    (emptytree.remove(5))
  .CHECK_THROWS(emptytree.remove(5))
  .CHECK_EQUAL (emptytree.size() ,0)
  
  .CHECK_EQUAL (threetree.size(), 3)
  .CHECK_EQUAL (threetree.root(), 5)
  .CHECK_EQUAL (threetree.parent(3), 5)
  .CHECK_EQUAL (threetree.parent(7), 5)
  .CHECK_EQUAL (threetree.left(5), 3)
  .CHECK_EQUAL (threetree.right(5), 7)
  .CHECK_THROWS(threetree.insert(3))
  .CHECK_OK    (threetree.print())
  .CHECK_EQUAL (MyTree.size(), 8)
  .CHECK_EQUAL (MyTree.contains(100), false)
  .CHECK_EQUAL (MyTree.contains(20), true)
   .CHECK_EQUAL (MyTree.parent(4), 5)
.CHECK_THROWS(MyTree.insert(5))
.CHECK_OK    (MyTree.remove(5))
.CHECK_THROWS(MyTree.remove(55))
.CHECK_EQUAL (MyTree.parent(3), 4)
.CHECK_OK    (MyTree.insert(5))
.CHECK_OK    (MyTree.remove(10))
.CHECK_EQUAL    (MyTree.root(), 14)
.CHECK_EQUAL    (MyTree.right(14), 15)
.CHECK_EQUAL    (MyTree.size(), 7)
.CHECK_THROWS(MyEmptyTree.root())
.CHECK_OK    (MyEmptyTree.insert(100))
.CHECK_EQUAL(MyEmptyTree.size(), 1)
.CHECK_OK    (MyEmptyTree.insert(90))
.CHECK_EQUAL(MyEmptyTree.left(100), 90)
.CHECK_OK    (MyEmptyTree.insert(110))
.CHECK_OK    (MyEmptyTree.remove(100))
.CHECK_EQUAL    (MyEmptyTree.root(), 110)

  .print();
  
  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}

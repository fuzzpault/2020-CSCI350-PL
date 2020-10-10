#ifndef PARSER_H
#define PARSER_H  

/*   @file Parser.h
      @author Paul Talaga
      @date Oct 3, 2020
      @Desc Declaration of a parser for simple mathematical 
            expressions.
*/

#include <string>


using namespace std;

class Node{
public:
  virtual unsigned nodeCount() = 0;
};

class Op: public Node{
public:
  Op(string op, Node* left, Node* right);
  // ~Op
  Node* left;
  Node* right;
  string op;

  unsigned nodeCount();
};

class Leaf: public Node{
public:
  Leaf(string st);
  // ~Leaf
  string st;

  unsigned nodeCount();
};


class Parser{
public:
  Parser();

  bool parse(string s);

  unsigned nodeCount();
  

private:
  void trimL(string &s);
  void trimR(string &s);
  

  Node* expr(string s);
  Node* digit(string s);

  Node* root;
};


  
#endif
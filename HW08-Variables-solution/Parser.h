#ifndef PARSER_H
#define PARSER_H  

/*   @file Parser.h
      @author Paul Talaga
      @date Oct 3, 2020
      @Desc Declaration of a parser for simple mathematical 
            expressions.
*/

#include <string>
#include <map>


using namespace std;

class Node{
public:
  virtual unsigned nodeCount() = 0;
  virtual int eval() = 0;
};

class Op: public Node{
public:
  Op(string op, Node* left, Node* right, map<string,int>* var_map);
  // ~Op
  unsigned nodeCount();
  int eval();
  
private:
  Node* left;
  Node* right;
  string op;
  map<string,int>* var_map;
};

class Num: public Node{
public:
  Num(string st);
  // ~Num
  unsigned nodeCount();
  int eval();
private:
  string st;
};

class Var: public Node{
public:
  Var(string st, map<string,int>* var_map);
  // ~Var
  unsigned nodeCount();
  int eval();
  string st; // Make this public so Op can get it
private:
  map<string,int>* var_map;
};


class Parser{
public:
  Parser();

  bool parse(string s);
  unsigned nodeCount();
  int eval();
  int eval(string s);
  void varDump();
  void varClear();

private:
  void trimL(string &s);
  void trimR(string &s);
  
  Node* assign(string s);
  Node* expr(string s);
  Node* term(string s);
  Node* factor(string s);
  Node* digit(string s);
  Node* var(string s);

  Node* root;
  
  map<string,int> var_map;
};


  
#endif
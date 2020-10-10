/*   @file Parser.cpp    
      @author Paul Talaga
      @date Oct 3, 2020
      @Desc Implementation of a parser for simple mathematical 
            expressions.
*/

#include <string>
#include <iostream>

#include "Parser.h"


using namespace std;

Parser::Parser(){
  root = NULL;
}

bool Parser::parse(string s){
  root = expr(s);
  return root != NULL;
}

void Parser::trimL(string &s){
  if(s.length() > 0 && s[0] == ' '){
    s = s.substr(1);
    trimL(s);
  }
}

void Parser::trimR(string &s){
  if(s.length() > 0 && s[s.length()-1] == ' '){
    s = s.substr(0,s.length()-1);
    trimR(s);
  }
}

// Exp -> Exp + Exp | Exp - Exp | (Exp) | Val 
// Check ( first as there may be + or - inside it
Node* Parser::expr(string s){
  trimL(s);
  trimR(s);

  if(s.length() == 0)return NULL;

  // Paren
  Node* v = expr(s.substr(1,s.length()-2));
  if(s[0] == '(' && s[s.length() - 1] == ')' && v != NULL){
    return v;
  }
  
  // Plus
  size_t pos = s.find("+");
  while(pos != string::npos){
    //cout << "Found + [" << s.substr(0,pos) << "][" << s.substr(pos+1) << "]" << endl;
    Node* v_left = expr(s.substr(0,pos));
    Node* v_right = expr(s.substr(pos+1));
    if( v_left && v_right) return new Op("+", v_left, v_right);
    pos = s.find("+",pos + 1);
  }

  // Minus
  pos = s.find("-");
  while(pos != string::npos){
    //cout << "Found -" << endl;
    Node* v_left = expr(s.substr(0,pos));
    Node* v_right = expr(s.substr(pos+1));
    if( v_left && v_right) return new Op("-", v_left, v_right);
    pos = s.find("-",pos + 1);
  }

  // Digit
  v = digit(s);
  if(v)return  v;

  return NULL;
}

// Val -> numerics
Node* Parser::digit(string s){
  trimL(s);
  trimR(s);
  if(s.length() == 0)return NULL;
  for(unsigned i = 0; i < s.length(); i++){
    if(s[i] < '0' ||
       s[i] > '9')return NULL;
  }
  return new Leaf(s);
} 

unsigned Parser::nodeCount(){
  if(root == NULL)return 0;
  return root->nodeCount();
}


/*    --------------------------------------- */

Leaf::Leaf(string st){
  this->st = st;
}

unsigned Leaf::nodeCount(){
  return 1;
}

Op::Op(string op, Node* left, Node* right){
  this->op = op;
  this->left = left;
  this->right = right;
}

unsigned Op::nodeCount(){
  return 1 + left->nodeCount() + right->nodeCount();
}


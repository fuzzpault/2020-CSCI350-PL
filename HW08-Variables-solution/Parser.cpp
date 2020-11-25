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
  root = assign(s);
  return root != NULL;
}

int Parser::eval(){
  if(!root)return 0;
  return root->eval();
}

int Parser::eval(string s){
  root = assign(s);
  if(!root)return 0;
  return root->eval();
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

Node* Parser::assign(string s){
  trimL(s);
  trimR(s);
  if(s.length() == 0)return NULL;
  
  size_t pos = s.find("=");
  while(pos != string::npos){
    //cout << "Found -" << endl;
    Node* v_left = var(s.substr(0,pos));
    Node* v_right = assign(s.substr(pos+1));
    if( v_left && v_right) return new Op("=", v_left, v_right, &var_map);
    pos = s.find("=",pos + 1);
  }

  // term
  return expr(s);
}

// expr -> expr + term | expr - term | term
Node* Parser::expr(string s){
  trimL(s);
  trimR(s);
  if(s.length() == 0)return NULL;

  // Plus
  size_t pos = s.find("+");
  while(pos != string::npos){
    //cout << "Found + [" << s.substr(0,pos) << "][" << s.substr(pos+1) << "]" << endl;
    Node* v_left = expr(s.substr(0,pos));
    Node* v_right = term(s.substr(pos+1));
    if( v_left && v_right) return new Op("+", v_left, v_right, NULL);
    pos = s.find("+",pos + 1);
  }

  // Minus
  pos = s.find("-");
  while(pos != string::npos){
    //cout << "Found -" << endl;
    Node* v_left = expr(s.substr(0,pos));
    Node* v_right = term(s.substr(pos+1));
    if( v_left && v_right) return new Op("-", v_left, v_right, NULL);
    pos = s.find("-",pos + 1);
  }
  
  pos = s.find("=");
  while(pos != string::npos){
    //cout << "Found -" << endl;
    Node* v_left = var(s.substr(0,pos));
    Node* v_right = expr(s.substr(pos+1));
    if( v_left && v_right) return new Op("=", v_left, v_right, &var_map);
    pos = s.find("=",pos + 1);
  }

  // term
  return term(s);
}

// term -> term * factor | term * factor | <factor>
Node* Parser::term(string s){
  trimL(s);
  trimR(s);
  if(s.length() == 0)return NULL;

  // Multiply
  size_t pos = s.find("*");
  while(pos != string::npos){
    //cout << "Found + [" << s.substr(0,pos) << "][" << s.substr(pos+1) << "]" << endl;
    Node* v_left = term(s.substr(0,pos));
    Node* v_right = factor(s.substr(pos+1));
    if( v_left && v_right) return new Op("*", v_left, v_right, NULL);
    pos = s.find("*",pos + 1);
  }

  // Divide
  pos = s.find("/");
  while(pos != string::npos){
    //cout << "Found -" << endl;
    Node* v_left = term(s.substr(0,pos));
    Node* v_right = factor(s.substr(pos+1));
    if( v_left && v_right) return new Op("/", v_left, v_right, NULL);
    pos = s.find("/",pos + 1);
  }

  // factor
  return factor(s);
}

// <factor> -> (<expr>) | <digit> | <var>
Node* Parser::factor(string s){
  trimL(s);
  trimR(s);
  if(s.length() == 0)return NULL;

  // Paren
  Node* v = assign(s.substr(1,s.length()-2));
  if(s[0] == '(' && s[s.length() - 1] == ')' && v != NULL){
    return v;
  }
  
  v = digit(s);
  if(v)return v;
  
  return var(s);
}

// digit -> number with 1 or more digits
Node* Parser::digit(string s){
  trimL(s);
  trimR(s);
  if(s.length() == 0)return NULL;
  for(unsigned i = 0; i < s.length(); i++){
    if(s[i] < '0' ||
       s[i] > '9')return NULL;
  }
  return new Num(s);
} 

// variable -> 1 or more lowercase letters
Node* Parser::var(string s){
  trimL(s);
  trimR(s);
  if(s.length() == 0)return NULL;
  for(unsigned i = 0; i < s.length(); i++){
    if(s[i] < 'a' ||
       s[i] > 'z')return NULL;
  }
  return new Var(s, &var_map);
} 

unsigned Parser::nodeCount(){
  if(root == NULL)return 0;
  return root->nodeCount();
}

void Parser::varClear(){
  var_map.clear();
}

void Parser::varDump(){
  for(auto it = var_map.begin(); it != var_map.end(); it++){
    cout << it->first << ": " << it->second << endl;
  }
}


/*    --------------------------------------- */

Num::Num(string st){
  this->st = st;
}

unsigned Num::nodeCount(){
  return 1;
}

int Num::eval(){
  return stoi(st);
}

Var::Var(string st, map<string,int>* var_map){
  this->st = st;
  this->var_map = var_map;
}

unsigned Var::nodeCount(){
  return 1;
}

int Var::eval(){
  auto it = var_map->find(st);
  if(it != var_map->end()){
    //cout << "eval " << it->second << endl; 
    return it->second;
  }
  cout << st << " not declared." << endl;
  return 0;
}

Op::Op(string op, Node* left, Node* right, map<string,int>* var_map){
  this->op = op;
  this->left = left;
  this->right = right;
  this->var_map = var_map;
}

unsigned Op::nodeCount(){
  return 1 + left->nodeCount() + right->nodeCount();
}

int Op::eval(){
  if(op == "+"){
    return left->eval() + right->eval();
  }else if(op == "-"){
    return left->eval() - right->eval();
  }else if(op == "*"){
    return left->eval() * right->eval();
  }else if(op == "/"){
    return left->eval() / right->eval();
  }else if(op == "="){
    int right_val = right->eval();
    string st = ((Var*)left)->st;
    // Insert will not replace if it is already there, so attempt to erase it first.
    auto it = var_map->find(st);
    if(it != var_map->end())var_map->erase(it);
    var_map->insert( pair<string, int>(st, right_val));
    return right_val;
  }else{
    cout << "INVALID OP:" << op << endl;
  }
  return 0;
}


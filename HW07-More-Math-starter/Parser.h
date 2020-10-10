#ifndef PARSER_H
#define PARSER_H  

/**   @file Parser.h    
      @author xx 
      @date xx     
      
            */

#include <string>


using namespace std;

// Add anything you want in this file.

class Parser{
public:

  Parser();

  bool parse(string s);

  unsigned nodeCount();
  
  int eval();
  

private:
 // 
};


  
#endif
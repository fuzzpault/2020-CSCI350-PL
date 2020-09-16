/*
Name: Paul Talaga
Date: Aug 01, 2020
Desc: Runner program to allow manual evaluation of DFA functions.

*/
#include "dfa.h"
#include <string>
#include <iostream>

using namespace std;



int main(){
    unsigned prob_num = 0;
    
    // So we don't have a ugly if/else code below for each function, and since
    // they all have the same type signature, store all the function pointers
    // in an array.  Because we can!
    bool (* fn_pointers[])(const string &) = {fn1, fn2, fn3, fn4, fn5};
    
    cout << "What function do you want to test? 1-5?" << endl;
    cin >> prob_num;
    
    if(prob_num < 1 || prob_num > 5){
        cout << "Invalid entry." << endl;
        return 1;
    }
    
    while(true){
        string input;
        cout << endl << "Input string for function fn" << prob_num << endl;
        cin >> input;
        if( (*fn_pointers[prob_num - 1])(input)  ){
            cout << "ACCEPT" << endl;
        }else{
            cout << "REJECT" << endl;
        }
    }
}
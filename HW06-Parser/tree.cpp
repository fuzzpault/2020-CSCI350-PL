/*
Name: Paul Talaga
Date: Demonstration of building a tree recursively, using child classes.
      Developed during zoom-class discussion on Oct 7, 2020
      YouTube: 

*/

#include <iostream>
#include <string>

using namespace std;

// Define 3 classes, a parent class and 2 child classes.  This allows two
// 'kinds' of nodes in the tree, and the correct class's functions will be called
class Node{
    public:
   virtual unsigned count() = 0; // This makes Node a pure virtual class
   virtual void print(int) = 0;  // meaning all child classes MUST implement
                                 // these functions.
};

class Dual : public Node{
    public: 
    Dual(Node* l, Node* r, string thing){
        left = l;
        right = r;
        data = thing;
    }
    
    unsigned count(){
        unsigned ret = 0;
        if(left)ret += left->count();
        if(right)ret += right->count();
        return ret + 1;
    }
    
    void print(int depth){
        if(right)right->print(depth + 5);
        for(int i = 0; i < depth; i++)cout << " ";
        cout << "Dual: " << data << endl;
        if(left)left->print(depth + 5);
    }
    
    private:
    Node* left;
    Node* right;
    string data;
};

class Leaf : public Node{
    public:
     Leaf(string thing){
        data = thing;
    }
    unsigned count(){
        return 1;
    }
    
    void print(int depth){
        for(int i = 0; i < depth; i++)cout << " ";
        cout << "Leaf: " <<  data << endl;
    }
    private:
    string data;
};

// A recursive function to build the tree based on a string.
Node* consume(string thing, int depth){
    if(thing.length() == 0)return NULL; // Base case!
    if(thing.length() == 1)return new Leaf(thing);
    

    string l = thing.substr(0,thing.length() / 2);
    string r = thing.substr(thing.length() / 2 );
    
    //cout << l << "|" << r << endl;
    Node* left = consume(l, depth + 5);
    Node* right = consume(r, depth + 5);
    
    for(int i = 0; i < depth; i++)cout << " ";
    cout << "Creating: " << thing << endl;
    return new Dual(left, right, thing);
}


int main(){
    Node* root = consume("123456789", 0);
    cout << "There are " << root->count() << " nodes." << endl;
    root->print(0);
    
}
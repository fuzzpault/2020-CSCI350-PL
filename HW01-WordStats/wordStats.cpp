/*
Name: Paul Talaga
Date: Aug 01, 2020
Desc: Enter a text file name on the command-line and this program will
      provide the number of words in the file, the number of unique
      words, and the top 20 used words.

*/
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

const int top_count = 20;

// Function to allow sorting based on a pair.
bool pairCompare(pair<string, unsigned>& a, pair<string, unsigned>& b){
    return a.second > b.second;
}

int main(int argc, char** argv){
    
    if( argc <= 1){
        cout << "Enter a textfile filename on the command-line." << endl;
        return 1;
    }
    
    map<string,unsigned> word_list;
    unsigned total_number_of_words = 0;

    // Read the file
    
    string word;
    
    fstream file;
    file.open(argv[1]);
    while(file >> word){
        if(word.length() == 0)continue;
        total_number_of_words++;
        
        // Make it lowercase
        for(unsigned i = 0; i < word.length(); i++){
            word[i] = tolower(word[i]);
        }
        //cout << word << endl;
        
        if( word_list.find(word) == word_list.end()){
           word_list[word] = 0;
        }
        word_list[word]++;
    }
    file.close();
    
    // To do the sort we push them all into a vector
    vector< pair<string, unsigned> > vec;
    
    for(auto i = word_list.begin(); i != word_list.end(); i++){
        vec.push_back(*i);  // The * converts the iterator to a pair
    }   // Think of dereferencing a pointer.
    
    sort(vec.begin(), vec.end(), pairCompare);
    
    cout << "There were " << total_number_of_words << " words in the file." << endl;
    cout << "there were " << word_list.size() << " unique words in the file." << endl;
    
    cout << endl << "Top " << top_count << " words in " << argv[1] << ":" << endl;
    
    for(int i = 0; i < min(top_count,((int)vec.size())); i++){
        cout << setw(10) << vec[i].first << " " << vec[i].second << endl;
    }
    
    
}
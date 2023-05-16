//returns true if any word in Trie that starts with given prefix
#include<iostream>
using namespace std;

class TrieNode{
 public:
   char data;
   TrieNode* children[26];
   bool isTerminal;

 TrieNode(char ch)
{
  data=ch;
  for(int i=0; i<26; i++){
    children[i]=NULL;
  }
  isTerminal=false;
 }
};

//implementation

class Trie{
public:
TrieNode* root;

//consttructor
Trie(){
  root=new TrieNode('\0');
}

//using recursion
void insertUtil(TrieNode* root,string word){
  //base case last character
  if(word.length()==0){
    root->isTerminal=true;
    return;
  }
  //assuem all char CAPS
  int index=word[0]-'A';
  TrieNode* childNode;
  
  //present
  if(root -> children[index] != NULL)
  {childNode=root->children[index];}//go next forward/ below

  //absent
  else{
    childNode=new TrieNode(word[0]);//create new child below
    root->children[index]=childNode;
  } 
  
//recursion: Solve 1; Rest will be solved by recursion
insertUtil(childNode,word.substr(1));//substr next char  
}

void insertWord(string word){
  insertUtil(root,word);
}

 /*
bool searchUtil(TrieNode* root,string word){
  //base case last character
  if(word.length()==0){
    return (root->isTerminal);
  }
  //assuem all char CAPS
  int index=word[0]-'A';
  TrieNode* childNode;
  
  //present
  if(root -> children[index] != NULL)
     childNode=root->children[index];//go next forward/ below

  //absent
  else{
    return false;
  } 
  
//recursion: Solve 1; Rest will be solved by recursion
return searchUtil(childNode,word.substr(1));//substr next char  
}

bool searchWord(string word){
  return searchUtil(root,word);
}*/


bool prefixUtil(TrieNode* root,string word){
  //base case last character
  if(word.length() == 0){
    //return (root->isTerminal);
    //only change here:not use above and return true if prefix matches
    return true;//if prefix found
  }
  //assuem all char CAPS
  int index=word[0]-'A';
  TrieNode* childNode;
  
  //present
  if(root -> children[index] != NULL)
     childNode=root->children[index];//go next forward/ below

  //absent
  else{
    return false;
  } 
  
//recursion: Solve 1; Rest will be solved by recursion
return prefixUtil(childNode,word.substr(1));//substr next char  
}

bool startsWith(string prefix){
  return prefixUtil(root,prefix);
}

};

int main()
{
  Trie* t=new Trie();
  t->insertWord("HELLO");
  t->insertWord("HELL");
  t->insertWord("HELP");

  // cout<<"Present:1 or Not:0"<<endl;
  // cout<<"Search HELL: "<<t->searchWord("HELL")<<endl;
  // cout<<"Search HM: "<<t->searchWord("HM")<<endl;
  // cout<<"Search HELLO: "<<t->searchWord("HELLO")<<endl;

  cout<<"HEL Prefix: "<<t->startsWith("HEL")<<endl;
  cout<<"HX Prefix: "<<t->startsWith("HX")<<endl;
  cout<<"HE Prefix: "<<t->startsWith("HE")<<endl;
  cout<<"HELL Prefix: "<<t->startsWith("HELL");
  return  0;
}

//Time Comp: processing every chars in insertion
//Insertion T(n): O(n); n=Length of word
//Search: T(n): O(n)

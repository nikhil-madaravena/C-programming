#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//Trie node structure
typedef struct TrieNode{
	struct TrieNode* children[26];
	bool isEndOfWord;
} TrieNode;

	TrieNode* createNode(){
		TrieNode* newNode = (TrieNode*)malloc(sizeof(TrieNode));
		newNode->isEndOfWord = false;
		for(int i=0;i<26;i++){
			newNode->children[i]=NULL;
		}
		return newNode;

	}
	void insertWord(TrieNode* root,const char* word){
		TrieNode* curr = root;
		for(int i=0;word[i]!='\0';i++){
			int index = word[i]- 'a';
			if(curr->children[index]==NULL){
				curr->children[index]=createNode();
			}
			curr =curr->children[index];
		}
		curr->isEndOfWord=true;
	}
	bool searchWord(TrieNode* root,const char* word){
		TrieNode* curr = root;
		for(int i = 0 ; word[i]!='\0';i++){
			int index = word[i]-'a';
			if(curr->children[index]==NULL){
				return false;
			}
			curr= curr->children[index];
		}
		return(curr!=NULL && curr->isEndOfWord);
	}
	int main(){
		TrieNode* root = createNode();
		insertWord(root,"apple");
		insertWord(root,"mango");
		insertWord(root,"banana");
		printf("Search results:\n");
		printf("apple: %s\n",searchWord(root,"apple")?"found":"Not found"); 
		printf("apple: %s\n",searchWord(root,"mango")?"found":"Not found");
		printf("apple: %s\n",searchWord(root,"banana")?"found":"Not found");
		printf("apple: %s\n",searchWord(root,"orange")?"found":"Not found");
		return 0;  
	}
	 


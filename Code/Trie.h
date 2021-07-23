#pragma once

#include "List.h"

template <class T>
struct TrieNode 
{
public:

	List<string> synonyms;	//vector to store synonyms
	string meaning;	//stores Meanings
	TrieNode<T>* arr[26];	
	bool Flag;	//Returns 0 or 1
	T value;	//Stores values
	int synCount;					//Number of synonyms

};

  //-----------------//
 //----Trie Class---//
//-----------------//

class TRIE 
{
private:
	TrieNode<char>* root;	//Root of the Dictionary
	string data;	//String type data
	
public:

	TRIE()	//Constructor
	{
		root = NULL;
	}


	~TRIE()	//Destructor
	{
		delete root;
	}


	TrieNode<char>* create(char x)	//Creates a new node
	{
		TrieNode<char>* newNode = new TrieNode<char>;
		for (int i = 0; i < 26; ++i) 
		{
			newNode->arr[i] = NULL; 
		}
		newNode->Flag = 0;
		newNode->value = x;
		return newNode;
	}


	void CreateDictionary(string s)		//Creates a dictionary .... 's' is the name of the file
	{
		TrieNode<char>* rootNode = new TrieNode<char>;		//temporary root node
		rootNode->value = ' ';
		for (int i = 0; i < 26; i++) 
		{
			rootNode->arr[i] = nullptr;
			rootNode->Flag = 0;
		}
		root = rootNode;
		fstream in;
		string s1;

		in.open(s.c_str(), ios::in);		//opens the file
		if (!in)							//if file does not open
		{
			cout << "File could not be opened\n";
			exit(0);
		}
		int synCount = 0;
		int place;							//temporary variable counting the location of a node
		

		TrieNode<char>* newNode = root;
		TrieNode<char>* temp = newNode;
		
		while (getline(in, s1)) 
		{
			int len;
			if (s1[0] == '-' && s1[1] != '-')		//Checks for a word
			{
				synCount = 0;
				len = s1.length();
				newNode = root;
												
				for (int i = 1; i< len; i++)	//We'll start from first index because of '-'
				{
					place = s1[i] % 97;

					if (newNode->arr[place] == NULL) 
					{
						newNode->arr[place] = create(s1[i]);
					}
					newNode = newNode->arr[place];
				}
				newNode->Flag = 1;
			}

			else if (s1[0] == '-' && s1[1] == '-')	//Checks for Meaning
			{
				int len = s1.length();
				for (int i = 2; i < len; i++) 
				{
					s1[i - 2] = s1[i];
				}
				string s2 = "";
				s1[len - 2] = '\0';
				for (int j = 0; s1[j] != '\0'; j++) 
				{
					s2 += s1[j];
				}
				newNode->meaning = s2;		//Storing the meaning in each node
			}

			else			//Checks for synonyms
			{
				if (newNode->Flag) 
				{
					newNode->synonyms.InsertLast(s1);		//Inserting the synonyms into the lists
					++synCount;
				}
			}
			temp = newNode;
		}
		in.close();		//Closing File
	}


	bool FindWord(string s)			//Returns true if the word is present
	{
		TrieNode<char>* temproot;
		temproot = root;
		int len = s.length();

		//cout << s;
		//cout << len;
		/*for (int x = 0; x < len; ++x)
		{
			cout << s[x] << "$";
		}*/
		int place;
		for (int x = 0; x < len; ++x) {
			place = s[x] % 97;
			if (temproot->arr[place] == NULL) 
			{
				return 0;
			}
			temproot = temproot->arr[place];
		}
		if (temproot != NULL && temproot->Flag == 1) 
		{
			return 1;
		}
		return 0;
	}


	TrieNode<char>* FindNode(string s)	//Finds a specific data in a node and returns that node if found
	{
		TrieNode<char>* temproot;
		temproot = root;
		int len = s.length();
		int place;
		for (int x = 0; x < len; ++x) 
		{
			place = s[x] % 97;
			if (!temproot->arr[place]) 
			{
				return NULL;
			}
			temproot = temproot->arr[place];
		}
		if (temproot != NULL && temproot->Flag == 1) 
		{
			return temproot;
		}
		return NULL;

	}


	string FindMeaning(string s)	//Finds meanings of the words
	{
		TrieNode<char>* temp;
		temp = FindNode(s);
		if (temp == NULL)			//if word is not found, then it will display "s-not found"
		{
			string str = s;
			str += "-Not Found\n";
			return str;				
		}
		else
		return temp->meaning;

	}
	

	List<string>& FindSynonyms(string s)	//Finds synonyms and returns list of printers
	{
		TrieNode <char>* temp = FindNode(s);	//Find the node 
		return temp->synonyms;
	}
};

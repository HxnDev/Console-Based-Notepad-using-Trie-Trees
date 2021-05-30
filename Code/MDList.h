#pragma once
#include <cstddef>
#include <Windows.h>

#include<iostream>
using namespace std;
struct MDnode
{
	MDnode* up, * down, * left, * right;
	char data;
	int xcoord, ycoord;
};
class MDList
{
public:
	MDnode* head;
	MDnode* current;
	int returningx, returningy;
public:
	MDList()	//Constructor
	{
		head = NULL;
		current = NULL;
	}
	void Insert(char dataItem, int xx, int yy)	//Inserts in to the list
	{

		MDnode* nodee = new MDnode;
		nodee->data = dataItem;
		nodee->xcoord = xx;
		nodee->ycoord = yy;
		if (head == NULL)
		{
			nodee->left = NULL;
			nodee->right = NULL;
			nodee->up = NULL;
			nodee->down = NULL;
			head = nodee;

		}
		else
		{
			MDnode* check = head;
			while (check != NULL and check->ycoord != yy)
			{
				check = check->down;
			}
			while (check != NULL and check->xcoord != xx)
			{
				check = check->right;
			}
			if (check != NULL)
			{
				check->data = dataItem;
				//charAt(check->xcoord, check->ycoord);//////////////////
			}
			else if (nodee->ycoord == head->ycoord) //inserts in the vertical direction (node->down)
			{
				MDnode* temp = head;
				while (temp->right != NULL)
				{
					temp = temp->right;
				}
				nodee->up = NULL;
				nodee->down = NULL;
				nodee->right = NULL;
				nodee->left = temp;
				temp->right = nodee;
			}
			else if (nodee->xcoord == head->xcoord)//inserts in the hoizontal direction (node->right)
			{
				MDnode* temp = head;
				while (temp->down != NULL)
				{
					temp = temp->down;
				}
				nodee->up = temp;
				nodee->down = NULL;
				nodee->right = NULL;
				nodee->left = NULL;
				temp->down = nodee;
			}

			else
			{
				MDnode* temp = head;
				while (temp->ycoord != yy)
				{
					temp = temp->down;
				}


				while (temp->right != NULL)
				{
					temp = temp->right;
				}

				nodee->down = NULL;
				nodee->right = NULL;
				nodee->left = temp;
				MDnode* temp1 = head;
				while (temp1->ycoord != yy - 1)
				{
					temp1 = temp1->down;
				}
				int val = 0;
				while (temp1!=NULL and temp1->xcoord != xx)
				{
					val = temp1->xcoord;
					temp1 = temp1->right;
					if (temp1 != NULL)
					{
						val = temp1->xcoord;
					}
					
				}
				if (val < xx)
				{
					nodee->up = NULL;
					temp->right = nodee;
				}
				else
				{
					nodee->up = temp1;
					temp->right = nodee;
					temp1->down = temp->right;
				}
				
				
			}

		}
	}
	int NULLCheck(int x, int y)
	{
		MDnode* nodee = new MDnode;
		nodee = head;

		for (int i = 1; i < y; i++)
		{
			nodee = nodee->down;
		}
		for (int i = 1; i <= x; i++)
		{
			if (nodee != NULL)
			{
				nodee = nodee->right;
			}
		}
		if (nodee == NULL)
		{
			return 1;
		}
		else return 0;
	}

	void Display()
	{
		//cout << endl;
		//cout << "displaying the list: " << endl;
		MDnode* nodee;
		MDnode* nodee1;
		nodee = head;
		while (nodee != NULL)
		{
			nodee1 = nodee;
			while (nodee1 != NULL)
			{
				cout << nodee1->data;
				nodee1 = nodee1->right;

			}
			cout << endl;
			nodee = nodee->down;
		}
	}
	void fileWriting()
	{
		string fname;
		ofstream f;
		//cin.ignore();
		cout << "Please Enter the Name of the File = ";
		getline(cin, fname);
		fname += ".txt";
		f.open(fname.c_str());

		MDnode* nodee;
		MDnode* nodee1;
		nodee = head;
		while (nodee != NULL)
		{
			nodee1 = nodee;
			while (nodee1 != NULL)
			{
				f << nodee1->data;
				nodee1 = nodee1->right;

			}
			f << endl;
			nodee = nodee->down;
		}
		f.close();

	}
	void remove(int xx, int yy) // for removing a character at specific coordinates (from the end)
	{
		MDnode* nodee = new MDnode;
		nodee = head;
		if (head != NULL)
		{
			for (int i = 1; i < yy; i++)
			{
				nodee = nodee->down;
			}
			for (int i = 1; i < xx; i++)
			{
				if (nodee->right != NULL)
				{
					nodee = nodee->right;
				}
			}
			//nodee = nodee->right;
			nodee->data;
			if (nodee != NULL and nodee->down == NULL and nodee->up == NULL and nodee->left != NULL and nodee->right == NULL) //if character has the same y coordinates as the head
			{
				MDnode* temp;
				MDnode* freeing;
				freeing = nodee;
				temp = nodee->left;
				//nodee->left = NULL;
				freeing->left = NULL;
				nodee = temp;
				nodee->right = NULL;
				delete freeing;
			}
			else if (nodee != NULL and nodee->down == NULL and nodee->left != NULL and nodee->right == NULL and nodee->up != NULL) //in case the y coordinate of the character is different from y coordinate of head
			{
				MDnode* temp;
				MDnode* temp1;
				MDnode* freeing;
				freeing = nodee;
				temp = nodee->left;
				temp1 = nodee->up;
				temp1->down = NULL;
				nodee->up = NULL;
				nodee->left = NULL;
				nodee = temp;
				nodee->right = NULL;
				delete freeing;
			}
			else if (nodee != NULL and nodee->down == NULL and nodee->left == NULL and nodee->right == NULL and nodee->up != NULL) //in case when user reaches the coordinate x=1 
			{
				MDnode* temp = head;
				MDnode* temp1;
				MDnode* freeing;
				freeing = nodee;
				for (int i = 1; i < yy - 1; i++)
				{
					temp = temp->down;
				}
				temp1 = temp;
				while (temp1->right != NULL)
				{
					temp1 = temp1->right;
				}
				temp->down = NULL;
				freeing->up = NULL;
				nodee = temp;
				delete freeing;

			}
			else if (nodee != NULL and nodee->down == NULL and nodee->up == NULL and nodee->right != NULL and nodee->left != NULL)
			{
				MDnode* temp1;
				MDnode* temp2;
				temp1 = nodee->left;
				temp2 = nodee->right;
				MDnode* freeing;
				freeing = nodee;
				nodee->left->right = temp2;
				nodee->left->right->left = temp1;
				delete freeing;

			}
		}

	}

	int charAt(int xx, int yy)
	{
		int i = 0;
		MDnode* nodee = head;
		char char1;
		while (nodee->ycoord != yy)
		{
			nodee = nodee->down;
		}
		while (nodee != NULL and nodee->xcoord != xx)
		{
			nodee = nodee->right;
		}
		char1 = nodee->data;
		while ((nodee->data != ' ' and nodee->data != '.' and nodee->data != ',' and nodee->data != ';' and nodee->data != ':'))
		{
			if ((nodee->ycoord != 1 or nodee->left != NULL))
			{
				if (nodee->left == NULL)
				{
					i++;
					nodee = nodee->up;
					while (nodee->right != NULL)
					{
						nodee = nodee->right;
					}
				}
				else

				{
					i++;
					nodee = nodee->left;
				}
			}
			else
			{
				i++;
				break;
			}
		}
		//cout << nodee->data;

		return i;
	}
	string stringAt(int xx, int yy) //after pressing special characters if a user wants to go back and display meaning of the word by making some changes in it
	{
		int i = 0;
		//cout << xx;
		string str;
		MDnode* nodee;
		nodee = head;
		if (head != NULL)
		{
			for (int i = 1; i < yy; i++) //checks where the character is present vertically
			{
				nodee = nodee->down;
			}
			for (int i = 1; i < xx; i++) //checks the exact location of the char horizontally
			{
				nodee = nodee->right;
			}
			while (nodee->left != NULL and nodee->left->data != ' ' and nodee->left->data != ';' and nodee->left->data != ':' and nodee->left->data != '.' and nodee->left->data != ',') //getting the size of the word
			{
				i++;

				if (nodee->xcoord != 1)
				{
					nodee = nodee->left;
				}
				if (nodee->xcoord == 1 and nodee->ycoord != 1) //when we're backspacing from the line below to the line above
				{
					nodee = nodee->up;
					while (nodee->right != NULL)
					{
						nodee = nodee->right;
					}
					i++;
				}
			}

			for (int j = 0; j < i; j++) //adding the character to form a string 
			{

				str += nodee->data;
				if (nodee->right != NULL)
				{
					nodee = nodee->right;
				}
				else
				{
					MDnode* temp = head;
					while (temp->ycoord != nodee->ycoord + 1)
					{
						temp = temp->down;
					}
					nodee = temp;
				}
			}
		}
		return str;


	}
	bool SpecialCharCheck(int xx, int yy) //checks if the char at specific coordinate is ',' or '.' or ' ' or ';' or ':'
	{
		MDnode* nodee = head;
		while (nodee->ycoord != yy)
		{
			nodee = nodee->down;
		}
		while (nodee->xcoord != xx and nodee != NULL)//changes made
		{
			nodee = nodee->right;
		}
		if (nodee->data == ' ' or nodee->data == ',' or nodee->data == '.' or nodee->data == ';' or nodee->data == ':')
		{
			return true;
		}
		else
			return false;
	}
	void insertingAT(int xx, int yy)
	{

	}
	string savestring(int sx, int sy)
	{
		string s;
		MDnode* nodee = head;
		MDnode* temp;
		while (nodee->ycoord != sy)
		{
			nodee = nodee->down;
		}
		temp = nodee;
		while (nodee->right != NULL and nodee->right->xcoord != sx)
		{
			nodee = nodee->right;
		}
		while (temp != NULL)
		{
			while (nodee->right != NULL)
			{
				s += nodee->data;
				nodee = nodee->right;
			}
			s += nodee->data;
			temp = temp->down;
			if (temp != NULL)
			{
				nodee = temp;
			}
		}
		//nodee = nodee->left;
		//nodee = head;
		if (nodee != NULL and nodee->ycoord != sy)
		{
			MDnode* help;
			while (nodee->xcoord != 1)
			{
				help = nodee->left;
				remove(nodee->xcoord, nodee->ycoord);
				nodee = help;
			}
			int newx = nodee->xcoord, newy = nodee->ycoord;
			nodee = nodee->up;

			remove(newx, newy);
			while (nodee->right != NULL)
			{
				nodee = nodee->right;
			}
		}
		else
		{
			MDnode* neww;
			neww = nodee;
			while (nodee != NULL and nodee->xcoord != sx - 2)
			{
				neww = neww->left;
				remove(nodee->xcoord, nodee->ycoord);
				nodee = neww;
			}
			//if (nodee != NULL)
			//{
			//	remove(nodee->xcoord, nodee->ycoord);
			//}
		}
		//fileWriting();

		return s;

		//cout << s;
	}
	void MemoryDeallocation()
	{
		MDnode* nodee = new MDnode;
		nodee = head;
		while (nodee->down != NULL)
		{
			nodee = nodee->down;
		}
		
		while (nodee->up != NULL)
		{
			while (nodee != NULL and nodee->right != NULL)
			{
				nodee = nodee->right;
			}
			while (nodee->left != NULL)
			{
				if (nodee != NULL and nodee->down == NULL and nodee->up == NULL and nodee->left != NULL and nodee->right == NULL) //if character has the same y coordinates as the head
				{
					MDnode* temp;
					MDnode* freeing;
					freeing = nodee;
					temp = nodee->left;
					//nodee->left = NULL;
					freeing->left = NULL;
					nodee = temp;
					nodee->right = NULL;
					delete freeing;
				}
				else if (nodee != NULL and nodee->down == NULL and nodee->left != NULL and nodee->right == NULL and nodee->up != NULL) //in case the y coordinate of the character is different from y coordinate of head
				{
					MDnode* temp;
					MDnode* temp1;
					MDnode* freeing;
					freeing = nodee;
					temp = nodee->left;
					temp1 = nodee->up;
					temp1->down = NULL;
					nodee->up = NULL;
					nodee->left = NULL;
					nodee = temp;
					nodee->right = NULL;
					delete freeing;
				}
				else if (nodee != NULL and nodee->down == NULL and nodee->left == NULL and nodee->right == NULL and nodee->up != NULL) //in case when user reaches the coordinate x=1 
				{
					MDnode* temp;
					MDnode* temp1;
					MDnode* freeing;
					freeing = nodee;
					temp = nodee->up;
					temp->down = NULL;
					freeing->left = NULL;
					freeing->up = NULL;
					freeing->down = NULL;
					freeing->right = NULL;
					nodee = nodee->left;
					nodee->right = NULL;
					delete freeing;
				}
				else if (nodee != NULL and nodee->down == NULL and nodee->up == NULL and nodee->right != NULL and nodee->left != NULL)
				{
					MDnode* temp1;
					MDnode* temp2;
					temp1 = nodee->left;
					temp2 = nodee->right;
					MDnode* freeing;
					freeing = nodee;
					nodee->left->right = temp2;
					nodee->left->right->left = temp1;
					delete freeing;

				}
				//nodee = nodee->left;
			}
			MDnode* temp;
			MDnode* temp1;
			MDnode* freeing;
			freeing = nodee;
			temp = nodee->up;
			temp->down = NULL;
			freeing->left = NULL;
			freeing->up = NULL;
			freeing->down = NULL;
			freeing->right = NULL;
			//nodee = nodee->left;
			//nodee->right = NULL;
			delete freeing;

			nodee = temp;
		}

		if (nodee->up == NULL)
		{
			while (nodee != NULL and nodee->right != NULL)
			{
				nodee = nodee->right;
			}
			while (nodee->left != NULL)
			{
				if (nodee != NULL and nodee->down == NULL and nodee->up == NULL and nodee->left != NULL and nodee->right == NULL) //if character has the same y coordinates as the head
				{
					MDnode* temp;
					MDnode* freeing;
					freeing = nodee;
					temp = nodee->left;
					//nodee->left = NULL;
					freeing->left = NULL;
					nodee = temp;
					nodee->right = NULL;
					delete freeing;
				}
				else if (nodee != NULL and nodee->down == NULL and nodee->left != NULL and nodee->right == NULL and nodee->up != NULL) //in case the y coordinate of the character is different from y coordinate of head
				{
					MDnode* temp;
					MDnode* temp1;
					MDnode* freeing;
					freeing = nodee;
					temp = nodee->left;
					temp1 = nodee->up;
					temp1->down = NULL;
					nodee->up = NULL;
					nodee->left = NULL;
					nodee = temp;
					nodee->right = NULL;
					delete freeing;
				}
				else if (nodee != NULL and nodee->down == NULL and nodee->left == NULL and nodee->right == NULL and nodee->up != NULL) //in case when user reaches the coordinate x=1 
				{
					MDnode* temp;
					MDnode* temp1;
					MDnode* freeing;
					freeing = nodee;
					temp = nodee->up;
					temp->down = NULL;
					freeing->left = NULL;
					freeing->up = NULL;
					freeing->down = NULL;
					freeing->right = NULL;
					nodee = nodee->left;
					nodee->right = NULL;
					delete freeing;
				}
				else if (nodee != NULL and nodee->down == NULL and nodee->up == NULL and nodee->right != NULL and nodee->left != NULL)
				{
					MDnode* temp1;
					MDnode* temp2;
					temp1 = nodee->left;
					temp2 = nodee->right;
					MDnode* freeing;
					freeing = nodee;
					nodee->left->right = temp2;
					nodee->left->right->left = temp1;
					delete freeing;

				}
				//nodee = nodee->left;
			}
			MDnode* temp;
			MDnode* temp1;
			MDnode* freeing;
			freeing = nodee;
			freeing->left = NULL;
			freeing->up = NULL;
			freeing->down = NULL;
			freeing->right = NULL;
			//nodee = nodee->left;
			//nodee->right = NULL;
			head = NULL;
			delete freeing;
		}


	}
	void afterdeletion()
	{
		string fname;
		ofstream f;
		/*cout << "please enter the name of the file";
		getline(cin, fname);
		fname += ".txt";*/
		fname = "imdone1.txt";
		f.open(fname.c_str());

		MDnode* nodee;
		MDnode* nodee1;
		nodee = head;
		while (nodee != NULL)
		{
			nodee1 = nodee;
			while (nodee1 != NULL)
			{
				f << nodee1->data;
				nodee1 = nodee1->right;

			}
			f << endl;
			nodee = nodee->down;
		}
		f.close();
	}
	void gotoxy(int x, int y)	//Sets coordinates
	{

		///COORD = Structure of Coordinates
		COORD c = { x, y };
		///STD_OUTPUT_HANDLE  = Output mode
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);	//Sets co-ordinates  

	}
	void loadingFile(int start)
	{
		string line;
		string fname;
		fstream f;
		int len = 0;
		int x = 1, y = 1;
		cin.ignore();
		loop:
		cout << "Please Enter the Name of the File that You Want to Read from = ";
		getline(cin, fname);
		fname += ".txt";
		system("cls");
		f.open(fname.c_str());
		if (f.is_open())
		{
			while (getline(f, line))
			{
				len = line.length();
			}
			f.close();
		}
		else
		{
			cout << "Invalid Name Entered!!"<<endl;
			goto loop;
		}
		for (int i = 0; i < len; i++)
		{
			Insert(line[i], x, y);
			if (x == (start - 10))
			{
				x = 1;
				y++;
				
			}
			else
			{
				x++;
			}
		}
		gotoxy(1, 1);
		Display();
		returningx = x, returningy = y;
	}

};
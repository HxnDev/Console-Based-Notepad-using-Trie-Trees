#pragma once
#include "List.h"
#include "Trie.h"
#include"MDList.h"
#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;
int c, r; //Stores the coordinates of the console window
int countLines = 0;
int shiftcheck = 0;
int nextline = 0;
int movecheck = 0;
char safechar;
int finalcheck = 0, point = 0;
int bsp = 0; //backspace (using a check fr occurance of backspace)
int movekeycheck = 0, currentx = 0, currenty = 0;
int exx = 0, exy = 0;
int finallyover = 0;
MDList mdlist;


void gotoxy(int x, int y)	//Sets coordinates
{

	///COORD = Structure of Coordinates
	COORD c = { x, y };
	///STD_OUTPUT_HANDLE  = Output mode
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);	//Sets co-ordinates  

}


class Notepad {
private:
	float x = 1, y = 1;
	int start;
	string s, meaning;
	TRIE trie;
	bool flag = false;
	bool exist = true;

public:

	Notepad()
	{
		x = 1;
		y = 1;
		s = "";
		start = 0;
		meaning = "";
	}


	void getConsoleSize()	//This function will return the console size of each laptop
	{
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
		c = csbi.srWindow.Right - csbi.srWindow.Left + 1;	//stores the number of columns
		r = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;	//stores the number of rows
		start = c * (0.70);
	}


	void SplitScreen()	//Splitting screen into two "0-169" and "170-230"
	{
		x = start;
		y = countLines;
		gotoxy(x, y);
	}


	void Backspace()	//Checks if backspace is pressed
	{
		x--;
		gotoxy(x, y);
		cout << " ";
		if (x == 1 and y != 1)
		{
			x = start - 10;
			y--;
		}
		else
		{
			x--;
		}
		gotoxy(x, y);


	}






	void NotFound()		//Displays error message in splitted screen if word is not found
	{
		int temp = x;
		int temp2 = y;
		SplitScreen();
		cout << "Entered word not found" << endl;
		x = temp+1;
		y = temp2;
		gotoxy(x, y);
	}


	void DisplayMeaning()	//Displays Meaning on Console
	{
		int count = 0;
		int len = 0;
		int temp = x;
		int temp2 = y;
		meaning = trie.FindMeaning(s);	//Finds meaning of the string before space
		SplitScreen();
		len = meaning.size();
		for (int i = 0; i < len; i++)
		{
			if (count >= (c - start - 2))
			{
				y++;
				countLines++;
				x = start;
				gotoxy(x, y);
				count = 0;
			}
			count++;
			cout << meaning[i];
			x++;
		}
		x = temp ;
		y = temp2;
		countLines++;
		gotoxy(x, y);
	}


	void DisplaySynonyms()	//Displays synonyms of the word
	{
		TrieNode<char>* obj = trie.FindNode(s);

		int temp1 = x;
		int temp2 = y;
		
		int size = obj->synonyms.getSize();	//size of synonym list
		
		for(int i=0; i<size;i++)
		{
			string temp = obj->synonyms[i];
			SplitScreen();		//Moving cursor to other side of splitted screen
			countLines++;
			cout << temp << endl;

			temp = "";
		}
		x = temp1 + 1;
		y = temp2; 
		gotoxy(x, y);		//Moves cursor back to original location
	}


	void Interface()		//Displays a Welcome Screen
	{
		Sleep(1000);
		system("color 30");
		fstream file("Welcome1.txt", ios::in);		//"Welcome"
		while (!file.eof())
		{
			string title;
			getline(file, title);
			cout << title << endl;
		}
		file.close();
		cout << endl;
		Sleep(1000);
		cout << endl;


		file.open("Welcome2.txt", ios::in);		//"to"
		while (!file.eof())
		{
			string title;
			getline(file, title);
			cout << "\t \t" << title << endl;
		}
		file.close();
		cout << endl;
		Sleep(1000);
		cout << endl;


		file.open("Welcome3.txt", ios::in);		//"DS"
		while (!file.eof())
		{
			string title;
			getline(file, title);
			cout << "\t \t \t" << title << endl;
		}
		file.close();
		cout << endl;
		Sleep(1000);


		file.open("Welcome4.txt", ios::in);		//"Project"
		while (!file.eof())
		{
			string title;
			getline(file, title);
			cout << "\t \t \t \t \t \t" << title << endl;
		}
		file.close();
		cout << endl;
		Sleep(3000);
		system("cls");

		system("color 47");
		file.open("MenuTitle.txt", ios::in);		//"Notepad"
		while (!file.eof())
		{
			string temp;
			getline(file, temp);
			cout << temp << endl;
		}
		file.close();
		cout << endl;
		Sleep(1000);


		file.open("Credits1.txt", ios::in);		//"by"
		while (!file.eof())
		{
			string temp;
			getline(file, temp);
			cout << temp << endl;
		}
		file.close();
		cout << endl;
		Sleep(1000);


		file.open("Credits2.txt", ios::in);		//"Azka & Hassan"
		while (!file.eof())
		{
			string temp;
			getline(file, temp);
			cout << "\t" << temp << endl;
		}
		file.close();
		Sleep(3000);

	}

	void Saved()		//"Changes have been saved"
	{
		system("cls");
		system("color 4e");
		fstream file("saved.txt", ios::in);		//"Changes saved. The program will end in... "
		while (!file.eof())
		{
			string title;
			getline(file, title);
			cout << title << endl;
		}
		file.close();
		Sleep(1000);

		file.open("end1.txt", ios::in);		//"3.."
		while (!file.eof())
		{
			string title;
			getline(file, title);
			cout << title << endl;
		}
		file.close();
		Sleep(1000);

		file.open("end2.txt", ios::in);		//"2.."
		while (!file.eof())
		{
			string title;
			getline(file, title);
			cout << "\t" << title << endl;
		}
		file.close();
		Sleep(1000);

		file.open("end3.txt", ios::in);		//"1.."
		while (!file.eof())
		{
			string title;
			getline(file, title);
			cout << "\t\t" << title << endl;
		}
		file.close();
		Sleep(1000);

		system("cls");
		system("color 47");
		file.open("bye.txt", ios::in);		//"Bye"
		while (!file.eof())
		{
			string title;
			getline(file, title);
			cout << "\t\t\t" << title << endl;
		}
		file.close();
		cout << endl << endl;
		Sleep(1000);
		exit(0);

	}

	void NotSaved()		//"Changes were not saved"
	{
		system("cls");
		system("color 4e");
		fstream file("notsaved.txt", ios::in);		//"Changes not saved. The program will end in... "
		while (!file.eof())
		{
			string title;
			getline(file, title);
			cout << title << endl;
		}
		file.close();
		Sleep(1000);

		file.open("end1.txt", ios::in);		//"3.."
		while (!file.eof())
		{
			string title;
			getline(file, title);
			cout << title << endl;
		}
		file.close();
		Sleep(1000);

		file.open("end2.txt", ios::in);		//"2.."
		while (!file.eof())
		{
			string title;
			getline(file, title);
			cout << "\t" << title << endl;
		}
		file.close();
		Sleep(1000);

		file.open("end3.txt", ios::in);		//"1.."
		while (!file.eof())
		{
			string title;
			getline(file, title);
			cout << "\t\t" << title << endl;
		}
		file.close();
		Sleep(1000);

		system("cls");
		system("color 47");
		file.open("bye.txt", ios::in);		//"Bye"
		while (!file.eof())
		{
			string title;
			getline(file, title);
			cout << "\t\t\t" << title << endl;
		}
		file.close();
		cout << endl << endl;
		Sleep(1000);
		exit(0);
	}

	void Invalid()		//"Invalid option selected"
	{
		system("cls");
		system("color 49");
		fstream file("invalid.txt", ios::in);		//"Invalid Key pressed "
		while (!file.eof())
		{
			string title;
			getline(file, title);
			cout << title << endl;
		}
		file.close();
		Sleep(1000);

		exit(0);
	}



	void DisplayMenu()		//Displays the menu
	{
		system("cls");
		system("color 5e");		//Blue + Yellow
		fstream file("D1.txt", ios::in);		//"Following are the list of options: "
		while (!file.eof())
		{
			string title;
			getline(file, title);
			cout << title << endl;
		}
		file.close();
		cout << endl;

		Sleep(1000);


		file.open("D2.txt", ios::in);		//"1: New File"
		while (!file.eof())
		{
			string title;
			getline(file, title);
			cout << "\t" << title << endl;
		}
		file.close();
		cout << endl;
		Sleep(1000);


		file.open("D3.txt", ios::in);		//"2: Existing File"
		while (!file.eof())
		{
			string title;
			getline(file, title);
			cout << "\t" << title << endl;
		}
		file.close();
		cout << endl;
		Sleep(1000);
		cout << endl << endl;

		file.open("D4.txt", ios::in);		//"Select your option"
		while (!file.eof())
		{
			string title;
			getline(file, title);
			cout << "\t \t" << title << endl;
		}
		file.close();
		cout << endl;

		int op;
		cin >> op;

		if (op == 1)
		{
			cout << "New File Selected\n \n";
			system("cls");
			x = 1, y = 1;
			gotoxy(x, y);
		}
		else if (op == 2)
		{
			cout << "Existing file selected\n\n";
			mdlist.loadingFile(start);
			x = mdlist.returningx, y = mdlist.returningy;
			gotoxy(x, y);
		}
		else
			Invalid();
	}

	void ExitMenu()
	{
		system("cls");
		system("color 27");
		fstream file("exitmenu.txt", ios::in);		//"Do you want to save the changes?"
		while (!file.eof())
		{
			string title;
			getline(file, title);
			cout << title << endl;
		}
		file.close();
		cout << endl;

		Sleep(1000);
		cout << endl;

		file.open("Exit1.txt", ios::in);		//"1:Yes	2: No"
		while (!file.eof())
		{
			string title;
			getline(file, title);
			cout << "\t" << title << endl;
		}
		file.close();
		cout << endl << endl << endl;

		int op;
		cin >> op;
		if (op == 1)
		{
			cin.ignore();
			mdlist.fileWriting();
			mdlist.MemoryDeallocation();
			Saved();
		}
		else if (op == 2)
		{
			mdlist.MemoryDeallocation();
			NotSaved();
		}
		else
		{
			Invalid();
		}
		Sleep(1000);
	}



	void ExitScreen()
	{
		system("cls");
		system("color 70");
		fstream file("Exit.txt", ios::in);		//"Do you really want to exit?"
		while (!file.eof())
		{
			string title;
			getline(file, title);
			cout << "\t" << title << endl;
		}
		file.close();
		Sleep(1000);

		file.open("sademoji.txt", ios::in);		//":("
		while (!file.eof())
		{
			string title;
			getline(file, title);
			cout << "\t\t" << title << endl;
		}
		file.close();
		cout << endl;
		Sleep(1000);
		cout << endl;


		file.open("Exit1.txt", ios::in);		//Choice
		while (!file.eof())
		{
			string title;
			getline(file, title);
			cout << "\t" << title << endl;
		}
		file.close();
		cout << endl;
		cout << endl;

		int op;
		cin >> op;
		if (op == 1)
		{
			ExitMenu();
		}
		else if (op == 2)
		{
			cout << "Function is not exitted" << endl;
		}
		else
		{
			Invalid();
		}
	}


	void Escape()	//Checks if Esc Key is pressed
	{
		ExitScreen();
		exit(0);
	}



	void RunAll()
	{
		Interface();

		system("cls");	//Clears Screen

		getConsoleSize();

		//--------Tree objects-----------------------//
		trie.CreateDictionary("dictionary.txt");




		///Handle is sort of datatype which tells the device we are using
		///STD_INPUT_HANDLE = Input mode

		HANDLE  rhnd = GetStdHandle(STD_INPUT_HANDLE);  // Handle to read console

		///Events = any sort of operation happening (e.g key press / mouse click)
		///DWORD = long unsigned integer (Alternative keyword)
		DWORD Events = 0;     // Event count
		DWORD EventsRead = 0; // Events read from console

		bool Running = true;	//Tells if console is running or not


		gotoxy(x, y);

		//Main loop of program

		while (Running)
		{
			if (finallyover == 0)
			{
				DisplayMenu();
				finallyover++;
			}
			

			// gets the systems current "event" count
			GetNumberOfConsoleInputEvents(rhnd, &Events);

			if (Events != 0) { // Tells that an event occured

				// create event buffer(array) the size of how many Events
				INPUT_RECORD eventBuffer[200];

				// Fills the event buffer with the events and saves count in EventsRead
				ReadConsoleInput(rhnd, eventBuffer, Events, &EventsRead);

				// Loop through the event buffer using the saved count
				for (DWORD i = 0; i < EventsRead; ++i) {

					// check if event[i] is a key event && if so is a press not a release
					if (eventBuffer[i].EventType == KEY_EVENT && eventBuffer[i].Event.KeyEvent.bKeyDown)
					{
						// check if the key press was an arrow key
						switch (eventBuffer[i].Event.KeyEvent.wVirtualKeyCode)
						{

						case VK_UP: //up
							if (movekeycheck == 0)
							{
								movekeycheck++;
								currentx = x;
								currenty = y;
							}
							y--;
							gotoxy(x, y);
							movecheck++;
							if (mdlist.NULLCheck(x, y) == 1)
							{
								movekeycheck = 0;
							}
							break;

						case VK_DOWN: //down
							if (movekeycheck == 0)
							{
								movekeycheck++;
								currentx = x;
								currenty = y;
							}
							y++;
							gotoxy(x, y);
							movecheck++;
							if (mdlist.NULLCheck(x, y) == 1)
							{
								movekeycheck = 0;
							}
							break;

						case VK_RIGHT: //right
							if (movekeycheck == 0)
							{
								movekeycheck++;
								currentx = x;
								currenty = y;
							}
							x++;
							gotoxy(x, y);
							movecheck++;
							if (mdlist.NULLCheck(x, y) == 1)
							{
								movekeycheck = 0;
							}
							break;

						case VK_LEFT: //left
							if (movekeycheck == 0)
							{
								movekeycheck++;
								currentx = x;
								currenty = y;
							}
							x--;
							gotoxy(x, y);
							movecheck++;
							if (mdlist.NULLCheck(x, y) == 1)
							{
								movekeycheck = 0;
							}
							break;

						case VK_SHIFT:
							shiftcheck++;
							break;
						default:        //Keypress was not arrow key
							//movekeycheck = 0;
							char c = eventBuffer->Event.KeyEvent.uChar.AsciiChar;	//identifies which ascii character is pressed and stores its value in "c" 
							if (c == VK_SPACE or c == '.' or c == ',' or c == ';' or c == ':')
							{
								movecheck = 0;
							}
							if (c == 8 and x == 1 and y == 1)
							{
								exit(1);
							}
						/*	if (c == '9')
							{
								mdlist.fileWriting();
								mdlist.MemoryDeallocation();
								mdlist.afterdeletion();
							}*/
							if (c != 8)
							{
								mdlist.Insert(c, x, y);
							}
							if (c != ' ')
							{
								cout << c;	//Displays the character pressed on Console
							}
							if (c == ' ' and bsp != 0)
							{
								cout << c;
								bsp = 0;
							}
							if (x + 10 == start and c!=8)
							{
								y++;
								x = 1;
								gotoxy(x, y);
								nextline++;
							}
							
							if (c == VK_SPACE or c == '.' or c == ',' or c == ';' or c == ':')	//Checking if 'SpaceBar' or ',' or '.' or ';' or  ':' is pressed
							{
								if (trie.FindWord(s))	//Checks if word is found
								{
									DisplayMeaning();
									DisplaySynonyms();
									s = "";
									flag = true;
								}
								else
								{
									NotFound();		//Displays not found message
									s = "";
									flag = true;
								}
								
								
							}
							if (!flag and c!=8)
							{
								s += c;		//Adding that character to a string
						
							}
							else
								flag = false;
							if (nextline == 0 and c!=' ' and c != '.' and c != ',' and c != ';' and c != ':' )/////////////////
							{
								x++;
							}

							
							if (nextline != 0 and (c == ' ' or c == '.' or c == ',' or c == ';' or c == ':'))
							{
								x = 1;
								gotoxy(1, y);
							}
							else 
							{
								gotoxy(x, y);	//Jumps to these coordinates
							}
							
							nextline = 0;
							if (c == 27)	//Checks if "Esc" key is pressed
							{
								Escape();
							}
							int x1, y1;
							if (c == 8 and movekeycheck == 1)
							{
								string saved;
								//if (finalcheck % 2 == 0)
								{
									//x = x - finalcheck;
								}
								if (point != 0)
								{
									x = finalcheck - 1;
								}
								point += 1;
								saved = mdlist.savestring(x, y);
								int backx = 0, backy = 0;
								backx = x, backy = y;
								x = currentx, y = currenty;
								gotoxy(x, y);
								for (int j = y; j >= backy; j--)
								{
									if (j != backy)
									{
										for (int i = x; i > 0; i--)
										{
											cout << " ";
											gotoxy(i, j);
											//gotoxy(i, j);
											//Backspace();

										}
										if (i == 0)
										{
											x = start - 10;
										}
									}
									if (j == backy)
									{
										for (int i = x; i >= backx - 1; i--)
										{
											cout << " ";
											gotoxy(i, j);
											//gotoxy(i, j);
											//Backspace();
											x1 = i, y1 = j;
										}
									}
								}
								cout << " ";
								x1 = x1 - 1;
								gotoxy(x1 , y1);
							//	mdlist.fileWriting();
								mdlist.remove(x1, y1);
								//x1++;
								int slen = saved.length();
						//		mdlist.fileWriting();
								for (int a = 0; a < slen; a++)
								{
									mdlist.Insert(saved[a], x1, y1);
									x1 = x1 + 1;
								}
								//mdlist.fileWriting();
								cout << saved;
								gotoxy(backx - 2, backy);
								x = backx, y = backy;
								finalcheck = x;
							//	mdlist.fileWriting();
							}
							else if (c == 8 and movekeycheck == 0)	//Checks if "Backspace" key is pressed
							{
								bsp++;
								if (safechar != ' ' and safechar != '.' and safechar != ',' and safechar != ';' and safechar != ':')
								{
									int len = 0;
									len = s.length();
									if (len != 0)
									{
										s.erase(len - 1); //erases the last character from sring that the user wants to remove
									}
								}
								Backspace();
								mdlist.SpecialCharCheck(x, y);
								if (safechar == ' ' or safechar == '.' or safechar == ',' or safechar == ';' or safechar == ':' or mdlist.SpecialCharCheck(x, y) == true)
								{
									s = mdlist.stringAt(x, y);
								}
								mdlist.remove(x, y);
							}
							/*if (movecheck != 0)
							{
								int a = 0;
								a = mdlist.charAt(x - 1, y);
								int len = 0;
								len = s.length();
								if (len != 0)
								{
									s.erase(len - 1); //erases the last character from sring that the user wants to remove
								}
								s[a-1] = c;
								movecheck = 0;
							}*/
							safechar = c;
							//movekeycheck = 0;
						}
					}
					
				} // end of EventsRead loop
				
			}

		} // end of program loop
	}
};
// Napon Krassner (Jett)
// CSC 2430, Homework 5
// 6-7-2015
// Due: 6-9-2015
// Name: Main of KWIC - mainKWIC
// Description: This is the main program of KeyWordInContext that [does what] the [fill in the rest]
//******************************************************************************

#include <iostream>
#include <iomanip>
#include <list>
#include <fstream>
#include <string>

using namespace std;

// Function declaration
void readFileToList(ifstream&, list<list<string> *>&, list<string>*&);
void reportPhrases(list<list<string> *>&);
void outputKWIC(list<list<string> *>&);



int main()
{
	// Declare variables
	ifstream fileLinesIn;  // inFile

	// list to store list of titles
	list<list<string> *> myListofLists;

	// list to hold all words in single title
	list<string> *pTitle;

	// open movie-title file
	fileLinesIn.open("..\\JamesBondMovies.txt");

	// check if able to open file
	if (fileLinesIn.fail())
	{
		cout << "Error, failed to open file!" << endl;
		exit(1);  // 1 = error, 0 = good
	}

	// Extract from file
	readFileToList(fileLinesIn, myListofLists, pTitle);

	// close file stream
	fileLinesIn.close();

	// report simple listing of each phrases from file
	reportPhrases(myListofLists);

	// KWIC with output formatting
	outputKWIC(myListofLists);

	return 0;
}

void readFileToList(ifstream &inFile, list<list<string> *> &myListofLists, list<string>* &pTitle)
{
	// loop through all the phrase from file
	while (inFile.good())
	{
		string aWord;

		// new list everytime
		pTitle = new list<string>;

		// prime read
		inFile >> aWord;

		// store each word until end of line
		while (inFile.peek() != '\n' && aWord != "")
		{
			pTitle->push_back(aWord);  // store word
			inFile >> aWord;  // next word
		}

		// store last word
		if (aWord != "")
		{
			pTitle->push_back(aWord);

			// add individual title list into list of lists
			myListofLists.push_back(pTitle);
		}
	}
}

void reportPhrases(list<list<string> *>& myListofLists)
{
	// declare 2 iterators
	list<list<string> *>::iterator curPhrase;  // for cur List of Lists
	list<string>::iterator curWord;  // for cur title
	int lineCount = 0;
	cout << "Input Phrases: " << endl;

	// Loop through list of lists
	for (curPhrase = myListofLists.begin(); curPhrase != myListofLists.end(); ++curPhrase)
	{
		cout << "   ";
		// Loop through list of titles
		for (curWord = (*curPhrase)->begin(); curWord != (*curPhrase)->end(); ++curWord)
		{
			// print each word
			cout << *curWord << " ";
		}
		lineCount++;
		cout << endl;
	}

	cout << "The number of phrases in the input file = " << lineCount << endl << endl;
}

void outputKWIC(list<list<string> *>& myListofLists)
{
	// declare 2 iterators
	list<list<string> *>::iterator curPhrase;  // for cur List of Lists
	list<string>::iterator curWord;  // for cur title
	int lineCount = 0;
	cout << "Input Phrases: " << endl;

	// Loop through list of lists
	for (curPhrase = myListofLists.begin(); curPhrase != myListofLists.end(); ++curPhrase)
	{
		// Loop through list of titles
		for (curWord = (*curPhrase)->begin(); curWord != (*curPhrase)->end(); ++curWord)
		{
			// determine keyword in context

			// include output formatting

			// print keyword in context
		}
		lineCount++;
		cout << endl;
	}

	cout << "The number of phrases in the input file = " << lineCount << endl << endl;
}

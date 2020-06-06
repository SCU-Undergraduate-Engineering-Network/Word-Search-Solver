// Jonathan Ho

// Word Search Solver

#include <iostream>
#include <fstream>
#include <ostream>
#include <cstdlib>
#include <algorithm>
#include <string>

#include <unordered_set>
#include <set>
#include <vector>

using namespace std;

const int minLength = 6;				// minimum length of words being looked for
const int maxLength = 50;				// maximum length of words being looked for

int N = 0;								// number of rows
int M = 0;								// number of columns

unordered_set<string> wordlist;			// C++ STL unordered_set to store the wordlist
vector<vector<char>> puzzle;			// C++ STL vector of vectors containing characters to store the puzzle
set<string> words;						// C++ STL set to store the answers of the word search

void readWordlist(string filename);		// fucntion to read the wordlist when given the filename
void readPuzzle(string filename);		// function to read the puzzle when given the filename
void findWords();						// function to solve the word search
void printWords(string filename);		// function to print the answers

void printWordlist();					// debugging function to print the wordlist
void printPuzzle();						// debugging function to print the puzzle

// main
int main() {
	readWordlist("words.txt");
	// debugging
	// printWordlist();

	readPuzzle("puzzle.txt");
	// debugging
	// printPuzzle();

	findWords();
	printWords("answers.txt");

	return 0;
}


// helper function to validate strings that are read from the wordlist
bool validatestring(string str) {
	int count = 0;
	for (int i = 0; i < str.size(); i++) {
		if(str[i] < 'a' || str[i] > 'z') {
			return false;
		} else {
			count++;
		}
	}
	return count >= minLength && count <= maxLength;
}

// fucntion to read the wordlist when given the filename
void readWordlist(string filename) {
	ifstream wlReader(filename);

	string word;
	if (wlReader.is_open()) {
		while (getline(wlReader, word)) {
			if (validatestring(word)) {
				wordlist.insert(word);
			}
		}
		wlReader.close();
	}
}

// fucntion to read the puzzle when given the filename
void readPuzzle(string filename) {
	ifstream pzlReader(filename);

	string line;
	if (pzlReader.is_open()) {
		while (getline(pzlReader, line)) {
			if (N == 0) {
				M = (line.size()+1)/2;
			}
			N++;

			vector<char> row;
			for (int i = 0; i < line.size(); i+=2) {
				row.push_back(line[i]);
			}
			puzzle.push_back(row);
		}
		pzlReader.close();
	}
}


// helper function to calculate the minimum of 2 integers
int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

// helper function to check if a string is in the wordlist and add it to the answer
void checkWord(string s, string t) {
	if (wordlist.count(s)) {
		words.insert(s+t);
	}
}

// helper function to check horizontally to the right from the current position (tests the reverse as well)
void search0(int r, int c) {
	string test1 = "";
	string test2 = "";
	for (int i = 0; i < min(M-c, maxLength); i++) {
		test1 = test1 + puzzle[r][c+i];
		test2 = puzzle[r][c+i] + test2;
		if ((i+1) >= minLength) {
			checkWord(test1, " from ("+to_string(r)+", "+to_string(c)+") to ("+to_string(r)+", "+to_string(c+i)+")");
			checkWord(test2, " from ("+to_string(r)+", "+to_string(c+i)+") to ("+to_string(r)+", "+to_string(c)+")");
		}
	}
}


// helper function to check diagonally down-right from the current position (tests the reverse as well)
void search45(int r, int c) {
	string test1 = "";
	string test2 = "";
	for (int i = 0; i < min(maxLength, min(N-r, M-c)); i++) {
		test1 = test1 + puzzle[r+i][c+i];
		test2 = puzzle[r+i][c+i] + test2;
		if ((i+1) >= minLength) {
			checkWord(test1, " from ("+to_string(r)+", "+to_string(c)+") to ("+to_string(r+i)+", "+to_string(c+i)+")");
			checkWord(test2, " from ("+to_string(r+i)+", "+to_string(c+i)+") to ("+to_string(r)+", "+to_string(c)+")");
		}
	}
}

// helper function to check vertically down from the current position (tests the reverse as well)
void search90(int r, int c) {
	string test1 = "";
	string test2 = "";
	for (int i = 0; i < min(N-r, maxLength); i++) {
		test1 = test1 + puzzle[r+i][c];
		test2 = puzzle[r+i][c] + test2;
		if ((i+1) >= minLength) {
			checkWord(test1, " from ("+to_string(r)+", "+to_string(c)+") to ("+to_string(r+i)+", "+to_string(c)+")");
			checkWord(test2, " from ("+to_string(r+i)+", "+to_string(c)+") to ("+to_string(r)+", "+to_string(c)+")");
		}
	}
}

// helper function to check diagonally down-left from the current position (tests the reverse as well)
void search135(int r, int c) {
	string test1 = "";
	string test2 = "";
	for (int i = 0; i < min(maxLength, min(N-r, c+1)); i++) {
		test1 = test1 + puzzle[r+i][c-i];
		test2 = puzzle[r+i][c-i] + test2;
		if ((i+1) >= minLength) {
			checkWord(test1, " from ("+to_string(r)+", "+to_string(c)+") to ("+to_string(r+i)+", "+to_string(c-i)+")");
			checkWord(test2, " from ("+to_string(r+i)+", "+to_string(c-i)+") to ("+to_string(r)+", "+to_string(c)+")");
		}
	}
}

// function to solve the word search by going through each index and traversing in the 4 directions (+ their opposites)
void findWords() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			search0(r, c);
			search45(r, c);
			search90(r, c);
			search135(r, c);
		}
	}
}

// function to print the answers
void printWords(string filename) {
	ofstream wordprinter (filename);
	if (wordprinter.is_open()) {
		for (auto const& i: words) {
			wordprinter << i << endl;
		}
		wordprinter.close();
	}
}

// debugging function to print the wordlist
void printWordlist() {
	for (auto const& i: wordlist) {
		cout << i << " ";
	}
	cout << endl;
}

// debugging function to print the puzzle
void printPuzzle() {
	cout << "N: " << N << "; M: " << M << endl;

	for (int i = 0; i < N; i++) {
		vector<char> row = puzzle[i];
		for (int j = 0; j < M; j++) {
			cout << row[j] << " ";
		}
		cout << endl;
	}
}
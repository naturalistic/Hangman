/*
  ------
  |    |
  0    |
 /|\   |
 / \   |
       |
 -------
*/

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

const string intro = 	"\n"	
			"************************************************\n"
			"* 		Welcome to Hangman! 		*\n"
			"************************************************\n"
			" Guess the letters but don't make too many \n" 
			" mistakes a mans life depends on it!\n\n";

const int p_height = 7;
const int p_width = 8; 

void draw_picture(int m) {	
	for(int y=0; y<p_height; y++) { 		// Y Goes down
		for (int x=0; x<p_width; x++) {
			if(m > 0 && y == 6 && x > 0) {	// Base
				cout << '-';	
			} else if(m > 1 && y > 0 && y < 7 && x == 7) {	// V-beam
				cout << '|';
			} else if(m > 2 && y == 0 && x > 1) {	// Crossbeam
				cout << '-';	
			} else if(m > 3 && y == 1 && x == 2) {	// Rope 
				cout << '|';
			} else if(m > 4 && y == 2 && x == 2) {	// Head 
				cout << '0';
			} else if(m > 5 && y == 3 && x == 2) {	// Body
				cout << '|';
			} else if(m > 6 && y == 3 && x == 1) {	// Left arm
				cout << '/';
			} else if(m > 7 && y == 3 && x == 3) {	// Right arm
				cout << '\\';
			} else if(m > 8 && y == 4 && x == 1) { // Left leg
				cout << '/';
			} else if(m > 9 && y == 4 && x == 3) {	// Right leg
				cout << '\\';
			} else {
				cout << ' ';
			}
		}
		cout << endl;
	}
}

int main() {
	cout << intro;	

	vector<string> words;
	words.push_back("QUADRUPLE");
	words.push_back("NEVER");
	words.push_back("CLEVER");
	srand(time(0));
	int r_index = rand() % words.size();
	string word = words.at(r_index); 
	
	vector<bool> guessed;
	int w_size = word.size();
	for(int i=0; i < w_size; i++) {
		guessed.push_back(false);
	}
	char guess;
	int correct = 0;
	int mistakes = 0;

	while(true) {
			
		// for each character in word print _ or the letter if it's been guessed	
		for(int i=0; i < w_size; i++) {
			if(guessed[i]) {
				cout << word[i];
			} else {
				cout << "_";
			}
			cout << " ";
		}
		cout << endl;

		// Get input
		cout << "Guess: ";
		cin >> guess;
		if(guess >= 'a' && guess <= 'z') {
			guess = guess + 'A' - 'a';
		} else if(guess < 'A' || guess > 'Z') {
			cout << "You only need to guess letters!" << endl;
			continue;
		}
		
		// Determine turn outcome
		bool found = false;
		for(int i=0; i < w_size; i++) {
			if(guess == word[i]) {
				found = true;
				if(!guessed[i]) {
					++correct;	
					guessed[i] = true;
				}
			}
		}	
		if(!found) {
			++mistakes;
			draw_picture(mistakes);
		}
		if(mistakes == 10) {
			cout << "Game over, you lost!" << endl;
			break;
		} else if (correct == 9) {
			cout << "Congratualations, you won!" << endl;
			break;
		}
		cout << endl;
	}
	return 0;
}

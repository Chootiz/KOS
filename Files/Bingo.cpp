#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <stdlib.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;
int board1[5][5] = { 0 }, board2[5][5] = { 0 }, temp1[5][5], temp2[5][5], available[25], score1 = 0, score2 = 0, gameid = 0;
void init(); //this function initializes the "available" array which is used to to display the numbers that can be marked
void playGame(); // this function runs the whole game
void HowtoPlay(); // this function just displays some instructions
void printCredits(); // just for printing some credits (fancy stuff)
void printBoard1(); // prints the board for player 1
void printBoard2(); // prints the board for player 2
int toss(); // generates a number and returns 0 or 1
void ncr(); // misc function used to clear the screen and to display the +---=/[bingo]\=---+ on top of every screen
int check(int x); // checks wether a number lies between 1-25 and has not already been selected (used during both filling out the boards and marking numbers for elimination) returns 1 if number is available 0 if its not
void eliminate(int x); // eliminates the selected number from the Available numbers list (only if the check or markAndCheck function returns true) 
void markAndCheck(int x); // eliminates the selected number from both boards and also checks winning conditions 
void mainMenu(); //main menu function
void gameHistory(); //prints game history

int main() {
	mainMenu();
	ncr();
	return 0;
}
void init() {
	int i, j;
	for (i = 0; i < 25; i++) {
		available[i] = i + 1; //initializing the array 1-25 in order
	}
}
void playGame() {
	int slct, slct1, slct2, c = 0, i, j, k, x, y, turn, game = 1;
	string plr1, plr2;
	char xyz;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) { //lines 39 to 46 are resetting the game
			board1[i][j] = 0;
			board2[i][j] = 0;
		}
	}
	gameid = 0;
	score1 = 0;
	score2 = 0;
	srand(time(0));
	ofstream Game_History("Bingo_Game_History.txt", ios::app);
	ncr();
	if (!Game_History.is_open()) {
		cout << "Error: Couldnt retrive game history file\n";
		system("pause");
		exit(0);
	}
	//player vs cpu
	gameid = rand() % 10000 + 1000;
	ncr();
	cout << "Enter your Name: ";
	cin.ignore();
	getline(cin, plr1);
	ncr();
	plr2 = "CPU";
	cout << "" << plr1 << " how would you like to fill your board?\n1.Manually\n2.Automatically(Randomly)\n";
	cin >> slct2;
	while (slct2 != 1 && slct2 != 2) {
		cout << "Invalid Input! Enter again: ";
		cin >> slct2;
	}
	switch (slct2) {
	case 1: //player 1 manual
		init();
		for (i = 0; i < 5; i++) {
			for (j = 0; j < 5; j++) {
				ncr();
				printBoard1();
				cout << endl;
				cout << "\nAvailable Numbers: ";
				for (k = 0; k < 25; k++) {
					if (available[k] != 0) {
						cout << available[k] << " ";
					}
				}
				cout << "\nEnter any number from the list of available numbers shown above: ";
				cin >> board1[i][j];
				while (board1[i][j] == 0) {
					cout << "Invalid Input! That number is either already marked or is outside the limit. Enter again: ";
					cin >> board1[i][j];
				}
				while (check(board1[i][j]) == 0) {
					cout << "Invalid Input! That number is either already marked or is outside the limit. Enter again: ";
					cin >> board1[i][j];
				}
				eliminate(board1[i][j]);
			}
		}
		ncr();
		printBoard1();
		break;
	case 2: //player 1 automatic
		init();
		for (i = 0; i < 5; i++) {
			for (j = 0; j < 5; j++) {
				ncr();
				printBoard1();
				cout << endl;
				cout << "\nAvailable Numbers: ";
				for (k = 0; k < 25; k++) {
					if (available[k] != 0) {
						cout << available[k] << " ";
					}
				}
				srand(time(0));
				board1[i][j] = rand() % 25 + 1;
				while (board1[i][j] == 0) {
					board1[i][j] = rand() % 25 + 1;
				}
				while (check(board1[i][j]) == 0) {
					board1[i][j] = rand() % 25 + 1;
				}
				eliminate(board1[i][j]);
				sleep(1);
			}
		}
		ncr();
		printBoard1();
		break;
	}
	cout << "You have 5 seconds to look at your board.";
	sleep(5);
	ncr();
	init();
	for (i = 0; i < 5; i++) { //cpu filling its board using random
		for (j = 0; j < 5; j++) {
			srand(time(0));
			board2[i][j] = rand() % 25 + 1;
			while (board2[i][j] == 0) {
				board2[i][j] = rand() % 25 + 1;
			}
			while (check(board2[i][j]) == 0) {
				board2[i][j] = rand() % 25 + 1;
			}
			eliminate(board2[i][j]);
		}
	}
	ncr();
	for (c = 0; c < 3; c++) {
		ncr();
		cout << endl << "Tossing";
		sleep(1);
		ncr();

	}
	ncr();
	x = toss();
	turn = x;
	cout << endl;
	if (turn == 0) {
		cout << plr1;
	}
	else {
		cout << plr2;
	}
	cout << " won the toss!";
	sleep(1);
	ncr();
	init();
	while (game == 1) {
		ncr();
		if (turn == 0) {
			if (x > 0) { //
				cout << "CPU Marked: " << y << endl; //displaying what the cpu marked on its last turn
			}
			cout << plr1 << "'s Turn\n";
			printBoard1();
			cout << "\nAvailable Numbers: ";
			for (k = 0; k < 25; k++) {
				if (available[k] != 0) {
					cout << available[k] << " ";
				}
			}
			cout << "\nSelect a number to mark: ";
			cin >> y;
			while (check(y) == 0) {
				cout << "\nInvalid Input! That number is either already marked or is outside the limit. Enter Again: ";
				cin >> y;
			}
			x += 1;
			turn = x % 2;
			markAndCheck(y);
			eliminate(y);
			if (score1 >= 5 && score2 >= 5) {
				cout << "Draw!";
			}
			else {
				if (score1 >= 5) {
					ncr();
					printBoard1();
					cout << endl << plr1 << " Wins!";
					game = 0;
				}
				if (score2 >= 5) {
					ncr();
					printBoard2();
					cout << endl << plr2 << " Wins!";
					game = 0;
				}
			}
		}
		else {
			y = rand() % 25 + 1; //cpu making its move
			while (check(y) == 0) {
				y = rand() % 25 + 1;
			}
			markAndCheck(y);
			eliminate(y);
			x += 1;
			turn = x % 2;
			if (score1 >= 5 && score2 >= 5) {
				cout << "Draw!\n";
				cout << plr1 << "'s Board\n";
				printBoard1();
				cout << plr2 << "'s Board\n";
				printBoard2();
				game = 0;
			}
			else {
				if (score1 >= 5) {
					ncr();
					cout << endl << plr1 << " Wins!\n\nWinner's Board\n";
					printBoard1();
					cout << "\n\nLooser's Board\n";
					printBoard2();
					game = 0;
				}
				if (score2 >= 5) {
					ncr();
					cout << endl << plr2 << " Wins!\n\nWinner's Board\n";
					printBoard2();
					cout << "\n\nLooser's Board\n";
					printBoard1();
					game = 0;
				}
			}
		}
	}
	Game_History << "\nGame ID: " << gameid << endl << plr1 << " vs " << plr2 << endl << score1 << " - " << score2 << endl;
	cout << "\nInput any key to return to main menu\n";
	cin >> xyz;
	gameid = 0;
	mainMenu();
}
void HowtoPlay() {
	char chr;
	ncr();
	cout << "First each player will take turns filling out the board with numbers between 1 and 25.\nYou will have the option to fill the board manually or automatically in a random order.\nAfter filling out the board each player will take turns marking a number on the board.\nWhen a player marks an entire row, column or diagonal on their board, their score goes up by one.\nFirst player to get 5 or more score wins.\nPress any key to return to main menu\n";
	cin >> chr;
	main();
}
int toss() {
	srand(time(0));
	return rand() % 2;
}
void printBoard1() {
	int i, j;
	switch (score1) {
	case 0:
		cout << "\n    B       I       N       G       O\n";
		break;
	case 1:
		cout << "\n            I       N       G       O\n"; //printing the   b i n g o   on top of the board relative to the score number of alphabets absent on the board = score
		break;
	case 2:
		cout << "\n                    N       G       O\n";
		break;
	case 3:
		cout << "\n                            G       O\n";
		break;
	case 4:
		cout << "\n                                    O\n";
		break;
	case 5:
		cout << "\n                                     \n";
		break;
	}
	for (i = 0; i < 5; i++) {
		cout << "+-------+-------+-------+-------+-------+\n|       |       |       |       |       |\n|";
		for (j = 0; j < 5; j++) {
			if (board1[i][j] == 0) {
				cout << setw(5) << " " << "  |";
			}
			else {
				if (board1[i][j] < 10) {
					cout << setw(4) << board1[i][j] << "   |";
				}
				else {
					cout << setw(5) << board1[i][j] << "  |";
				}
			}
		}
		cout << "\n|       |       |       |       |       |\n";
		if (i == 4) {
			cout << "+-------+-------+-------+-------+-------+\n";
		}
	}
	cout << endl;
}
void printBoard2() {
	int i, j;
	switch (score2) {
	case 0:
		cout << "\n    B       I       N       G       O\n";
		break;
	case 1:
		cout << "\n            I       N       G       O\n";
		break;
	case 2:
		cout << "\n                    N       G       O\n";
		break;
	case 3:
		cout << "\n                            G       O\n";
		break;
	case 4:
		cout << "\n                                    O\n";
		break;
	case 5:
		cout << "\n                                     \n";
		break;
	}
	for (i = 0; i < 5; i++) {
		cout << "+-------+-------+-------+-------+-------+\n|       |       |       |       |       |\n|";
		for (j = 0; j < 5; j++) {
			if (board2[i][j] == 0) {
				cout << setw(5) << " " << "  |";
			}
			else {
				if (board2[i][j] < 10) {
					cout << setw(4) << board2[i][j] << "   |";
				}
				else {
					cout << setw(5) << board2[i][j] << "  |";
				}
			}
		}
		cout << "\n|       |       |       |       |       |\n";
		if (i == 4) {
			cout << "+-------+-------+-------+-------+-------+\n";
		}
	}
	cout << endl;

}
void ncr() {
	system("clear");
	cout << "+=---=/[Bingo]\\=---=+" << endl;
	if (gameid != 0) {
		cout << "Game ID: " << gameid << endl;
	}
}
void eliminate(int x) {
	int i;
	for (i = 0; i < 25; i++) {
		if (available[i] == x) {
			available[i] = 0;
		}
	}
}
int check(int x) {
	int yes = 0, i;
	for (i = 0; i < 25; i++) {
		if (available[i] == x) {
			yes = 1;
		}
	}
	return yes;
}
void markAndCheck(int x) {
	int i, j, found = 0;
	for (i = 0; i < 5 && found == 0; i++) { //finding where the selected number is present on the board
		for (j = 0; j < 5 && found == 0; j++) {
			if (x == board1[i][j]) {
				board1[i][j] = 0;
				found = 1;
			}
		}
	}
	i -= 1;j -= 1;
	if (i == j) { //checking if one of the diagonal is zero
		if (board1[0][0] == board1[1][1] && board1[1][1] == board1[2][2] && board1[2][2] == board1[3][3] && board1[3][3] == board1[4][4]) {
			score1 += 1;
		}
	}
	if (i == 4 - j) { //checking if the anti-diagonal is zero
		if (board1[0][4] == board1[1][3] && board1[1][3] == board1[2][2] && board1[2][2] == board1[3][1] && board1[3][3] == board1[4][0]) {
			score1 += 1;
		}
	}
	if (board1[0][j] == board1[1][j] && board1[1][j] == board1[2][j] && board1[2][j] == board1[3][j] && board1[3][j] == board1[4][j]) { //checking if the input completes a zero row
		score1 += 1;
	}
	if (board1[i][0] == board1[i][1] && board1[i][1] == board1[i][2] && board1[i][2] == board1[i][3] && board1[i][3] == board1[i][4]) { //checking if the input completes a zero column
		score1 += 1;
	}
	found = 0; //resetting the found flag for the next board
	for (i = 0; i < 5 && found == 0; i++) {
		for (j = 0; j < 5 && found == 0; j++) {
			if (x == board2[i][j]) {
				board2[i][j] = 0;
				found = 1;
			}
		}
	}
	i -= 1;
	j -= 1;
	if (i == j) {
		if (board2[0][0] == board2[1][1] && board2[1][1] == board2[2][2] && board2[2][2] == board2[3][3] && board2[3][3] == board2[4][4]) {
			score2 += 1;
		}
	}
	if (i == 4 - j) {
		if (board2[0][4] == board2[1][3] && board2[1][3] == board2[2][2] && board2[2][2] == board2[3][1] && board2[3][3] == board2[4][0]) {
			score2 += 1;
		}
	}
	if (board2[0][j] == board2[1][j] && board2[1][j] == board2[2][j] && board2[2][j] == board2[3][j] && board2[3][j] == board2[4][j]) {
		score2 += 1;
	}
	if (board2[i][0] == board2[i][1] && board2[i][1] == board2[i][2] && board2[i][2] == board2[i][3] && board2[i][3] == board2[i][4]) {
		score2 += 1;
	}
}
void mainMenu() {
	int slct;
	ncr();
	cout << "1.Play Game\n2.How to Play\n3.Game History\n4.Exit\n\nYour Choice: "; cin >> slct;
	while (slct < 1 || slct>5) {
		cout << "Invalid Input! Enter again:";
		cin >> slct;
	}
	switch (slct) {
	case 1:
		playGame();
		break;
	case 2:
		HowtoPlay();
		break;
	case 3://game history
		gameHistory();
		break;
	case 4://exit
		return;
		break;
	}
}
void gameHistory()
{
	ncr();
	string strText;
	char xyz;
	ifstream Game_History("Bingo_Game_History.txt");
	while (getline(Game_History, strText)) { //retreiving a line from Game History.txt and storing it in a string (strText), this loop stops automatically when getline fails to retreive a line (reaches the end of file) and hence returns false
		cout << strText << endl;
		sleep(0);
	}
	cout << "Input any key to return to main menu.\n";
	cin >> xyz;
	mainMenu();
}

#include <iostream>
#include <cstdlib>
using namespace std;

enum enGameResult { ComputerWin = 1, Player1Win = 2, Draw = 3 };

int ReadNumberInRange(int From, int To, string Message, string space) {
	int Number;
	do {
		cout << Message << space;
		cin >> Number;
	} while (Number < From || Number > To);
	return Number;
}

int ReadRandomNumberInRange(int From, int To) {
	int RandomNumber = rand() % (To + 1 - From) + From;
	return RandomNumber;
}

void StoreChoices(int& Player1, int& Computer) {
	Player1 = ReadNumberInRange(1, 3, "Your Choice: [1]:Stone, [2]:Paper, [3]:Scissors ?", " ");
	Computer = ReadRandomNumberInRange(1, 3);
}

string GetChoiceName(int Choice) {
	string Array[3] = { "Stone", "Paper", "Scissors" };
	return Array[Choice - 1];
}

enGameResult DetermineTheRoundWinner(int Player1, int Computer) {

	string Player1Choice = GetChoiceName(Player1);
	string ComputerChoice = GetChoiceName(Computer);

	if (Player1Choice == ComputerChoice)
		return enGameResult::Draw;
	else if
		((Player1Choice == "Stone" && ComputerChoice == "Paper") ||
			(Player1Choice == "Paper" && ComputerChoice == "Scissors") ||
			(Player1Choice == "Scissors" && ComputerChoice == "Stone"))
		return enGameResult::ComputerWin;
	else
		return enGameResult::Player1Win;
}

string ResultOfGameOneRound(int Player1, int Computer) {
	if (DetermineTheRoundWinner(Player1, Computer) == enGameResult::Draw) {
		system("color 6F");
		return "[No Winner]";
	}
	else if (DetermineTheRoundWinner(Player1, Computer) == enGameResult::ComputerWin) {
		system("color 4F");
		cout << "\a";
		return "[Computer]";
	}
	else {
		system("color AF");
		return "[Player1]";
	}
}

string FindFinalWinner(int  Player1Won, int  ComputerWon) {

	string FinalWinner = "";

	if (Player1Won == ComputerWon) {
		FinalWinner = "No Winner";
	}
	else if (ComputerWon > Player1Won) {
		FinalWinner = "Computer";
	}
	else {
		FinalWinner = "Player1";
	}
	return FinalWinner;
}

void ResetScreen() {
	system("cls");
	system("color 0F");
}

void StartTheGame() {
	int Player1, Computer, Player1Won = 0, ComputerWon = 0, DrawTimes = 0;
	char Again;

	int Times = ReadNumberInRange(1, 10, "How Many Rounds 1 to 10 ?", "\n");

	for (int i = 1; i <= Times; i++) {
		cout << "\nRound [" << i << "] begins:" << "\n\n";
		StoreChoices(Player1, Computer);
		cout << "\n______________Round [" << i << "] ______________\n";
		cout << "\nPlayer1  Choice: " << GetChoiceName(Player1) << endl;
		cout << "Computer Choice: " << GetChoiceName(Computer) << endl;
		cout << "Rounnd Winner  : " << ResultOfGameOneRound(Player1, Computer) << endl;
		cout << "\n________________________________________________\n";

		if (ResultOfGameOneRound(Player1, Computer) == "[No Winner]")
			DrawTimes++;
		else if (ResultOfGameOneRound(Player1, Computer) == "[Computer]")
			ComputerWon++;
		else
			Player1Won++;
	}
	cout << "\n\n\t\t\t___________________________________________________________________________\n\n";
	cout << "\t\t\t\t\t\t+++ G a m e  O v e r +++";
	cout << "\n\t\t\t___________________________________________________________________________\n\n";
	cout << "\t\t\t_____________________________ [Game Results ]______________________________\n\n";

	cout << "\t\t\tGame Rounds        : " << Times << endl;
	cout << "\t\t\tPlayer1 won times  : " << Player1Won << endl;
	cout << "\t\t\tComputer won times : " << ComputerWon << endl;
	cout << "\t\t\tDraw times         : " << DrawTimes << endl;
	cout << "\t\t\tFinal Winner       : " << FindFinalWinner(Player1Won, ComputerWon);

	cout << "\n\n\t\t\t___________________________________________________________________________\n\n";
	cout << "\t\t\tDo you want to play again? Y/N? ";
	cin >> Again;
	if (Again == 'Y' || Again == 'y') {
		ResetScreen();
		StartTheGame();
	}
}

int main()
{
	srand((unsigned)time(NULL));

	StartTheGame();


	return 0;
}



/*
Ask how many rounds 1 to 10? Read number In Range N   done

Read the choice?  done

game function done

for loop from 1 to N with done

print final results done

*/

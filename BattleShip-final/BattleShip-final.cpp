// BattleShip-final.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <Windows.h>
#include <dos.h>

using namespace std;

class Game :public GameLogic {
private:
	bool exit = false; //Variable to check exit from the program
	char act[10]; //Variable that carries the player's action

public:
	bool CheckExit(char* act);//Method for check "Stop" or "Start" game
	void Start_game();
	void Timer();

};

int main()
{
	Game game;
	game.Start_game();
	return 0;
}

bool Game::CheckExit(char* act) {
	if (strcmp(act, "stop"))
		return false;
	else
		return true;
};

void Game::Timer() {
	system("cls");
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	cout << "Current Datetime:" << asctime(timeinfo);
	Sleep(5);
};

void Game::Start_game()
{
	int count = 0;
	int Ux = 0, Uy = 0;
	int command_pause = 0;

	GameLogic gameLogic;
	
	//Main loop program
	while (true){

		if (count == 0) {
			cout << "Please, input \"start\" game for start game or press \"stop\" game for stop: ";
			cin >> act;
		}

		if (CheckExit(act) == 1&&count==0){
			break;
		}

		//Create field players
		if (count == 0) {
			gameLogic.Field_user_mapping();//initialization Field user
			gameLogic.Field_computer_mapping();//initialization Field computer
		}

		system("cls"); //Clear window

		cout << "Your field:" << endl;
		gameLogic.View_field_user();

		cout << endl << "Your opponent's field" << endl;
		gameLogic.View_field_computer();

		//Pause
			cout << "input command move 1 or pause 2: ";
			cin >> command_pause;
		if (command_pause == 2) {
			while (true) {
				if (GetAsyncKeyState(VK_LSHIFT))break;//Exit loop left shift
				Timer();
			}
		}
			system("cls");
			cout << "Your field:" << endl;
			gameLogic.View_field_user();

			cout << endl << "Your opponent's field" << endl;
			gameLogic.View_field_computer();

			cout << "input coordinate x and y: " << endl;
			cin >> Ux >> Uy;
		
		system("cls"); //Clear window
		if (gameLogic.Move_user(Ux-1, Uy-1) == 1) {	//Move user, if user finish move, start move computer  		
			gameLogic.Move_computer();
		}
		count++;

		//Check Victory
		if (gameLogic.Check_victory()==1) {
			system("cls");
			
			gameLogic.Check_victory();

			cout << "Your field:" << endl;
			gameLogic.View_field_user();

			cout << endl << "Your opponent's field" << endl;
			gameLogic.View_field_computer();
			count = 0;
		}
	}
}

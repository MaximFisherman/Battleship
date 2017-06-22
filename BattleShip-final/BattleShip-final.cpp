// BattleShip-final.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <Windows.h>
#include <dos.h>

using namespace std;

class Game :public Game_logic {
private:
	bool exit = false; //Variable to check exit from the program
	char act[10]; //Variable that carries the player's action

public:
	bool Check_exit(char* act);//Method for check "Stop" or "Start" game
	void Start_game();
	void Timer();

};

int main()
{
	Game game;
	game.Start_game();
	return 0;
}

bool Game::Check_exit(char* act) {
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

	Game_logic game_logic;
	
	//Main loop program
	while (true){

		if (count == 0) {
			cout << "Please, input \"start\" game for start game or press \"stop\" game for stop: ";
			cin >> act;
		}

		if (Check_exit(act) == 1&&count==0){
			break;
		}

		//Create field players
		if (count == 0) {
			game_logic.Field_user_mapping();//initialization Field user
			game_logic.Field_computer_mapping();//initialization Field computer
		}

		system("cls"); //Clear window

		cout << "Your field:" << endl;
		game_logic.View_field_user();

		cout << endl << "Your opponent's field" << endl;
		game_logic.View_field_computer();

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
			game_logic.View_field_user();

			cout << endl << "Your opponent's field" << endl;
			game_logic.View_field_computer();

			cout << "input coordinate x and y: " << endl;
			cin >> Ux >> Uy;
		
		system("cls"); //Clear window
		if (game_logic.Move_user(Ux, Uy) == 1) {	//Move user, if user finish move, start move computer  		
			game_logic.Move_computer();
		}
		count++;

		//Check Victory
		if (game_logic.Check_victory()==1) {
			system("cls");
			
			game_logic.Check_victory();

			cout << "Your field:" << endl;
			game_logic.View_field_user();

			cout << endl << "Your opponent's field" << endl;
			game_logic.View_field_computer();
			count = 0;
		}
	}
}

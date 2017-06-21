#include "stdafx.h"
#include "Global_variables.h"

using namespace std;
void Game_logic::useStrategy() {
	operation->use(x,y);
};

void Game_logic::setStrategy(Strategy* strategy) {
	operation = strategy;
};

void Game_logic::Field_user_mapping() {
	set_water(Field_user);
	set_ships(Field_user);
	int* temp_mas = print_field(Field_user);

	//Convert to 2d array 
	int count = 0;
	for (int i = 0; i < SIZE_FIELD; ++i) {
		for (int j = 0; j < SIZE_FIELD; ++j) {
			Field_user[i][j] = (char)temp_mas[count];
			count++;
		}
	}
};

void Game_logic::Field_computer_mapping() {
	set_water(Field_computer);
	set_ships(Field_computer);
	int* temp_mas = print_field(Field_computer);

	//Convert to 2d array 
	int count = 0;
	for (int i = 0; i < SIZE_FIELD; ++i) {
		for (int j = 0; j < SIZE_FIELD; ++j) {
			Field_computer[i][j] = (char)temp_mas[count];
			count++;
		}
	}
};

bool Game_logic::Check_victory() {
	int flag = 0;
	int human_flag = 0;
	int computer_flag = 0;
	for (int i = 0; i<10; i++)
	{
		for (int j = 0; j<10; j++)
		{
			if (Field_user[i][j] == '#')
				human_flag = 1; // у пользователя ещё остались неповреждённые корабли
			if (Field_computer[i][j] == '#')
				computer_flag = 1; // у компьютера ещё остались неповреждённые корабли
		}
	}
	if (human_flag == 0)
		flag = 2;
	if (computer_flag == 0)
		flag = 1;
	if (flag == 1)
	{
		std::cout << "You win!\n";
		return true;
	}
	if (flag == 2)
	{
		std::cout << "Comuter win!\n";
		return true;
	}
	return false;
}

//Move computer
bool Game_logic::Move_computer() {
	bool attak = 0;

	while (attak == 0)
	{		
		int x_temp = rand() % 10;
		int y_temp = rand() % 10;
		if (Field_user[y_temp][x_temp] == '*') attak = 1;
		if (Field_user[y_temp][x_temp] == 'X') attak = 1;
		if (Field_user[y_temp][x_temp] == '0') {
			attak = 0;
			Field_user[y_temp][x_temp] = '*';
			break;
		}
		if (Field_user[y_temp][x_temp] == '#') {
			Field_user[y_temp][x_temp] = 'X';
			bool attak_ship = 1;
			while (attak_ship == 0)
			{
			    x_temp = rand() % x_temp + 2 + x_temp - 1;
				y_temp = rand() % y_temp + 2 + y_temp - 1;
				if (Field_user[y_temp][x_temp] == '#') {
					Field_user[y_temp][x_temp] = 'X';
					attak_ship = 1;
				}else{
					Field_user[y_temp][x_temp] = '*';
					attak_ship = 0; break;
				}
				attak = 0;
			}
		}
	}
	return true;
};
//Move players
bool Game_logic::Move_user(int Ux, int Uy) {

	HitSpace hit_space;
	HitShip hit_ship;
	WentBeyond went_beyond;
		//Initialization global value
		x = Ux; y = Uy;

		if (x > SIZE_FIELD || x < 0 || y > SIZE_FIELD || y < 0 || Field_computer[y][x] == '*' || Field_computer[y][x] == 'X'){
			went_beyond.setStrategy(&went_beyond);
			went_beyond.useStrategy();
			return false;
		}

		if (Field_computer[y][x] == '0') {
			hit_space.setStrategy(&hit_space);
			hit_space.useStrategy(); 
			Field_computer[y][x] = '*';
			return true;
		}
		
		if (Field_computer[y][x] == '#') {
			hit_ship.setStrategy(&hit_ship);
			hit_ship.useStrategy();
			Field_computer[y][x] = 'X';
			return false;
		}
		return false;
};

void Game_logic::View_field_computer() {
	for (int i = 0; i < SIZE_FIELD; ++i) {
		for (int j = 0; j < SIZE_FIELD; ++j) {
			cout << Field_computer[i][j] << " ";
		}
		cout << endl;
	}
};

void Game_logic::View_field_user() {
	for (int i = 0; i < SIZE_FIELD; ++i) {
		for (int j = 0; j < SIZE_FIELD; j++) {
			cout << Field_user[i][j] << " ";
		}
		cout << endl;
	}
};
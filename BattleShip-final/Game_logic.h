#pragma once

#include "stdafx.h"

class GameLogic : public Field, public Context {
private:
	static const char WATER_SYMB = '0';
	static const char SHIP_SYMB = '#';


protected: 
	static const int SIZE_FIELD = 10;

	char Field_user[SIZE_FIELD][SIZE_FIELD]; //Field user
	char Field_computer[SIZE_FIELD][SIZE_FIELD]; //Field computer
	int x, y;


public:
	GameLogic() {};
	~GameLogic() {};
	void useStrategy();
	void setStrategy(Strategy* o);

	void Field_user_mapping();
	void Field_computer_mapping();
	bool Move_user(int Ux, int Uy);
	bool Move_computer();
	bool Check_victory();
	void View_field_computer();
	void View_field_user();
};
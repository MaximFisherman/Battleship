#pragma once
#ifndef __CCLASS_H__
#define __CCLASS_H__

#include "stdafx.h"

class Field
{
private:
	static const int  FIELD_DIM = 10;
	static const char WATER_SYMB = '0';
	static const char SHIP_SYMB = '#';
	int fourDeckShip[10];

public:
	Field() {
		srand(static_cast<unsigned>(time(0)));
	};

	bool  ship_is_good(
		int         size,
		bool        is_horiz,
		int         row_top,
		int         col_left,
		char  field[][FIELD_DIM]
	);

	void  set_ship_with_size(int  size, char  field[][FIELD_DIM]);
	void  set_ships(char field[][FIELD_DIM]);
	void  set_water(char field[][FIELD_DIM]);

	int* print_field(char field[][FIELD_DIM]);
	int* getFourDeckShip();
};

#endif // __CCLASS_H__
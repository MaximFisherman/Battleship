#include "stdafx.h"
#include "Field.h"

bool  Field::SHIP_IS_GOOD
(
	int         size,
	bool        is_horiz,
	int         row_top,
	int         col_left,
	char  field[][FIELD_DIM]
)
{
	if (is_horiz)
	{
		for (int i = std::max(0, row_top - 1);
			i <= std::min(FIELD_DIM - 1, row_top + 1);
			++i)
		{
			for (int j = std::max(0, col_left - 1);
				j <= std::min(FIELD_DIM - 1, col_left + size);
				++j)
			{
				if (field[i][j] == SHIP_SYMB) return false; //If in this place is the ship we return false
			}
		}
		return  true;
	}
	else//Vertical
	{
		for (int i = std::max(0, row_top - 1);
			i <= std::min(FIELD_DIM - 1, row_top + size);
			++i)
		{
			for (int j = std::max(0, col_left - 1);
				j <= std::min(FIELD_DIM - 1, col_left + 1);
				++j)
			{
				if (field[i][j] == SHIP_SYMB) return false;
			}
		}
		return  true;
	}
}
/////////////////////////////////////////////////////////////////////////////////////////
void  Field::setShipWithSize(int  size, char  field[][FIELD_DIM])
{
	bool  is_horiz = rand() % 2 == 0;//If rand() % 2 == 0 return true 
	int   row_top = 0;
	int   col_left = 0;
	int	  count = 0;

	do
	{
		do
		{
			row_top = rand() % FIELD_DIM;// get random top cell width size 
		} while (!is_horiz
			&& row_top > FIELD_DIM - size);

		do
		{
			col_left = rand() % FIELD_DIM;// get random size cell width size 
		} while (is_horiz
			&& col_left > FIELD_DIM - size);
	} while (!SHIP_IS_GOOD(size, is_horiz, row_top, col_left, field));

	if (is_horiz)
	{
		for (int j = col_left; j < col_left + size; ++j)
		{
			field[row_top][j] = SHIP_SYMB;//Centering horizontally 
		}
	}
	else
	{
		for (int i = row_top; i < row_top + size; ++i)
		{
			field[i][col_left] = SHIP_SYMB;// Centering vertical
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////////
void  Field::setShips(char  field[][FIELD_DIM])
{
	for (int i = 0; i < 1; ++i)
	{
		setShipWithSize(4, field);
	}

	for (int i = 0; i < 2; ++i)
	{
		setShipWithSize(3, field);
	}

	for (int i = 0; i < 3; ++i)
	{
		setShipWithSize(2, field);
	}

	for (int i = 0; i < 4; ++i)
	{
		setShipWithSize(1, field);
	}
};

int* Field::getFourDeckShip() {
	return this->fourDeckShip;
};

int* Field::print_field(char  field[][FIELD_DIM]){
	//Initialization
	int* temp_mas = new int[FIELD_DIM*FIELD_DIM];
	int count = 0;
	for (int i = 0; i < FIELD_DIM; ++i)
	{
		for (int j = 0; j < FIELD_DIM; ++j)
		{
			temp_mas[count] = field[i][j];
			count++;
		}
	}
	return temp_mas;
};

void  Field::setWater(char  field[][FIELD_DIM])
{
	for (int i = 0; i < FIELD_DIM; ++i)
	{
		for (int j = 0; j < FIELD_DIM; ++j)
		{
			field[i][j] = WATER_SYMB;
		}
	}
}
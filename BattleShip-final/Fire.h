#pragma once
#include "stdafx.h"

class HitSpace : public Strategy, public Game_logic{
public:
	void use(int x, int y) { 
		std::cout << "You are hit space" << std::endl;
	};
};

class HitShip : public Strategy, public Game_logic {
public:
	void use(int x, int y) { 
		std::cout << "You are hit ship " << std::endl; 
	};
};

class WentBeyond : public Strategy, public Game_logic {
public:
	void use(int x, int y) { 
		std::cout << "Went beyond or you already shot this place" << std::endl;
	};
};
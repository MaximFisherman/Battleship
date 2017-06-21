#pragma once
#include "stdafx.h"

class Strategy
{
public:
	virtual ~Strategy() {}
	virtual void use(int x, int y) = 0;
};

#pragma once
#include "stdafx.h"

class Context
{
protected:
	Strategy* operation;

public:
	virtual ~Context() {}
	virtual void useStrategy() = 0;
	virtual void setStrategy(Strategy* v) = 0;
};
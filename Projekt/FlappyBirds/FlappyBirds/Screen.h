#pragma once
#include "ScreenEnum.h"
class Screen {
public:
	virtual void show(ScreenEnum* screen) = 0;
	virtual void createView() = 0;
	virtual void events(ScreenEnum* screen) = 0;
};
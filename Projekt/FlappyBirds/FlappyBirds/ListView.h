#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <string>
#include "ScoreEntity.h"
#include "RenderWindowSingleton.h"
#include <sstream>
#include "Positions.h"

using namespace std;
using namespace sf;

class ListView {
	vector<ScoreEntity> scores;
	float spaceBetweenItem = 0.05;
	int maxItemOnPage = 10;
	shared_ptr <Font> font;
	shared_ptr<Text> listItemText;
	shared_ptr<RenderWindow> renderWindow;
public:
	ListView() {};
	ListView(vector<ScoreEntity>& scoresArray);
	void show();
};
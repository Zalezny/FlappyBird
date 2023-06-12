#pragma oncew

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <string>
#include "TextButton.h"
#include "ScreenEnum.h"
#include "ScoreEntity.h"
#include "FileReader.h"
#include "ListView.h"

using namespace std;
using namespace sf;

class ScoreScreen {
	vector<ScoreEntity> scores;
	shared_ptr<RenderWindow> renderWindow;
	shared_ptr<TextButton> menuButton;
	ListView listView;
	void events(ScreenEnum* screen);
	void createView();
	void getData();
public:
	ScoreScreen();
	void show(ScreenEnum* screen);


};
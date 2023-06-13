#pragma once
#include <iostream>
#include <filesystem>
#include <fstream>
#include <ranges>
#include <vector>
#include "ScoreEntity.h"

using namespace std;

class FileReader {
	filesystem::path filePath;
public:
	FileReader();
	void writeFile(vector<ScoreEntity> scores);
	void writeScore(ScoreEntity score);
	vector<ScoreEntity> readFile();
};
#pragma once
#include <iostream>
#include <filesystem>
#include <fstream>
#include <ranges>
#include "ScoreEntity.h"

using namespace std;

class FileReader {
	filesystem::path filePath;
public:
	FileReader();
	void writeFile(vector<ScoreEntity> scores);
	vector<ScoreEntity> readFile();
};
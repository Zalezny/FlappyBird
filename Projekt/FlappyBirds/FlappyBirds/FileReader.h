#pragma once
#include <iostream>
#include <filesystem>
#include <fstream>
#include <ranges>

using namespace std;

class FileReader {
	filesystem::path filePath;
public:
	FileReader();
	void writeFile(vector<int> scores);
	vector<int> readFile();
};
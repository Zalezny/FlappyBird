#pragma once
#include <iostream>
#include <filesystem>
#include <fstream>
#include <ranges>

using namespace std;

class FileReader {
	filesystem::path filePath;
	void writeFile();
	vector<int> readFile();
public:
	FileReader();
};
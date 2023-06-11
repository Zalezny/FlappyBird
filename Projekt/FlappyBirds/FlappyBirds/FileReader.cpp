#include "FileReader.h"


FileReader::FileReader() {
	filePath = "scores.txt";
}

void FileReader::writeFile(vector<int> scores) {
	ofstream outputFile(filePath);
	ranges::for_each(scores, [&](int element) {
		outputFile << element << "\n";
		});
	outputFile.close();
}

vector<int> FileReader::readFile() {
	vector<int> scores;
	ifstream inputFile(filePath);

	if (inputFile.is_open()) {
		int value;
		while (inputFile >> value) {
			scores.push_back(value);
		}
	
	inputFile.close();

	// sortowanie od najwiêkszego do najmniejszego
	ranges::sort(scores, greater<int>());

	return scores;

}
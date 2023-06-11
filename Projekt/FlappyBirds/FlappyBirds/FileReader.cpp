#include "FileReader.h"


FileReader::FileReader() {
	filePath = "scores.txt";
}

void FileReader::writeFile() {
	ofstream outputFile(filePath);
	vector<int> daneDoZapisu = { 1,2,3,4,5 };
	ranges::for_each(daneDoZapisu, [&](int element) {
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
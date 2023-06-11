#include "FileReader.h"


FileReader::FileReader() {
	filePath = "scores.txt";
}

void FileReader::writeFile(vector<ScoreEntity> scores) {
	ofstream outputFile(filePath);
	ranges::for_each(scores, [&](ScoreEntity element) {
		outputFile << element << "\n";
		});
	outputFile.close();
}

vector<ScoreEntity> FileReader::readFile() {
	vector<ScoreEntity> scores;
	ifstream inputFile(filePath);

	if (inputFile.is_open()) {
		int score;
		string date;
		while (inputFile >> score >> date) {
			ScoreEntity scoreEnt = ScoreEntity(score, date);
			scores.push_back(ScoreEntity(score, date));
		}

		inputFile.close();

		// sortowanie od najwiêkszego do najmniejszego
		ranges::sort(scores, [](const ScoreEntity& obj1, const ScoreEntity& obj2) {
			return obj1.score > obj2.score;
			});

		return scores;

	}
}
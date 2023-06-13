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

void FileReader::writeScore(ScoreEntity score)
{

	ofstream outputFile(filePath);
	outputFile << score << "\n";
	outputFile.close();
}

vector<ScoreEntity> FileReader::readFile() {

	vector<ScoreEntity> scores;
	if (filesystem::exists(filePath)) {
		ifstream inputFile(filePath);
		if (inputFile.is_open()) {
			int score;
			string time, date;
			while (inputFile >> score >> time >> date) {
				ostringstream oss;
				oss << time << " " << date;
				ScoreEntity scoreEnt = ScoreEntity(score, oss.str());
				scores.push_back(scoreEnt);
			}

			inputFile.close();

			// sortowanie od najwiêkszego do najmniejszego
			ranges::sort(scores, [](const ScoreEntity& obj1, const ScoreEntity& obj2) {
				return obj1.score > obj2.score;
				});

		}
		else {
			cout << "Otwieranie pliku sie nie powiodlo" << endl;
		}
	}
	return scores;
}




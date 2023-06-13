#include "FileReader.h"


FileReader::FileReader() {
	filePath = "scores.txt";
}

void FileReader::writeScore(ScoreEntity score)
{

	ofstream outputFile(filePath, ios::app);
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
		}
		else {
			cout << "Otwieranie pliku sie nie powiodlo" << endl;
		}
	}
	return *cleanList(&scores);
}

vector<ScoreEntity>* FileReader::cleanList(vector<ScoreEntity>* scores) {
	// sortowanie od najwiêkszego do najmniejszego
	ranges::sort(*scores, [](const ScoreEntity& obj1, const ScoreEntity& obj2) {
		return obj1.score > obj2.score;
	});

	//usuniêcie pozycji powy¿ej 10 w vektorze
	if (scores->size() > 10) {
		scores->erase(scores->begin() + 10, scores->end());
	}

	return scores;
}



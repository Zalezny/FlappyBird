#include "FileReader.h"


FileReader::FileReader() {
	filePath = "scores.txt";
}

void FileReader::writeFile(vector<ScoreEntity> scores) {

	ofstream outputFile(filePath, ios::app);
	ranges::for_each(scores, [&](ScoreEntity element) {
		outputFile << element << "\n";
		});
	outputFile.close();
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
	// sortowanie od największego do najmniejszego
	ranges::sort(*scores, [](const ScoreEntity& obj1, const ScoreEntity& obj2) {
		return obj1.score > obj2.score;
	});

	//usunięcie pozycji powyżej 10 w vektorze
	if (scores->size() > 10) {
		scores->erase(scores->begin() + 10, scores->end());
	}

	return scores;
}



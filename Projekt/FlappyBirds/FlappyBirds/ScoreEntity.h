#pragma oncew

#include <iostream>

class ScoreEntity {
public:
	int score;
	std::string date;
	ScoreEntity(int _score, std::string _date) : score(_score), date(_date) {}
	inline friend std::ostream& operator<<(std::ostream& os, const ScoreEntity& obj) {
		os << obj.score << " " << obj.date;
		return os;
	}
};
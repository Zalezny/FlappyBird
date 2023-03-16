#include <iostream>
#include <regex>
#include <string>
using namespace std;

string removeWhitespace(string text) {
	regex pattern("\\s+");
	return regex_replace(text, pattern, "");
}

int searchCat(string text) {
	regex pattern("(Cat|cat|Kot)");
	int count = 0;

	sregex_iterator it(text.begin(), text.end(), pattern); 
	sregex_iterator end; 
	while (it != end) {
		count++;
		it++;
	}
	return count;
}

bool check_email(const string& email) {
	regex pattern("[a-zA-Z0-9&#_]{1,10}@[a-z0-9&#_]{2,10}\\.[a-z0-9&#_]{2,3}");
	return regex_match(email, pattern);
}

int main() {
	string text = "Lorem ipsum dolor sit amet, consectetur adipiscingCat elit, sed catdo Cat Kot eiusmod tempor incididunt ut labore et dolore magna aliqua.Risus nullam eget felis eget.Enim diam vulputate pharetra sit amet.Cras tincidunt lobortis feugiat vivamus.Ultrices sagittis orci a purus semper eget duis.Placerat duis ultricies lacus sed.Nulla aliquet enim tortor at urna nunc.In fermentum et sollicitudin ac orci phasellus egestas tellus.Viverra vitae congueeu consequat.Eu lobortis elementum nibh tellus molestie nunc.Platea dictumst vestibulumrhoncus est pellentesque elit ullamcorper.Lacus vestibulum sed arcu non odio euismodlacinia at.Egestas sed tempus urna et pharetra pharetra massa massa.Dui faucibus in ornare quam.Auctor urna nunc id cursus metus.Auctor augue mauris augue neque gravida in.Consequat acfelis donec et odio pellentesque diam volutpat commodo.Eleifend mi in nulla posueresollicitudin aliquam ultrices sagittis.Integer vitae justo eget magna fermentum iaculis.Ultrices dui sapien eget mi.Ac turpis egestas maecenas pharetra.Penatibus et magnis disparturient montes nascetur.Justo laoreet sit amet cursus.Libero id faucibus nisl tincidunteget.Pulvinar sapien et ligula ullamcorper malesuada proin.Lacus suspendisse faucibusinterdum posuere lorem ipsum dolor.Vulputate eu scelerisque felis imperdiet proin fermentum leo vel.Accumsan in nisl nisiscelerisque.Risus viverra adipiscing at in tellus.Mauris pellentesque pulvinar pellentesquehabitant.Urna molestie at elementum eu facilisis sed.Nam at lectus urna duis convallis.Blandit aliquam etiam erat velit scelerisque in.Justo laoreet sit amet cursus sit amet.Etmolestie ac feugiat sed lectus vestibulum mattis ullamcorper.Tristique senectus et netus et.";
	vector<string>maile { "_a_@km.pl","a5@aa.pl",".@km.pl", "abcd123456@ala.com" };
	cout << "Usuniete spacje: " << removeWhitespace(text) << endl;
	cout << "Liczba wystapien Cat|cat|Kot: " << searchCat(text) << endl;

	for (int i = 0; i < maile.size(); i++) {
		if (check_email(maile[i])) {
			cout << "Mail: " << maile[i] << " jest prawidlowy" << endl;
		}
		else {
			cout << "Mail: " << maile[i] << " jest zly" << endl;
		}
	}
	

	
}


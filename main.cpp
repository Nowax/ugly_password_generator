#include <random>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class cPG {
	/* klasa ktora ma generowac haslo z okreslonymi warunkami*/
	
private: string pass = {}; //class variable to hold generated password
public:
	string password();	
};

string cPG::password()
{
	string result;
	std::random_device r;
	char temp;
		std::uniform_int_distribution<char> uid1('a','z');
		temp = uid1(r);
		result.push_back(temp);
	
		std::uniform_int_distribution<char> uid2('A','Z');
		temp = uid2(r);
		result.push_back(temp);
		
		std::uniform_int_distribution<char> uid3('0','9');
		temp = uid3(r);
		result.push_back(temp);

	
		std::uniform_int_distribution<int> uid4(6,20);
		int ipl = uid4(r);
		
	for (int i = result.length(); i < ipl; i++) {
		char t = '?'; 
		while (!isalnum(t) || find(result.begin(), 
	                                    result.end(), t) != result.end()) {
			std::uniform_int_distribution<char> uid('0','z');
			t = uid(r);
			}
		result.push_back(t);
	}
	std::shuffle(result.begin(), result.end(),
	                          std::default_random_engine(std::random_device()()));
	this->pass = result;
	cout << result << endl;
	return result;
}

int main (){
	cPG a;
	a.password();
	return 0;
}

#include "BalanceOfBracketsHeader.h";

int main(int argc, char* argv[]) 
{
	string s;			//string for getting statements from file
	fstream file(argv[1], ios::in);			//opening file from command line arguments
	int i = 0;								//variable for displaying number of statements
	if (file) {
		while (file.good()) {				//while file not at end
			getline(file, s);				//getting statements from file
			cout << "Statement " << i + 1 << " is: " << s << endl;
			if (areBalanced(s)) {			//calling function for checking brackets
				cout << "Brackets are balanced in above statement!\n";
			}
			else {
				cout << "Brackets are not balanced in above statement!\n";
			}
			i++;
		}
	}
	file.close();
	return 0;
}
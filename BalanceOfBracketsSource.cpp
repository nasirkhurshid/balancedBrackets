#include "BalanceOfBracketsHeader.h";

bool areBalanced(const string& s) {		//function for checking whether brackets are balanced or not
	stack<char> st;						//stack for storing brackets				
	int n = s.length();					//getting length of string
	int j = 0;							//variable for counting brackets
	for (int i = 0; i < n; i++) {		//loop for checking each character of string
		if (s[i] == '[' || s[i] == ']' || s[i] == '{' || s[i] == '}' || s[i] == '(' || s[i] == ')') {	//checking if character is bracket
			j++;									//if character is bracket, incrementing j
			if (st.empty()) {						
				st.push(s[i]);						//if stack is empty, pushing bracket
			}
			else if (s[i] == '[' || s[i] == '{' || s[i] == '(') {		//if character is opening bracket, pushing into stack
				st.push(s[i]);
			}
			else if (s[i] == ']') {
				if (st.top() == '[') {			//if character is ] and st.top() is [ then popping element from stack
					st.pop();
				}
				else if (st.top() == '{') {			//if character is ] and st.top() is { then returning false
					cout << "] at location " << i + 1 << " is unbalancing {\n";		//message for telling why brackets are unbalanced
					return false;
				}
				else {			//if character is ] and st.top() is ( then returning false
					cout << "] at location " << i + 1 << " is unbalancing (\n";		//message for telling why brackets are unbalanced
					return false;
				}
			}
			else if (s[i] == '}') {
				if (st.top() == '{') {			//if character is } and st.top() is { then popping element from stack
					st.pop();
				}
				else if (st.top() == '[') {			//if character is } and st.top() is [ then returning false
					cout << "} at location " << i + 1 << " is unbalancing [\n";		//message for telling why brackets are unbalanced
					return false;
				}
				else {			//if character is } and st.top() is ( then returning false
					cout << "} at location " << i + 1 << " is unbalancing (\n";		//message for telling why brackets are unbalanced
					return false;
				}
			}
			else {			//if character is ) and st.top() is ( then popping element from stack
				if (st.top() == '(') {
					st.pop();
				}
				else if (st.top() == '[') {			//if character is ) and st.top() is [ then returning false
					cout << ") at location " << i + 1 << " is unbalancing [\n";		//message for telling why brackets are unbalanced
					return false;
				}
				else {			//if character is ) and st.top() is { then returning false
					cout << ") at location " << i + 1 << " is unbalancing {\n";		//message for telling why brackets are unbalanced
					return false;
				}
			}
		}
	}
	if (j == 0) {					//if there are no brackets in statement displaying message & returning false
		cout << "\nThere are no brackets in the statement!\n";
		return false;
	}
	if (!st.empty()) {				//if stack is not empty then
		while (!st.empty()) {		//popping elements from stack while it is empty and displaying them
			char ch;
			ch = st.top();
			st.pop();
			cout << ch << " ";
		}
		cout << "\nAbove brackets are extra/unbalanced in the statement!\n";		//displaying message 
		return false;			//returning false
	}
	else {
		return true;			//if stack is empty returning true
	}
}
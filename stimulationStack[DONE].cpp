#include <bits/stdc++.h>

using namespace std;

/*
PUSH 1
PUSH 2
PUSH 3
POP
POP
PUSH 4
PUSH 5
POP
#

3
2
5
*/

int main(){
	stack<int> Stack;
	string cmd;
	do {
		cin >> cmd;
		if (cmd == "#") return 0;
		else if (cmd == "PUSH") {
			int toPush;
			cin >> toPush;
			Stack.push(toPush);
		}
		else if (cmd == "POP") {
			if (Stack.empty()){
				cout << "NULL" <<endl;
			}
			else {
				cout << Stack.top() <<endl;
				Stack.pop();
			}
		}
	} while(cmd != "#");
}

//(()[][]{}){}{}[][]({[]()})
//1

#include <bits/stdc++.h>

using namespace std;

// int main () {
// 	bool isMatchParentheses = false;
// 	char str[1000000];
// 	cin.get();
// 	stack<char> Stack;
// 	for (int i = 0; i < strlen(str); i++){
// 		if (str[i] == '[' || str[i] == '(' || str[i] == '{')
// 		{
// 			Stack.push(str[i]);
// 		}
// 		if (str[i] == ']' || str[i] == ')' || str[i] == '}')
// 		{
// 			char top = Stack.top();
// 			if ((top == '[' && str[i] == ']') || (top == '(' && str[i] == ')') || (top == '{' && str[i] == '}')){
// 				isMatchParentheses = true;
// 			} else {
// 				isMatchParentheses = false;
// 				break;
// 			}
// 			Stack.pop();
// 		}
// 	}
// 	if (isMatchParentheses) cout << 1;
// 	else cout << 0;
// }

int main(int argc, char const *argv[])
{
	char c;
	stack<char> Stack;
	bool isMatchParentheses = false;
	while((c = getc(stdin)) != '\n'){
		if (c == '[' || c == '(' || c == '{')
		{
			Stack.push(c);
		}
		if (c == ']' || c == ')' || c == '}')
		{
			if (Stack.empty()){
				isMatchParentheses = false;
				break;	
			}
			char top = Stack.top();
			if ((top == '[' && c == ']') || (top == '(' && c == ')') || (top == '{' && c == '}')){
				isMatchParentheses = true;
			} else {
				isMatchParentheses = false;
				break;
			}
			Stack.pop();
		}
	}
	if (isMatchParentheses) cout << 1;
	else cout << 0;
	return 0;
}


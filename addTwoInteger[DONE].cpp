#include <bits/stdc++.h>

using namespace std;

short sumoneandone(char a, char b){
	short inta = (short)a - 48;
	short intb = (short)b - 48;
	return inta + intb;
}

void sum(char *a, char *b){
	char *result = (char*)malloc(sizeof(char)*256);
	int sizea = strlen(a);
	int sizeb = strlen(b);
	int offset;
	stack<int> Stack;
	short du = 0;
	if (sizea > sizeb){//assume b larger than a
		swap(a,b);
		swap(sizea, sizeb);
	}
	offset = sizeb - sizea;
	for (int i = sizea-1; i >= 0; i--){
		short s = sumoneandone(a[i], b[i+offset]) + du;
		if (s >= 10){
			du = 1;
			Stack.push(s-10);
		} else {
			Stack.push(s);
			du = 0;
		}
	}
	for (int i = offset-1; i >=0; i--){
		short s = sumoneandone(b[i], '0') + du;
		if (s >= 10){
			du = 1;
			Stack.push(s-10);
		}
		else {
			Stack.push(s);
			du = 0;
		}
	}
	if (du == 1){
		Stack.push(1);
	}
	while(!Stack.empty()){
		int s = Stack.top();
		cout << s;
		Stack.pop();
	}
//	cout <<a;
//	cout <<b;
}

int main(){
	char a[256];
	char b[256];
	cin >> a;
	cin >> b;
	sum(a,b);
	//cout << result;
}

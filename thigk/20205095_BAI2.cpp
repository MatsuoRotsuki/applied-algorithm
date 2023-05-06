#include <bits/stdc++.h>
#define N 1000002

using namespace std;

/*
10
8 5 7 9 10 4 7 2 2 6
insert 3
delete-max
insert 6
insert 10
insert 7
insert 8
delete-max
delete-max
delete-max
delete-max
*
*/
int n;
vector<int> a;
void input(){
    cin >> n;
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    sort(a.begin(), a.end(), [](int a, int b){
    	return a < b;
	});
}

void command(){
    string cmd;
    do {
	    cin >> cmd;
	    if (cmd == "*")
	      return;
	    if (cmd == "insert"){
	    	int temp;
	    	cin >> temp;
	    	a.push_back(temp);
		}
		if (cmd == "delete-max"){
			auto it = max_element(a.begin(), a.end());	
            cout << *it <<endl;
            a.erase(it);
		}
	    
  	} while (cmd != "*");
}

int main(int argc, char const *argv[])
{
    input();
    command();
    /* code */
    return 0;
}

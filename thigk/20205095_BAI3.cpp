
#include <bits/stdc++.h>
using namespace std;
void generateSubsets(int start, int setSize, int S[],
									vector<int>& res)
{
	// setSize of power set of a set with setSize
	// N is (2^n - 1)
	unsigned int pow_setSize = pow(2, setSize);

	// Store the sum of particular subset of set
	int sum;

	// Run from counter 000..0 to 111..1
	for (int counter = 0; counter < pow_setSize; counter++) {

		// set the sum initially to zero
		sum = 0;

		for (int j = 0; j < setSize; j++) {

			// Check if jth bit in the counter is set
			// If set then print jth element from set
			if (counter & (1 << j))
				sum += S[j + start];
		}

		// Store the sum in a vector
		res.push_back(sum);
	}
}

int numberOfSubsets(int S[], int N, int A, int B)
{
	// Vectors to store the subsets sums
	// of two half sets individually
	vector<int> S1, S2;

	// Generate subset sums for the first half set
	generateSubsets(0, N / 2, S, S1);

	// Generate subset sums for the second half set
	if (N % 2 != 0)
		generateSubsets(N / 2, N / 2 + 1, S, S2);
	else
		generateSubsets(N / 2, N / 2, S, S2);

	// Sort the second half set
	sort(S2.begin(), S2.end());

	vector<int>::iterator low, high;

	int ans = 0;

	for (int i = 0; i < S1.size(); i++) {

		low = lower_bound(S2.begin(), S2.end(), A - S1[i]);

		high = upper_bound(S2.begin(), S2.end(), B - S1[i]);

		ans += (high - low);
	}
	return ans;
}

int main()
{
	int n;
	cin >> n;
	int S[51];

	int A, B;
	cin >> A >> B;
	for (int i = 0; i < n; i++){
		cin >> S[i];
	}

	// Find the number of subsets with desired Sum
	cout << numberOfSubsets(S, n, A, B) << endl;
	return 0;
}


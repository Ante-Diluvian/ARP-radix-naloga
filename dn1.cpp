#include <fstream>
#include <vector>
#include <iostream>
#include <climits>
using namespace std;

bool Branje_Stevil(vector<int> &vec, const char s[]) {
	ifstream input(s);
	int st;

	if (!input.is_open()) {
		return false;
	}

	while (!input.eof()) {
		input >> st;
		vec.push_back(st);
		while (isspace(input.peek())) input.get();
	}
	input.close();
	return true;
}

void Izpis_Stevil(int* polje, unsigned int velikost) {
	ofstream output("out.txt");

	for (int i = 0; i<velikost; i++)
		output << polje[i] << ' ';
}


vector<int> extractKthBit(const vector<int>& A, int k) {
    vector<int> D;
    for (int num : A) {
        int bit = (num >> k) & 1;
        D.push_back(bit);
    }
    return D;
}

int main(int argc, const char* argv[]) {
	vector<int> A;
	int k = 0;

	if (!Branje_Stevil(A, argv[1])) return 0;

	vector<int> D = extractKthBit(A, k);

	Izpis_Stevil(&A[0], A.size());

	return 0;
}

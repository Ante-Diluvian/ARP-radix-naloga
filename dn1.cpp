#include <fstream>
#include <vector>
#include <iostream>
#include <climits>
using namespace std;

bool Branje_Stevil(vector<unsigned char> &vec, const char s[]) {
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

void Izpis_Stevil(vector<unsigned char>& A) {
	ofstream output("out.txt");
	if(output.is_open()){
		for (unsigned char num : A) {
			output << static_cast<int>(num) << " ";
		}

		output.close();
	} else {
		cerr << "Napaka pri odpiranju datoteke" << endl;
	}
}


vector<int> extractKBit(const vector<unsigned char>& A, int k) {
    vector<int> D;
    for (int num : A) {
        int bit = (num >> k) & 1;
        D.push_back(bit);
    }
    return D;
}

void binaryRadixSort(vector<unsigned char>& A) {
    if (A.empty()) return;
	for (int k = 0; k < 8; k++) {
		int max = INT_MIN;
		vector<int> D = extractKBit(A, k);

		for(int i=0; i < A.size(); i++){
			if(A[i] > max){
				max = A[i];
			}
		}
	
		vector<int> C(max + 1, 0);
		
		for(int i = 0; i < D.size(); i++) {
			C[D[i]]++;
		}
		
		for(int i = 1; i < C.size(); i++) {
			C[i] += C[i - 1];
		}
		
		vector<unsigned char> sortedA(A.size());
		vector<int> sortedD(D.size());
		
		for (int i = A.size() - 1; i >= 0; i--) {
			int pos = C[D[i]] - 1;
			sortedA[pos] = A[i];
			sortedD[pos] = D[i];
			C[D[i]]--;
		}
		
		A = sortedA;

	}

}

int main(int argc, const char* argv[]) {
	vector<unsigned char> A;
	int k = 0;

	if (!Branje_Stevil(A, argv[1])) return 0;

	binaryRadixSort(A);

	Izpis_Stevil(A);

	return 0;
}

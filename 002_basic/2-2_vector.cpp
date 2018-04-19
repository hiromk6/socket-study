// vector
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<char> v;
	int i;
	
	for(i=0; i<10; i++)
	v.push_back(i+'A');

	cout << "Vector's original contents:\n";
	for(i=0; i<v.size(); i++) cout << v[i] << " ";
	cout << "\n\n";

	do {
		v.pop_back();

		cout << "Vector now contains:\n";
		for(i=0; i<v.size(); i++) cout << v[i] << " ";
		cout << endl;

	} while(!v.empty());

	return 0;
}

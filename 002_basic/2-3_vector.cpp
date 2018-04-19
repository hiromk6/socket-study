// vector
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v(10);
	vector<int>::iterator p;
	int i;

	p = v.begin();
	i = 0;
	while(p != v.end()) {
		*p = i;
		p++;
		i++;
	}

	cout << "Original contents:\n";
	p = v.begin();
	while(p != v.end()) {
		cout << *p << " ";
		p++;
	}
	cout << "\n\n";

	p = v.begin();
	while(p != v.end()) {
		*p = *p * 2;
		p++;
	}

	cout << "Modified Contents:\n";
	p = v.begin();
	while(p != v.end()) {
		cout << *p << " ";
		p++;
	}
	cout << endl;

	return 0;
}

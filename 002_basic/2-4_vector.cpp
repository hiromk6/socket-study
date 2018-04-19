// vector
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v;
	int i;

	for(i=0; i<10; i++) v.push_back(i);
	cout << "Vector printed forwards:\n";
	vector<int>::iterator p = v.begin();
	while(p != v.end()) {
		cout << *p << " ";
		p++;
	}
	cout << "\n\n";

	cout << "Vector printed backwards:\n";
	p = v.end();
	while(p != v.begin()) {
		p--;
		cout << *p << " ";
	}

	return 0;
}

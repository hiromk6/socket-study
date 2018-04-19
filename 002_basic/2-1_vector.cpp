// vector
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v(10);
	int i;

	cout << "Size = " << v.size() << endl;

	for(i=0; i<10; i++) v[i] = i;

	cout << "Current Contents:\n";
	for(i=0; i<v.size(); i++) cout << v[i] << " ";
	cout << "\n\n";

	cout << "Expanding vector\n";

	for(i=0; i<5; i++) v.push_back(i+10);

	cout << "Size now = " << v.size() << endl;

	cout << "Current Contents:\n";
	for(i=0; i<v.size(); i++) cout << v[i] << " ";
	cout << "\n\n";

	for(i=0; i<v.size(); i++) v[i] = -v[i];

	cout << "Modified Contents:\n";
	for(i=0; i<v.size(); i++) cout << v[i] << " ";
	cout << endl;

	return 0;
}

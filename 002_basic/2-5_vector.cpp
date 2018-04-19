// vector
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<char> v(10);
	vector<char> v2;

	char str[] = "<Vector>";
	int i;

	for(i=0; i<10; i++) v[i] = i + 'a';

	for(i=0; str[i]; i++) v2.push_back(str[i]);
	
	cout << "Original contents of v:\n";
	for(i=0; i<v.size(); i++) cout << v[i] << " ";
	cout << "\n\n";

	vector<char>::iterator p = v.begin();
	p += 2;

	v.insert(p, 10, 'X');

	cout << "Size after inserting X's = " << v.size() << endl;
	cout << "Contents after insert:\n";
	for(i=0; i<v.size(); i++) cout << v[i] << " ";
	cout << "\n\n";

	p = v.begin();
	p += 2;
	v.erase(p, p+10);

	cout << "Size after erase = " << v.size() << endl;
	cout << "Contents after erase:\n";
	for(i=0; i<v.size(); i++) cout << v[i] << " ";
	cout << "\n\n";

	v.insert(p, v2.begin(), v2.end());
	cout << "Size after v2's insertion = ";
	cout << v.size() << endl;
	cout << "Contents after insert:\n";
	for(i=0; i<v.size(); i++) cout << v[i] << " ";
	cout << endl;

	return 0;
}

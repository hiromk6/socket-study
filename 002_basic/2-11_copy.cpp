//remove_copy, replace_copy
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	char str[] = "Algorithms operate on containers through iterators.";
	vector<char> v, v2(100);
	vector<char>::iterator p;
	int i;

	for(i=0; str[i]; i++) v.push_back(str[i]);

	cout << "Input sequence:\n";
	for(i=0; i<v.size(); i++) cout << v[i];
	cout << endl;

	p = remove_copy(v.begin(), v.end(), v2.begin(), ' ');

	cout << "Result after removing spaces:\n";
	for(i=0; i<p-v2.begin(); i++) cout << v2[i];
	cout << "\n\n";

	cout << "Input sequence:\n";
	for(i=0; i<v.size(); i++) cout << v[i];
	cout << endl;

	p = replace_copy(v.begin(), v.end(), v2.begin(), ' ', '+');

	cout << "Result after replacing spaces with +'s:\n";
	for(i=0; i<p-v2.begin(); i++) cout << v2[i];
	cout << "\n\n";

	return 0;
}

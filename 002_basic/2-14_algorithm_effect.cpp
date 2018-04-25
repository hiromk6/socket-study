// list to vectow
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int main ()
{
	vector<char> v(20);
	list<char> lst;
	int i;

	for(i=0; i<20; i++) v[i] = 'A' + i;

	cout << "Original contens of vector:\n";
	for(i=0; i<v.size(); i++) cout << v[i] << " ";
	cout << "\n\n";

	char str[] = "STL Power-";
	for(i=0; str[i]; i++) lst.push_back(str[i]);

	copy(lst.begin(), lst.end(), v.begin());

	cout << "Contents of vector after copy:\n";
	for(i=0; i<v.size(); i++) cout << v[i] << " ";
	return 0;
}

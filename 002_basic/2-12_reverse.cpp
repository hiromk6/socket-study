// reverse
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> v;
	int i;

	for(i=0; i<10; i++) v.push_back(i);

	cout << "Initial: ";
	for(i=0; i<v.size(); i++) cout << v[i] << " ";
	cout << endl;

	reverse(v.begin(), v.end()-1);

	cout << "Reversed: ";
	for(i=0; i<v.size(); i++) cout << v[i] << " ";
	cout << endl;

	return 0;
}



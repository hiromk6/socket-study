//count_if
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isEven(int i)
{
	return !(i%2);
	return false;
}

int main()
{
	vector<int> v;
	int i;

	for(i=1; i<20; i++) v.push_back(i);

	cout << "Sequence:\n";
	for(i=0; i<v.size(); i++)
		cout << v[i] << " ";
	cout << endl;

	i = count_if(v.begin(), v.end(), isEven);
	cout << i << " numbers are evenly divisible by 2.\n";

	return 0;
}

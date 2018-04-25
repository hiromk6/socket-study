// divide
#include <iostream>
#include <list>
#include <functional>
#include <algorithm>
using namespace std;

int main()
{
	list<double>vals;
	list<double> divisors;
	int i;

	for(i=10; i<100; i+=10) vals.push_back((double)i);
	for(i=1; i<10; i++) divisors.push_back(i+1.0);

	cout << "Original contens of vals:\n";
	list<double>::iterator p = vals.begin();
	while(p != vals.end()) {
		cout << *p << " ";
		p++;
	}

	cout << endl;

	p = transform(vals.begin(), vals.end(), divisors.begin(), vals.begin(), divides<double>());

	cout << "Divided contents of vals:\n";
	p = vals.begin();
	while(p != vals.end()) {
		cout << *p << " ";
		p++;
	}

	return 0;
}

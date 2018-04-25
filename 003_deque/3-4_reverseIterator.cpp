// reverse iterator
#include <iostream>
#include <deque>
using namespace std;

int main()
{
	deque<int> q;
	deque<int>::reverse_iterator rp;
	int i;

	for(i=0; i<10; i++) q.push_back(i);

	cout << "Contents printed backward:\n";
	rp = q.rbegin();
	while(rp != q.rend()) {
		cout << *rp << " ";
		rp++;
	}
	cout << "\n\n";

	cout << "Contents printed forward:\n";
	rp = q.rend();
	while(rp != q.rbegin()) {
		rp--;
		cout << *rp << " ";
	}

	cout << endl;

	return 0;
}

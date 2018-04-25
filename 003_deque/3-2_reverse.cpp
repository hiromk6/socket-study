// deque reverse
#include <iostream>
#include <deque>
using namespace std;

int main()
{
	deque<char> q;
	deque<char> rev_q;
	int i;

	for(i=0; i<10; i++) q.push_back('A'+i);

	cout << "Contents of q: ";
	for(i=0; i<q.size(); i++)
		cout << q[i];
	cout << "\n";

	while(!q.empty()) {
		rev_q.push_front(q.front());
		q.pop_front();
	}

	cout << "Contents of rev_q: ";
	for(i=0; i<rev_q.size(); i++)
		cout << rev_q[i];
	
	cout << endl;

	return 0;
}


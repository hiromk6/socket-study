// deque
#include <iostream>
#include <deque>
#include <cstring>
using namespace std;

int main()
{
	deque<char> q1;
	char str[] = "Using a deque.";
	int i;

	for(i=0; str[i]; i++) {
		q1.push_front(str[i]);
		q1.push_back(str[i]);
	}

	cout << "Original q1:\n";

	for(i=0; i<q1.size(); i++)
		cout << q1[i];
	cout << "\n\n";

	for(i=0; i<strlen(str); i++) q1.pop_front();
	cout << "q1 after popping front:\n";
	for(i=0; i<q1.size(); i++)
		cout << q1[i];
	cout << "\n\n";

	deque<char> q2(q1);
	cout << "q2 original contents:\n";
	for(i=0; i<q2.size(); i++)
		cout << q2[i];
	cout << "\n\n";
	
	for(i=0; i<q2.size(); i++)
		q2[i] = q2[i]+1;

	cout << "q2 transposed contents:\n";
	for(i=0; i<q2.size(); i++)
		cout << q2[i];
	cout << "\n\n";

	deque<char>::iterator p = q1.begin();
	while(p != q1.end()) {
		if(*p == 'a') break;
		p++;
	}

	q1.insert(p, q2.begin(), q2.end());

	cout << "q1 after insertion:\n";
	for(i=0; i<q1.size(); i++)
		cout << q1[i];
	cout << "\n\n";

	return 0;
}


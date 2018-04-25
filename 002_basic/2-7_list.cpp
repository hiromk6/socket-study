#include <iostream>
#include <list>
using namespace std;

int main()
{
	list<char> lst1, lst2, lst3;
	int i;

	for(i=0; i<10; i+=2) lst1.push_back(i+'A');
	for(i=1; i<11; i+=2) lst2.push_back(i+'A');

	cout << "Contents of lst1:\n";
	list<char>::iterator p = lst1.begin();
	while(p != lst1.end()) {
		cout << *p << " ";
		p++;
	}
	cout << "\n\n";

	cout << "Contents of lst2:\n";
	p = lst2.begin();
	while(p != lst2.end()) {
		cout << *p << " ";
		p++;
	}
	cout << "\n\n";

	lst1.merge(lst2);
	if(lst2.empty())
		cout << "lst2 is now empty\n";

	cout << "Contents of lst1 after merge:\n";

	p = lst1.begin();
	while(p != lst1.end()) {
		cout << *p << " ";
		p++;
	}
	cout << "\n\n";
	
	char str[] = "-splicing-";
	for(i=0; str[i]; i++) lst3.push_back(str[i]);

	cout << "Contents of lst3:\n";
	p = lst3.begin();
	while(p != lst3.end()) {
		cout << *p << " ";
		p++;
	}
	cout << "\n\n";

	p = lst1.begin();
	while(p != lst1.end()) {
		if(*p == 'F') lst1.splice(p, lst3);
		p++;
	}

	cout << "Contents of lst1 after splice:\n";
	p = lst1.begin();
	while(p != lst1.end()) {
		cout << *p << " ";
		p++;
	}

	return 0;
}

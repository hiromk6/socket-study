// deque rotate
#include <iostream>
#include <deque>
#include <string>
using namespace std;

template <class T> void lrot(deque<T> &q)
{
	q.push_back(q.front());
	q.pop_front();
}

template <class T> void rrot(deque<T> &q)
{
	q.push_front(q.back());
	q.pop_back();
}

int main()
{
	deque<string> w;
	int i, n;

	w.push_back("Rotation");
	w.push_back("is");
	w.push_back("easy");
	w.push_back("using");
	w.push_back("deque.");

	cout << "This is the original sentence:\n";
	for(i=0; i<w.size(); i++)
		cout << w[i] << " ";
	cout << "\n\n";

	cout << "First, left rotate:\n";
	for(n=0; n<w.size(); n++) {
		lrot(w);
		for(i=0; i<w.size(); i++)
			cout << w[i] << " ";
		cout << "\n";
	}

	cout << "\nNow, right rotate:\n";
	for(n=0; n<w.size(); n++) {
		rrot(w);
		for(i=0; i<w.size(); i++)
			cout << w[i] << " ";
		cout << "\n";
	}

	return 0;
}

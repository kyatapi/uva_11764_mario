#include <stdio.h>
#include <string>
#include <iostream>

#ifndef ONLINE_JUDGE
#include <fstream>
#endif

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	//Redirect stdin/out
	ifstream in("D:\\Project\\Mario\\Debug\\in.txt");
	streambuf *cinbuf = cin.rdbuf(); //save old buf
	cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

	ofstream out("D:\\Project\\Mario\\Debug\\out.txt");
	streambuf *coutbuf = cout.rdbuf(); //save old buf
	cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!
#endif // !ONLINE_JUDGE

#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);
	cout.rdbuf(coutbuf);
#endif // !ONLINE_JUDGE

	return 0;
}
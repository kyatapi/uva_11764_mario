#include <stdio.h>
#include <string>
#include <utility>
#include <iostream>

#ifndef ONLINE_JUDGE
#include <fstream>
#include <gtest\gtest.h>
#endif

using namespace std;

pair<int, int> EvaluateJumps(const unsigned int wall_count, const string&  wall_list) {
	return pair<int, int>(0, 0);
}

TEST(EvaluateJumpsTest, HandleSingleWall) {
	ASSERT_EQ((pair<int, int>(0, 0)), EvaluateJumps(1, "1"));
}

int main(int argc, char **argv) {
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
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	cin.rdbuf(cinbuf);
	cout.rdbuf(coutbuf);
#endif // !ONLINE_JUDGE

	return 0;
}
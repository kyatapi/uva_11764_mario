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
	istringstream iss(wall_list);
	unsigned int current_height = 0;
	unsigned int next_height = 0;
	unsigned int high_jump_count = 0;
	unsigned int low_jump_count = 0;

	iss >> current_height;

	for (unsigned int w = 1; w < wall_count; ++w) {
		iss >> next_height;
		if (next_height > current_height) {
			++high_jump_count;
		}
		current_height = next_height;
	}
	return pair<int, int>(high_jump_count, low_jump_count);
}

TEST(EvaluateJumpsTest, HandleSingleWall) {
	ASSERT_EQ((pair<int, int>(0, 0)), EvaluateJumps(1, "1"));
}

TEST(EvaluateJumpsTest, HandleAscendingWalls) {
	ASSERT_EQ((pair<int, int>(1, 0)), EvaluateJumps(2, "1 2"));

	ASSERT_EQ((pair<int, int>(4, 0)), EvaluateJumps(5, "1 3 5 7 9"));
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
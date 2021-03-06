#include <stdio.h>
#include <string>
#include <utility>
#include <iostream>
#include <sstream>

#ifndef ONLINE_JUDGE
#include <fstream>
#include <gtest\gtest.h>
#endif // !ONLINE_JUDGE

using namespace std;

inline void init_io(streambuf **cinbuf, streambuf **coutbuf) {
#ifndef ONLINE_JUDGE
	//Redirect stdin/out
	ifstream in("D:\\Project\\Mario\\Debug\\in.txt");
	*cinbuf = cin.rdbuf(); //save old buf
	cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

	ofstream out("D:\\Project\\Mario\\Debug\\out.txt");
	*coutbuf = cout.rdbuf(); //save old buf
	cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!
#endif // !ONLINE_JUDGE
}

inline void uninit_io(streambuf *cinbuf, streambuf *coutbuf) {
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);
	cout.rdbuf(coutbuf);
#endif // !ONLINE_JUDGE
}

inline void run_test(int argc, char **argv) {
#ifndef ONLINE_JUDGE
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();;
#endif // !ONLINE_JUDGE
}

#ifndef ONLINE_JUDGE

pair<int, int> EvaluateJumps(const unsigned int, const string&);

TEST(EvaluateJumpsTest, HandleSingleWall) {
	ASSERT_EQ((pair<int, int>(0, 0)), EvaluateJumps(1, "1"));
}

TEST(EvaluateJumpsTest, HandleAscendingWalls) {
	ASSERT_EQ((pair<int, int>(1, 0)), EvaluateJumps(2, "1 2"));

	ASSERT_EQ((pair<int, int>(4, 0)), EvaluateJumps(5, "1 3 5 7 9"));
}

TEST(EvaluateJumpsTest, HandleDescendingWalls) {
	ASSERT_EQ((pair<int, int>(0, 1)), EvaluateJumps(2, "2 1"));

	ASSERT_EQ((pair<int, int>(0, 4)), EvaluateJumps(5, "8 7 6 5 4"));
}

TEST(EvaluateJumpsTest, HandleZigZaggingWalls) {
	ASSERT_EQ((pair<int, int>(1, 1)), EvaluateJumps(3, "2 1 3"));

	ASSERT_EQ((pair<int, int>(3, 4)), EvaluateJumps(8, "8 2 6 5 4 7 1 3"));

	ASSERT_EQ((pair<int, int>(2, 1)), EvaluateJumps(6, "8 2 2 4 4 7"));
}

#endif // !ONLINE_JUDGE

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
		else if (next_height < current_height) {
			++low_jump_count;
		}
		current_height = next_height;
	}
	return pair<int, int>(high_jump_count, low_jump_count);
}

int main(int argc, char **argv) {
	streambuf *cinbuf = NULL;
	streambuf *coutbuf = NULL;

	init_io(&cinbuf, &coutbuf);
	run_test(argc, argv);

	unsigned int test_count = 0;
	cin >> test_count;
	cin.ignore(1, '\n');

	for (unsigned int t = 0; t < test_count; ++t) {
		unsigned int wall_count = 0;
		string wall_list = "";

		cin >> wall_count;
		cin.ignore(1, '\n');

		getline(cin, wall_list);

		pair<int, int> jumps = EvaluateJumps(wall_count, wall_list);
		cout << "Case " << t + 1 << ": " << jumps.first << " " << jumps.second << endl;
	}

	uninit_io(cinbuf, coutbuf);

	return 0;
}
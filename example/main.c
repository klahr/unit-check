/* SPDX-License-Identifier: GPL-3.0-or-later */

#include <unit-check/uc.h>

TEST(Math) {
	ASSERT_TRUE(1 + 1 == 2, "One plus one equals two");
	ASSERT_TRUE(1 - 1 == 0, "One minus one equals zero");
	ASSERT_TRUE(1 * 1 == 1, "One times one equals one");
}

TEST(Colors) {
	const int red = 0xff0000ff;
	const int blue = 0x0000ffff;
	ASSERT_FALSE(red == blue, "Red is not blue");
	ASSERT_TRUE(red != blue, "Red is still not blue");
	ASSERT_EQ(red, red, "Red is red");
	ASSERT_NE(blue, red, "Blue is not red");
}

int main(void) {
	return UC_PrintResults();
}

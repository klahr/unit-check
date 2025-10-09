/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef UC_H
#define UC_H

#include <stdio.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

void UC_RunTest(const char* fn_name);
void UC_Assert(int condition, const char* description, const char* filename, int line);
void UC_AssertEqInt(int expected, int actual, const char* description, const char* filename, int line);
void UC_AssertNeInt(int not_expected, int actual, const char* description, const char* filename, int line);
int UC_PrintResults(void);

#define TEST(fn) \
	__attribute__((constructor)) void fn(void); \
	__attribute__((constructor)) void _##fn(void) { UC_RunTest(#fn); } \
	void fn(void)

#ifdef ASSERT
#	undef ASSERT
#endif

#define ASSERT(condition, description) UC_Assert(condition, description, (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__), __LINE__)
#define ASSERT_TRUE(condition, description) ASSERT((condition) > 0, description)
#define ASSERT_FALSE(condition, description) ASSERT((condition) == 0, description)
#define ASSERT_STR_EQ(first, second, description) ASSERT(strcmp(first, second) == 0, description)
#define ASSERT_EQ(expected, actual, description) UC_AssertEqInt((expected), (actual), description, (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__), __LINE__)
#define ASSERT_NE(not_expected, actual, description) UC_AssertNeInt((not_expected), (actual), description, (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__), __LINE__)

#ifdef __cplusplus
}
#endif

#endif


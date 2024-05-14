/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef UC_H
#define UC_H

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

void UC_RunTest(const char* fn_name);
void UC_Assert(int condition, const char* description, const char* filename, int line);
int UC_PrintResults();
void UC_SetStdOutput(FILE* stream);
void UC_SetErrOutput(FILE* stream);

#define TEST(fn) \
	__attribute__((constructor)) void fn(); \
	__attribute__((constructor)) void _##fn() { UC_RunTest(#fn); } \
	void fn()

#ifdef ASSERT
#	undef ASSERT
#endif

#define ASSERT(condition, description) UC_Assert(condition, description, (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__), __LINE__)
#define ASSERT_TRUE(condition, description) ASSERT((condition) > 0, description)
#define ASSERT_FALSE(condition, description) ASSERT((condition) == 0, description)

#ifdef __cplusplus
}
#endif

#endif


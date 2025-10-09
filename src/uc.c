/* SPDX-License-Identifier: GPL-2.0-only */

#include <unit-check/uc.h>

int passed_tests = 0;
int failed_tests = 0;

void UC_RunTest(const char* fn_name) {
	fprintf(stdout, "test: %s\n", fn_name);
}

void UC_Assert(int condition, const char* description, const char* filename, int line) {
	if (condition) {
		++passed_tests;
		fprintf(stdout, "  \"%s\" (%s:%d) [\033[1m\033[32mPASSED\033[0m]\n", description, filename, line);
	} else {
		++failed_tests;
		fprintf(stderr, "\033[1m\033[31m> \"%s\" (%s:%d) [FAILED]\033[0m\n", description, filename, line);
	}
}

void UC_AssertEqInt(int expected, int actual, const char* description, const char* filename, int line) {
	if (expected == actual) {
		++passed_tests;
		fprintf(stdout, "  \"%s\" (%s:%d) [\033[1m\033[32mPASSED\033[0m]\n", description, filename, line);
	} else {
		++failed_tests;
		fprintf(stderr, "\033[1m\033[31m> \"%s\" (%s:%d) expected %d but got %d [FAILED]\033[0m\n", description, filename, line, expected, actual);
	}
}

void UC_AssertNeInt(int not_expected, int actual, const char* description, const char* filename, int line) {
	if (not_expected != actual) {
		++passed_tests;
		fprintf(stdout, "  \"%s\" (%s:%d) [\033[1m\033[32mPASSED\033[0m]\n", description, filename, line);
	} else {
		++failed_tests;
		fprintf(stderr, "\033[1m\033[31m> \"%s\" (%s:%d) expected value different from %d [FAILED]\033[0m\n", description, filename, line, actual);
	}
}

int UC_PrintResults() {
	fprintf(stdout, "\n%d/%d tests passed\n", passed_tests, passed_tests + failed_tests);
	if (failed_tests == 0) {
		fprintf(stdout, "\033[1m\033[32mSUCCESS\033[0m\n");
		return 0;
	} else {
		fprintf(stdout, "\033[1m\033[31mFAILED\033[0m\n");
		return 1;
	}
}

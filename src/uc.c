/* SPDX-License-Identifier: GPL-2.0-only */

#include <unit-check/uc.h>

int passed_tests = 0;
int failed_tests = 0;
FILE* std_output = NULL;
FILE* err_output = NULL;

void UC_RunTest(const char* fn_name) {
	fprintf(std_output ? std_output : stdout, "test: %s\n", fn_name);
}

void UC_Assert(int condition, const char* description, const char* filename, int line) {
	if (condition) {
		++passed_tests;
		fprintf(std_output ? std_output : stdout, "  \"%s\" (%s:%d) [\033[1m\033[32mPASSED\033[0m]\n", description, filename, line);
	} else {
		++failed_tests;
		fprintf(err_output ? err_output : stderr, "\033[1m\033[31m> \"%s\" (%s:%d) [FAILED]\033[0m\n", description, filename, line);
	}
}

int UC_PrintResults() {
	fprintf(std_output ? std_output : stdout, "\n%d/%d tests passed\n", passed_tests, passed_tests + failed_tests);
	if (failed_tests == 0) {
		fprintf(std_output ? std_output : stdout, "\033[1m\033[32mSUCCESS\033[0m\n");
		return 0;
	} else {
		fprintf(err_output ? err_output : stderr, "\033[1m\033[31mFAILED\033[0m\n");
		return 1;
	}
}

void UC_SetStdOutput(FILE* stream) {
	std_output = stream;
}

void UC_SetErrOutput(FILE* stream) {
	err_output = stream;
}


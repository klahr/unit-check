# UnitCheck - A Lightweight C Library for Unit Testing

## Table of Contents
- [Description](#description)
- [Installation](#installation)
- [Example](#example)
- [Maintainers](#maintainers)

## Description
UnitCheck, the minimalist C library designed to streamline your unit testing process. With UnitCheck, you get a super simple toolset to ensure your code's reliability and quality.

### Key Features:
* **Minimalistic Design**: Focus on writing tests, not on learning a complex framework.
* **Efficient**: Lightweight and fast, UnitCheck won't slow down your development process.
* **Easy Integration**: Seamlessly integrates into your existing projects with minimal setup.

## Installation

```bash
$ git clone https://git.sr.ht/~klahr/unit-check
$ cd unit-check/
$ mkdir build
$ cd build/
$ cmake ..
$ make
$ sudo make install
```
```bash
$ sudo make uninstall # To uninstall.
```

## Example
The example is available in the [example/](./example/) folder.
```c
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
```
Build and run the example.
```bash
$ cd example/
$ make
$ ./example
```
This is the output from the code above.
<pre style="color: red; background-color: black;">
<code>
test: Math
  "One plus one equals two" (main.c:4) [<b style="color: lightgreen">PASSED</b>]
  "One minus one equals zero" (main.c:5) [<b style="color: lightgreen">PASSED</b>]
  "One times one equals one" (main.c:6) [<b style="color: lightgreen">PASSED</b>]
test: Colors
  "Red is not blue" (main.c:12) [<b style="color: lightgreen">PASSED</b>]
  "Red is still not blue" (main.c:13) [<b style="color: lightgreen">PASSED</b>]
  "Red is red" (main.c:14) [<b style="color: lightgreen">PASSED</b>]
  "Blue is not red" (main.c:15) [<b style="color: lightgreen">PASSED</b>]

7/7 tests passed
<b style="color: lightgreen">SUCCESS</b>
</code>
</pre>

## Maintainers
[~klahr](https://sr.ht/~klahr)
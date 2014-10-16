###Dependencies
1. Linux
2. g++ and GNU make

###How to Run Tests

1. Edit the Makefile, make sure `CFLAGS=-c -g -Wall -DSAMPLE_TEST`
2. If you have build the program before, run `make clean`
3. In the project directory, run `make`
4. In the project directory, run `./md5`

###How to Use It As a Program
1. Edit the Makefile, make sure `CFLAGS=-c -g -Wall`
2. If you have build the program before, run `make clean`
3. In the project directory, run `make`
4. In the project directory, run `./md5`
5. Enter strings into stdin, the results will be output to stdout

If you want to use redirection, this is an example. (Checkout the `test` target in Makefile)

  ./md5 < testcase/in > testcase/result

###API

* `string md5(const string str)`

  Sample usage:

```cpp
#include <iostream>
#include "md5.h"
using namespace joyee;

int main(int argc, char* argv[]) {
  std::cout << md5("abc") << '\n'; // 900150983cd24fb0d6963f7d28e17f72
  return 0;
}
```
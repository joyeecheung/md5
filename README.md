###Dependencies
1. Linux
2. g++ and GNU make

###How to Run Tests

1. Edit the Makefile, make sure `CFLAGS=-c -g -Wall -DSAMPLE_TEST`
2. If you have built the program before, run `make clean`
3. In the project directory, run `make`
4. In the project directory, run `./md5`

###How to Use It As a Program
1. Edit the Makefile, make sure `CFLAGS=-c -g -Wall`
2. If you have built the program before, run `make clean`
3. In the project directory, run `make`
4. In the project directory, run `./md5`
5. Enter strings into stdin, the results will be output to stdout

If you want to use redirection, this is an example. (Checkout the `test` target in Makefile)

```bash
./md5 < testcase/in > testcase/result
```

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
* `update`, `finalize`, `toString`

  Sample usage:

  ```cpp
  #include <iostream>
  #include <cstring>
  #include "md5.h"
  using namespace joyee;

  int main(int argc, char* argv[]) {
    MD5 md5 = MD5();
    int data = 1234;
    md5.update(reinterpret_cast<char*>(&data), sizeof(data));
    md5.finalize();
    std::cout << md5.toString() << '\n'; // 099c28f29510c7938bc8c307d287557f
    return 0;
  }
  ```
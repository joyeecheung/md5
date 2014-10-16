#include <iostream>
#include <string>

#ifdef SAMPLE_TEST
#include "test.h"
#else
#include "md5.h"
#endif

using std::getline;
using std::cin;
using std::cout;
using std::string;

using namespace joyee;

int main(int argc, char* argv[]) {
  std::ios::sync_with_stdio(false);

#ifdef SAMPLE_TEST
  runTests();
#else

  string buffer;
  while (getline(cin, buffer)) {
    cout << md5(buffer) << '\n';
  }

#endif

  return 0;
}

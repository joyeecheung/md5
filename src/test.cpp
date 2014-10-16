#include "test.h"

namespace joyee {

void testMD5(const string src, const string expected) {
  static int count = 1;
  string actual = md5(src);

  if (actual == expected) {
    cout << "[PASS] Test " << count << ":\n";
    cout << "         SRC: " << src << '\n';
    cout << "    EXPECTED: " << expected << '\n';
    cout << "      ACTUAL: " << actual << '\n';
  }
  else {
    cout << "[FAIL] Test " << count << ":\n";
    cout << "         SRC: " << src << '\n';
    cout << "    EXPECTED: " << expected << '\n';
    cout << "      ACTUAL: " << actual << '\n';
  }

  cout << "---------------------------------------------------------------\n";
  count++;
}

}

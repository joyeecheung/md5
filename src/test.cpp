#include <sstream>
#include "test.h"

namespace joyee {

void testMD5(const string src, const string expected) {
  static int count = 1;
  string actual = md5(src);

  if (actual == expected) {
    cout << "[PASS] MD5 Test " << count << ":\n";
  } else {
    cout << "[FAIL] Test " << count << ":\n";
  }

  cout << "         SRC: " << src << '\n';
  cout << "    EXPECTED: " << expected << '\n';
  cout << "      ACTUAL: " << actual << '\n';
  cout << "---------------------------------------------------------------\n";
  count++;
}

// LSB first
string byteToString(const uint8_t* arr) {
  std::ostringstream ss;
  for (size_t i = 0; i < 3; ++i) {
    ss << +arr[i] << ' ';
  }
  ss << + arr[3];
  return ss.str();
}

bool byteEqual(const uint8_t* a, const uint8_t* b) {
  for (size_t i = 0; i < 4; ++i) {
    if (a[i] != b[i]) return false;
  }
  return true;
}

void testEncoder(const uint32_t src, const uint8_t* expected) {
  static int count = 1;
  uint8_t actual[4];
  MD5::u32tou8a(actual, src);

  if (byteEqual(actual, expected)) {
    cout << "[PASS] Encoder Test " << count << ":\n";
  } else {
    cout << "[FAIL] Test " << count << ":\n";
  }

  cout << "         SRC: "
       << std::showbase << std::hex << src
       << std:: dec << std::noshowbase << '\n';
  cout << "    EXPECTED: " << byteToString(expected) << "(little endian)\n";
  cout << "      ACTUAL: " << byteToString(actual) << "(little endian)\n";
  cout << "---------------------------------------------------------------\n";
  count++;
}

void testDecoder(const uint8_t* src, const uint32_t expected) {
  static int count = 1;
  uint32_t actual = 0;
  MD5::u8atou32(actual, src);

  if (actual == expected) {
    cout << "[PASS] Decoder Test " << count << ":\n";
  } else {
    cout << "[FAIL] Test " << count << ":\n";
  }

  cout << "         SRC: " << byteToString(src) << "(little endian)\n";
  cout << "    EXPECTED: " << std::showbase << std::hex << expected
       << std:: dec << std::noshowbase << '\n';
  cout << "      ACTUAL: " << std::showbase << std::hex << actual
       << std:: dec << std::noshowbase << '\n';
  cout << "---------------------------------------------------------------\n";
  count++;
}

void runTests() {
  uint8_t u8a1[4] = {0, 0, 0, 0};
  uint8_t u8a2[4] = {255, 255, 255, 255};
  uint8_t u8a3[4] = {0, 0, 255, 255};
  uint32_t u32i1 = 0;
  uint32_t u32i2 = 0xffffffff;
  uint32_t u32i3 = 0xffff0000;

  cout << "---------------------------------------------------------------\n";
  cout << "Test encoders\n";
  cout << "---------------------------------------------------------------\n";

  testEncoder(u32i1, u8a1);
  testEncoder(u32i2, u8a2);
  testEncoder(u32i3, u8a3);

  cout << "---------------------------------------------------------------\n";
  cout << "Test decoders\n";
  cout << "---------------------------------------------------------------\n";

  testDecoder(u8a1, u32i1);
  testDecoder(u8a2, u32i2);
  testDecoder(u8a3, u32i3);


  // cout << "---------------------------------------------------------------\n";
  // cout << "Test MD5\n";
  // cout << "---------------------------------------------------------------\n";
  // testMD5("", "d41d8cd98f00b204e9800998ecf8427e");
  // testMD5("a", "0cc175b9c0f1b6a831c399e269772661");
  // testMD5("abc", "900150983cd24fb0d6963f7d28e17f72");
  // testMD5("message digest", "f96b697d7cb7938d525a2f31aaf161d0");
  // testMD5("abcdefghijklmnopqrstuvwxyz", "c3fcd3d76192e4007dfb496cca67e13b");
  // testMD5("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789",
  //         "d174ab98d277d9f5a5611c2c9f419d9f");
  // testMD5("12345678901234567890123456789012345678901234567890123456789012345678901234567890",
  //         "57edf4a22be3c955ac49da2e2107b67a");
}

}

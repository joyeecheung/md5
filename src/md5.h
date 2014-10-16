#include <string>
using std::string;

#ifndef MD5_H
#define MD5_H

namespace joyee {

#define BLOCK_SIZE 64
typedef unsigned char uint8_t;
typedef unsigned int uint32_t;
typedef unsigned int size_t;

class MD5 {
public:
  MD5();
  void update(const unsigned char* in, size_t len);
  void update(const char* in, size_t len);
  void finalize();
  string toString() const;

#ifndef SAMPLE_TEST
private:
#endif
  void init();
  void transform(const uint8_t block[BLOCK_SIZE]);

  static void u8atou32a(uint32_t* out, const uint8_t* in, size_t len);
  static void u32atou8a(uint8_t* out, const uint32_t* in, size_t len);
  static void u8atou32(uint32_t& out, const uint8_t* in);
  static void u32tou8a(uint8_t* out, const uint32_t in);

  uint8_t buffer[BLOCK_SIZE];
  uint8_t digest[16];

  uint32_t state[4];
  uint32_t lo, hi;
  bool finalized;
};

string md5(const string str);

}

#endif

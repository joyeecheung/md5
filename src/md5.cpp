#include <cstdio>
#include "md5.h"

namespace joyee {

MD5::MD5() {
  init();
}

void MD5::update(const uint8_t* in, size_t len) {

}

void MD5::update(const char* in, size_t len) {

}

void MD5::finalize() {

}

string MD5::toString() const {
  if (!finalized)
    return string("");

  char result[33] = {0};
  for (int i = 0; i < 16; ++i)
    sprintf(result + i * 2, "%02x", digest[i]);

  return string(result);
}

void MD5::init() {
  hi = lo = 0;

  state[0] = 0x67452301;
  state[1] = 0xefcdab89;
  state[2] = 0x98badcfe;
  state[3] = 0x10325476;

  finalized = false;
}

void MD5::transform(const uint8_t block[BLOCK_SIZE]) {

}

void MD5::u8atou32a(uint32_t* out, const uint8_t* in, size_t len) {
  for (size_t i = 0, j = 0; j < len; i++, j += 4) {
    u8atou32(out[i], in + j);
  }
}

void MD5::u32atou8a(uint8_t* out, const uint32_t* in, size_t len) {
  for (size_t i = 0, j = 0; j < len; i++, j += 4) {
    u32tou8a(out + j, in[i]);
  }
}

void MD5::u8atou32(uint32_t& out, const uint8_t* in) {
  out = 0;
  for (size_t i = 0; i < 4; ++i) {
    out |= ((uint32_t)in[i]) << i * 8;
  }
}

void MD5::u32tou8a(uint8_t* out, const uint32_t in) {
  for (size_t i = 0; i < 4; ++i) {
    out[i] = (in >> i * 8) & 0xff;
  }
}

string md5(const string str) {
  MD5 md5 = MD5();
  md5.update(str.c_str(), str.size());
  md5.finalize();
  return md5.toString();
}

}

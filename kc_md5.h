//
// Copyright 2017 Wyatt Miller
//
// THIS CODE BORROWS SIGNIFICANTLY FROM:
// http://www.zedwood.com/article/cpp-md5-function
// https://bobobobo.wordpress.com/2010/10/17/md5-c-implementation/
//
// Please attribute accordingly.
//
// My goal with this code was to streamline user input - a simple .hash() function is called for everything

#ifndef KC_MD5_H
#define KC_MD5_H

#include <iostream>

// Constants for MD5Transform routine.
#define S11 7
#define S12 12
#define S13 17
#define S14 22
#define S21 5
#define S22 9
#define S23 14
#define S24 20
#define S31 4
#define S32 11
#define S33 16
#define S34 23
#define S41 6
#define S42 10
#define S43 15
#define S44 21

namespace kc {

    class md5
    {
    public:

        md5();
        std::string hash(const std::string &text) const;
        std::string hash(const std::ifstream &infile) const;

    private:
        typedef unsigned int size_type; // must be 32bit
        typedef unsigned char uint1; //  8bit
        typedef unsigned int uint4;  // 32bit
        enum {blocksize = 64}; // VC6 won't eat a const static int here

        md5(const std::string& text);
        void update(const unsigned char *buf, size_type length);
        void update(const char *buf, size_type length);

        std::string hexdigest() const;
        void transform(const uint1 block[blocksize]);
        static void decode(uint4 output[], const uint1 input[], size_type len);
        static void encode(uint1 output[], const uint4 input[], size_type len);

        bool finalized;
        uint1 buffer[blocksize]; // bytes that didn't fit in last 64 byte chunk
        uint4 count[2];   // 64bit counter for number of bits (lo, hi)
        uint4 state[4];   // digest so far
        uint1 digest[16]; // the result

        // low level logic operations
        static inline uint4 F(uint4 x, uint4 y, uint4 z);
        static inline uint4 G(uint4 x, uint4 y, uint4 z);
        static inline uint4 H(uint4 x, uint4 y, uint4 z);
        static inline uint4 I(uint4 x, uint4 y, uint4 z);
        static inline uint4 rotate_left(uint4 x, int n);
        static inline void FF(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac);
        static inline void GG(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac);
        static inline void HH(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac);
        static inline void II(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac);
    };


}
#endif //KC_MD5_H



/* MD5
 converted to C++ class by Frank Thilo (thilo@unix-ag.org)
 for bzflag (http://www.bzflag.org)

   based on:

   md5.h and md5.c
   reference implementation of RFC 1321

   Copyright (C) 1991-2, RSA Data Security, Inc. Created 1991. All
rights reserved.

License to copy and use this software is granted provided that it
is identified as the "RSA Data Security, Inc. MD5 Message-Digest
Algorithm" in all material mentioning or referencing this software
or this function.

License is also granted to make and use derivative works provided
that such works are identified as "derived from the RSA Data
Security, Inc. MD5 Message-Digest Algorithm" in all material
mentioning or referencing the derived work.

RSA Data Security, Inc. makes no representations concerning either
the merchantability of this software or the suitability of this
software for any particular purpose. It is provided "as is"
without express or implied warranty of any kind.

These notices must be retained in any copies of any part of this
documentation and/or software.

*/
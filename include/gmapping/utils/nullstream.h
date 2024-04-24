#ifndef NULLSTREAM_H
#define NULLSTREAM_H

#include <iostream>

namespace GMapping {

/** Null output buffer/stream support.
 */
class NullBuffer : public std::streambuf {
  public:
    int overflow(int c) {
        return c;
    }
};
class NullStream : public std::ostream {
  public:
    NullStream()
      : std::ostream(&m_sb) {
    }

  private:
    NullBuffer m_sb;
};

/** Null output stream that can be used to suppress outputs. 
 *  Passing this into the GridSlamProcessor constructor as
 *      GridSlamProcessor(GMapping::g_null_stream, GMapping::g_null_stream)
 *  will effectively suppress all command line output from the class.
 */
static NullStream g_null_stream;

}

#endif

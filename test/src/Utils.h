#ifndef UTILS_H
#define UTILS_H

#if defined(WIN32)
#include <crtdbg.h>
#endif

#include <boost/test/unit_test.hpp>

struct CrtCheckMemory
{

#if defined(WIN32)
  _CrtMemState state1;
  _CrtMemState state2;
  _CrtMemState state3;
#endif
  CrtCheckMemory()
  {
#if defined(WIN32)
    _CrtMemCheckpoint(&state1);
#endif
  }
  ~CrtCheckMemory()
  {
#if defined(WIN32)
    _CrtMemCheckpoint(&state2);
    // using google test you can just do this.
    BOOST_REQUIRE_EQUAL(0, _CrtMemDifference(&state3, &state1, &state2));
    // else just do this to dump the leaked blocks to stdout.
    if( _CrtMemDifference( &state3, &state1, &state2) )
      _CrtMemDumpStatistics( &state3 );
#endif
  }
};

#endif



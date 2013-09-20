#ifndef UTILS_H
#define UTILS_H

#if defined(WIN32) && defined(_DEBUG)
#include <crtdbg.h>
#endif

struct CrtCheckMemory
{

#if defined(WIN32) && defined(_DEBUG)
  _CrtMemState state1;
  _CrtMemState state2;
  _CrtMemState state3;
#endif
  CrtCheckMemory()
  {
#if defined(WIN32) && defined(_DEBUG)
    _CrtMemCheckpoint(&state1);
#endif
  }
  ~CrtCheckMemory()
  {
#if defined(WIN32) && defined(_DEBUG)
    _CrtMemCheckpoint(&state2);
    // using google test you can just do this.
    EXPECT_EQ(0,_CrtMemDifference( &state3, &state1, &state2));
    // else just do this to dump the leaked blocks to stdout.
    if( _CrtMemDifference( &state3, &state1, &state2) )
      _CrtMemDumpStatistics( &state3 );
#endif
  }
};

#endif



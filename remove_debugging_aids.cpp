#define DIBUG
...
#if defined( DEBUG )
// debugging cod
...
#endif



===============


#define DEBUG
#if defined( DEBUG )
#define DebugCode( code_fragment ) { code_fragment }
#else
#define DebugCode( code_fragment )
#endif

DebugCode(
   statement 1;
   ...
);

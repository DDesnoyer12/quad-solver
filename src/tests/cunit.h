// File: cunit.h
// License: GPL 2.0 JKK Consulting  2019
#define CUNIT_VERSION 1.0

#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include <float.h>
#include <math.h> 
#include <string.h>


// Later for a log file name
// extern FILE *cunit_log; 
// int cunit_init();
// 
// #define cunit_open(log) { \
//     if((cunit_log=fopen( log, "w") == NULL ) { \
//      cunit_log = stderr; \
//     } \
// }
// #define cunit_close fclose(cunit_log)
// #define cunit_flush() fflush(cunit_log)
#define cunit_log stdout

#define cunit_date(str) { \
    fprintf(cunit_log, "%s  LINE %d:  DATE:%s TIME:%s :%s\n", \
              __FILE__ , __LINE__ , __DATE__ , __TIME__ , str ); \
}
#define cunit_print(str) { \
    fprintf(cunit_log, "%s\n", str ); \
}

// Integer asserts
#define assertd_eq(str,a,b) { \
  if( a != b ) { \
    fprintf(cunit_log, "%s  LINE %d: %s, %d ! == %d\n", \
              __FILE__ , __LINE__ , str ,  a , b ); \
  } \
}
#define assertd_neq(str,a,b) { \
  if( a == b ) { \
    fprintf(cunit_log, "%s  LINE %d: %s, %d ! != %d\n", \
              __FILE__ , __LINE__ , str ,  a , b ); \
  } \
}
#define assertd_ge(str,a,b) { \
  if( a < b ) { \
    fprintf(cunit_log, "%s  LINE %d: %s, %d ! >= %d\n", \
              __FILE__ , __LINE__ , str ,  a , b ); \
  } \
}
#define assertd_gt(str,a,b) { \
  if( a <= b ) { \
    fprintf(cunit_log, "%s  LINE %d: %s, %d ! > %d\n", \
              __FILE__ , __LINE__ , str ,  a , b ); \
  } \
}
#define assertd_le(str,a,b) { \
  if( a > b ) { \
    fprintf(cunit_log, "%s  LINE %d: %s, %d ! <= %d\n", \
              __FILE__ , __LINE__ , str ,  a , b ); \
  } \
}
#define assertd_lt(str,a,b) { \
  if( a >= b ) { \
    fprintf(cunit_log, "%s  LINE %d: %s, %d ! < %d\n", \
              __FILE__ , __LINE__ , str ,  a , b ); \
  } \
}

// Double or float asserts (floats are promoted to doubles)
#define assertf_eq(str, a, b) { \
  if( a != b ) { \
    fprintf(cunit_log, "%s  LINE %d: %s, %24.19g ! == %24.19g\n", \
              __FILE__ , __LINE__ , str , a , b ); \
  } \
}
#define assertf_neq(str,a,b) { \
  if( a == b ) { \
    fprintf(cunit_log, "%s  LINE %d: %s, %24.19g ! != %24.19g\n", \
              __FILE__ , __LINE__ , str , a , b ); \
  } \
}
// eq equal subject to absolute error
#define assertf_eqaerr(str,a,b,aerr) { \
  if( fabs(a - b) > aerr ) { \
    fprintf(cunit_log, "%s  LINE %d: %s, %24.19g ! == %24.19g, aerr=%10.6e\n", \
              __FILE__ , __LINE__ , str , a , b , aerr); \
  } \
}
// eq equal subject to relative error
#define assertf_eqrerr(str,a,b,rerr) { \
  {double rerr1; \
    if((a==0.0) && (b==0.0)) { \
      rerr1 = 0.0; \
    } else { \
      rerr1 = fabs(a - b)/fmax(fabs(a),fabs(b)); \
    } \
    if( rerr1 > rerr ) { \
      fprintf(cunit_log, "%s  LINE %d: %s, %24.19g ! == %24.19g rerr=%10.6e\n", \
                __FILE__ , __LINE__ , str , a , b , rerr ); \
    } \
  } \
}
#define assertf_ge(str,a,b) { \
  if( a < b ) { \
    fprintf(cunit_log, "%s  LINE %d: %s, %24.19g ! >= %24.19g\n", \
              __FILE__ , __LINE__ , str ,  a , b ); \
  } \
}
#define assertf_gt(str,a,b) { \
  if( a <= b ) { \
    fprintf(cunit_log, "%s  LINE %d: %s, %24.19g ! > %24.19g\n", \
              __FILE__ , __LINE__ , str ,  a , b ); \
  } \
}
#define assertf_le(str,a,b) { \
  if( a > b ) { \
    fprintf(cunit_log, "%s  LINE %d: %s, %24.19g ! <= %24.19g\n", \
              __FILE__ , __LINE__ , str , a , b ); \
  } \
}
#define assertf_lt(str,a,b) { \
  if( a >= b ) { \
    fprintf(cunit_log, "%s  LINE %d: %s, %24.19g ! < %24.19g\n", \
              __FILE__ , __LINE__ , str , a , b ); \
  } \
}

// String asserts, could add le lt ge gt
// Also using n might be problematic
#define asserts_eq(str,n,str1,str2) { \
  if( strncmp(str1,str2,n) != 0)  { \
    if(n<24) { \
      fprintf(cunit_log, "%s  LINE %d: %s \
          str1=/%s/  str2=/%s/  n=%d\n", \
                __FILE__ , __LINE__ , str , str1 , str2, n); \
    } else { \
      fprintf(cunit_log, "%s  LINE %d: %s,\n \
      str1=/%s/ ! == \n \
      str2=/%s/ \n \
      n=%d \n", \
          __FILE__ , __LINE__ , str , str1 , str2, n ); \
    } \
  } \
}
#define asserts_neq(str,n,str1,str2) { \
  if( strncmp(str1,str2,n) == 0)  { \
  } \
}

// IEEE-fp testing
#define assertf_normal(str,a) { \
  if( !isnormal(a) )  { \
    fprintf(cunit_log, "%s  LINE %d: %s, a=%g\n", \
       __FILE__ , __LINE__ , str , a); \
  } \
}

#define assertf_nnormal(str,a) { \
  if( !isnormal(a) )  { \
    fprintf(cunit_log, "%s  LINE %d: %s, a=%g\n", \
       __FILE__ , __LINE__ , str , a); \
  } \
}
#define assertf_subnnormal(str,a) { \
  if( !issubnormal(a) )  { \
    fprintf(cunit_log, "%s  LINE %d: %s, a=%g\n", \
       __FILE__ , __LINE__ , str , a); \
  } \
}
#define assertf_nsubnormal(str,a) { \
  if( !issubnormal(a) )  { \
    fprintf(cunit_log, "%s  LINE %d: %s, a=%g\n", \
       __FILE__ , __LINE__ , str , a); \
  } \
}
#define assertf_nan(str,a) { \
  if( !isnan(a) )  { \
    fprintf(cunit_log, "%s  LINE %d: %s, a=%g\n", \
       __FILE__ , __LINE__ , str , a); \
  } \
}
#define assertf_nnan(str,a) { \
  if( isnan(a) )  { \
    fprintf(cunit_log, "%s  LINE %d: %s, a=%g\n", \
       __FILE__ , __LINE__ , str , a); \
  } \
}
#define assertf_inf(str,a) { \
  if( !isinf(a) )  { \
    fprintf(cunit_log, "%s  LINE %d: %s, a=%g\n", \
       __FILE__ , __LINE__ , str , a); \
  } \
}
#define assertf_ninf(str,a) { \
  if( isinf(a) )  { \
    fprintf(cunit_log, "%s  LINE %d: %s, a=%g\n", \
       __FILE__ , __LINE__ , str , a); \
  } \
}
#define assertf_posinf(str,a) { \
  if( !isinf(a) || a<0.0 )  { \
    fprintf(cunit_log, "%s  LINE %d: %s, a=%g\n", \
       __FILE__ , __LINE__ , str , a); \
  } \
}
#define assertf_neginf(str,a) { \
  if( !isinf(a) || 0.0<a )  { \
    fprintf(cunit_log, "%s  LINE %d: %s, a=%g\n", \
       __FILE__ , __LINE__ , str , a); \
  } \
}

#include "math.h"
#include "math_private.h"

libm_hidden_proto(fma)
#ifdef __STDC__
	double fma(double x, double y, double z)
#else
	double fma(x,y)
	double x;
	double y;
        double z;
#endif
{
  /* Implementation defined. */
  return (x * y) + z;
}
libm_hidden_def(fma)

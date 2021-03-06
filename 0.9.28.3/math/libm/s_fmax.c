/* Copyright (C) 2002 by  Red Hat, Incorporated. All rights reserved.
 *
 * Permission to use, copy, modify, and distribute this software
 * is freely granted, provided that this notice is preserved.
 */

#include "math.h"
#include "math_private.h"

#ifdef __STDC__
	double fmax(double x, double y)
#else
	double fmax(x,y)
	double x;
	double y;
#endif
{
  if (__fpclassify(x) == FP_NAN)
    return x;
  if (__fpclassify(y) == FP_NAN)
    return y;
  
  return x > y ? x : y;
}

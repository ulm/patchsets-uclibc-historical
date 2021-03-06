/* Copyright (C) 2002 by  Red Hat, Incorporated. All rights reserved.
 *
 * Permission to use, copy, modify, and distribute this software
 * is freely granted, provided that this notice is preserved.
 */

#include "math.h"
#include "math_private.h"

#ifdef __STDC__
	double fdim(double x, double y)
#else
	double fdim(x,y)
	double x;
	double y;
#endif
{
  int c = __fpclassify(x);
  if (c == FP_NAN || c == FP_INFINITE)
    return HUGE_VAL;

  return x > y ? x - y : 0.0;
}

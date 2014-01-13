/** 
 * gcdi.c
 *   Instructions for computing the GCD of two integers.
 *
 *   Copyright (c) 2014 Samuel A. Rebelsky.  All rights reserved.
 *
 *   This file is part of mathlib, a simple library of math functions
 *   distributed as part of "Don't Embarrass Me: Thinking in C and *nix",
 *   which is available on the Web at 
 *
 *     <http://www.cs.grinnell.edu/~rebelsky/Cnix/>.
 *
 *   mathlib is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   mathlib is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with mathlib.  If not, see <http://www.gnu.org/licenses/>.
 */


// +---------+---------------------------------------------------------
// | Headers |
// +---------+

#include "mathlib.h"


// +---------+---------------------------------------------------------
// | Helpers |
// +---------+

/**
 * Compute the GCD of two positive integers.  (Intended as a helper
 * for gcdi.
 */
static int
gcdi2 (int x, int y)
{
  if (x == 0)
    {
      gcdi_status = STATUS_SUCCESS;
      return y;
    } // if (x == 0)
  else
    return gcdi2 (y % x, x);
} // gcdi2 (int, int)

/**
 * Compute the absolute value of an integer.
 */
static inline int
absi (int x)
{
  return (x > 0) ? x : -x;
} // absi (int)


// +--------------------+----------------------------------------------
// | Exported Variables |
// +--------------------+

status gcdi_status;


// +--------------------+----------------------------------------------
// | Exported Functions |
// +--------------------+

int
gcdi (int x, int y)
{
  if ((x == 0) || (y == 0)) 
    {
      gcdi_status = STATUS_FAILURE;
      return 0;
    } // if either value is zero
  else 
    {
      return gcdi2 (absi (x), absi (y));
    } // if both values are nonzero
} // gcdi (int, int)

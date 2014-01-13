#ifndef __MATHLIB_H__
#define __MATHLIB_H__

/**
 * mathlib.h
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


// +-------+-----------------------------------------------------------
// | Types |
// +-------+

/**
 * Possible status values for procedures.
 */
enum status
{
  STATUS_SUCCESS = 0,
  STATUS_FAILURE,                // unspecified failure
  STATUS_OVERFLOW,               // numeric overflow
  STATUS_UNDERFLOW,              // numeric underflow
  STATUS_INVALID_EXPONENT,       // for exptl
  STATUS_OTHER 
}; // enum status
typedef enum status status;


// +--------------------+----------------------------------------------
// | Exported Variables |
// +--------------------+

extern status gcdi_status;


// +--------------------+----------------------------------------------
// | Exported Functions |
// +--------------------+

/**
 * Compute the greatest-common-divisor of integers x and y.
 */
int gcdi (int x, int y);

#endif // __MATHLIB_H__


/**
 * scanf.c
 *   A quick exploration of scanf.  Takes a file name from the 
 *   command line and reads a string from that file.
 */

// +-------+-----------------------------------------------------------
// | Notes |
// +-------+


// +---------+---------------------------------------------------------
// | Headers |
// +---------+

#include <stdio.h>      # For fscanf and such.


// +-----------+-------------------------------------------------------
// | Utilities |
// +-----------+

/**
 * Read one line from the file and return it.  (The string is static,
 * so do not free it.)
 */
char *
read_line (FILE *file)
{
  static char *
} // read_line (FILE *)


// +------+------------------------------------------------------------
// | Main |
// +------+

int
main (int argc, char *argv[])
{
  // Sanity check: Make sure that we have the correct number of params.
  if (argc != 2) 
    {
      fprintf (stderr, "Usage: fscanf filename.\n");
      return 1;
    } // if (argc != 2)

  FILE *infile = fopen (argv[
} // main (int, char **)

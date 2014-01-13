Designing Functions
===================

*A work in progress.*

**Summary**: We explore the ways in which C programmers structure the
interfaces for the functions they write.

**Prerequisites**: C basics.  Functions. Pointers. 
[Returning multiple values from a function](multiple-return-values.html).  
[Programming foibles](foibles.html).

- - -

At the core of programming of most C programs is a collection of
inter-related procedures (functions, subroutines).  You've probably
written most of your procedures so that they take a bunch of inputs,
do some actions and computations, and generate one or more outputs.
And that's a good way to think about them.

So, why have a reading on designing functions?  Because there are many
ways to provide inputs to a procedure and to return values from a 
procedure.  The typical beginning C programmer passes inputs as 
parameters to the procedure and gets the outputs from the return
value of the procedure.  (Okay, some really beginning C programmers
might take inputs as globals; we'll assume that you don't do that.)
Let's look at a simple example, computing x^n for long x and non-negative
integer n.

Here's a typical initial version of that procedure.  (You can find a more
efficient version at the end of this reading.)

    /**
     * Compute x^n for non-negative n.
     */
    long
    exptl (long x, int n)
    {
      int i;
      long result = 1;
      for (i = 0; i < n; i++) 
        {
          result *= x;
        } // for
      return result;
    } // exptl (long, int)

But `exptl` can fail.  How?  The client can provide a negative exponent
(violating the preconditions), or x^n can be larger than the largest
`long` value.  What should we do?  There are two basic approaches. The
client can be responsible for meeting the preconditions. (That is, the
client needs to make sure that `n` is not negative and that x^n is
smaller than the largest `long`.)  Alternately, the procedure can signal
an error to the client if the computation fails.  Which strategy is better?
Some folks prefer that the client take responsibility - after all, making
the library procedure do the checking can lead to duplicated work and,
in the end, the client has to figure out whether or not the procedure fails
in any case.  But there are many cases in which the client may not be able
to check all of the conditions, or may find it inefficient to do so.  For
example, the client may not have access to system information (e.g., whether
a file is writable) or may not know enough about underlying representations
to be able to check.

Approaches for indicating success/failure
-----------------------------------------
Hence, most C programmers design their functions in such a way that the
client can determine whether or not the procedure succeeded.  How do they
do so?  Here are a variety of approaches you are likely to see.

### Approach 1: Set a global flag

One simple technique is to put the indication of success/failure outside
of the function, typically with a global "flag" that the client can check.
Here's one such approach.

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
      ...
    }; // enum status
    typedef enum status status;

    // +---------+---------------------------------------------------------
    // | Globals |
    // +---------+

    /**
     * The status of the last call to exptl.
     */
    status exptl_status;

    /**
     * The status of the last call to multl
     */
    status multl_status;

    // +-------------------+-----------------------------------------------
    // | Library Functions |
    // +-------------------+

    /**
     * Multiply a and b.  Sets multl_status to indicate success/failure.
     */
    long 
    multl (long a, long b)
    {
      ...;
    } // multl (long, long)

    /**
     * Compute x^n for non-negative n.
     */
    long
    exptl (long x, int n)
    {
      // Sanity check: Is the exponent valid?
      if (n < 0) 
        {
          exptl_status = STATUS_INVALID_EXPT;
          return 0;
        } // if (n < 0)

      int i;
      long result = 1;
      for (i = 0; i < n; i++) 
        {
          result = multl (result, x);
          if (multl_status != STATUS_SUCCESS)
            {
              explt_status = multl_status;
              return result;
            } // if multiplication failed
            result *= x;
        } // for
      exptl_status = STATUS_SUCCESS;
      return result;
    } // exptl (long, int)

Yes, that's a lot more code.  But most of the code (e.g., the declarations)
will be shared by a number of other functions.  

More importantly, you'll see that the way a client deals with a result
changes.  The client must now check the global value each time, as we
see `exptl` doing in the call to `multl`.  What happens if the client does
not check that global?  Computation continues, although with likely errors.

### Approach 2: Return a special "failure value"

Particularly when a procedure is returning an integer, some programmers
find it easier to return a special value from a procedure to indicate that
the procedure failed.  The client must then check that value before
proceeding.  For our `exptl` procedure, we might return `LONG_MIN` to
indicate an error.

One problem with such an approach is that we are effectively returning
only one bit of information: Did the procedure succeed or fail?  Sometimes
clients want to 


### Approach 3: Return the status through a parameter

### Approach 4: Return the status; Pass back the result through a parameter

### Approach 5: Return the status as a string; Pass back the result through a parameter

### Approach 6: Use signals

It is also possible to indicate that a procedure failed by using
[signals](signals.html).  Since most novice C programmers have not learned
signals, we leave that topic for another time.

A more efficient `exptl`
------------------------

In the examples above, we wrote `exptl` using a for loop.  That means
that it will do `n` multiplications.  Can we do better?  Yes, we can
use *divide and conquer* to cut the exponent in half whenever the exponent
is event.  Here's one such approach.

    /**
     * Compute x^n for long x and non-negative integer n.
     */
    long
    exptl (long x, int n)
    {
      // Case 1: x^0 is 1
      if (n == 0)
        return 1;
      // Case 2: x^n = (x^(n/2)) * (x^(n/2)) if n is even.
      else if (n % 2 == 0)
        {
          long tmp = exptl (x, n/2);
          return tmp*tmp;
        } // if the exponent is even
      // Case 3: x^n = x*(x^(n-1))
      else
        return x*exptl (x, n-1);
    } // exptl

This solution does 2*log(n) multiplications in the worst case, which is
significantly better than n multiplications.

Further reading
---------------

Exercises
---------

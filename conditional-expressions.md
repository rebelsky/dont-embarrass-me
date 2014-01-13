Conditional Expressions
=======================

*This reading is in draft form.*

C's if statements allow you to choose between two paths of control flow -
if a test holds, we execute one set of statements; if a test holds, we
execute another set of statements.  But sometimes we want to choose between
two values (or two expressions), rather than two statements.  Consider the
problem of setting `x` to the larger of `y` and `z`.  (Suppose also that 
we don't have a `max` function or macro.)  With the if statement,
we can write

    if (y > z)
      x = y;
    else
      x = z;

But that's verbose, and it repeats the `x =` component.  What we'd really
like to do is write an expression that, given two values, returns the
larger of the two, and then assign that expression to x.

    x = "larger of y and z"

For situations like this, C includes *conditional expressions*.  Like
if statements, conditional expressions have a test, a consequent, and
an alternate.  However, for concision (and to distinguish them from
if statements), we write them as

    *test* ? *consequent* : *alternate*

So, so set `x` to the larger of `y` and `z`, we would write

    x = (y > z) ? y : z;

You'll find that exprienced programmers use this form a lot, in
assignments, function calls, tests, and more.  Get used to reading it,
and start finding places to write it.

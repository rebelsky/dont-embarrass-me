Formatting Your C Code
======================

C, like many programming languages, is somewhat agnostic about whitespace.
That means that you can format the same piece of code in mulitple ways, with
no real effect on the way the code is compiled or runs.  For example, consider
the following simple function.

    int 
    gcd (int x, int y)
    {
      if (x == 0)
        return y;
      else 
        return gcd (y % x, x);
    } // gcd

We could just as easily format this as

    int gcd( int x, int y ) {
      if (x == 0) return y;
      else return gcd( y % x, x );
    } 

Or on one line as

    int gcd(int x, int y) { if (x == 0) return y; else return gcd(y%x, x); }
 
Or even like this

    int gcd(
    int x
    , int y
    ) {
        if (x
        == 0
        )
    return y; else
    return gcd
    (
    y
    %x
    ,x); }

How should you format your code?  Typically, you will follow some set of
conventions. English writers follow conventions of the English language.
(Okay, not all of them, but most of them.)  These conventions dictate
not only word meaning and order, but also punctuation.  And following
conventions makes text more readable.  Think of how hard it is to read
things that are missing spaces, have inconsistent indentation, or shove
extra punctuation in the middle of lines.  Similarly, programmers also
have conventions to follow.  Some come from the language (e.g., the
meanings of braces), but many come from the local programming community.
Conventions dictate indentation, the way loops are formatted, the way
and place variables are declared, and so on and so forth.

I think it's difficult to read badly formatted code.  (The fourth example
illustrates that issue.)  I know it's difficult to read code that's
formatted using multiple styles.  I've observed that almost every FOSS
(Free and Open Source Software) community has coding conventions for their
projects.  And I hear from our alums that most of the companies they work
for require that their programmers follow local coding conventions when
working on a project.  When you're working on a larger project, follow
the conventions of that project.  When you're working on your own code,
pick a set of conventions to follow.

My favorite set of code conventions is the [GNU C Source Code Formatting
Standards](http://www.gnu.org/prep/standards/standards.html#Formatting).
And they're really my favorites: I not only like them more than any 
other standards I've seen for C, I also like them more than standards I've
seen for other languages.  I use these standards whenever possible, not
least because I often work on GIMP source code, which follows these
conventions.  I will do my best to follow the conventions in this book,
and I encourage you to do the same.

I do extend the conventions in one way - I comment every set of end braces.
Why?  Because in too many years of helping students debug too many problems,
I've found that knowing what a brace is *supposed to* match is incredibly
helpful, particularly since many programmers often forget to add end braces
or add extra end braces in the wrong location.

Conventions are often a matter of taste.  Look back at the examples above.  
One can probably find an argument that any of them is "better".  The
third version is nicely concise (in terms of the number f lines
used).  The second version is a bit less concise, but it's easier to
follow the control structure.  The first is the least concise, but perhaps
easiest to follow.  And that first one is the one I like the most (and
which I think follows the GNU conventions).

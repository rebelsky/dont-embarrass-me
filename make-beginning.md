Beginning Make
--------------

*A placeholder*

**Summary**: ...

**Prerequisites**: ...

- - -

Why have Make?
--------------

As you've learned, compiling a C program can involve multiple steps
and multiple files.  As importantly, when files change, you may have to
redo some of those steps.  Experience suggests that most programmers
need to spend some time figuring out the steps to do, and will forget those
steps if they don't write them down.

Of course, one of the advantages of computers is that once you've written
something down, you can probably have a program do the work for you, rather
than doing it yourself.  Make is a program that takes series of instructions
for building things, along with dependencies between the things you build, 
and figures out what instructions need to be executed and in what order.

An example: A simple library
-----------------------------

Suppose we've written a library of mathematical functions, including
a procedure, `gcdi`, that computes the greatest common divisor of 
two integers.  We are likely to have the following files:

* `gcdi.c` - the source code for the `gcdi` function.  (That function
  might also be joined with other functions into a file like `intfuns.c`.
  For this example, we'll assume that each function has its own file.)
* `mathlib.h` - the header file for our  math library.
* `utest.h` - the header file for the unit testing library.
* `utest.c` - the source code for the unit testing library.  (Ideally,
  this would be a real library file, but I'll assume that you don't
  yet know how to turn source code into libraries.)
* `gcdi-utest.c` - our unit tests for `gcdi`.
* `gcd.c` - a command-line program for computing the GCD of two numbers.

What do we know about instructions and dependencies?

* To build `gcdi-utest`, we need to 
    * compile `gcdi.c` to `gcdi.o`
    * compile `utest.c` to `utest.o`
    * compile `gcd-utest.c` to `gcd-utest.o`
    * link those files together to create the executable.
* To  build `gcd`, we need to
    * compile `gcdi.c` to `gcdi.o`
    * compile `gcd.c` to `gcd.o`
    * link those files together to create the executable.
* If `utest.h` changes, we need to recompile `utest.c` and
  `gcd-utest.c`.  We then need to rebuild anything that depends 
  upon those recompiled files.
* If `mathlib.h` changes, we need to recompile `gcdi.c` and
  `gcd.c`.  We then need to rebuild anything that depends upon 
  those recompiled files.

Another example: Course Web sites
---------------------------------

While Make was originally designed for working with C (or at least I'll
pretend that it was), you can use Make whenever you have a collection of
related files and instructions for building things.  In fact, I use Make
to manage most of my Web sites, including the one for this book.

For this site, I write most of the pages in
[Markdown](http://daringfireball.net/projects/markdown/) because it
provides a quick and dirty way to generate HTML pages without typing
too much extraneous markup.  (Markdown is not ideal.  For example,
I like to be able to automatically include source code into a file.
Markdown does not seem to include a mechanism for doing so, so I've
hacked together scripts to help with such situations.)

But the results of Markdown are fairly basic HTML.  Hence, I have a script
that wraps those results with things that I like to see on every page,
such as the links at the top of the page and the instructions to use a
CSS stylesheet.  That script uses a template (`resources/template.html`)
to figure out what else goes on the page.

Here's a sample of the kind of rules I need to remember to build pages.

* If I have a file that ends in `.md` (for Markdown), I convert it
  to an intermediate HTML file (ending in `-md.html`) using
  `Markdown.pl`.  For example, to create `index-md.html`, I run
  the command <br>
  `Markdown.pl index.md > index-md.html`.
* If I have an intermediate file, I wrap it with `wrap-md-html`, which
  uses the corresponding template.  For example, to create
  `index.html`, I run the command <br>
  `wrap-md-html index-md.html resources/template.html > index.html`.
* If any `.md` file changes, I should regenerate the corresponding HTML
  file.
* If `resources/template.html` changes, I should regenerate all of the
  HTML files.

Note that this project has one important difference from the C project:
We have some *general* patterns, patterns that should work with any
file (e.g., any file ending with `.md`).  We'll see how to write such
general patterns in [a subsequent reading](make-generic-rules.html).

Key concepts
------------

Targets - Some explicit, some conceptual

Dependencies

Instructions

Rules - Tie together targets, dependencies, and instructions

Variables - Important settings

The format of a rule
---------------------

A Makefile for the C example
----------------------------

One nice thing about Make is that it knows default rules for most of
the components of a C program.  So, I don't have to tell make that to
generate `gcdi.o` from `gcdi.c`, use the command `cc -c -o gcdi.o gcdi.c`.
Rather, I can just type `make gcdi.o` (or use `gcdi.o` as a target),
and Make will figure out what to do.

Important settings
------------------

- - -

For further reading
-------------------

Exercises
---------


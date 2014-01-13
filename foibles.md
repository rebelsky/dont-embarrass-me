Programming Foibles: Approaches to Avoid
----------------------------------------

*VERY rough draft of a work in progress*

**Summary**: We consider some typical flaws in the programs of young
programmers.

**Prerequisites**: Basic programming in C.

- - -

New programmers tend to make a variety of common mistakes that, over the
long term, lead to less usable and less maintainable code.  Here are some
particular foibles that bother me, and that you should strive to avoid.

Don't break the abstraction barrier
-----------------------------------

Things go wrong in programs.  Sometimes a file you need is unavailable.
Sometimes a computation overflows.  Sometimes other unexpected things
happen.  As a programmer, you have a responsibility to identify such
problems and to communicate them appropriately.

I see many novice programmers who understand the need to communicate
problems, but who really don't understand how to do so *appropriately*.
Understanding how to communicate problems requires that you first
understand how the parts of a typical program fit together.  Here's
the model I tend to use:

    User --- User Interface --- Application Code --- General Library

That is, most programs focus on providing services to a user.  The user
interacts with a user interface.  (In many cases, we might provide multiple
user interfaces for the same program, such as a graphical and a textual
UI, or separate user interfaces for novices and experts.)  The user 
interface communicates with application-specific procedures.  (We separate
those procedures from the user interface so that it's easier to swap
interfaces.)  And the application-specific procedures communicate with
general library procedures.

When you are writing application code or general library code, you are
responsible for communicating with your *client*, the procedure that
called you, and not with the *user*, who expects to deal primariliy with
the user interface.  

What does this have to do with errors?  I see too many programmers whose
default approach is to print an error message when something goes wrong.
For example,

    /**
     * Get the name of the database to use.
     */
    char *
    get_database ()
    {
      FILE *config = fopen (CONFIG_DATABASE);
      if (NULL == config)
        {
          fprintf (stderr, "Could not open %s.\n", CONFIG_DATABASE);
          return null;
        } // if we failed to open the file
      ...;
    } // get_database()

But printing an error message breaks the abstraction barrier.  It has
library code communicating directly with the user.  And most users won't
understand the messages.  (After all, think about how much you appreciate
the dialogs that pop up in Microsoft windows with messages like "Error 5135".)
More importantly, the client code for your library code might have a way
to recover from the error.  For example, if we can't open a particular file,
it might have an alternative file to use.

So, how do you signal an error other than printing an error message?  There
are [a wide variety of approaches](designing-functions.html), which you can 
read about [elsewhere](designing-functions.html).

Don't hard-code constants
-------------------------

Don't write code by copy-and-paste
----------------------------------

Write concise Boolean functions
-------------------------------

- - -

For further reading
-------------------

Exercises
---------


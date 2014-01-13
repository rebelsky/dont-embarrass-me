Compilation
-----------

*A work in progress.*

**Summary**: We consider the stages of compilation of a C program and the
flags that programmers may use to customize compilation.

**Prerequisites**: Basic understanding of C.

- - -

The stages of compilation
-------------------------

Most of your work with C may have treated compilation as a one step
process: You start with C source code (typically stored in a `.c` file)
and compile that C code to an executable.

However, behind the scenes, the C compiler actually does a sequence of
steps in generating the executable.  Good C compilers even let you stop
the compilation process after any of these stages so that you can view
the output.  (You can then learn from that output, or you might even want
to modify it by program or by hand.)

The first step in compilation is *preprocessing*.  The preprocessor does
simple textual substitutions: It pastes in the contents of any included
files and it replaces macros and constants with their bodies.

The second step in compilation is *translation*.  The compiler converts
the preprocessed C code into assembly code.  By default, GCC tends to
use an internal pseudo-assembly, but you can also tell GCC to generate
particular kinds of assembly code (not only the assembly code for the
current architecture, but even assembly code for other architectures).
This step is traditionally the most complicated.  Assembly code tends
to be stored in a file with a `.s` suffix.

The third step in compilation is *assembly*.  The lines of assembly code
are converted into equivalent object code.  (Assembly code is human
readable.  Object code is more directly machine readable.)  Object code
is usually stored in a file with a `.o` suffix.

The final step in compilation is *linking*.  Your object code is joined
together with other object code (e.g., the standard I/O libraries or
libraries provided by other people) into an executable program.

Separate compilation
--------------------

Back when compiling was an expensive proposition, the designers of C
decided that it would be useful to be able to compile each C file
separately.  That way, when we made a change to one file, we would only
need to recompile that one file and then link all of the compiled files
together.  In fact, even though compilation is much faster, it's still
useful to be able to only recompile a subset of files - On most of the
workstations I use, it takes about thirty minutes to recompile the Gimp
from scratch.  If I change only one file, it takes less than a minute to
recompile and relink that one file.

Hence, good programmers tend to separate their program into logical
components and put each logical component into a separate file.  

Command-line flags
------------------

`-g` - Include information for the debugger.

`-Wall` - Include all compiler warnings.  (If you see warnings, you should
probably fix them.)

For further reading
-------------------

[GCC command options](http://gcc.gnu.org/onlinedocs/gcc-4.8.2/gcc/Invoking-GCC.html)

Exercises
---------


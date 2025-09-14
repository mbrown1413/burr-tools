This is a modified version of BurrTools with bugfixes and code improvements. It
aims to be as backwards-compatible as possible, but no promises! Eventually
some of these changes should be contributed to upstream.

For upstream BurrTools, see: [github.com/burr-tools/burr-tools](https://github.com/burr-tools/burr-tools)


## Notable Changes

Features:
* Undo / redo
* Improvements to command line tool `burrTxt2`, including error checking and
  extra options.

Bugfixes:
* Prevent accidental rapid voxel adding/removing in 3D view.
* Fix crash when solve drop/limit is not strictly positive.

Code cleanup:
* Substantially clean up assembler_1 code so it's more understandable.

Branches:
* `baseline`: This is the original code except for changes to `burrTxt2` to add
  functionality needed for regression testing.


## Original README

```
BurrTools is a library to solve burr-type puzzles. Bundled with the
library comes a graphical program that lets you edit the puzzles and
view the found solutions.

The real documentation is inside the executable-file as on-line help.
And also available as a pdf for off-line reading or printouts.

I've also been able to bundle a few puzzles with the program to
demonstrate its features. Thanks to the designers. You can find these
puzzles in the examples subdirectory.

The library that contains all the mathematical and algorithmical stuff
is documented using doxygen. You can generate that documentation using
the doxygen.cfg file that is in the source-code of the program. I tried
to include algorithmic as well as organisatorical comments into the
doxygen documentation.

Have fun.


    Andreas Röver
```
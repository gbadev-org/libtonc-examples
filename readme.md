# libtonc examples

The examples in this repository are the v1.4.2 examples of libtonc, updated to
be able to build with the current libtonc distributed by devkitpro, and without
the "toolbox" library that some examples used to have.

The examples have been upgraded so that they convert their graphics at build
time. The exception is example `cbb_demo`, as it does special handling with the
converted data, and it can't easily be replicated by an automated process.

To build any of the individual examples, go to its folder and type `make`.

To build all examples at once, type `make` in the root of this repository. All
examples will be copied to folder `bin`.

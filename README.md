# Simple Garbage Collector

My implmentation of the [Mark and Sweep algorithm](https://en.wikipedia.org/wiki/Tracing_garbage_collection#Na%C3%AFve_mark-and-sweep)
by John McCarthy. For this project, I am following Bob Nystrom's [tutorial](http://journal.stuffwithstuff.com/2013/12/08/babys-first-garbage-collector/).

## Installation
Once you have cloned or downloaded the repository, navigate to its root. Then type the following:

```
make install
```

This will create the bin folder, where our compiled executables go.

## Compiling
To compile the code, make sure you are in the root of the repository, and run:

```
make all
```

This will compile all code in `src/` and place the executable in `bin/`.

As a side note, if you want to remove an old version of the executable, run the following:

```
make clean
```

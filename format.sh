#! /bin/bash

files=$(fd .[ch]pp)

clang-format -i $files

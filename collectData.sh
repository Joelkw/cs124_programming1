#!/bin/bash
# collect our data
make 
#

# # Dim 3
./randmst 0 16 5 3
./randmst 0 32 5 3
./randmst 0 64 5 3
./randmst 0 128 5 3
./randmst 0 256 5 3
./randmst 0 512 5 3
./randmst 0 1024 5 3
./randmst 0 2048 5 3
./randmst 0 4096 5 3
./randmst 0 8192 5 3
./randmst 0 16384 5 3
./randmst 0 32768 5 3
./randmst 0 65536 5 3

# Dim 4
./randmst 0 16 5 4
./randmst 0 32 5 4
./randmst 0 64 5 4
./randmst 0 128 5 4
./randmst 0 256 5 4
./randmst 0 512 5 4
./randmst 0 1024 5 4
./randmst 0 2048 5 4
./randmst 0 4096 5 4
./randmst 0 8192 5 4
./randmst 0 16384 5 4
./randmst 0 32768 5 4
./randmst 0 65536 5 4

# Dim 2
./randmst 0 16 5 2
./randmst 0 32 5 2
./randmst 0 64 5 2
./randmst 0 128 5 2
./randmst 0 256 5 2
./randmst 0 512 5 2
./randmst 0 1024 5 2
./randmst 0 2048 5 2
./randmst 0 4096 5 2
./randmst 0 8192 5 2
./randmst 0 16384 5 2
./randmst 0 32768 5 2
./randmst 0 65536 5 2

# Dim 0
./randmst 0 16 5 0
./randmst 0 32 5 0
./randmst 0 64 5 0
./randmst 0 128 5 0
./randmst 0 256 5 0
./randmst 0 512 5 0
./randmst 0 1024 5 0
./randmst 0 2048 5 0
./randmst 0 4096 5 0
./randmst 0 8192 5 0
./randmst 0 16384 5 0
./randmst 0 32768 5 0
./randmst 0 65536 5 0
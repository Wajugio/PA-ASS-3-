Team Members:
- Giovanni Derisca 6170712
- Joseph Woolley 6349901
- 

Assigned Tasks:
- Implemented all four allocation strategies in C.
- Ran simulations using provided parameters.
- Generated the required tables for the final report.

Completed Tasks:
- first_fit.c
- next_fit.c
- best_fit.c
- worst_fit.c
- Final report (report.pdf)
- Compilation and makefile

How to Compile and Run:
1. Run `make` to compile the program.
2. Execute with:
   ./allocator -n [memory size] -d [mean request size] -v [stddev] -x [rounds]
   (Example: ./allocator -n 16777216 -d 1048576 -v 262144 -x 1000)

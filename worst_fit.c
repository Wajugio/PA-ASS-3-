#include "allocator.h"

static int find_worst_fit(int request_size) {
    int worst_hole = -1;
    int worst_size = -1;
    int current_addr = 0;
    int start = 1;
    number_of_examined_holes++;

    while (start || current_addr != 0) {
        start = 0;
        if (memory[current_addr] < 0) {
            int hole_size = -memory[current_addr];
            if (hole_size >= request_size + 5 && hole_size > worst_size) {
                worst_size = hole_size;
                worst_hole = current_addr;
            }
            number_of_examined_holes++;
            current_addr = memory[current_addr + NEXT];
        } else {
            current_addr += (memory[current_addr] + 4);
            if (current_addr >= n) break;
        }
    }
    return worst_hole;
}

void simulate_worst_fit() {
    printf("Simulating worst-fit!\n");
    memory[0] = -(n - 4);
    memory[n - 1] = -(n - 4);
    memory[1] = memory[2] = 0;

    int block_count = 0, total_occupied_size = 0;
    double amu = 0;
    number_of_examined_holes = 0;
    int i = 0;

    for (int round = 0; round < x; round++) {
        while (1) {
            int hole_addr = find_worst_fit(next_request[i]);
            if (hole_addr < 0)
                break;
            int block_size = next_request[i++];
            occupy(hole_addr, block_size, block_count++);
            total_occupied_size += block_size;
        }

        amu += (total_occupied_size / (double)n);
        int to_be_released;
        do {
            to_be_released = rand() % block_count;
        } while (blocks[to_be_released].released);
        release(to_be_released);
        total_occupied_size -= blocks[to_be_released].size;
    }

    printf("Average memory utilization for worst fit is %.2f%%.\n", 100 * amu / x);
    printf("Avg. number of examined holes in the worst fit algorithm is %.2f per round.\n", number_of_examined_holes / (double)x);
}

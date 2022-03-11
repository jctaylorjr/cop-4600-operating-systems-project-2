#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "policies.h"
#include "error_check.h"
#include "dataStructures.h"

// <tracefile> <nframes> <lru|fifo|vms> <p [if vms used]> <debug|quiet>
void fifo(const char *argv)
{
	struct PageTableEntry arr[argv[2]];
	struct Buffer fifo = { .trace_file = argv[1],
			       .nframes = argv[2],
			       .policy = argv[3],
			       .debug_mode = argv[4],
			       .buffer = arr,
			       .buffer_size = 0 };

	// opening and checking trace file
	FILE *fp;
	fp = fopen(fifo.trace_file, "r");
	file_check_err(fp);

	unsigned int addr;
	char rw;
	while (fscanf(fp, "%x %c", &addr, &rw) != EOF) {
		struct PageTableEntry new_pte = { .addr = addr, .rw = rw };
		generateVpn(&new_pte);
		// fifo.buffer[fifo.buffer_size] = new_pte;
		// fifo.buffer_size++;

		if (isPteInBuffer(&new_pte, &fifo)) {
			addDirtyBit(&new_pte, &fifo);
		} else {
			fifo.read_count++;
		}
		fifo.trace_count++;
	}
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "error_check.h"

int main(int argc, char const *argv[])
{
	// declaring variables to give names to all argv inputs for easier recognition
	const char *trace_file, *policy, *debug_mode;
	int num_page_frames, memory_percent;

	// checking if argc is correct, takes vms into account as well
	argc_check_err(argc, argv);

	// setting the argv variables
	trace_file = argv[1];
	num_page_frames = atoi(argv[2]);
	policy = argv[3];
	debug_mode = argv[4];

	// check if policy is valid first
	// if vms policy, args are in different order
	// p and debug arg are set, p value is checked
	policy_check_err(policy);
	if (!strcmp(policy, "vms")) {
		memory_percent = atoi(argv[4]);
		mem_percent_check_err(memory_percent);
		debug_mode = argv[5];
	}
	// debug check here because vms can change it
	debug_mode_check_err(debug_mode);

	// opening and checking trace file
	FILE *fp;
	fp = fopen(trace_file, "r");
	file_check_err(fp);

	// these hold given virtual address and read/write option
	// read from the .trace files
	unsigned int addr;
	char rw;

	while (fscanf(fp, "%x %c", &addr, &rw) != EOF) {
		// probably only have printing on for debugging
		printf("read/write: %c\tvaddr_b2: ", rw);
		// shifting 1 to left 31 times, masking number in question, then reducing 1 bit
		for (unsigned int i = 1 << 31; i > 0; i = i >> 1) {
			addr &i ?
				printf(ANSI_COLOR_GREEN "1" ANSI_COLOR_RESET) :
				      printf("0");
		}

		// make sure to print in unsigned %u
		// checking to see if highest or lowest bit is empty
		// (they aren't)
		printf("\tvaddr_b10: %u\tvaddr_b16: %x\n", addr, addr);
		if (addr & ((UINT_MAX >> 1) ^ UINT_MAX) || addr & 1) {
			fprintf(stderr, "Found the bit\n");
			exit(EXIT_FAILURE);
		}
	}

	return 0;
}

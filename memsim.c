#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	policy_check_err(policy);
	debug_mode = argv[4];
	debug_mode_check_err(debug_mode);

	// changes if vms policy is used, also checking is given percent is acceptable
	if (!strcmp(policy, "vms")) {
		memory_percent = atoi(argv[4]);
		mem_percent_check_err(memory_percent);
		debug_mode = argv[5];
	}

	// opening and checking trace file
	FILE *fp;
	fp = fopen(trace_file, "r");
	file_check_err(fp);

	unsigned int addr;
	char rw;

	while (fscanf(fp, "%x %c", &addr, &rw) != EOF) {
		printf("Read/write: %c\tAddress: %x\n", rw, addr);
	}

	return 0;
}

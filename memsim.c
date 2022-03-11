#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "error_check.h"
#include "dataStructures.h"
#include "policies.h"

int main(int argc, char const *argv[])
{
	// declaring variables to give names to all argv inputs for easier recognition
	const char *trace_file, *policy, *debug_mode;
	int nframes, memory_percent;

	// checking if argc is correct, takes vms into account as well
	argc_check_err(argc, argv);

	// setting the argv variables
	trace_file = argv[1];
	nframes = atoi(argv[2]);
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

	if (!strcmp(policy, "fifo")) {
		fifo(argv);
	} else if (!strcmp(policy, "lru")) {
		printf("lru runs\n");
	} else if (!strcmp(policy, "vms")) {
		printf("vms runs\n");
	} else {
		fprintf(stderr, ANSI_COLOR_RED
			"No policy was selected to run." ANSI_COLOR_RESET);
		exit(EXIT_FAILURE);
	}

	return 0;
}

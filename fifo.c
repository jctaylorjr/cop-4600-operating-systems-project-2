#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "policies.h"
#include "error_check.h"
#include "dataStructures.h"

void addressPrint(struct PageTableEntry *pte, const char *debug_mode)
{
	if (!strcmp(debug_mode, "debug")) {
		// probably only have printing on for debugging
		printf("read/write: %c\ttrace: ", pte->rw);
		// shifting 1 to left 31 times, masking number in question, then reducing 1 bit
		for (unsigned int i = 1 << 31; i > 0; i = i >> 1) {
			pte->addr &i ?
				printf(ANSI_COLOR_GREEN "1" ANSI_COLOR_RESET) :
				      printf("0");
		}

		printf("\tvpn: ");
		for (unsigned int i = 1 << 31; i > 0; i = i >> 1) {
			pte->vpn &i ?
				printf(ANSI_COLOR_GREEN "1" ANSI_COLOR_RESET) :
				      printf("0");
		}

		printf("\tpaddr: ");
		for (unsigned int i = 1 << 31; i > 0; i = i >> 1) {
			pte->offset &i ?
				printf(ANSI_COLOR_GREEN "1" ANSI_COLOR_RESET) :
				      printf("0");
		}
		printf("\n");
	}
}

void fifo(const char *trace_file, int nframes, const char *debug_mode)
{
	struct PageTableEntry page_table[nframes];
	int trace_count = 0;
	int read_count = 0;
	int write_count = 0;

	int pgtb_offset = 0; // offset for making circular array
	int pgtb_count = 0; // keep track of how many entries in page table
	int unsigned addr;
	char rw;

	// opening and checking trace file
	FILE *fp;
	fp = fopen(trace_file, "r");
	file_check_err(fp);

	while (fscanf(fp, "%x %c", &addr, &rw) != EOF) {
		int index = 0;
		struct PageTableEntry temp;

		temp.addr = addr;
		temp.rw = rw;
		generateVpn(&temp);
		generateOffset(&temp);

		if (pgtb_count < nframes) {
			page_table[index].addr = addr;
			page_table[index].rw = rw;
			generateVpn(&page_table[index]);
			generateOffset(&page_table[index]);

			for (; index < nframes; index++) {
				if (temp.vpn == page_table[index].vpn) {
				}
			}
			pgtb_count++;
			addressPrint(&temp, debug_mode);
		}
		trace_count++;
	}
	printf("pgtb_count: %d\t", pgtb_count);
	printf("trace_count: %d\n", trace_count);
}
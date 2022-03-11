#include "dataStructures.h"
#include "debug.h"
#include "error_check.h"

void printBinary(int n)
{
	for (unsigned int i = 1 << 31; i > 0; i = i >> 1) {
		n &i ? printf(ANSI_COLOR_GREEN "1" ANSI_COLOR_RESET) :
			     printf("0");
	}
}

void addressPrint(struct PageTableEntry *pte, const char *debug_mode)
{
	if (!strcmp(debug_mode, "debug")) {
		// probably only have printing on for debugging
		printf("read/write: %c\ttrace: ", pte->rw);
		// shifting 1 to left 31 times, masking number in question, then reducing 1 bit
		printBinary(pte->addr);
		printf("\tvpn: ");
		printBinary(pte->vpn);
		printf("\n");
	}
}
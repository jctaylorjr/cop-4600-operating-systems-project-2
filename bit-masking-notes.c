#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	// 2^10 = 1KB = 1024B, 2^2 = 4B, 4KB = 4096B = 2^12
	unsigned int virtual_address = 21; //010101b
	unsigned int vpn_mask = 0x30; //110000b
	unsigned int vpn = (virtual_address & vpn_mask) >> 4; //010000 >> 000001
	// unsigned int PTE_addr ==
	printf("vpn: %d\n", vpn);

	unsigned int sixfour = 32;
	printf("base 10: %d\nbase 16: %x\nbinary: ", sixfour, sixfour);

	// shifting 1 to left 31 times, masking number in question, then reducing 1 bit
	for (unsigned int i = 1 << 31; i > 0; i = i >> 1) {
		sixfour &i ? printf("1") : printf("0");
	}
	printf("\n");
	return 0;
}

// exit(EXIT_SUCCESS);

// // opening and checking trace file
// FILE *fp;
// fp = fopen(trace_file, "r");
// file_check_err(fp);

// // these hold given virtual address and read/write option
// // read from the .trace files
// unsigned int addr;
// char rw;
// int arr[PAGETABLE_SIZE] = { 0 };
// int total = 0;

// while (fscanf(fp, "%x %c", &addr, &rw) != EOF) {
// 	// probably only have printing on for debugging
// 	printf("read/write: %c\tvaddr_b2: ", rw);
// 	// shifting 1 to left 31 times, masking number in question, then reducing 1 bit
// 	for (unsigned int i = 1 << 31; i > 0; i = i >> 1) {
// 		addr &i ?
// 			printf(ANSI_COLOR_GREEN "1" ANSI_COLOR_RESET) :
// 			      printf("0");
// 	}

// 	// make sure to print in unsigned %u
// 	// checking to see if highest or lowest bit is empty
// 	// (they aren't)
// 	printf("\tvaddr_b10: %u\tvaddr_b16: %x\n", addr, addr);
// 	// if (addr & ((UINT_MAX >> 1) ^ UINT_MAX) || addr & 1) {
// 	// 	fprintf(stderr, "Found the bit\n");
// 	// 	exit(EXIT_FAILURE);
// 	// }
// 	struct PageTableEntry temp;
// 	temp.addr = addr;
// 	temp.rw = rw;
// 	generateVpn(&temp);
// 	generateOffset(&temp);
// 	printf("vpn: %x\n", temp.vpn);
// 	if (arr[temp.vpn] == 0) {
// 		total++;
// 	}
// 	arr[temp.vpn]++;
// }

// for (int i = 0; i < PAGETABLE_SIZE; i++) {
// 	if (arr[i] > 0) {
// 		printf("Index: %d, count: %d\n", i, arr[i]);
// 	}
// }
// printf("total: %d\n", total);

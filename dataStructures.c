#include "dataStructures.h"

struct PageTableEntry PageTable[PAGETABLE_SIZE]; // 2^20 total entries
struct PageTableEntry TLB[TBL_SIZE]; // 2^12 total entries
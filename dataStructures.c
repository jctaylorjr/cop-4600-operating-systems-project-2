#include "dataStructures.h"

struct PageTableEntry PageTable[(UINT_MAX >> 12)]; // 2^20 total entries
struct PageTableEntry TLB[(UINT_MAX >> 20)]; // 2^12 total entries
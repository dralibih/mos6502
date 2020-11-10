#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "addressing_modes.h"
#include "fetch_cycle.h"
#include "execute_cycle.h"
#include "instruction_set.h"
#include "mos6502_utils.h"

int main()
{
    Mos6502 cpu;
    Memory mem;

    init_memory(&mem);

    reset_cpu(&cpu, &mem);

    printf("INITIAL PC: 0x%04x \n\n", cpu.pc);
    for(int i=0; i<100; i++) printf("=");
    printf("\n");

    mem.ram[0x0600] = 0xa2;
    mem.ram[0x0601] = 0x0A;
    mem.ram[0x0602] = 0xca;
    mem.ram[0x0603] = 0xd0;
    mem.ram[0x0604] = 0xfd;
    mem.ram[0x0605] = 0x60;

    execute_program(&cpu, &mem);
}

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

    mem.ram[0x0101] = 0xA9;
    mem.ram[0x0102] = 30;
    mem.ram[0x0103] = 0x85;
    mem.ram[0x0104] = 0x20;

    execute_program(&cpu, &mem);

    printf("RAM[0x0020]: %d\n", mem.ram[0x0020]);
}

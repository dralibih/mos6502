#include <stdio.h>
#include <stdint.h>

#include "mos6502_types.h"
#include "instruction_set.h"
#include "fetch_cycle.h"

void fetch(Mos6502 *cpu, Memory *mem)
{
  cpu->inst = mem->ram[cpu->pc];
  cpu->pc++;
}

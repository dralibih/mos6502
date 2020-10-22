#include <stdio.h>
#include <stdint.h>

#include "mos6502_types.h"
#include "instruction_set.h"
#include "execute_cycle.h"
#include "addressing_modes.h"

void decode(Mos6502 *cpu, Memory *mem)
{
  void (*addrs_mode)(Mos6502 *, Memory *);
  addrs_mode = get_addressing_mode(cpu->inst);
  addrs_mode(cpu, mem);
}

void execute(Mos6502 *cpu, Memory *mem)
{
  void (*instruction)(Mos6502 *, Memory *);
  instruction = get_instruction(cpu->inst);
  instruction(cpu, mem);
}

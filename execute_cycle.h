#ifndef EXECUTE_CYCLE_H
#define EXECUTE_CYCLE_H

#include <stdint.h>
#include "mos6502_types.h"

void decode(Mos6502 *cpu, Memory *mem);
void execute(Mos6502 *cpu, Memory *mem);

#endif

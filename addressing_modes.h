#ifndef ADDRESSING_MODES_H
#define ADDRESSING_MODES_H

#include <stdint.h>
#include "mos6502_types.h"

typedef void (*addr_mode)(Mos6502 *cpu, Memory *mem);

addr_mode get_addressing_mode(uint8_t opcode);

void accumulator(Mos6502 *cpu, Memory *mem);
void absolute(Mos6502 *cpu, Memory *mem);
void absolute_x(Mos6502 *cpu, Memory *mem);
void absolute_y(Mos6502 *cpu, Memory *mem);
void immediate(Mos6502 *cpu, Memory *mem);
void implied(Mos6502 *cpu, Memory *mem);
void indirect(Mos6502 *cpu, Memory *mem);
void x_indirect(Mos6502 *cpu, Memory *mem);
void indirect_y(Mos6502 *cpu, Memory *mem);
void relative(Mos6502 *cpu, Memory *mem);
void zeropage(Mos6502 *cpu, Memory *mem);
void zeropage_x(Mos6502 *cpu, Memory *mem);
void zeropage_y(Mos6502 *cpu, Memory *mem);

#endif

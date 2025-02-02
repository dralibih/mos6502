#ifndef MOS6502_UTILS_H
#define MOS6502_UTILS_H

#include "mos6502_types.h"

#define RESET_VAL_MSB 0xfffd
#define RESET_VAL_LSB 0xfffc

void init_memory(Memory *mem);
void reset_cpu(Mos6502 *cpu, Memory *mem);
void set_flag(Mos6502 *cpu, uint8_t mask, uint8_t val1, uint8_t val2, uint8_t aux);
void execute_program(Mos6502 *cpu, Memory *mem);
void show_cpu_info(Mos6502 *cpu);

#endif

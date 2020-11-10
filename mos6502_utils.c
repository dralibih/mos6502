#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "mos6502_types.h"
#include "mos6502_utils.h"
#include "fetch_cycle.h"
#include "execute_cycle.h"

void init_memory(Memory *mem)
{
  mem->ram = (uint8_t *)malloc(sizeof(uint8_t) * 1024 * 64); // 64K
  mem->ram[RESET_VAL_MSB - 1] = 0x06;
  mem->ram[RESET_VAL_LSB - 1] = 0x00;
}

void reset_cpu(Mos6502 *cpu, Memory *mem)
{
  uint8_t ph = mem->ram[RESET_VAL_MSB - 1];
  uint8_t pl = mem->ram[RESET_VAL_LSB - 1];
  cpu->pc = ph * 256 + pl;
  cpu->sp = 0xFF;
  cpu->psr = 0x00;
  cpu->a = 0;
  cpu->x = 0;
  cpu->y = 0;
}

void set_flag(Mos6502 *cpu, uint8_t mask, uint8_t val1, uint8_t val2, uint8_t aux){

  int change = 0;

  if (mask == 0x01){        // Carry
    // arithmetic
    if (val1 > val2) change = 1;
    // compare
    if (val1 >= val2) change = 1;
  }
  else if (mask == 0x02) {  // Zero
    // compare
    if (val1 == val2) change = 1;
    // otherwise
    if (val1 == 0) change = 1;
  }
  else if (mask == 0x04) {  // Interrupt Disable
  }
  else if (mask == 0x08) {  // Decimal
  }
  else if (mask == 0x10) {  // Break
  }
  else if (mask == 0x40) {  // Overflow
    // arithmetic
    uint8_t sig_val1 = val1 & 0x80;
    uint8_t sig_val2 = val2 & 0x80;
    uint8_t sig_aux = aux & 0x80;
    if (sig_val1 == sig_val2)
      if (sig_val1 != sig_aux) change = 1;
  }
  else if (mask == 0x80) {  // Negative
    // compare
    if (val1 < val2) change = 1;
    // otherwise
    if (val1 & mask) change = 1;
  }

  if (change) cpu->psr |= mask;
}

void execute_program(Mos6502 *cpu, Memory *mem)
{
    while (mem->ram[cpu->pc]) {
        fetch(cpu, mem);
        decode(cpu, mem);
        execute(cpu, mem);
        show_cpu_info(cpu);
    }
}

void show_cpu_info(Mos6502 *cpu)
{
    printf("\n");
    printf("\033[1;32m");
    printf("A: 0x%02x \t", cpu->a);
    printf("X: 0x%02x \t", cpu->x);
    printf("Y: 0x%02x \t", cpu->y);
    printf("PSR: 0x%02x \t", cpu->psr);
    printf("SP: 0x%02x \t", cpu->sp);
    printf("PC: 0x%04x \t", cpu->pc);
    printf("\033[0m");
    printf("\n");
    for(int i=0; i<100; i++) printf("=");
    printf("\n");
}

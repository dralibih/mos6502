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
  mem->ram[RESET_VAL_MSB - 1] = 0x01;
  mem->ram[RESET_VAL_LSB - 1] = 0x01;
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
    printf("A: 0x%02x \t", cpu->a);
    printf("X: 0x%02x \t", cpu->x);
    printf("Y: 0x%02x \t", cpu->y);
    printf("PSR: 0x%02x \t", cpu->psr);
    printf("SP: 0x%02x \t", cpu->sp);
    printf("PC: 0x%04x \t", cpu->pc);
    printf("\n");
}

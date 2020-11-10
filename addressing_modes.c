#include <stdio.h>
#include <stdint.h>

#include "mos6502_types.h"
#include "fetch_cycle.h"
#include "addressing_modes.h"

// opcode (1 byte)   = aaabbbcc
// cc_mask (1 byte)  = 00000011
// bbb_mask (1 byte) = 00011100
addr_mode get_addressing_mode(uint8_t opcode)
{
    uint8_t cc_mask = 0x03, bbb_mask = 0x1C;
    uint8_t cc = opcode & cc_mask;
    uint8_t bbb = opcode & bbb_mask;

    printf("Addressing Mode: ");
    printf("\033[1;35m");

    if (cc == 0x01)
    {
        switch (bbb)
        {
        case 0x00:
            printf("(zero page, X)\n");
            return &x_indirect;
            break;
        case 0x04:
            printf("zero page\n");
            return &zeropage;
            break;
        case 0x08:
            printf("#immediate\n");
            return &immediate;
            break;
        case 0x0c:
            printf("absolute\n");
            return &absolute;
            break;
        case 0x10:
            printf("(zero page), Y\n");
            return &indirect_y;
            break;
        case 0x14:
            printf("zero page, X\n");
            return &zeropage_x;
            break;
        case 0x18:
            printf("absolute, Y\n");
            return &absolute_y;
            break;
        case 0x1c:
            printf("absolute, X\n");
            return &absolute_x;
        default:
            break;
        }
    }
    else if (cc == 0x02)
    {
        switch (bbb)
        {
        case 0x00:
            printf("#immediate\n");
            return &immediate;
            break;
        case 0x04:
            printf("zero page\n");
            return &zeropage;
            break;
        case 0x08:
            if (opcode > 0x7A)
            {
                printf("implied\n");
                return &implied;
                break;
            }
            printf("accumulator\n");
            return &accumulator;
            break;
        case 0x18:
            if (opcode > 0x7A)
            {
                printf("implied\n");
                return &implied;
                break;
            }
            printf("accumulator\n");
            return &accumulator;
            break;
        case 0x0C:
            printf("absolute\n");
            return &absolute;
            break;
        case 0x14:
            if (opcode == 0xB6 || opcode == 0x96)
            {
                printf("zero page, Y\n");
                return &zeropage_y;
            }
            printf("zero page, X\n");
            return &zeropage_x;
            break;
        case 0x1C:
            if (opcode == 0xBE)
            {
                printf("absolute, Y\n");
                return &absolute_y;
            }
            printf("absolute, X\n");
            return &absolute_x;
            break;
        default:
            break;
        }
    }
    else if (cc == 0x00)
    {
        if (opcode == 0x20)
            return &absolute; // JSR
        if (opcode == 0x6c)
            return &indirect; // JSR
        switch (bbb)
        {
        case 0x00:
            printf("#immediate\n");
            return &immediate;
            break;
        case 0x04:
            printf("zero page\n");
            return &zeropage;
            break;
        case 0x0C:
            printf("absolute\n");
            return &absolute;
            break;
        case 0x14:
            printf("zero page, X\n");
            return &zeropage_x;
            break;
        case 0x1C:
            printf("absolute, X\n");
            return &absolute_x;
            break;
        case 0x08:
            printf("implied\n");
            return &implied;
        case 0x18:
            printf("implied\n");
            return &implied;
        case 0x10:
            printf("relative\n");
            return &relative;
        default:
            break;
        }
    }
    return NULL;
}

// 3 bytes
void absolute(Mos6502 *cpu, Memory *mem)
{
    uint8_t addr_l = mem->ram[cpu->pc];
    cpu->pc++;
    uint8_t addr_h = mem->ram[cpu->pc];
    cpu->pc++;
    cpu->addr = addr_h * 256 + addr_l;
}

// 1 byte
void accumulator(Mos6502 *cpu, Memory *mem)
{
}

// 3 bytes
void absolute_x(Mos6502 *cpu, Memory *mem)
{
    uint8_t addr_l = mem->ram[cpu->pc];
    cpu->pc++;
    uint8_t addr_h = mem->ram[cpu->pc];
    cpu->pc++;
    cpu->addr = addr_h * 256 + addr_l + cpu->x;
}

// 3 bytes
void absolute_y(Mos6502 *cpu, Memory *mem)
{
    uint8_t addr_l = mem->ram[cpu->pc];
    cpu->pc++;
    uint8_t addr_h = mem->ram[cpu->pc];
    cpu->pc++;
    cpu->addr = addr_h * 256 + addr_l + cpu->y;
}

// 2 bytes
void immediate(Mos6502 *cpu, Memory *mem)
{
    cpu->addr = cpu->pc;
    cpu->pc++;
}

// 1 byte
void implied(Mos6502 *cpu, Memory *mem)
{
}

// 3 bytes
void indirect(Mos6502 *cpu, Memory *mem)
{
    uint8_t addr_l = mem->ram[cpu->pc];
    cpu->pc++;
    uint8_t addr_h = mem->ram[cpu->pc];
    cpu->pc++;
    uint16_t addr = addr_h * 256 + addr_l;
    addr_l = mem->ram[addr];
    addr_h = mem->ram[addr + 0x0001];
    cpu->addr = addr_h * 256 + addr_l;
}

// 2 bytes
void x_indirect(Mos6502 *cpu, Memory *mem)
{
    uint8_t addr = mem->ram[cpu->pc] + cpu->x;
    uint8_t aux_l = mem->ram[addr];
    uint8_t aux_h = mem->ram[addr + 0x01];
    cpu->addr = aux_h * 256 + aux_l;
    cpu->pc++;
}

// 2 bytes
void indirect_y(Mos6502 *cpu, Memory *mem)
{
    uint8_t addr_l = mem->ram[mem->ram[cpu->pc]];
    uint8_t addr_h = mem->ram[mem->ram[cpu->pc] + 0x01];
    cpu->addr = addr_h * 256 + addr_l + cpu->y;
    cpu->pc++;
}

// 2 bytes
void relative(Mos6502 *cpu, Memory *mem)
{
    int8_t offset = mem->ram[cpu->pc];
    cpu->pc++;
    cpu->addr = cpu->pc + offset;
}

// 2 bytes
void zeropage(Mos6502 *cpu, Memory *mem)
{
    cpu->addr = mem->ram[cpu->pc];
    cpu->pc++;
}

// 2 bytes
void zeropage_x(Mos6502 *cpu, Memory *mem)
{
    cpu->addr = mem->ram[cpu->pc] + cpu->x;
    cpu->pc++;
}

// 2 bytes
void zeropage_y(Mos6502 *cpu, Memory *mem)
{
    cpu->addr = mem->ram[cpu->pc] + cpu->y;
    cpu->pc++;
}

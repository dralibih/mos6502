#include <stdio.h>
#include "mos6502_types.h"
#include "instruction_set.h"

instruction get_instruction(uint8_t opcode)
{
    if (opcode == 0x69 || opcode == 0x65 || opcode == 0x75 || opcode == 0x6D ||
        opcode == 0x7D || opcode == 0x7D || opcode == 0x79 || opcode == 0x61 ||
        opcode == 0x71)
        return &ADC;

    if (opcode == 0x29 || opcode == 0x25 || opcode == 0x35 || opcode == 0x2D ||
        opcode == 0x3D || opcode == 0x39 || opcode == 0x21 || opcode == 0x31)
        return &AND;

    if (opcode == 0x0A || opcode == 0x06 || opcode == 0x16 || opcode == 0x0E ||
        opcode == 0x1E)
        return &ASL;

    if (opcode == 0x90)
        return &BCC;

    if (opcode == 0xB0)
        return &BCS;

    if (opcode == 0xF0)
        return &BEQ;

    if (opcode == 0x24 || opcode == 0x2C)
        return &BIT;

    if (opcode == 0x30)
        return &BMI;

    if (opcode == 0xD0)
        return &BNE;

    if (opcode == 0x10)
        return &BPL;

    if (opcode == 0x00)
        return &BRK;

    if (opcode == 0x50)
        return &BVC;

    if (opcode == 0x70)
        return &BVS;

    if (opcode == 0x18)
        return &CLC;

    if (opcode == 0xD8)
        return &CLD;

    if (opcode == 0x58)
        return &CLI;

    if (opcode == 0xB8)
        return &CLV;

    if (opcode == 0xC9 || opcode == 0xC5 || opcode == 0xD5 || opcode == 0xCD ||
        opcode == 0xDD || opcode == 0xD9 || opcode == 0xC1 || opcode == 0xD1)
        return &CMP;

    if (opcode == 0xE0 || opcode == 0xE4 || opcode == 0xEC)
        return &CPX;

    if (opcode == 0xC0 || opcode == 0xC4 || opcode == 0xCC)
        return &CPY;

    if (opcode == 0xC6 || opcode == 0xD6 || opcode == 0xCE || opcode == 0xDE)
        return &DEC;

    if (opcode == 0xCA)
        return &DEX;

    if (opcode == 0x88)
        return &DEY;

    if (opcode == 0x49 || opcode == 0x45 || opcode == 0x55 || opcode == 0x4D ||
        opcode == 0x5D || opcode == 0x59 || opcode == 0x41 || opcode == 0x51)
        return &EOR;

    if (opcode == 0xE6 || opcode == 0xF6 || opcode == 0xEE || opcode == 0xFE)
        return &INC;

    if (opcode == 0xE8)
        return &INX;

    if (opcode == 0xC8)
        return &INY;

    if (opcode == 0x4C || opcode == 0x6C)
        return &JMP;

    if (opcode == 0x20)
        return &JSR;

    if (opcode == 0xA9 || opcode == 0xA5 || opcode == 0xB5 || opcode == 0xAD ||
        opcode == 0xBD || opcode == 0xB9 || opcode == 0xA1 || opcode == 0xB1)
        return &LDA;

    if (opcode == 0xA2 || opcode == 0xA6 || opcode == 0xB6 || opcode == 0xAE ||
        opcode == 0xBE)
        return &LDX;

    if (opcode == 0xA0 || opcode == 0xA4 || opcode == 0xB4 || opcode == 0xAC ||
        opcode == 0xBC)
        return &LDY;

    if (opcode == 0x4A || opcode == 0x46 || opcode == 0x56 || opcode == 0x4E ||
        opcode == 0x5E)
        return &LSR;

    if (opcode == 0xEA)
        return &NOP;

    if (opcode == 0x09 || opcode == 0x05 || opcode == 0x15 || opcode == 0x0D ||
        opcode == 0x1D || opcode == 0x19 || opcode == 0x01 || opcode == 0x11)
        return &ORA;

    if (opcode == 0x48)
        return &PHA;

    if (opcode == 0x08)
        return &PHP;

    if (opcode == 0x68)
        return &PLA;

    if (opcode == 0x28)
        return &PLP;

    if (opcode == 0x2A || opcode == 0x26 || opcode == 0x36 || opcode == 0x2E ||
        opcode == 0x3E)
        return &ROL;

    if (opcode == 0x6A || opcode == 0x66 || opcode == 0x76 || opcode == 0x6E ||
        opcode == 0x7E)
        return &ROR;

    if (opcode == 0x40)
        return &RTI;

    if (opcode == 0x60)
        return &RTS;

    if (opcode == 0xE9 || opcode == 0xE5 || opcode == 0xF5 || opcode == 0xED ||
        opcode == 0xED || opcode == 0xFD || opcode == 0xF9 || opcode == 0xE1 ||
        opcode == 0xF1)
        return &SBC;

    if (opcode == 0x38)
        return &SEC;

    if (opcode == 0xF8)
        return &SED;

    if (opcode == 0x78)
        return &SEI;

    if (opcode == 0x85 || opcode == 0x95 || opcode == 0x8D || opcode == 0x9D ||
        opcode == 0x99 || opcode == 0x81 || opcode == 0x91)
        return &STA;

    if (opcode == 0x86 || opcode == 0x96 || opcode == 0x8E)
        return &STX;

    if (opcode == 0x84 || opcode == 0x94 || opcode == 0x8C)
        return &STY;

    if (opcode == 0xAA)
        return &TAX;

    if (opcode == 0xA8)
        return &TAY;

    if (opcode == 0xBA)
        return &TSX;

    if (opcode == 0x8A)
        return &TXA;

    if (opcode == 0x9A)
        return &TXS;

    if (opcode == 0x98)
        return &TYA;

    return NULL;
}

void ADC(Mos6502 *cpu, Memory *mem)
{
    // 16 bits uint16_t
    int8_t sum = 0, cin = cpu->psr & flag_mask.carry, cout;
    int8_t a = cpu->a, b = mem->ram[cpu->addr];
    sum = a + b + cin;

    printf("%d %d", a, b);
    if (a > 0 && b > 0 && sum < 0) 
        cpu->psr |= flag_mask.overflow;
    else if (sum == 0) 
        cpu->psr |= flag_mask.zero;
    else if (sum < 0)
        cpu->psr |= flag_mask.negative;
    cout = sum >> 7;
    if (cout == 0) 
        cpu->psr &= ~(0x01);
    else
        cpu->psr |= 0x01;
    cpu->a = sum;
}

// checked
void AND(Mos6502 *cpu, Memory *mem)
{
    uint8_t aux = mem->ram[cpu->addr];
    cpu->a &= aux;
    // Flags
    if (cpu->a == 0)
        cpu->psr &= flag_mask.zero;
    if ((cpu->a & flag_mask.negative) == flag_mask.negative)
        cpu->psr &= flag_mask.negative;
}

// checked
void ASL(Mos6502 *cpu, Memory *mem)
{
    uint8_t aux;
    if ((cpu->inst & 0x1C) == 0x08)
        aux = cpu->a;
    else
        aux = mem->ram[cpu->addr];

    uint8_t carry = aux & 0x80;
    aux <<= 1;

    // Flags
    cpu->psr |= carry;
    if (aux == 0)
        cpu->psr &= flag_mask.zero;
    if ((aux & flag_mask.negative) == flag_mask.negative)
        cpu->psr &= flag_mask.negative;

    if ((cpu->inst & 0x1C) == 0x08)
    {
        cpu->a = aux;
    }
    else
    {
        mem->ram[cpu->addr] = aux;
    }
}

// checked
void BCC(Mos6502 *cpu, Memory *mem)
{
    if ((cpu->psr & flag_mask.carry) != flag_mask.carry)
        cpu->pc = cpu->addr;
}

// checked
void BCS(Mos6502 *cpu, Memory *mem)
{
    if ((cpu->psr & flag_mask.carry) == flag_mask.carry)
        cpu->pc = cpu->addr;
}

// checked
void BEQ(Mos6502 *cpu, Memory *mem)
{
    if ((cpu->psr & flag_mask.zero) == flag_mask.zero)
        cpu->pc = cpu->addr;
}

// checked
void BIT(Mos6502 *cpu, Memory *mem)
{
    uint8_t aux = mem->ram[cpu->addr];
    uint8_t b6 = aux & flag_mask.overflow;
    uint8_t b7 = aux & flag_mask.negative;

    // Flags
    cpu->psr = (cpu->psr | b6) | b7;
    if ((cpu->a & aux) == 0)
        cpu->psr += flag_mask.zero;
}

// checked
void BMI(Mos6502 *cpu, Memory *mem)
{
    if ((cpu->psr & flag_mask.negative) == flag_mask.negative)
        cpu->pc = cpu->addr;
}

// checked
void BNE(Mos6502 *cpu, Memory *mem)
{
    if ((cpu->psr & flag_mask.zero) != flag_mask.zero)
        cpu->pc = cpu->addr;
}

// checked
void BPL(Mos6502 *cpu, Memory *mem)
{
    if ((cpu->psr & flag_mask.negative) != flag_mask.negative)
        cpu->pc = cpu->addr;
}

// checked
void BRK(Mos6502 *cpu, Memory *mem)
{
    cpu->psr |= flag_mask.break_cmd;
    cpu->psr |= flag_mask.int_disable;
    cpu->sp--;
    mem->ram[cpu->sp] = (cpu->pc + 1) >> 8;
    cpu->sp--;
    mem->ram[cpu->sp] = (cpu->pc + 1);
    cpu->sp--;
    mem->ram[cpu->sp] = cpu->psr;
}

// checked
void BVC(Mos6502 *cpu, Memory *mem)
{
    if ((cpu->psr & flag_mask.overflow) != flag_mask.overflow)
        cpu->pc = cpu->addr;
}

// checked
void BVS(Mos6502 *cpu, Memory *mem)
{
    if ((cpu->psr & flag_mask.overflow) == flag_mask.overflow)
        cpu->pc = cpu->addr;
}

// checked
void CLC(Mos6502 *cpu, Memory *mem)
{
    cpu->psr &= ~flag_mask.carry;
}

// checked
void CLD(Mos6502 *cpu, Memory *mem)
{
    cpu->psr &= ~flag_mask.decimal_mode;
}

// checked
void CLI(Mos6502 *cpu, Memory *mem)
{
    cpu->psr &= ~flag_mask.int_disable;
}

// checked
void CLV(Mos6502 *cpu, Memory *mem)
{
    cpu->psr &= ~flag_mask.overflow;
}

// checked
void CMP(Mos6502 *cpu, Memory *mem)
{
    if (cpu->a < mem->ram[cpu->addr])
    {
        cpu->psr |= flag_mask.negative;
    }
    else if (cpu->a == mem->ram[cpu->addr])
    {
        cpu->psr |= flag_mask.zero;
        cpu->psr |= flag_mask.carry;
    }
    else if (cpu->a == mem->ram[cpu->addr])
    {
        cpu->psr |= flag_mask.carry;
    }
}

// checked
void CPX(Mos6502 *cpu, Memory *mem)
{
    if (cpu->x < mem->ram[cpu->addr])
    {
        cpu->psr |= flag_mask.negative;
    }
    else if (cpu->x == mem->ram[cpu->addr])
    {
        cpu->psr |= flag_mask.zero;
        cpu->psr |= flag_mask.carry;
    }
    else if (cpu->x == mem->ram[cpu->addr])
    {
        cpu->psr |= flag_mask.carry;
    }
}

// checked
void CPY(Mos6502 *cpu, Memory *mem)
{
    if (cpu->y < mem->ram[cpu->addr])
    {
        cpu->psr |= flag_mask.negative;
    }
    else if (cpu->y == mem->ram[cpu->addr])
    {
        cpu->psr |= flag_mask.zero;
        cpu->psr |= flag_mask.carry;
    }
    else if (cpu->y == mem->ram[cpu->addr])
    {
        cpu->psr |= flag_mask.carry;
    }
}

// checked
void DEC(Mos6502 *cpu, Memory *mem)
{
    mem->ram[cpu->addr]--;

    // Flags
    if (mem->ram[cpu->addr] == 0)
        cpu->psr |= flag_mask.zero;
    if (mem->ram[cpu->addr] < 0)
        cpu->psr |= flag_mask.negative;
}

// checked
void DEX(Mos6502 *cpu, Memory *mem)
{
    cpu->x--;

    // Flags
    if (cpu->x == 0)
        cpu->psr |= flag_mask.zero;
    if (cpu->x < 0)
        cpu->psr |= flag_mask.negative;
}

// checked
void DEY(Mos6502 *cpu, Memory *mem)
{
    cpu->y--;

    // Flags
    if (cpu->y == 0)
        cpu->psr |= flag_mask.zero;
    if (cpu->y < 0)
        cpu->psr |= flag_mask.negative;
}

// checked
void EOR(Mos6502 *cpu, Memory *mem)
{
    cpu->a ^= mem->ram[cpu->addr];

    // Flags
    if (cpu->a == 0)
        cpu->psr |= flag_mask.zero;
    if (cpu->a < 0)
        cpu->psr |= flag_mask.negative;
}

// checked
void INC(Mos6502 *cpu, Memory *mem)
{
    mem->ram[cpu->addr]++;

    // Flags
    if (mem->ram[cpu->addr] == 0)
        cpu->psr |= flag_mask.zero;
    if (mem->ram[cpu->addr] < 0)
        cpu->psr |= flag_mask.negative;
}

// checked
void INX(Mos6502 *cpu, Memory *mem)
{
    cpu->x++;

    // Flags
    if (cpu->x == 0)
        cpu->psr |= flag_mask.zero;
    if (cpu->x < 0)
        cpu->psr |= flag_mask.negative;
}

// checked
void INY(Mos6502 *cpu, Memory *mem)
{
    cpu->y++;

    // Flags
    if (cpu->y == 0)
        cpu->psr |= flag_mask.zero;
    if (cpu->y < 0)
        cpu->psr |= flag_mask.negative;
}

// checked
void JMP(Mos6502 *cpu, Memory *mem)
{
    cpu->pc = cpu->addr;
}

// checked
void JSR(Mos6502 *cpu, Memory *mem)
{
    cpu->sp--;
    mem->ram[cpu->sp] = cpu->pc >> 8;
    cpu->sp--;
    mem->ram[cpu->sp] = cpu->pc;
    JMP(cpu, mem);
}

// checked
void LDA(Mos6502 *cpu, Memory *mem)
{
    cpu->a = mem->ram[cpu->addr];

    // Flags
    if (cpu->a == 0)
        cpu->psr |= flag_mask.zero;
    if (cpu->a < 0)
        cpu->psr |= flag_mask.negative;
}

// checked
void LDX(Mos6502 *cpu, Memory *mem)
{
    cpu->x = mem->ram[cpu->addr];

    // Flags
    if (cpu->x == 0)
        cpu->psr |= flag_mask.zero;
    if (cpu->x < 0)
        cpu->psr |= flag_mask.negative;
}

// checked
void LDY(Mos6502 *cpu, Memory *mem)
{
    cpu->y = mem->ram[cpu->addr];

    // Flags
    if (cpu->y == 0)
        cpu->psr |= flag_mask.zero;
    if (cpu->y < 0)
        cpu->psr |= flag_mask.negative;
}

// checked
void LSR(Mos6502 *cpu, Memory *mem)
{
    uint8_t aux;
    if ((cpu->inst & 0x1C) == 0x08)
        aux = cpu->a;
    else
        aux = mem->ram[cpu->addr];

    uint8_t carry = aux & 0x01;
    aux >>= 1;

    // Flags
    cpu->psr |= carry;
    cpu->psr &= ~flag_mask.negative;
    if (aux == 0)
        cpu->psr |= flag_mask.zero;

    if ((cpu->inst & 0x1C) == 0x08)
        cpu->a = aux;
    else
        mem->ram[cpu->addr] = aux;
}

// checked
void NOP(Mos6502 *cpu, Memory *mem)
{
}

// checked
void ORA(Mos6502 *cpu, Memory *mem)
{
    cpu->a |= mem->ram[cpu->addr];

    // Flags
    if (cpu->a == 0)
        cpu->psr |= flag_mask.zero;
    if (cpu->a < 0)
        cpu->psr |= flag_mask.negative;
}

// checked
void PHA(Mos6502 *cpu, Memory *mem)
{
    cpu->sp--;
    mem->ram[cpu->sp] = cpu->a;
}

// checked
void PHP(Mos6502 *cpu, Memory *mem)
{
    cpu->sp--;
    mem->ram[cpu->sp] = cpu->psr;
}

// checked
void PLA(Mos6502 *cpu, Memory *mem)
{
    cpu->a = mem->ram[cpu->sp];
    cpu->sp++;
}

// checked
void PLP(Mos6502 *cpu, Memory *mem)
{
    cpu->psr = mem->ram[cpu->sp];
    cpu->sp++;
}

// checked
void ROL(Mos6502 *cpu, Memory *mem)
{
    uint8_t bit;
    if ((cpu->inst & 0x1C) == 0x08)
    {
        bit = (cpu->a >> 7) & 0x01;
        cpu->a <<= 1;
        cpu->a |= bit;
    }
    else
    {
        bit = (mem->ram[cpu->addr] >> 7) & 0x01;
        mem->ram[cpu->addr] <<= 1;
        mem->ram[cpu->addr] |= bit;
    }
}

// checked
void ROR(Mos6502 *cpu, Memory *mem)
{
    uint8_t bit;
    if ((cpu->inst & 0x1C) == 0x08)
    {
        bit = cpu->a & 0x01;
        cpu->a = (cpu->a >> 1) & (~(1 << 7));
        cpu->a |= (bit << 7);
    }
    else
    {
        bit = mem->ram[cpu->addr] & 0x01;
        mem->ram[cpu->addr] = (mem->ram[cpu->addr] >> 1) & (~(1 << 7));
        mem->ram[cpu->addr] |= bit;
    }
}

// checked
void RTI(Mos6502 *cpu, Memory *mem)
{
    cpu->psr = mem->ram[cpu->sp];
    cpu->sp++;
    uint8_t pc_l = mem->ram[cpu->sp];
    cpu->sp++;
    uint8_t pc_h = mem->ram[cpu->sp];
    cpu->sp++;
    cpu->pc = pc_h * 256 + pc_l;
}

// checked
void RTS(Mos6502 *cpu, Memory *mem)
{
    uint8_t pc_l = mem->ram[cpu->sp];
    cpu->sp++;
    uint8_t pc_h = mem->ram[cpu->sp];
    cpu->sp++;
    cpu->pc = pc_h * 256 + pc_l + 1;
}

void SBC(Mos6502 *cpu, Memory *mem)
{
}

// checked
void SEC(Mos6502 *cpu, Memory *mem)
{
    cpu->psr |= flag_mask.carry;
}

// checked
void SED(Mos6502 *cpu, Memory *mem)
{
    cpu->psr |= flag_mask.decimal_mode;
}

// checked
void SEI(Mos6502 *cpu, Memory *mem)
{
    cpu->psr |= flag_mask.int_disable;
}

// checked
void STA(Mos6502 *cpu, Memory *mem)
{
    mem->ram[cpu->addr] = cpu->a;
}

// checked
void STX(Mos6502 *cpu, Memory *mem)
{
    mem->ram[cpu->addr] = cpu->x;
}

// checked
void STY(Mos6502 *cpu, Memory *mem)
{
    mem->ram[cpu->addr] = cpu->y;
}

// checked
void TAX(Mos6502 *cpu, Memory *men)
{
    cpu->x = cpu->a;

    // Flags
    if (cpu->x == 0)
        cpu->psr |= flag_mask.zero;
    if (cpu->x < 0)
        cpu->psr |= flag_mask.negative;
}

// checked
void TAY(Mos6502 *cpu, Memory *men)
{
    cpu->y = cpu->x;

    // Flags
    if (cpu->y == 0)
        cpu->psr |= flag_mask.zero;
    if (cpu->y < 0)
        cpu->psr |= flag_mask.negative;
}

// checked
void TSX(Mos6502 *cpu, Memory *men)
{
    cpu->x = cpu->sp;

    // Flags
    if (cpu->x == 0)
        cpu->psr |= flag_mask.zero;
    if (cpu->x < 0)
        cpu->psr |= flag_mask.negative;
}

// checked
void TXA(Mos6502 *cpu, Memory *men)
{
    cpu->a = cpu->x;

    // Flags
    if (cpu->a == 0)
        cpu->psr |= flag_mask.zero;
    if (cpu->a < 0)
        cpu->psr |= flag_mask.negative;
}

// checked
void TXS(Mos6502 *cpu, Memory *men)
{
    cpu->sp = cpu->x;
}

// checked
void TYA(Mos6502 *cpu, Memory *men)
{
    cpu->a = cpu->y;

    // Flags
    if (cpu->a == 0)
        cpu->psr |= flag_mask.zero;
    if (cpu->a < 0)
        cpu->psr |= flag_mask.negative;
}

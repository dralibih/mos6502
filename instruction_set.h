#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include <stdint.h>
#include "mos6502_types.h"

typedef void (*instruction)(Mos6502 *cpu, Memory *mem);

instruction get_instruction(uint8_t opcode);

void ADC(Mos6502 *cpu, Memory *mem); // A + M + C -> A, C
void AND(Mos6502 *cpu, Memory *mem); // A AND M -> A
void ASL(Mos6502 *cpu, Memory *mem); // C <- [76543210] <- 0
void BCC(Mos6502 *cpu, Memory *mem); // Branch on C = 0
void BCS(Mos6502 *cpu, Memory *mem); // Branch on C = 1
void BEQ(Mos6502 *cpu, Memory *mem); // Branch on Z = 1
void BIT(Mos6502 *cpu, Memory *mem); //
void BMI(Mos6502 *cpu, Memory *mem); // a <- mem
void BNE(Mos6502 *cpu, Memory *mem); // a <- mem
void BPL(Mos6502 *cpu, Memory *mem); // a <- mem
void BRK(Mos6502 *cpu, Memory *mem); // a <- mem
void BVC(Mos6502 *cpu, Memory *mem); // a <- mem
void BVS(Mos6502 *cpu, Memory *mem); // a <- mem
void CLC(Mos6502 *cpu, Memory *mem); // a <- mem
void CLD(Mos6502 *cpu, Memory *mem); // a <- mem
void CLI(Mos6502 *cpu, Memory *mem); // a <- mem
void CLV(Mos6502 *cpu, Memory *mem); // a <- mem
void CMP(Mos6502 *cpu, Memory *mem); // a <- mem
void CPX(Mos6502 *cpu, Memory *mem); // a <- mem
void CPY(Mos6502 *cpu, Memory *mem); // a <- mem
void DEC(Mos6502 *cpu, Memory *mem); // a <- mem
void DEX(Mos6502 *cpu, Memory *mem); // a <- mem
void DEY(Mos6502 *cpu, Memory *mem); // a <- mem
void EOR(Mos6502 *cpu, Memory *mem); // a <- mem
void INC(Mos6502 *cpu, Memory *mem); // a <- mem
void INX(Mos6502 *cpu, Memory *mem); // a <- mem
void INY(Mos6502 *cpu, Memory *mem); // a <- mem
void JMP(Mos6502 *cpu, Memory *mem); // a <- mem
void JSR(Mos6502 *cpu, Memory *mem); // a <- mem
void LDA(Mos6502 *cpu, Memory *mem); // a <- mem
void LDY(Mos6502 *cpu, Memory *mem); // a <- mem
void LDX(Mos6502 *cpu, Memory *mem); // a <- mem
void LSR(Mos6502 *cpu, Memory *mem); // a <- mem
void NOP(Mos6502 *cpu, Memory *mem); // a <- mem
void ORA(Mos6502 *cpu, Memory *mem); // a <- mem
void PHA(Mos6502 *cpu, Memory *mem); // a <- mem
void PHP(Mos6502 *cpu, Memory *mem); // a <- mem
void PLA(Mos6502 *cpu, Memory *mem); // a <- mem
void PLP(Mos6502 *cpu, Memory *mem); // a <- mem
void ROL(Mos6502 *cpu, Memory *mem); // a <- mem
void ROR(Mos6502 *cpu, Memory *mem); // a <- mem
void RTI(Mos6502 *cpu, Memory *mem); // a <- mem
void RTS(Mos6502 *cpu, Memory *mem); // a <- mem
void SBC(Mos6502 *cpu, Memory *mem); // a <- mem
void SEC(Mos6502 *cpu, Memory *mem); // a <- mem
void SED(Mos6502 *cpu, Memory *mem); // a <- mem
void SEI(Mos6502 *cpu, Memory *mem); // a <- mem
void STA(Mos6502 *cpu, Memory *men); // mem <- a
void STX(Mos6502 *cpu, Memory *men); // mem <- x
void STY(Mos6502 *cpu, Memory *men); // mem <- y
void TAX(Mos6502 *cpu, Memory *men); // mem <- y
void TAY(Mos6502 *cpu, Memory *men); // mem <- y
void TSX(Mos6502 *cpu, Memory *men); // mem <- y
void TXA(Mos6502 *cpu, Memory *men); // mem <- y
void TXS(Mos6502 *cpu, Memory *men); // mem <- y
void TYA(Mos6502 *cpu, Memory *men); // mem <- y

#endif

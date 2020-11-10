#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include <stdint.h>
#include "mos6502_types.h"

typedef void (*instruction)(Mos6502 *cpu, Memory *mem);

instruction get_instruction(uint8_t opcode);

void ADC(Mos6502 *cpu, Memory *mem); 
void AND(Mos6502 *cpu, Memory *mem);
void ASL(Mos6502 *cpu, Memory *mem);
void BCC(Mos6502 *cpu, Memory *mem);
void BCS(Mos6502 *cpu, Memory *mem);
void BEQ(Mos6502 *cpu, Memory *mem);
void BIT(Mos6502 *cpu, Memory *mem);
void BMI(Mos6502 *cpu, Memory *mem);
void BNE(Mos6502 *cpu, Memory *mem);
void BPL(Mos6502 *cpu, Memory *mem);
void BRK(Mos6502 *cpu, Memory *mem);
void BVC(Mos6502 *cpu, Memory *mem);
void BVS(Mos6502 *cpu, Memory *mem);
void CLC(Mos6502 *cpu, Memory *mem);
void CLD(Mos6502 *cpu, Memory *mem);
void CLI(Mos6502 *cpu, Memory *mem);
void CLV(Mos6502 *cpu, Memory *mem);
void CMP(Mos6502 *cpu, Memory *mem);
void CPX(Mos6502 *cpu, Memory *mem);
void CPY(Mos6502 *cpu, Memory *mem);
void DEC(Mos6502 *cpu, Memory *mem);
void DEX(Mos6502 *cpu, Memory *mem);
void DEY(Mos6502 *cpu, Memory *mem);
void EOR(Mos6502 *cpu, Memory *mem);
void INC(Mos6502 *cpu, Memory *mem);
void INX(Mos6502 *cpu, Memory *mem);
void INY(Mos6502 *cpu, Memory *mem);
void JMP(Mos6502 *cpu, Memory *mem);
void JSR(Mos6502 *cpu, Memory *mem);
void LDA(Mos6502 *cpu, Memory *mem);
void LDY(Mos6502 *cpu, Memory *mem);
void LDX(Mos6502 *cpu, Memory *mem);
void LSR(Mos6502 *cpu, Memory *mem);
void NOP(Mos6502 *cpu, Memory *mem);
void ORA(Mos6502 *cpu, Memory *mem);
void PHA(Mos6502 *cpu, Memory *mem);
void PHP(Mos6502 *cpu, Memory *mem);
void PLA(Mos6502 *cpu, Memory *mem);
void PLP(Mos6502 *cpu, Memory *mem);
void ROL(Mos6502 *cpu, Memory *mem);
void ROR(Mos6502 *cpu, Memory *mem);
void RTI(Mos6502 *cpu, Memory *mem);
void RTS(Mos6502 *cpu, Memory *mem);
void SBC(Mos6502 *cpu, Memory *mem);
void SEC(Mos6502 *cpu, Memory *mem);
void SED(Mos6502 *cpu, Memory *mem);
void SEI(Mos6502 *cpu, Memory *mem);
void STA(Mos6502 *cpu, Memory *men);
void STX(Mos6502 *cpu, Memory *men);
void STY(Mos6502 *cpu, Memory *men);
void TAX(Mos6502 *cpu, Memory *men);
void TAY(Mos6502 *cpu, Memory *men);
void TSX(Mos6502 *cpu, Memory *men);
void TXA(Mos6502 *cpu, Memory *men);
void TXS(Mos6502 *cpu, Memory *men);
void TYA(Mos6502 *cpu, Memory *men);

#endif

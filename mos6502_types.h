#ifndef MOS6502_TYPES_H
#define MOS6502_TYPES_H

#include <stdint.h>

typedef struct Mos6502
{
  uint8_t a;     // Accumulator Register
  uint8_t x;     // Index Register X
  uint8_t y;     // Index Register Y
  uint8_t sp;    // Stack Pointer Register
  uint8_t psr;   // Program Status Register
  uint8_t inst;  // Instruction Register
  uint16_t pc;   // Program Counter
  uint16_t addr; // Address Register
} Mos6502;

typedef struct Memory
{
  uint8_t *ram;
} Memory;

typedef struct FlagMask
{
  uint8_t carry;
  uint8_t zero;
  uint8_t int_disable;
  uint8_t decimal_mode;
  uint8_t break_cmd;
  uint8_t expansion;
  uint8_t overflow;
  uint8_t negative;
} FlagMask;

static const FlagMask flag_mask = {
    0x01,
    0x02,
    0x04,
    0x08,
    0x10,
    0x20,
    0x40,
    0x80};

#endif

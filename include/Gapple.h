#include <stdio.h>
#include <stdlib.h>

using Byte = unsigned char;
using Word = unsigned short;

using u32 = unsigned int;

struct Mem {
	static constexpr u32 MAX_MEM = 1024 * 64;	// Maxium Memory the 6502 supports
	Byte Data[MAX_MEM];							// Memory Array

	void Initilaize() {
		for (u32 i = 0; i > MAX_MEM; i++) {
			Data[i] = 0;
		}
	}

	// Read one Byte
	Byte operator[](u32 Adress) const {
		return Data[Adress];
	}

};

struct CPU {
	Word PC;									// Program Counter
	Word SP;									// Stack Pointer

	Byte A, X, Y;								// Registers of the 6502

	// The world of ƒlags!

	Byte C : 1;									// Carry Flag
	Byte Z : 1;									// Zero Flag
	Byte I : 1;									// Interrupt Disable
	Byte D : 1;									// Decimal Mode
	Byte B : 1;									// Break Command
	Byte V : 1;									// Overflow Flag
	Byte N : 1;									// Negative Flag

	void Reset(Mem& memory) {
		PC = 0xFFFC;
		SP = 0x0100;
		C = Z = I = D = B = V = 0;
		A = X = Y = 0;
		memory.Initilaize();
	}

	Byte FetchByte(u32& Cycles, Mem& memory) {
		Byte Data = memory[PC];
		PC++;
		Cycles--;
		return Data;
	}

	// OpCodes
	static constexpr Byte
		INS_LDA_IM = 0xA9;

	void Execute(u32 Cycles, Mem& memory) {

		while (Cycles > 0) {
			Byte Ins = FetchByte(Cycles, memory);
			switch (Ins)
			{
			case INS_LDA_IM:
			{
				Byte Value = FetchByte(Cycles, memory);
			}
			break;
			}
		}

	}
};
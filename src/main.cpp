#include <iostream>
#include "../include/Gapple.h"

int main(int argc, char argv[]) {

	if (argc != 1) {
		std::cout << "Invalid Usage! Usage: gapple" << std::endl;
	}

	CPU cpu;
	Mem mem;
	cpu.Reset(mem);
	cpu.Execute(2, mem);
	return 0;
}
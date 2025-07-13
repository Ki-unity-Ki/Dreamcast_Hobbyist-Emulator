// dreamcast_emulator.cpp
#include <iostream>
#include <vector>
#include <cstdint>

// A minimal skeleton showing CPU cycle loop and memory map.
class DreamcastEmulator {
public:
    static constexpr size_t RAM_SIZE = 8 * 1024 * 1024; // 8 MB
    std::vector<uint8_t> ram;

    DreamcastEmulator(): ram(RAM_SIZE, 0) {}

    void loadROM(const std::vector<uint8_t>& rom) {
        size_t n = std::min(rom.size(), ram.size());
        std::copy(rom.begin(), rom.begin()+n, ram.begin());
        std::cout << "ROM loaded (" << n << " bytes)\n";
    }

    void run() {
        uint32_t pc = 0;
        for (int cycle = 0; cycle < 1000; ++cycle) {
            uint8_t opcode = ram[pc];
            // Simplified: pretend 0x00 = NOP, 0xFF = HALT
            if (opcode == 0xFF) {
                std::cout << "HALT at cycle " << cycle << ", pc=" << pc << "\n";
                break;
            }
            pc = (pc + 1) % RAM_SIZE;
        }
    }
};

int main(int argc, char* argv[]) {
    DreamcastEmulator emu;
    std::vector<uint8_t> dummyROM(1024, 0x00);
    dummyROM.back() = 0xFF;
    emu.loadROM(dummyROM);
    emu.run();
    return 0;
}

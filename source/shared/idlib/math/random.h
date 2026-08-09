#pragma once

#include <cstdint>

class idRandom {
public:
    static const int MAX_RAND = 0x7FFF;

    int seed;

    explicit idRandom(const int initialSeed = 0) : seed(initialSeed) {}
    void SetSeed(const int value) { seed = value; }
    int GetSeed() const { return seed; }

    int RandomInt() {
        seed = static_cast<int>(1103515245u * static_cast<unsigned int>(seed) + 12345u);
        return (static_cast<unsigned int>(seed) >> 16) & MAX_RAND;
    }

    int RandomInt(const int max) {
        return max == 0 ? 0 : RandomInt() % max;
    }

    float RandomFloat() { return RandomInt() * (1.0f / 32768.0f); }
    float CRandomFloat() { return 2.0f * RandomFloat() - 1.0f; }
};

class idRandom2 {
public:
    static const int MAX_RAND = 0x7FFF;

    unsigned int seed;

    explicit idRandom2(const unsigned int initialSeed = 0) : seed(initialSeed) {}
    void SetSeed(const unsigned int value) { seed = value; }
    unsigned int GetSeed() const { return seed; }

    int RandomInt() {
        seed = 1664525u * seed + 1013904223u;
        return static_cast<int>((seed >> 10) & MAX_RAND);
    }

    int RandomInt(const int max) {
        return max == 0 ? 0 : RandomInt() % max;
    }

    int RandomInt(const int min, const int max) {
        return min >= max ? min : min + RandomInt(max - min + 1);
    }

    float RandomFloat() { return RandomInt() * (1.0f / 32768.0f); }
    float CRandomFloat() { return 2.0f * RandomFloat() - 1.0f; }

    float BellCurve(const int degree) {
        if (degree <= 0) return 0.0f;
        float sum = 0.0f;
        for (int index = 0; index < degree; ++index) sum += CRandomFloat();
        return sum / static_cast<float>(degree);
    }
};

class idRandomMersenneCyclic {
public:
    unsigned int MT[624];
};

class idRandomWELL1024 {
public:
    unsigned int seedArray[32];
    unsigned int state_i;
    unsigned int STATE[32];
};

class idRandomMersenne {
public:
    unsigned int MT[624];
    unsigned int index;

    explicit idRandomMersenne(const unsigned int seed = 5489u) {
        SetSeed(seed);
    }

    void SetSeed(const unsigned int seed) {
        MT[0] = seed;
        for (unsigned int i = 1; i < 624; ++i) {
            MT[i] = 1812433253u * (MT[i - 1] ^ (MT[i - 1] >> 30)) + i;
        }
        index = 624;
    }

    void GenerateNumbers() {
        static const unsigned int mag01[2] = { 0u, 0x9908B0DFu };
        for (unsigned int i = 0; i < 227; ++i) {
            const unsigned int value = (MT[i] & 0x80000000u)
                | (MT[i + 1] & 0x7FFFFFFEu);
            MT[i] = MT[i + 397] ^ (value >> 1) ^ mag01[value & 1u];
        }
        for (unsigned int i = 227; i < 623; ++i) {
            const unsigned int value = (MT[i] & 0x80000000u)
                | (MT[i + 1] & 0x7FFFFFFEu);
            MT[i] = MT[i - 227] ^ (value >> 1) ^ mag01[value & 1u];
        }
        const unsigned int value = (MT[623] & 0x80000000u)
            | (MT[0] & 0x7FFFFFFEu);
        MT[623] = MT[396] ^ (value >> 1) ^ mag01[value & 1u];
    }

    unsigned int RandomInt() {
        if (index >= 624) {
            index = 0;
            GenerateNumbers();
        }
        unsigned int value = MT[index++];
        value ^= value >> 11;
        value ^= (value << 7) & 0x9D2C5680u;
        value ^= (value << 15) & 0xEFC60000u;
        value ^= value >> 18;
        return value;
    }
};

using idRandomType = idRandom2;

static_assert(sizeof(idRandom) == 4, "Recovered idRandom ABI changed");
static_assert(sizeof(idRandom2) == 4, "Recovered idRandom2 ABI changed");
static_assert(sizeof(idRandomMersenneCyclic) == 2496,
    "Recovered idRandomMersenneCyclic ABI changed");
static_assert(sizeof(idRandomWELL1024) == 260,
    "Recovered idRandomWELL1024 ABI changed");
static_assert(sizeof(idRandomMersenne) == 2500,
    "Recovered idRandomMersenne ABI changed");

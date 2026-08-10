#pragma once

#include "coveractions.h"

class alignas(4) idCoverCapabilities : public idCoverActions {
public:
    idCoverCapabilities() : capabilityBits(0) {}
    ~idCoverCapabilities() override = default;

    void Clear() override {
        idCoverActions::Clear();
        capabilityBits &= 0x01u;
    }

    bool HasCapability(const idCoverCapabilities& other) const {
        return (actionBits & other.actionBits & 0xF8u) != 0
            || (capabilityBits & other.capabilityBits & 0xFEu) != 0;
    }

    bool HasCapability(const idCoverActions& other) const {
        idCoverCapabilities promoted;
        promoted.Promote(other);
        return HasCapability(promoted);
    }

    int NumMatchingCapabilities(const idCoverCapabilities& other) const {
        const unsigned actionDifference =
            (actionBits ^ other.actionBits) & 0xF8u;
        const unsigned capabilityDifference =
            (capabilityBits ^ other.capabilityBits) & 0xFEu;
        int matches = 12;
        for (unsigned bit = 0x08u; bit <= 0x80u; bit <<= 1u) {
            if ((actionDifference & bit) != 0) --matches;
        }
        for (unsigned bit = 0x02u; bit <= 0x80u; bit <<= 1u) {
            if ((capabilityDifference & bit) != 0) --matches;
        }
        return matches;
    }

    void Promote(const idCoverActions& actions) {
        actionBits = static_cast<std::uint8_t>(
            (actionBits & 0x07u) | (actions.actionBits & 0xF8u));
        const std::uint8_t input = actions.actionBits;
        capabilityBits = static_cast<std::uint8_t>(
            (capabilityBits & 0x01u)
            | ((input & 0x40u) << 1u)
            | ((input & 0x10u) << 2u)
            | ((input & 0x80u) >> 2u)
            | ((input & 0x40u) >> 2u)
            | ((input & 0x10u) >> 1u)
            | ((input & 0x80u) >> 5u)
            | 0x02u);
    }

    // Bits 1..7 are hide, peek-over/right/left, blindfire-over/right/left.
    std::uint8_t capabilityBits;
};

class idAICoverCapabilities {
public:
    idCoverCapabilities crouchCaps;
    idCoverCapabilities fullCaps;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idCoverCapabilities) == 12,
    "Recovered cover-capability ABI changed");
static_assert(sizeof(idAICoverCapabilities) == 24,
    "Recovered posture cover-capability ABI changed");
#endif

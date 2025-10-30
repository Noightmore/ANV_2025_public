//
// Created by rob on 10/22/25.
//

#include "CafeConfig.h"

#include <cstdint>


// Singleton instance implementation
CafeConfig& CafeConfig::getInstance() {
    static CafeConfig instance; // static means shared across all class objects
    return instance;
}

// Getter implementation
std::string_view CafeConfig::getCafeName() {
    return cafeName; // + &instance;
}


// Setter implementation (optional - not in your original Java code)
// void CafeConfig::setCafeName(std::string_view newName) {
//     cafeName = newName;
// }
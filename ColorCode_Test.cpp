#include "ColorCode.h"
#include <iostream>
#include <assert.h>
#include <sstream>  // for string comparison

void testNumberToPair(int pairNumber, TelCoColorCoder::MajorColor expectedMajor, TelCoColorCoder::MinorColor expectedMinor) {
    auto colorPair = TelCoColorCoder::GetColorFromPairNumber(pairNumber);
    assert(colorPair.getMajor() == expectedMajor && colorPair.getMinor() == expectedMinor);
}

void testPairToNumber(TelCoColorCoder::MajorColor major, TelCoColorCoder::MinorColor minor, int expectedPairNumber) {
    assert(TelCoColorCoder::GetPairNumberFromColor(major, minor) == expectedPairNumber);
}

void testManualGeneration() {
    std::string manual = TelCoColorCoder::GenerateReferenceManual();
    std::ostringstream expectedManual;
    const char* expectedEntries[] = {
        "White Blue", "White Orange", "White Green", "White Brown", "White Slate", "Red Blue", "Red Orange", "Red Green", "Red Brown", "Red Slate",
        "Black Blue", "Black Orange", "Black Green", "Black Brown", "Black Slate", "Yellow Blue", "Yellow Orange", "Yellow Green", "Yellow Brown", "Yellow Slate",
        "Violet Blue", "Violet Orange", "Violet Green", "Violet Brown", "Violet Slate"
    };
    for (int i = 0; i < 25; ++i) expectedManual << i + 1 << ": " << expectedEntries[i] << "\n";
    assert(manual == expectedManual.str());
}

int main() {
    testNumberToPair(4, TelCoColorCoder::WHITE, TelCoColorCoder::BROWN);
    testNumberToPair(5, TelCoColorCoder::WHITE, TelCoColorCoder::SLATE);
    testPairToNumber(TelCoColorCoder::BLACK, TelCoColorCoder::ORANGE, 12);
    testPairToNumber(TelCoColorCoder::VIOLET, TelCoColorCoder::SLATE, 25);
    testManualGeneration();
    
    return 0;
}

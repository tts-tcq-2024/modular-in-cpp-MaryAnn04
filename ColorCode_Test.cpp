#include "ColorCode.h"
#include <iostream>
#include <assert.h>
#include <sstream>  

void testNumberToPair(int pairNumber,
    TelCoColorCoder::MajorColor expectedMajor,
    TelCoColorCoder::MinorColor expectedMinor)
{
    TelCoColorCoder::ColorPair colorPair =
        TelCoColorCoder::GetColorFromPairNumber(pairNumber);
    std::cout << "Got pair " << colorPair.ToString() << std::endl;
    assert(colorPair.getMajor() == expectedMajor);
    assert(colorPair.getMinor() == expectedMinor);
}

void testPairToNumber(
    TelCoColorCoder::MajorColor major,
    TelCoColorCoder::MinorColor minor,
    int expectedPairNumber)
{
    int pairNumber = TelCoColorCoder::GetPairNumberFromColor(major, minor);
    std::cout << "Got pair number " << pairNumber << std::endl;
    assert(pairNumber == expectedPairNumber);
}

// Function to test the generated manual
void testManualGeneration() {
    // Generate the manual
    std::string manual = TelCoColorCoder::GenerateReferenceManual();
    // create an expected manual
    std::ostringstream expectedManual;
    expectedManual << "1: White Blue\n";
    expectedManual << "2: White Orange\n";
    expectedManual << "3: White Green\n";
    expectedManual << "4: White Brown\n";
    expectedManual << "5: White Slate\n";
    expectedManual << "6: Red Blue\n";
    expectedManual << "7: Red Orange\n";
    expectedManual << "8: Red Green\n";
    expectedManual << "9: Red Brown\n";
    expectedManual << "10: Red Slate\n";
    expectedManual << "11: Black Blue\n";
    expectedManual << "12: Black Orange\n";
    expectedManual << "13: Black Green\n";
    expectedManual << "14: Black Brown\n";
    expectedManual << "15: Black Slate\n";
    expectedManual << "16: Yellow Blue\n";
    expectedManual << "17: Yellow Orange\n";
    expectedManual << "18: Yellow Green\n";
    expectedManual << "19: Yellow Brown\n";
    expectedManual << "20: Yellow Slate\n";
    expectedManual << "21: Violet Blue\n";
    expectedManual << "22: Violet Orange\n";
    expectedManual << "23: Violet Green\n";
    expectedManual << "24: Violet Brown\n";
    expectedManual << "25: Violet Slate\n";

    // Assert that the generated manual matches the expected manual
    std::cout << "Generated Manual:\n" << manual << std::endl;
    std::cout << "Expected Manual:\n" << expectedManual.str() << std::endl;
    assert(manual == expectedManual.str());  // Ensure both are identical
}

int main() {
    // tests for pair number to color and vice versa
    testNumberToPair(4, TelCoColorCoder::WHITE, TelCoColorCoder::BROWN);
    testNumberToPair(5, TelCoColorCoder::WHITE, TelCoColorCoder::SLATE);

    testPairToNumber(TelCoColorCoder::BLACK, TelCoColorCoder::ORANGE, 12);
    testPairToNumber(TelCoColorCoder::VIOLET, TelCoColorCoder::SLATE, 25);

    // test for manual generation
    testManualGeneration();

    return 0;
}

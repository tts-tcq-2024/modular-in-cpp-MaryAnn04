#include "ColorCode.h"
#include <iostream>
#include <sstream> // for std::ostringstream

namespace TelCoColorCoder 
{
    const char* MajorColorNames[] = {
        "White", "Red", "Black", "Yellow", "Violet"
    };
    const int numberOfMajorColors =
        sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
    
    const char* MinorColorNames[] = {
        "Blue", "Orange", "Green", "Brown", "Slate"
    };
    const int numberOfMinorColors =
        sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

    // Constructor for ColorPair
    ColorPair::ColorPair(MajorColor major, MinorColor minor):
        majorColor(major), minorColor(minor)
    {}

    // Getter for MajorColor
    MajorColor ColorPair::getMajor() const {
        return majorColor;
    }

    // Getter for MinorColor
    MinorColor ColorPair::getMinor() const {
        return minorColor;
    }

    // ToString method
    std::string ColorPair::ToString() const {
        std::string colorPairStr = MajorColorNames[majorColor];
        colorPairStr += " ";
        colorPairStr += MinorColorNames[minorColor];
        return colorPairStr;
    }

    // Function to get ColorPair from pair number
    ColorPair GetColorFromPairNumber(int pairNumber) {
        int zeroBasedPairNumber = pairNumber - 1;
        MajorColor majorColor = 
            (MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
        MinorColor minorColor =
            (MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
        return ColorPair(majorColor, minorColor);
    }

    // Function to get pair number from color
    int GetPairNumberFromColor(MajorColor major, MinorColor minor) {
        return major * numberOfMinorColors + minor + 1;
    }

    // Function to generate the reference manual as a string
    std::string GenerateReferenceManual() {
        std::ostringstream manual;
        for (int pairNumber = 1; pairNumber <= 25; ++pairNumber) {
            ColorPair colorPair = GetColorFromPairNumber(pairNumber);
            manual << pairNumber << ": " << colorPair.ToString() << "\n";
        }
        return manual.str();
    }
}

#include "ColorCode.h"
#include <iostream>
#include <sstream> // for std::ostringstream

namespace ColorCoder 
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

    ColorPair::ColorPair(MajorColor major, MinorColor minor):
        majorColor(major), minorColor(minor)
    {}

    MajorColor ColorPair::getMajor() const {
        return majorColor;
    }

    MinorColor ColorPair::getMinor() const {
        return minorColor;
    }

    std::string ColorPair::ToString() const {
        std::string colorPairStr = MajorColorNames[majorColor];
        colorPairStr += " ";
        colorPairStr += MinorColorNames[minorColor];
        return colorPairStr;
    }

    ColorPair GetColorFromPairNumber(int pairNumber) {
        int zeroBasedPairNumber = pairNumber - 1;
        MajorColor majorColor = 
            (MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
        MinorColor minorColor =
            (MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
        return ColorPair(majorColor, minorColor);
    }

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

// Copyright (C) Microsoft Corporation. All rights reserved.

#include <fstream>
#include "TestApp.h"

namespace PlayFabUnit
{
    // Partial class implementation of TestApp.
    // Each platform gets its own file and implementation of the following methods, since the logic
    // is likely to be very different on all of them.
    bool TestApp::LoadTitleDataJson(std::shared_ptr<char*>& testDataJson, size_t& testDataJsonLen)
    {
        // Get the path to the test data file from the current environment vars.
        std::string titleDataPath;
        {
            char* titleDataPathCStr =  getenv("PF_TEST_TITLE_DATA_JSON");

            if (titleDataPathCStr == nullptr)
                return false;

            titleDataPath = titleDataPathCStr;
        }

        // Read the title data from the file into the output character array.
        std::ifstream titleDataFile;
        titleDataFile.open(titleDataPath, std::ios::binary | std::ios::in);

        if (!titleDataFile)
        {
            return false;
        }

        auto begin = titleDataFile.tellg();
        titleDataFile.seekg(0, std::ios::end);
        auto end = titleDataFile.tellg();
        testDataJsonLen = static_cast<int>(end - begin);
        testDataJson = std::make_shared<char*>(new char[testDataJsonLen + 1]);

        titleDataFile.seekg(0, std::ios::beg);
        titleDataFile.read(*testDataJson, testDataJsonLen);
        (*testDataJson)[testDataJsonLen] = '\0';

        titleDataFile.close();

        return true;
    }

    void TestApp::LogPut(const char* message)
    {
        // Write to STDOUT.
        puts(message);
    }
}
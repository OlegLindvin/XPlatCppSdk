// Copyright (C) Microsoft Corporation. All rights reserved.

#include <jni.h>
#include <android/log.h>
#include <string>
#include <fstream>

#include "TestAppPch.h"
#include "TestApp.h"
#include "TestTitleDataLoader.h"

//#define USE_EXTERNAL_JSON_FILE

#ifdef USE_EXTERNAL_JSON_FILE
#warning "Replace below file name(except ext) with yours, and DO NOT SHARE IT."
static const char* c_jsonFileName = "YOUR_JSON_FILE_NAME";
#else // USE_EXTERNAL_JSON_FILE
#warning "Replace below information with yours, and DO NOT SHARE IT."
static const char* c_titleId = "6195";
static const char* c_developerSecretKey = "MJNXTPSTEMG4Y8EDUBQ1E4JDYKTT17SQ7RR5HMC6HEYR1IPFX9";
static const char* c_userEmail = "paul@playfab.com";
#endif // USE_EXTERNAL_JSON_FILE

namespace PlayFabUnit
{
    // Partial class implementation of TestTitleDataLoader.
    // Each platform gets its own file and implementation of TestTitleDataLoader::LoadTestJson(),
    // since the file handling logic is likely to be very different on all of them.
    bool TestApp::LoadTitleDataJson(std::shared_ptr<char*>& testDataJson, size_t& testDataJsonLen)
    {
#ifdef USE_EXTERNAL_JSON_FILE
        NSString *filePath = [[NSBundle mainBundle] pathForResource:c_jsonFileName ofType:@"json"];
        if(filePath == nil)
        {
            Log("Failed to get json file path.");
            return false;
        }
        NSData *data = [NSData dataWithContentsOfFile:filePath];
        if(data == nil)
        {
            Log("Failed to load json file.");
            return false;
        }

        NSString* jsonString = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
        if(jsonString == nil)
        {
            Log("Failed to encode json string.");
            return false;
        }

        testDataJsonLen = [jsonString lengthOfBytesUsingEncoding:NSUTF8StringEncoding];
        testDataJson = std::make_shared<char*>(new char[testDataJsonLen + 1]);
        strlcpy(*testDataJson, [jsonString UTF8String], testDataJsonLen + 1);
#else // USE_EXTERNAL_JSON_FILE
        static const char* jsonTestTitleData = "{\n"
            "    \"titleId\": \"%s\",\n"
            "    \"developerSecretKey\": \"%s\",\n"
            "    \"userEmail\": \"%s\"\n"
        "}";
        testDataJson = std::make_shared<char*>(new char[1024]);
        snprintf(*testDataJson, 1024, jsonTestTitleData, c_titleId, c_developerSecretKey, c_userEmail);
        testDataJsonLen = strlen(*testDataJson);
#endif // USE_EXTERNAL_JSON_FILE
        return true;
    }

    void TestApp::LogPut(const char* message)
    {
        // Write to Android Log.
        __android_log_print(ANDROID_LOG_INFO, "XPlatCppSdk", "%s", message);

        // Write to UI log list.
        //OutputDebugString(message);
    }
}

extern "C" JNIEXPORT jint JNICALL
Java_com_microsoft_xplatcppsdk_unittest_MainActivity_RunUnitTest(
        JNIEnv* env,
        jobject /* this */)
{
    PlayFabUnit::TestApp testApp;

    int result = testApp.Main();
    return (jint)result;
}

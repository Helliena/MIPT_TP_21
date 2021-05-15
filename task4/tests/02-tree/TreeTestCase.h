//
// Created by akhtyamovpavel on 5/1/20.
//


#pragma once

#include <gtest/gtest.h>
#include <boost/filesystem/path.hpp>
#include <string>

using std::string;

class TreeTestCase : public ::testing::Test {
    public:
        static void SetUpTestCase();
        static void TearDownTestCase();
        static string test_path;
        static string file_path;
};

string TreeTestCase::test_path{""};
string TreeTestCase::file_path{""};
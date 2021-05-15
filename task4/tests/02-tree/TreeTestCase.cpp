//
// Created by akhtyamovpavel on 5/1/20.
//


#include "TreeTestCase.h"
#include "Tree.h"
#include <boost/filesystem/path.hpp>
#include <boost/filesystem.hpp>



using boost::filesystem::create_directory;
using boost::filesystem::remove_all;
using boost::filesystem::current_path;

void TreeTestCase::SetUpTestCase(){
    test_path = current_path().string() + "/Test";
    create_directory(test_path);
    file_path = test_path + "/tets.txt";

    std::ofstream fout;
    fout.open(file_path);
    fout.close();
    create_directory(test_path + "/SubTest");
}

TEST_F(TreeTestCase, TestInvalidDirectory) {
    ASSERT_THROW(GetTree("test", true), std::invalid_argument);
}

TEST_F(TreeTestCase, TestInvalidSubdirectory){
    ASSERT_THROW(GetTree(test_path + "/NewTest", true), std::invalid_argument);
    ASSERT_THROW(GetTree(test_path + "/AnotherNewTest", true), std::invalid_argument);
}

TEST_F(TreeTestCase, TestCaseSensitive){
    ASSERT_THROW(GetTree(test_path + "/test", true), std::invalid_argument);
}

TEST_F(TreeTestCase, TestDir) {
    ASSERT_NO_THROW(GetTree(test_path, true));
}

TEST_F(TreeTestCase, TestFile) {
    ASSERT_THROW(GetTree(file_path, true), std::invalid_argument);
}

void TreeTestCase::TearDownTestCase() {
    remove_all(test_path);
}
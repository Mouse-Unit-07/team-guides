/*================================ FILE INFO =================================*/
/* Filename           : test_c_or_cpp_source.cpp                              */
/*                                                                            */
/* File description here...                                                   */
/*                                                                            */
/*============================================================================*/

/*============================================================================*/
/*                               Include Files                                */
/*============================================================================*/
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <fstream>

extern "C" {
#include "print_hello_world.h"
}

#include <CppUTest/TestHarness.h>

/*============================================================================*/
/*                             Private Definitions                            */
/*============================================================================*/
/* none */

/*============================================================================*/
/*                                 Test Group                                 */
/*============================================================================*/
TEST_GROUP(PrintHelloTest)
{
    FILE *original_stdout = nullptr;

    void setup()
    {
        original_stdout = stdout;
        FILE *file = freopen("test_output.txt", "w+", stdout);
        CHECK(file != NULL);
    }

    void teardown()
    {
        CHECK(stdout != NULL);
        fclose(stdout);
        FILE *file = freopen("CON", "w", original_stdout);
        CHECK(file != NULL);
    }
};

/*============================================================================*/
/*                                    Tests                                   */
/*============================================================================*/
TEST(PrintHelloTest, PrintsHelloWorld)
{
    enum {
        MAX_BUFFER_SIZE = 128u
    };
    char buffer[MAX_BUFFER_SIZE]{0};

    print_hello_world();

    fflush(stdout);

    FILE *file = fopen("test_output.txt", "r");
    CHECK(file != NULL);

    fread(buffer, sizeof(char), sizeof(buffer), file);
    fclose(file);

    STRCMP_EQUAL("Hello World\r\n", buffer);
}

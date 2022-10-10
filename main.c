#include "clonk.h"
#include <stdbool.h>

TEST_CASE(not_reached, { VERIFY_NOT_REACHED(); })
TEST_CASE(skipped, { SKIP(); })

static int str_index_of(const char* needle, const char* haystack)
{
    int needle_len = strlen(needle);
    int haystack_len = strlen(haystack);
    for (int i = 0; i < haystack_len - needle_len - 1; i++) {
        bool match = true;
        for (int n = 0; n < needle_len; n++) {
            if (needle[n] != haystack[i + n]) {
                match = false;
                break;
            }
        }
        if (match)
            return i;
    }
    return -1;
}

TEST_CASE(failed, {
    VERIFY(str_index_of("H", "Hello World") == 6);
})

TEST_CASE(success, {
    VERIFY(str_index_of("lo", "Hello World") == 3);
})

BENCHMARK(string_search, {
    VERIFY(str_index_of("Wor", "Hello World") == 6);
})

int main(int argc, char** argv)
{
    REGISTER_TEST_CASE(not_reached);
    REGISTER_TEST_CASE(skipped);
    REGISTER_TEST_CASE(failed);
    REGISTER_TEST_CASE(success);
    REGISTER_BENCHMARK(string_search);

    RUN_TEST_SUITE(argc, argv);
}
# Clonk

Clonk is a small but capable single header unit testing framework.
Aside from unit tests it also offers the possibility to write simple benchmarks.

```c
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
```

When executed it yields statistics about the tests it ran as well as source code location
of where verifications failed or tests were skipped:

```
FAIL[not_reached] VERIFY_NOT_REACHED (main.c:4)
SKIP[skipped](main.c:6)
FAIL[failed]: VERIFY 1 == 2 (main.c:8)
SUCCESS[success](main.c:10)
BENCHMARK[string_search]: took 69 ms (main.c:12)
Result: 1 Success, 2 Failed, 1 Skipped
```

It also provides the option to run a single test:
```bash
./unit_test not_reached
FAIL[not_reached] VERIFY_NOT_REACHED (main.c:3)
Result: 0 Success, 1 Failed, 0 Skipped
```

You can turn of VT100 color escape codes by adding `#define CLONK_NO_COLOR`.
Additionally you may set the amount of cycles done for benchmarks with overriding `CLONK_BENCHMARK_CYCLES`. 
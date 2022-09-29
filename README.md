# Clonk

Clonk is a small but capable single header unit testing framework.

```c
#include "clonk.h"

TEST_CASE(not_reached, { VERIFY_NOT_REACHED(); })

TEST_CASE(skipped, { SKIP(); })

TEST_CASE(failed, { VERIFY(1 == 2); })

TEST_CASE(success, {})

int main(int argc, char **argv) {
  REGISTER_TEST_CASE(not_reached);
  REGISTER_TEST_CASE(skipped);
  REGISTER_TEST_CASE(failed);
  REGISTER_TEST_CASE(success);

  RUN_TEST_SUITE(argc, argv);
}
```

When executed it yields statistics about the tests it ran as well as source code location
of where verifications failed or tests were skipped:

```
FAIL[not_reached] VERIFY_NOT_REACHED (main.c:3)
SKIP[skipped](main.c:5)
FAIL[failed]: VERIFY 1 == 2 (main.c:7)
SUCCESS[success](main.c:9)
Result: 1 Success, 2 Failed, 1 Skipped
```

It also provides the option to run a single test:
```bash
./unit_test not_reached
FAIL[not_reached] VERIFY_NOT_REACHED (main.c:3)
Result: 0 Success, 1 Failed, 0 Skipped
```

You can turn of VT100 color escape codes by adding `#define CLONK_NO_COLOR`.
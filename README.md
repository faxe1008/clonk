# Clonk

Clonk is a small but capable single header unit testing framework.
Aside from unit tests it also offers the possibility to write simple benchmarks.

https://github.com/faxe1008/clonk/blob/c13901710ca6f5716b34f968f2b0e8af6a5d70b6/main.c#L1-L46

Usage:
```bash
Usage: ./unit_test [-tblh] [TEST_NAME]...
clonk based test/benchmark executable.
Options:
  -b    Run benchmarks
  -t    Run tests
  -l    List available tests
  -h    Show this help message
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

It also provides the option to run a list of tests:
```bash
./unit_test not_reached failed
FAIL[not_reached] VERIFY_NOT_REACHED (main.c:3)
FAIL[failed]: VERIFY 1 == 2 (main.c:8)
Result: 0 Success, 1 Failed, 0 Skipped
```

You can turn of VT100 color escape codes by adding `#define CLONK_NO_COLOR`.
Additionally you may set the amount of cycles done for benchmarks with overriding `CLONK_BENCHMARK_CYCLES`. 
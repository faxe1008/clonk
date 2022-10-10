
<h1><img src="./img/clonk.svg" height="48px"> Clonk</h1>

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

![Running all tests](img/unit_test_run.svg?raw=true "Running all tests")

It also provides the option to run a list of tests:

![Running selected tests](img/run_select_tests.svg?raw=true "Running selected tests")

You can turn of VT100 color escape codes by adding `#define CLONK_NO_COLOR`.
Additionally you may set the amount of cycles done for benchmarks with overriding `CLONK_BENCHMARK_CYCLES`. 
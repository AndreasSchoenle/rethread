#rethread

Rethread is a header-only C++ library that implements cancellation tokens and [RAII](http://en.cppreference.com/w/cpp/language/raii)-compliant threads.

Getting started information is available in the [rethread tutorial](docs/Primer.md).  
For performance considerations, take a look at [benchmarks](docs/Performance.md).  
Also, there's an [advanced guide](docs/AdvancedGuide.md) about custom cancellation handlers.  
Design rationale is available [here](docs/Rationale.md).

Tests and benchmarks are kept in a separate repository: [rethread_testing](https://github.com/bo-on-software/rethread_testing).

##Features
* RAII-compliant threads
* Cancellable waits on any `condition_variable`
* Does not require exceptions
* Fine granularity - can cancel separate tasks without terminating the whole thread
* Can interrupt any POSIX call that cooperates with `poll`
* Custom cancellation handlers support
* [Super low price](docs/Performance.md) for cancellability - sometimes cancellable functions actually work faster!

##Platforms
Cancellation tokens, threads and cancellable waits for condition variables are implemented in terms of standard C++11. Obviously, cancelling blocking calls to the OS can't be platform-agnostic.

Builds are tested against following compilers:
#####Travis
[![Build Status](https://travis-ci.org/bo-on-software/rethread_testing.svg?branch=master)](https://travis-ci.org/bo-on-software/rethread_testing)
* gcc-4.8
* clang-3.5

#####AppVeyor
[![Build status](https://ci.appveyor.com/api/projects/status/rknxr8prxtgc6sx5?svg=true)](https://ci.appveyor.com/project/bo-on-software/rethread-testing)
* Visual Studio 2013
* Visual Studio 2015

There should be no major issues with porting `rethread` to C++98, but I see no reason in doing it right now.

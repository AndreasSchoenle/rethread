#ifndef RETHREAD_DETAIL_EXCEPTION_H
#define RETHREAD_DETAIL_EXCEPTION_H

#include <exception>
#include <type_traits>

#ifdef __GNUC__
#define RETHREAD_LIKELY(Condition_)   __builtin_expect((Condition_), 1)
#define RETHREAD_UNLIKELY(Condition_) __builtin_expect((Condition_), 0)
#else
#define RETHREAD_LIKELY(Condition_)   (Condition_)
#define RETHREAD_UNLIKELY(Condition_) (Condition_)
#endif

#define RETHREAD_THROW(Exception_) ::rethread::detail::throw_exception(Exception_, __FILE__, __LINE__)
#define RETHREAD_CHECK(Condition_, Exception_) do { if (RETHREAD_UNLIKELY(!(Condition_))) RETHREAD_THROW(Exception_); } while (false)

#ifndef RETHREAD_SUPPRESS_CHECKS
#define RETHREAD_ASSERT(Condition_, Message_) do { if (RETHREAD_UNLIKELY(!(Condition_))) std::terminate(); } while (false)
#else
#define RETHREAD_ASSERT(Condition_, Message_) do { } while (false)
#endif

#ifdef RETHREAD_USE_HELGRIND_ANNOTATIONS
#include <valgrind/helgrind.h>
#define RETHREAD_ANNOTATE_BEFORE(...) ANNOTATE_HAPPENS_BEFORE(__VA_ARGS__)
#define RETHREAD_ANNOTATE_AFTER(...) ANNOTATE_HAPPENS_AFTER(__VA_ARGS__)
#define RETHREAD_ANNOTATE_FORGET(...) ANNOTATE_HAPPENS_BEFORE_FORGET_ALL(__VA_ARGS__)
#else
#define RETHREAD_ANNOTATE_BEFORE(...)
#define RETHREAD_ANNOTATE_AFTER(...)
#define RETHREAD_ANNOTATE_FORGET(...)
#endif

namespace rethread {
namespace detail {

	template <typename T>
	[[noreturn]] inline typename std::enable_if<std::is_base_of<std::exception, T>::value>::type throw_exception(const T& t, const char*, int)
	{ throw t; }

}
}

#endif

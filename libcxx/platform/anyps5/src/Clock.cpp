#include "Runtime/Kernel.hpp"

#include <chrono>
#include <exception>
#include <limits>

namespace {

std::int64_t readClock(int clock, std::int64_t units, std::int64_t divisor) noexcept {
    AnyLibcxx::KernelTimespec value{};
    AnyLibcxx::RequireKernel(sceKernelClockGettime(clock, &value));
    if (value.Nanoseconds < 0 || value.Nanoseconds >= 1000000000) std::terminate();

    constexpr auto minimum = std::numeric_limits<std::int64_t>::min();
    constexpr auto maximum = std::numeric_limits<std::int64_t>::max();
    if (value.Seconds < minimum / units || value.Seconds > maximum / units) std::terminate();
    const auto seconds = value.Seconds * units;
    const auto fraction = value.Nanoseconds / divisor;
    if (seconds > maximum - fraction) std::terminate();
    return seconds + fraction;
}

}

_LIBCPP_BEGIN_NAMESPACE_STD
namespace chrono {

system_clock::time_point system_clock::now() noexcept { return time_point(duration(readClock(0, 1000000, 1000))); }
steady_clock::time_point steady_clock::now() noexcept { return time_point(duration(readClock(4, 1000000000, 1))); }

time_t system_clock::to_time_t(const time_point& value) noexcept { return static_cast<time_t>(duration_cast<seconds>(value.time_since_epoch()).count()); }
system_clock::time_point system_clock::from_time_t(time_t value) noexcept { return time_point(seconds(value)); }
}
_LIBCPP_END_NAMESPACE_STD

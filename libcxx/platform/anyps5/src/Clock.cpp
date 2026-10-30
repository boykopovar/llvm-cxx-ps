#include <chrono>

_LIBCPP_BEGIN_NAMESPACE_STD
namespace chrono {
time_t system_clock::to_time_t(const time_point& value) noexcept { return static_cast<time_t>(duration_cast<seconds>(value.time_since_epoch()).count()); }
system_clock::time_point system_clock::from_time_t(time_t value) noexcept { return time_point(seconds(value)); }
}
_LIBCPP_END_NAMESPACE_STD

#include <cstdlib>
#include <cstring>
#include <exception>
#include <stdexcept>

namespace {

[[noreturn]] void fail() { throw std::runtime_error("noexcept termination"); }
void invoke() noexcept { fail(); }

[[noreturn]] void verifyTerminate() noexcept {
    const auto error = std::current_exception();
    if (!error) std::_Exit(2);
    try {
        std::rethrow_exception(error);
    } catch (const std::runtime_error& value) {
        std::_Exit(std::strcmp(value.what(), "noexcept termination") == 0 ? 0 : 3);
    } catch (...) {
        std::_Exit(4);
    }
}

}

int main() {
    std::set_terminate(verifyTerminate);
    if (std::get_terminate() != verifyTerminate) return 6;
    invoke();
    return 5;
}


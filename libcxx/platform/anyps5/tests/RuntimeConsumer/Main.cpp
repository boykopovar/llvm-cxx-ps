#include "ContainerChecks.hpp"
#include "ThreadChecks.hpp"
#include "prx/libkernel/include/Api.hpp"
#include <exception>

void RunMutexChecks();
void RunCApiChecks();

int main() {
    try {
        RunContainerChecks(0x12345678);
        RunMutexChecks();
        RunThreadChecks();
        RunCApiChecks();
        sceKernelDebugOutText(0, "Runtime integration checks passed");
        return 0;
    } catch (const std::exception& error) {
        sceKernelDebugOutText(0, error.what());
        return 1;
    } catch (...) {
        sceKernelDebugOutText(0, "Unexpected exception in runtime checks");
        return 2;
    }
}

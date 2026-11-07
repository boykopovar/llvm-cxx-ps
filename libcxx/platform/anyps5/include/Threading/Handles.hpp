#ifndef ANYLIBCXX_THREADING_HANDLES_HPP
#define ANYLIBCXX_THREADING_HANDLES_HPP

namespace AnyLibcxx {

int InitializeMutex(void** storage);
int InitializeCondition(void** storage);

}

#endif


#ifndef CANNY_CONSOLE_H
#define CANNY_CONSOLE_H
#include <v8.h>

namespace canny {
    namespace console {
        v8::Handle<v8::ObjectTemplate> createConsoleObject();
    }
}

#endif /* CANNY_CONSOLE_H */

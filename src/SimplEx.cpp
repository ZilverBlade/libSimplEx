#include <SimplEx/SimplEx.h>

#define SPX_VERSION (0 << 24)|(1 << 16)|(0)

extern "C" int SpxVersion() {
    return SPX_VERSION;
}

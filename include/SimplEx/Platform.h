#pragma once

#ifdef ZB_SIMPLEX_SHARED
#ifdef _WIN32
#ifdef libSimplEx_EXPORTS
#define ZB_SPX_API __declspec(dllexport)
#else
#define ZB_SPX_API __declspec(dllimport)
#endif // libSimplEx_EXPORTS
#else
#define ZB_SPX_API
#endif // _WIN32
#else
#define ZB_SPX_API 
#endif // ZB_SIMPLEX_SHARED
// Created by Clark Burton Chambers on 4/4/16.
//
// DEBUG PRINT MACROS.
// C++ Version with cool exception throwing capabilities.

// They don't look super pretty, but these macros are super helpful for
//      printing useful debug messages!


#ifndef __dbg_h_cpp__
#define __dbg_h_cpp__

#include <stdio.h>
#include <errno.h>
#include <string.h>

// IF 0 debugf does nothing
#define DEBUG 1

// Definitions for debug phrases.
#define DEBUG_ON 1
#define DEBUG_OFF 0

// Define phrases here for debug(A, M, ...) to pass into A
// EX: #define DBG_MAIN DEBUG_ON

// __FILENAME__ is used to clean up the file paths a fair bit.
#ifdef WIN32
#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1: __FILE__)
#else // OSX & Linux
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1: __FILE__)
#endif

//#define sentinel(E, M, ...)                                                              \
//{                                                                                        \
//    log_err(E, M, ##__VA_ARGS__);                                                        \
//    errno=0;                                                                             \
//    throw E();                                                                           \
//}

// PRINTING STUFF!
#if DEBUG

// C errno stuff.
#define clean_errno() (errno == 0 ? "None" : strerror(errno))

// Logs an err. Called in check or if you REALLY need to
#define log_err(E, M, ...)                                                               \
fprintf(stderr, "[ERROR] (%s:%d | exception: %s): " M "\n",                              \
        __FILENAME__,                                                                    \
        __LINE__,                                                                        \
        #E,                                                                              \
        ##__VA_ARGS__)

// Logs a warning. Not fatal, but you probably don't want it happening.
#define log_warn(M, ...)                                                                 \
fprintf(stderr, "[WARN] (%s:%d | errno: %s): " M "\n",                                   \
        __FILENAME__,                                                                    \
        __LINE__,                                                                        \
        clean_errno(),                                                                   \
        ##__VA_ARGS__)

// Just a quick info log. Nothing big.
#define log_info(M, ...)                                                                 \
fprintf(stdout, "[INFO] (%s:%d): " M "\n",                                               \
        __FILENAME__,                                                                    \
        __LINE__,                                                                        \
        ##__VA_ARGS__)

// Logs an SQL error.
#define log_errsql(E, M, ...)                                                            \
log_err("N/A" ,                                                                          \
        "\n\t<SQLERR>: %s\n\t<ERRCode>: %d\n\t<SQLState>: %s\n\t\t" M "\n",              \
        (std::string("")+E.what()).c_str(),                                              \
        E.getErrorCode(),                                                                \
        E.getSQLState().c_str(),                                                         \
        ##__VA_ARGS__)

#define debug(A, M, ...) if(A){ log_info(M, ##__VA_ARGS__); } else{}

#else
#define debug(A, M, ...)
#define log_errsql(E, M, ...)
#define log_info(M, ...)
#define log_warn(M, ...)
#define log_err(E, M, ...)
#define clean_errno()
#endif // DEBUG

#endif // __dbg_h_cpp__

#ifndef DEBUG_H
#define DEBUG_H

#ifdef DEBUG
#define debug_print(args ...) fprintf(stderr, args)
#else
#define debug_print(args ...)
#endif

#endif

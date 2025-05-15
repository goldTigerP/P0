#ifndef __COMMON_H__
#define __COMMON_H__

#define FUNCTION_BEFORE_MAIN(function_name) __attribute__((constructor)) void function_name

#endif

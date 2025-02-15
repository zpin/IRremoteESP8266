#ifndef IRMACROS_H_
#define IRMACROS_H_
/****************************************************************
 * Copyright 2022 IRremoteESP8266 project and others
 */
/// @file IRmacros.h

/**
 * COND() Set of macros to facilitate single-line conditional compilation
 * argument checking.
 * Found here: https://www.reddit.com/r/C_Programming/comments/ud3xrv/
 * conditional_preprocessor_macro_anyone/
 * 
 * Usage:
 * COND(<define_to_test>[||/&&<more_define>...], <true_result>, <false_result>)
 */
/// @cond TEST
#define NOTHING
#define EXPAND(...) __VA_ARGS__
#define STUFF_P(a, ...) __VA_OPT__(a)
#define STUFF(...) STUFF_P(__VA_ARGS__)
#define VA_TEST_P(a, ...) __VA_OPT__(NO)##THING
#define VA_TEST(...) VA_TEST_P(__VA_ARGS__)
#define NEGATE(a) VA_TEST(a, a)
#define COND_P(cond, a, b) STUFF(a, cond)STUFF(b, NEGATE(cond))
#define COND(cond, a, b) EXPAND(COND_P(cond, a, b))
/// @endcond
/**
 * end of COND() set of macros
 */

#endif  // IRMACROS_H_

#ifdef RGB_MATRIX_ENABLE

#include "rgb_matrix.h"
#include "config_led.h"
// readability
#define NA NO_LED
/* Screenprint on the back of the pcb
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
 * │ 1 │ 6 │10 │15 │19 │23 │27 │32 │36 │40 │44 │49 │54 │  57   │64 │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
 * │  2  │ 7 │11 │16 │20 │24 │28 │33 │37 │41 │45 │50 │55 │     │65 │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐59  ├───┤
 * │  3   │ 8 │12 │17 │21 │25 │29 │34 │38 │42 │46 │51 │58 │    │66 │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴┬───┼───┤
 * │ 4  │69 │13 │18 │22 │26 │30 │35 │39 │43 │47 │52 │  60  │62 │67 │
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
 * │ 5  │ 9  │ 14 │           31           │48 │53 │56 │61 │63 │68 │
 * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘ */
led_config_t g_led_config = { {
{  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, NA, 15 },
{ 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, NA, 31 },
{ 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, NA, 47 },
{ 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, NA, 61, 62, 63 },
{ 64, 65, 66, NA, NA, NA, 70, NA, NA, NA, 74, 75, 76, 77, 78, 79 }
}, {
    { 1 *12, 0 }, { 2 *12, 0 }, { 3 *12, 0 }, { 4 *12, 0 }, { 5 *12, 0 }, { 6 *12, 0 }, { 7 *12, 0 }, { 8 *12, 0 }, { 9 *12, 0 }, { 10 *12, 0 }, { 11 *12, 0 }, { 12 *12, 0 }, { 13 *12, 0 }, { 14 *12, 0 }, { 14 *12, 0 },
    { 1 *12, 1 }, { 2 *12, 1 }, { 3 *12, 1 }, { 4 *12, 1 }, { 5 *12, 1 }, { 6 *12, 1 }, { 7 *12, 1 }, { 8 *12, 1 }, { 9 *12, 1 }, { 10 *12, 1 }, { 11 *12, 1 }, { 12 *12, 1 }, { 13 *12, 1 }, { 14 *12, 1 }, { 14 *12, 1 },
    { 1 *12, 2 }, { 2 *12, 2 }, { 3 *12, 2 }, { 4 *12, 2 }, { 5 *12, 2 }, { 6 *12, 2 }, { 7 *12, 2 }, { 8 *12, 2 }, { 9 *12, 2 }, { 10 *12, 2 }, { 11 *12, 2 }, { 12 *12, 2 }, { 13 *12, 2 }, { 14 *12, 2 }, { 14 *12, 2 },
    { 1 *12, 3 }, { 2 *12, 3 }, { 3 *12, 3 }, { 4 *12, 3 }, { 5 *12, 3 }, { 6 *12, 3 }, { 7 *12, 3 }, { 8 *12, 3 }, { 9 *12, 3 }, { 10 *12, 3 }, { 11 *12, 3 }, { 12 *12, 3 }, { 12 *12, 3 }, { 13 *12, 3 }, { 14 *12, 3 },
    { 1 *12, 4 }, { 2 *12, 4 }, { 3 *12, 4 }, { 4 *12, 4 }, { 5 *12, 4 }, { 6 *12, 4 }, { 7 *12, 4 }, { 8 *12, 4 }, { 9 *12, 4 }, { 10 *12, 4 }, { 11 *12, 4 }, { 12 *12, 4 }, { 12 *12, 4 }, { 13 *12, 4 }, { 14 *12, 4 }
}, {
   4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 4,
   4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 4,
   4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 4,
   4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 4, 4, 4,
   4, 4, 4, 0, 0, 0, 4, 0, 0, 0, 4, 4, 4, 4, 4, 4
} };

#endif

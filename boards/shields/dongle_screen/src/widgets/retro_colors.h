/* SPDX-License-Identifier: MIT
 * Retro Green Dark palette, shared by the existing YADS widgets.
 */
#ifndef YADS_RETRO_COLORS_H
#define YADS_RETRO_COLORS_H

#include <stddef.h>
#include <stdint.h>

static inline uint32_t yads_layer_color(uint8_t layer) {
    static const uint32_t palette[] = {
        0x88FFCC, 0xA8CFFF, 0xFFAACC, 0xD6B3FF, 0xFFD0A8,
    };
    /* The fixed, nonempty palette is independent of keymap layer count. */
    return palette[layer % (sizeof(palette) / sizeof(palette[0]))];
}

static inline uint32_t yads_wpm_color(int wpm) {
    if (wpm < 30) return 0x66B2A3;
    if (wpm < 60) return 0x88FFCC;
    if (wpm < 90) return 0xA8CFFF;
    return 0xFF77AA;
}

static inline uint32_t yads_battery_color(uint8_t level) {
    /* Zero/unknown keeps the existing red X behavior. */
    if (level <= 10) return 0xFF6961;
    if (level <= 20) return 0xFFAA55;
    if (level <= 50) return 0xFFD966;
    return 0xB6FF8E;
}
#endif

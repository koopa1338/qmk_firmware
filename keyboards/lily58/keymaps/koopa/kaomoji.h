#pragma once

#include QMK_KEYBOARD_H
#include "process_ucis.h"
#include "unicode/unicode.h"

// clang-format off
const ucis_symbol_t ucis_symbol_table[] = UCIS_TABLE(
    UCIS_SYM("rofl", 0x1F923)
    // UCIS_SYM("fpt", 0x0028, 0x256E, 0x00B0, 0x002D, 0x00B0, 0x0029, 0x256E, 0x2533,
    //                 0x2501, 0x2501, 0x2533, 0x0020, 0x0028, 0x0020, 0x256F, 0x00B0,
    //                 0x25A1, 0x00B0, 0x0029, 0x256F, 0x0020, 0x253B, 0x2501, 0x2501,
    //                 0x253B) // (╮°-°)╮┳━━┳ ( ╯°□°)╯ ┻━━┻
);
// clang-format on

enum {
    KC_UCIS,
};

void ucis_symbol_fallback(void) {
    send_unicode_string("(╮°-°)╮┳━━┳ ( ╯°□°)╯ ┻━━┻");
}

void ucis_success(uint8_t symbol_index) {
    send_string("success!");
}

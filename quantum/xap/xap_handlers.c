/* Copyright 2021 Nick Brassel (@tzarc)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <quantum.h>
#include <xap.h>
#include <info_json_gz.h>

void xap_respond_failure(xap_token_t token, xap_response_flags_t response_flags) { xap_send(token, response_flags, NULL, 0); }

bool xap_respond_u8(xap_token_t token, uint8_t value) {
    xap_send(token, XAP_RESPONSE_FLAG_SUCCESS, &value, sizeof(value));
    return true;
}

bool xap_respond_u16(xap_token_t token, uint16_t value) {
    xap_send(token, XAP_RESPONSE_FLAG_SUCCESS, &value, sizeof(value));
    return true;
}

bool xap_respond_u32(xap_token_t token, uint32_t value) {
    xap_send(token, XAP_RESPONSE_FLAG_SUCCESS, &value, sizeof(value));
    return true;
}

bool xap_respond_u64(xap_token_t token, uint64_t value) {
    xap_send(token, XAP_RESPONSE_FLAG_SUCCESS, &value, sizeof(value));
    return true;
}

uint32_t subsystem_xap_subsystem_query_getter(void) {
    return (1ul << SUBSYSTEM_XAP) | (1ul << SUBSYSTEM_QMK) | (1ul << SUBSYSTEM_KB) | (1ul << SUBSYSTEM_USER)
#if defined(DYNAMIC_KEYMAP_ENABLE)
           | (1ul << SUBSYSTEM_DYNAMIC_KEYMAP)
#endif
#if defined(ENCODER_MAP_ENABLE)
           | (1ul << SUBSYSTEM_DYNAMIC_ENCODER)
#endif
#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
           | (1ul << SUBSYSTEM_LIGHTING)
#endif
        ;
}

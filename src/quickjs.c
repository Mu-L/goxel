/* Goxel 3D voxels editor
 *
 * copyright (c) 2020 Guillaume Chereau <guillaume@noctua-software.com>
 *
 * Goxel is free software: you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.

 * Goxel is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.

 * You should have received a copy of the GNU General Public License along with
 * goxel.  If not, see <http://www.gnu.org/licenses/>.
 */

#define CONFIG_VERSION "2020-07-05"
#include "../ext_src/quickjs/cutils.c"
#include "../ext_src/quickjs/libregexp.c"
#include "../ext_src/quickjs/libunicode.c"

#define is_digit is_digit_
#define compute_stack_size compute_stack_size_

// Fix quickjs calls to memcpy with n = 0 and src = NULL.
#ifndef __APPLE__
#define memcpy(dest, src, n) ({ ((n) != 0) ? memcpy(dest, src, n) : dest; })
#endif

#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Warray-bounds"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#pragma GCC diagnostic ignored "-Wimplicit-int-float-conversion"

#include "../ext_src/quickjs/quickjs.c"

// Add functions to create arrays from a buffer.
JSValue JS_NewInt32Array(JSContext *ctx, JSValueConst arrayBuffer,
                         int offset, int length)
{
    JSValue offsetValue = JS_NewInt32(ctx, offset);
    JSValue lengthValue = JS_NewInt32(ctx, length);
    JSValue args[] = {arrayBuffer, offsetValue, lengthValue};
    return js_typed_array_constructor(ctx, arrayBuffer, 3, args,
                                      JS_CLASS_INT32_ARRAY);
}

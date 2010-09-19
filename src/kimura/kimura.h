/*
 * Copyright (c) 2009-2010 Chris Barber <chris@cb1inc.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __KIMURA_H__
#define __KIMURA_H__

// __DATE__ format macros from http://bytes.com/forum/thread215378.html
#define YEAR _YEAR(__DATE__)
#define _YEAR(d) ((((d[7] - '0') * 10 + (d[8] - '0')) * 10 + (d[9] - '0')) * 10 + (d[10] - '0'))

#define MONTH _MONTH(__DATE__)
#define _MONTH(d)  (d[2] == 'n' ? (d[1] == 'a' ? 1 : 6) \
: d[2] == 'b' ? 2 \
: d[2] == 'r' ? (d[0] == 'M' ? 3 : 4) \
: d[2] == 'y' ? 5 \
: d[2] == 'l' ? 7 \
: d[2] == 'g' ? 8 \
: d[2] == 'p' ? 9 \
: d[2] == 't' ? 10 \
: d[2] == 'v' ? 11 : 12)

#define DAY _DAY(__DATE__)
#define _DAY(d) ((d[4] == ' ' ? 0 : d[4] - '0') * 10 + (d[5] - '0'))

#endif

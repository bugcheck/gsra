/***************************************************************************
 *   Copyright (C) 2010 by Pierre Sermanet *
 *   pierre.sermanet@gmail.com *
 *   All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Redistribution under a license not approved by the Open Source
 *       Initiative (http://www.opensource.org) must display the
 *       following acknowledgement in all advertising material:
 *        This product includes software developed at the Courant
 *        Institute of Mathematical Sciences (http://cims.nyu.edu).
 *     * The names of the authors may not be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ThE AUTHORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 ***************************************************************************/

////////////////////////////////////////////////////////////////
// CBLAS configuration

#ifdef __CBLAS__

#ifdef __WINDOWS__
#include "cblas.h"
#else

/* #undef APPLE_FRAMEWORK_FOUND */

// Apple framework calls are mode into a C++ header
// On custom Atlas installations extern C is not included
// On package instalaltions from distributions, extern C is
// included, but another one does not hurt :)
#ifndef APPLE_FRAMEWORK_FOUND
extern "C" {
#endif

#include ""

#ifndef APPLE_FRAMEWORK_FOUND
}
#endif

#endif /* __WINDOWS__ */
#endif /* __CBLAS__ */

////////////////////////////////////////////////////////////////
// ImageMagick configuration

#ifdef __IMAGEMAGICK__
#ifdef __WINDOWS__
//TODO: for now assume convert is declared globally and do not use path
// because path with spaces don't work with _popen even with quotes
#define IMAGEMAGICK_CONVERT "convert.exe"
//#define IMAGEMAGICK_CONVERT "\"/usr/bin/convert\""
#else
#define IMAGEMAGICK_CONVERT "/usr/bin/convert"
#endif
#endif

////////////////////////////////////////////////////////////////
// pipes popen/pclose configuration

#ifdef __WINDOWS__
#define POPEN _popen
#define PCLOSE _pclose
#else
#define POPEN popen
#define PCLOSE pclose
#endif

////////////////////////////////////////////////////////////////
// Math configuration

#ifdef __WINDOWS__
#define ROUND 
#else
#define ROUND round
#endif

////////////////////////////////////////////////////////////////
// paths

#define DATA_PATH "/home/pierre/eblearn_release/eblearn/tools/data"
#define MNIST_PATH ""

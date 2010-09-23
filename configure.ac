# Copyright (c) 2009-2010 Chris Barber <chris@cb1inc.com>
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
# 3. The name of the author may not be used to endorse or promote products
#    derived from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
# A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
# CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
# EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
# PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
# PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
# LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
# NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
# SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

AC_PREREQ(2.64)
AC_COPYRIGHT([Copyright (c) 2009-2010 Chris Barber])
AC_INIT([kimura], [RELEASE_VERSION], [http://github.com/cb1kenobi/kimura])

AC_CONFIG_AUX_DIR([config])
AC_CONFIG_SRCDIR([src/kimura/kimura.cpp])
AC_CONFIG_MACRO_DIR([m4])
AC_PREFIX_DEFAULT([/usr])

PANDORA_CANONICAL_TARGET(less-warnings, warnings-always-on, require-cxx, force-gcc42, skip-visibility, version-from-vc)

PANDORA_VC_INFO_HEADER

PANDORA_CONFIGURE_CMD="[$]0"
if test `expr -- [$]0 : "'.*"` = 0; then
  PANDORA_CONFIGURE_CMD="'[$]0'"
fi
echo $ac_configure_args
for arg in $ac_configure_args; do
  if test `expr -- $arg : "'.*"` = 0; then
    if test `expr -- $arg : "--.*"` = 0; then
      break;
    fi
    PANDORA_CONFIGURE_OPTS="$PANDORA_CONFIGURE_OPTS '[$]arg'"
  else
    if test `expr -- $arg : "'--.*"` = 0; then
      break;
    fi
    PANDORA_CONFIGURE_OPTS="$PANDORA_CONFIGURE_OPTS [$]arg"
  fi
done
AC_DEFINE_UNQUOTED([PANDORA_CONFIGURE_COMMAND], ["$PANDORA_CONFIGURE_CMD$PANDORA_CONFIGURE_OPTS"], [The configure command used to perform the build])

PANDORA_REQUIRE_LIBPROTOBUF
PANDORA_PROTOBUF_REQUIRE_VERSION([2.1.0])
PANDORA_REQUIRE_PROTOC

AC_LANG_PUSH(C++)
PANDORA_REQUIRE_PTHREAD
#PANDORA_REQUIRE_LIBUUID
#PANDORA_REQUIRE_LIBZ
#PANDORA_REQUIRE_LIBPCRE
#PANDORA_REQUIRE_LIBREADLINE
PANDORA_REQUIRE_LIBDL
AC_LANG_POP

PANDORA_PLUGINS

#----------------------------------------------------------------------------
# Makefiles to build
#----------------------------------------------------------------------------
AC_CONFIG_FILES([Makefile gnulib/Makefile src/kimura/Makefile])

#----------------------------------------------------------------------------
# create the configure file
#----------------------------------------------------------------------------
AC_OUTPUT

#----------------------------------------------------------------------------
# Output some pretty information
#----------------------------------------------------------------------------
echo "---"
echo "Configuration summary for $PACKAGE_NAME version $VERSION $PANDORA_RELEASE_COMMENT"
echo ""
echo "   * Installation prefix:       $prefix"
echo "   * System type:               $host_vendor-$host_os"
echo "   * pandora-build version:     PANDORA_CANONICAL_VERSION"
echo "   * Host CPU:                  $host_cpu"
echo "   * C Compiler:                $CC_VERSION"
echo "   * C Compiler Flags:          $AM_CFLAGS"
echo "   * C Compiler Warnings:       $CC_WARNINGS"
echo "   * C++ Compiler:              $CXX_VERSION"
echo "   * C++ Compiler Flags:        $AM_CXXFLAGS"
echo "   * C++ Compiler Warnings:     $CXX_WARNINGS"
echo "   * Assertions enabled:        $ac_cv_assert"
echo "   * Debug enabled:             $with_debug"
echo "   * Profiling enabled:         $ac_profiling"
echo "   * Coverage enabled:          $ac_coverage"
echo "   * Warnings as failure:       $ac_cv_warnings_as_errors"
echo "   * C++ cstdint location:      $ac_cv_cxx_cstdint"
echo "   * C++ hash_map location:     $ac_cv_cxx_hash_map"
echo "   * C++ hash namespace:        $ac_cv_cxx_hash_namespace"
echo "   * C++ shared_ptr namespace:  $ac_cv_shared_ptr_namespace"
echo "   * Configured modules:"
echo ""
for module in `echo $PANDORA_PLUGIN_LIST | sed 's/_/::/g' | tr ',' '\n' | sort`
do
  echo "     - $module"
done
echo ""
echo "---"

# libtoolize scans configure.ac and needs to see some text
m4_define([LIBTOOLIZE_AC_INIT], [])

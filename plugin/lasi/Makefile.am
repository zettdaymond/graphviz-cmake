# $Id: Makefile.am,v 1.8 2009/06/03 01:10:57 ellson Exp $ $Revision: 1.8 $
## Process this file with automake to produce Makefile.in

if WITH_CGRAPH
GRAPH = cgraph
else
GRAPH = graph
endif

AM_CPPFLAGS = \
	-I$(top_srcdir) \
	-I$(top_srcdir)/lib/common \
	-I$(top_srcdir)/lib/pathplan \
	-I$(top_srcdir)/lib/gvc \
	-I$(top_srcdir)/lib/$(GRAPH) \
	-I$(top_srcdir)/lib/cdt \
	$(LASI_CFLAGS) $(PANGOCAIRO_CFLAGS) $(FREETYPE2_CFLAGS) $(LIBGVC_CFLAGS)

if WITH_LASI
if WITH_PANGOCAIRO
noinst_LTLIBRARIES = libgvplugin_lasi_C.la
if WITH_WIN32
lib_LTLIBRARIES = libgvplugin_lasi.la
else
pkglib_LTLIBRARIES = libgvplugin_lasi.la
endif
endif
endif

libgvplugin_lasi_C_la_SOURCES = \
	gvplugin_lasi.c \
	gvrender_lasi.cpp \
	ps.txt

libgvplugin_lasi_la_LDFLAGS = -version-info @GVPLUGIN_VERSION_INFO@
libgvplugin_lasi_la_SOURCES = $(libgvplugin_lasi_C_la_SOURCES)
libgvplugin_lasi_la_LIBADD = \
	$(top_builddir)/lib/gvc/libgvc.la @LASI_LIBS@ @PANGOCAIRO_LIBS@ @MATH_LIBS@

gvrender_lasi.o gvrender_lasi.lo: ps.h

ps.h : $(srcdir)/ps.txt
	$(AWK) -f $(top_srcdir)/awk/stringize.awk $(srcdir)/ps.txt > ps.h

if WITH_WIN32
libgvplugin_lasi_la_LDFLAGS += -no-undefined
endif

if WITH_DARWIN9
libgvplugin_lasi_la_LDFLAGS += -Wl,-exported_symbol,_gvplugin_lasi_LTX_library
endif

EXTRA_DIST = ps.h Makefile.old

DISTCLEANFILES = ps.h


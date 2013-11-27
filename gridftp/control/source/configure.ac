AC_INIT([globus_ftp_control], [4.7])
AM_INIT_AUTOMAKE
AM_PROG_LIBTOOL

MAJOR_VERSION=${PACKAGE_VERSION%%.*}
MINOR_VERSION=${PACKAGE_VERSION##*.}
AGE_VERSION=3

AC_SUBST(MAJOR_VERSION)
AC_SUBST(MINOR_VERSION)
AC_SUBST(AGE_VERSION)

m4_include([dirt.sh])
AC_SUBST(DIRT_TIMESTAMP)
AC_SUBST(DIRT_BRANCH_ID)

PACKAGE_DEPS="globus-common >= 14 globus-gss-assist >= 8 globus-gssapi-gsi >= 9 globus-io >= 8 globus-xio >= 3 globus-gssapi-error >= 4"

AC_SUBST(PACKAGE_DEPS)

PKG_CHECK_MODULES([PACKAGE_DEP], $PACKAGE_DEPS)

AC_PATH_PROGS([DOXYGEN], doxygen)

AM_CONDITIONAL([ENABLE_DOXYGEN], [test "$DOXYGEN" != ""])
AC_CONFIG_FILES(
        globus-ftp-control.pc
        globus-ftp-control-uninstalled.pc
        Makefile
        Doxyfile
	version.h)

AC_OUTPUT
AC_PREREQ([2.60])

AC_INIT([globus_gridmap_eppn_callout],[1.14],[https://github.com/globus/globus-toolkit/issues])
AC_CONFIG_MACRO_DIR([m4])
AC_SUBST([MAJOR_VERSION], [${PACKAGE_VERSION%%.*}])
AC_SUBST([MINOR_VERSION], [${PACKAGE_VERSION##*.}])
AC_SUBST([AGE_VERSION], [1])
AC_SUBST([PACKAGE_DEPS], ["globus-common >= 14, globus-gsi-sysconfig >= 5, globus-gssapi-gsi >= 9, globus-gss-assist >= 8, globus-gridmap-callout-error >= 0, globus-gsi-credential >= 6, globus-gsi-cert-utils >= 8, globus-gsi-openssl-error >= 2, globus-gssapi-error >= 4"])

AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE([1.11 foreign parallel-tests tar-pax])
LT_INIT([dlopen win32-dll])

m4_include([dirt.sh])
AC_SUBST(DIRT_TIMESTAMP)
AC_SUBST(DIRT_BRANCH_ID)

PKG_CHECK_MODULES([OPENSSL], [openssl >= 1.0],
    [OPENSSL_PKGCONFIG="openssl >= 1.0"],
    [
        PKG_CHECK_MODULES([OPENSSL], [openssl101e])
        OPENSSL_PKGCONFIG="openssl101e"
    ])

AC_SUBST([OPENSSL_PKGCONFIG])
PKG_CHECK_MODULES([PACKAGE_DEP], $PACKAGE_DEPS)

AC_CONFIG_FILES(
        globus-gridmap-eppn-callout-uninstalled.pc
        globus-gridmap-eppn-callout.pc
        Makefile
	version.h)
AC_OUTPUT

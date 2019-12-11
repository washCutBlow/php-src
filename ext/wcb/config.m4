PHP_ARG_ENABLE(wcb, whether to enable wcb support,
[  --enable-wcb          Enable wcb support], no)

if test "$PHP_WCB" != "no"; then
  AC_DEFINE(HAVE_WCB, 1, [ Have wcb support ])
  PHP_NEW_EXTENSION(wcb, wcb.c, $ext_shared)
fi

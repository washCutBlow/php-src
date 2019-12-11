/* wcb extension for PHP */

#ifndef PHP_WCB_H
# define PHP_WCB_H

extern zend_module_entry wcb_module_entry;
# define phpext_wcb_ptr &wcb_module_entry

# define PHP_WCB_VERSION "0.1.0"

# if defined(ZTS) && defined(COMPILE_DL_WCB)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_WCB_H */

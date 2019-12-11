/* wcb extension for PHP */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

// 该文件包含了我们常用的php扩展API定义
#include "php.h"
#include "ext/standard/info.h"
#include "php_wcb.h"

/* {{{ void wcb_test1()
 */
PHP_FUNCTION(wcb_test1)
{
	ZEND_PARSE_PARAMETERS_NONE();

	php_printf("The extension %s is loaded and working!\r\n", "wcb");
}
/* }}} */

/* {{{ string wcb_test2( [ string $var ] )
 */
PHP_FUNCTION(wcb_test2)
{
	char *var = "World";
	size_t var_len = sizeof("World") - 1;
	zend_string *retval;

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STRING(var, var_len)
	ZEND_PARSE_PARAMETERS_END();

	retval = strpprintf(0, "Hello %s", var);

	RETURN_STR(retval);
}
/* }}}*/

/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(wcb)
{
#if defined(ZTS) && defined(COMPILE_DL_WCB)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(wcb)
{
	return SUCCESS;
}
/* }}} */

PHP_RSHUTDOWN_FUNCTION(wcb)
{
// 例如记录请求结束时间， 并把相应的信息写⼊到⽇ ⾄⽂件中。
	return SUCCESS;
}

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(wcb)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "wcb support", "enabled");
	php_info_print_table_end();
}
/* }}} */

/* {{{ arginfo
 */
ZEND_BEGIN_ARG_INFO(arginfo_wcb_test1, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_wcb_test2, 0)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()
/* }}} */

/* {{{ wcb_functions[]
 */
static const zend_function_entry wcb_functions[] = {
	PHP_FE(wcb_test1,		arginfo_wcb_test1)
	PHP_FE(wcb_test2,		arginfo_wcb_test2)
	PHP_FE_END
};
/* }}} */

/* {{{ wcb_module_entry
 */
zend_module_entry wcb_module_entry = {
	STANDARD_MODULE_HEADER, //该字段为zend_module_entry结构体的前四个字段 size zend_api zend_debug zts
	NULL,	// ini_entry
	NULL,	// deps
	"wcb",					/* Extension name */
	/*wcb_functions*/NULL,			/* zend_function_entry */
	/*NULL*/extension_startup,							/* PHP_MINIT - Module initialization */
	/*NULL*/extension_shutdown,							/* PHP_MSHUTDOWN - Module shutdown */
	/*PHP_RINIT(wcb)*/extension_before_request,			/* PHP_RINIT - Request initialization */
	/*NULL*/extension_after_request,							/* PHP_RSHUTDOWN - Request shutdown */
	/*PHP_MINFO(wcb)*/extension_info,			/* PHP_MINFO - Module info */
	PHP_WCB_VERSION,		/* Version */
	// 填充了这些字段globals_size,globals_ptr,globals_ctor,globals_dtor,post_deactivate_func,module_started,type,
	// handle,module_number,build_id
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_WCB
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
// php/php-fpm程序会通过这个获取到我们的扩展定义
ZEND_GET_MODULE(wcb)
#endif

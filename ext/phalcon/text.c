
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/object.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */
/**
 * Phalcon\Text
 *
 * Provides utilities to work with texts
 */
ZEPHIR_INIT_CLASS(Phalcon_Text) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Text, phalcon, text, phalcon_text_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_class_constant_long(phalcon_text_ce, SL("RANDOM_ALNUM"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_text_ce, SL("RANDOM_ALPHA"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_text_ce, SL("RANDOM_HEXDEC"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_text_ce, SL("RANDOM_NUMERIC"), 3 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_text_ce, SL("RANDOM_NOZERO"), 4 TSRMLS_CC);

	return SUCCESS;

}

/**
 * Converts strings to camelize style
 *
 *<code>
 *      echo Phalcon\Text::camelize('coco_bongo'); //CocoBongo
 *</code>
 *
 * @param string str
 * @return string
 */
PHP_METHOD(Phalcon_Text, camelize) {

	zval *str_param = NULL, *_0;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);


	ZEPHIR_INIT_VAR(_0);
	zephir_camelize(_0, str);
	RETURN_CCTOR(_0);

}

/**
 * Uncamelize strings which are camelized
 *
 *<code>
 *      echo Phalcon\Text::camelize('CocoBongo'); //coco_bongo
 *</code>
 *
 * @param string str
 * @return string
 */
PHP_METHOD(Phalcon_Text, uncamelize) {

	zval *str_param = NULL, *_0;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);


	ZEPHIR_INIT_VAR(_0);
	zephir_uncamelize(_0, str);
	RETURN_CCTOR(_0);

}

/**
 * Adds a number to a string or increment that number if it already is defined
 *
 *<code>
 *	echo Phalcon\Text::increment("a"); // "a_1"
 *	echo Phalcon\Text::increment("a_1"); // "a_2"
 *</code>
 *
 * @param string $str
 * @param string $separator
 * @return string
 */
PHP_METHOD(Phalcon_Text, increment) {

	zval *str_param = NULL, *separator = NULL, *parts, *number, *_0;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &str_param, &separator);

	zephir_get_strval(str, str_param);
	if (!separator) {
		ZEPHIR_CPY_WRT(separator, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(separator);
	}


	if (Z_TYPE_P(separator) == IS_NULL) {
		ZEPHIR_INIT_NVAR(separator);
		ZVAL_LONG(separator, '_');
	}
	ZEPHIR_INIT_VAR(parts);
	zephir_fast_explode(parts, separator, str, LONG_MAX TSRMLS_CC);
	ZEPHIR_OBS_VAR(number);
	if (zephir_array_isset_long_fetch(&number, parts, 1, 0 TSRMLS_CC)) {
		ZEPHIR_SEPARATE(number);
		zephir_increment(number);
	} else {
		ZEPHIR_INIT_BNVAR(number);
		ZVAL_LONG(number, 1);
	}
	zephir_array_fetch_long(&_0, parts, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
	ZEPHIR_CONCAT_VVV(return_value, _0, separator, number);
	RETURN_MM();

}

/**
 * Generates a random string based on the given type. Type is one of the RANDOM_* constants
 *
 *<code>
 *	echo Phalcon\Text::random(Phalcon\Text::RANDOM_ALNUM); //"aloiwkqz"
 *</code>
 *
 * @param int type
 * @param int length
 * @return string
 */
PHP_METHOD(Phalcon_Text, random) {

	int ZEPHIR_LAST_CALL_STATUS;
	long length;
	zval *type_param = NULL, *length_param = NULL, *_0;
	zval *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &type_param, &length_param);

	zephir_get_strval(type, type_param);
	if (!length_param) {
		length = 8;
	} else {
		length = zephir_get_intval(length_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, length);
	ZEPHIR_RETURN_CALL_FUNCTION("random_string", NULL, type, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Check if a string starts with a given string
 *
 *<code>
 *	echo Phalcon\Text::startsWith("Hello", "He"); // true
 *	echo Phalcon\Text::startsWith("Hello", "he"); // false
 *	echo Phalcon\Text::startsWith("Hello", "he", false); // true
 *</code>
 *
 * @param string str
 * @param string start
 * @param boolean ignoreCase
 * @return boolean
 */
PHP_METHOD(Phalcon_Text, startsWith) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *str, *start, *ignoreCase = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &str, &start, &ignoreCase);

	if (!ignoreCase) {
		ignoreCase = ZEPHIR_GLOBAL(global_true);
	}


	ZEPHIR_RETURN_CALL_FUNCTION("starts_with", NULL, str, start, ignoreCase);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Check if a string ends with a given string
 *
 *<code>
 *	echo Phalcon\Text::endsWith("Hello", "llo"); // true
 *	echo Phalcon\Text::endsWith("Hello", "LLO"); // false
 *	echo Phalcon\Text::endsWith("Hello", "LLO", false); // true
 *</code>
 *
 * @param string str
 * @param string end
 * @param boolean ignoreCase
 * @return boolean
 */
PHP_METHOD(Phalcon_Text, endsWith) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool ignoreCase;
	zval *str_param = NULL, *end_param = NULL, *ignoreCase_param = NULL;
	zval *str = NULL, *end = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &str_param, &end_param, &ignoreCase_param);

	zephir_get_strval(str, str_param);
	zephir_get_strval(end, end_param);
	if (!ignoreCase_param) {
		ignoreCase = 1;
	} else {
		ignoreCase = zephir_get_boolval(ignoreCase_param);
	}


	ZEPHIR_RETURN_CALL_FUNCTION("ends_with", NULL, str, end, (ignoreCase ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Lowercases a string, this function makes use of the mbstring extension if available
 *
 * @param string $str
 * @return string
 */
PHP_METHOD(Phalcon_Text, lower) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *str_param = NULL;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);


	if ((zephir_function_exists_ex(SS("mb_strtolower") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_RETURN_CALL_FUNCTION("mb_strtolower", NULL, str);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_fast_strtolower(return_value, str);
	RETURN_MM();

}

/**
 * Uppercases a string, this function makes use of the mbstring extension if available
 *
 * @param string str
 * @return string
 */
PHP_METHOD(Phalcon_Text, upper) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *str_param = NULL;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);


	if ((zephir_function_exists_ex(SS("mb_strtoupper") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_RETURN_CALL_FUNCTION("mb_strtoupper", NULL, str);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_fast_strtoupper(return_value, str);
	RETURN_MM();

}


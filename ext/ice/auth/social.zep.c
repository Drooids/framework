
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"


/**
 * Simple implementation of authentication through popular social networks.
 *
 * @package     Ice/Auth
 * @category    Library
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Auth_Social) {

	ZEPHIR_REGISTER_CLASS(Ice\\Auth, Social, ice, auth_social, ice_auth_social_method_entry, 0);

	zend_declare_property_null(ice_auth_social_ce, SL("_adapter"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Ice_Auth_Social, getAdapter) {


	RETURN_MEMBER(this_ptr, "_adapter");

}

/**
 * Constructor.
 *
 * @param SocialInterface adapter
 */
PHP_METHOD(Ice_Auth_Social, __construct) {

	zval *adapter;

	zephir_fetch_params(0, 1, 0, &adapter);



	if (!(zephir_instance_of_ev(adapter, ice_auth_social_socialinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'adapter' must be an instance of 'Ice\\Auth\\Social\\SocialInterface'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("_adapter"), adapter TSRMLS_CC);

}

/**
 * Call method authenticate() of adater class.
 *
 * @return boolean
 */
PHP_METHOD(Ice_Auth_Social, authenticate) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_adapter"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "authenticate", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Retrieve a single key from an adapter.
 *
 * @param string key The data key
 * @param mixed defaultValue The value to return if data key does not exist
 * @return mixed
 */
PHP_METHOD(Ice_Auth_Social, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *defaultValue = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &defaultValue);

	zephir_get_strval(key, key_param);
	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_adapter"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "get", NULL, key, defaultValue);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Call method of this class or methods of adapter class.
 *
 * @param string method
 * @param mixed arguments
 * @return mixed
 */
PHP_METHOD(Ice_Auth_Social, __call) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *method_param = NULL, *arguments = NULL, *_1;
	zval *method = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &method_param, &arguments);

	zephir_get_strval(method, method_param);
	if (!arguments) {
		arguments = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 3);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("_adapter"), PH_NOISY_CC);
	zephir_array_fast_append(_0, _1);
	zephir_array_fast_append(_0, method);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, _0, arguments);
	zephir_check_call_status();
	RETURN_MM();

}


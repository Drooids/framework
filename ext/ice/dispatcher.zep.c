
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/file.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"

ZEPHIR_INIT_CLASS(Ice_Dispatcher) {

	ZEPHIR_REGISTER_CLASS(Ice, Dispatcher, ice, dispatcher, ice_dispatcher_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(ice_dispatcher_ce, SL("_di"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_dispatcher_ce, SL("_defaultNamespace"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_dispatcher_ce, SL("_activeHandler"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_dispatcher_ce, SL("_lastHandler"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_dispatcher_ce, SL("_finished"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(ice_dispatcher_ce, SL("_forwarded"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(ice_dispatcher_ce, SL("_silent"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_dispatcher_ce, SL("_modules"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_dispatcher_ce, SL("_module"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_dispatcher_ce, SL("_namespace"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_dispatcher_ce, SL("_handler"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_dispatcher_ce, SL("_action"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_dispatcher_ce, SL("_params"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_dispatcher_ce, SL("_returnedValue"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_dispatcher_ce, SL("_handlerSuffix"), "Handler", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_dispatcher_ce, SL("_actionSuffix"), "Action", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_dispatcher_ce, SL("_previousModule"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_dispatcher_ce, SL("_previousHandler"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_dispatcher_ce, SL("_previousAction"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_long(ice_dispatcher_ce, SL("DISPATCH_CYCLIC"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(ice_dispatcher_ce, SL("HANDLER_NOT_FOUND"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(ice_dispatcher_ce, SL("ACTION_NOT_FOUND"), 3 TSRMLS_CC);

	zend_declare_class_constant_long(ice_dispatcher_ce, SL("INVALID_PARAMS"), 4 TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Ice_Dispatcher, getDefaultNamespace) {


	RETURN_MEMBER(this_ptr, "_defaultNamespace");

}

PHP_METHOD(Ice_Dispatcher, setDefaultNamespace) {

	zval *defaultNamespace;

	zephir_fetch_params(0, 1, 0, &defaultNamespace);



	zephir_update_property_this(this_ptr, SL("_defaultNamespace"), defaultNamespace TSRMLS_CC);

}

PHP_METHOD(Ice_Dispatcher, getActiveHandler) {


	RETURN_MEMBER(this_ptr, "_activeHandler");

}

PHP_METHOD(Ice_Dispatcher, getLastHandler) {


	RETURN_MEMBER(this_ptr, "_lastHandler");

}

PHP_METHOD(Ice_Dispatcher, getFinished) {


	RETURN_MEMBER(this_ptr, "_finished");

}

PHP_METHOD(Ice_Dispatcher, getForwarded) {


	RETURN_MEMBER(this_ptr, "_forwarded");

}

PHP_METHOD(Ice_Dispatcher, setSilent) {

	zval *silent;

	zephir_fetch_params(0, 1, 0, &silent);



	zephir_update_property_this(this_ptr, SL("_silent"), silent TSRMLS_CC);

}

PHP_METHOD(Ice_Dispatcher, getModules) {


	RETURN_MEMBER(this_ptr, "_modules");

}

PHP_METHOD(Ice_Dispatcher, setModules) {

	zval *modules;

	zephir_fetch_params(0, 1, 0, &modules);



	zephir_update_property_this(this_ptr, SL("_modules"), modules TSRMLS_CC);

}

PHP_METHOD(Ice_Dispatcher, getModule) {


	RETURN_MEMBER(this_ptr, "_module");

}

PHP_METHOD(Ice_Dispatcher, setModule) {

	zval *module;

	zephir_fetch_params(0, 1, 0, &module);



	zephir_update_property_this(this_ptr, SL("_module"), module TSRMLS_CC);

}

PHP_METHOD(Ice_Dispatcher, getNamespace) {


	RETURN_MEMBER(this_ptr, "_namespace");

}

PHP_METHOD(Ice_Dispatcher, setNamespace) {

	zval *namespace;

	zephir_fetch_params(0, 1, 0, &namespace);



	zephir_update_property_this(this_ptr, SL("_namespace"), namespace TSRMLS_CC);

}

PHP_METHOD(Ice_Dispatcher, getHandler) {


	RETURN_MEMBER(this_ptr, "_handler");

}

PHP_METHOD(Ice_Dispatcher, setHandler) {

	zval *handler;

	zephir_fetch_params(0, 1, 0, &handler);



	zephir_update_property_this(this_ptr, SL("_handler"), handler TSRMLS_CC);

}

PHP_METHOD(Ice_Dispatcher, getAction) {


	RETURN_MEMBER(this_ptr, "_action");

}

PHP_METHOD(Ice_Dispatcher, setAction) {

	zval *action;

	zephir_fetch_params(0, 1, 0, &action);



	zephir_update_property_this(this_ptr, SL("_action"), action TSRMLS_CC);

}

PHP_METHOD(Ice_Dispatcher, getParams) {


	RETURN_MEMBER(this_ptr, "_params");

}

PHP_METHOD(Ice_Dispatcher, setParams) {

	zval *params;

	zephir_fetch_params(0, 1, 0, &params);



	zephir_update_property_this(this_ptr, SL("_params"), params TSRMLS_CC);

}

PHP_METHOD(Ice_Dispatcher, getReturnedValue) {


	RETURN_MEMBER(this_ptr, "_returnedValue");

}

PHP_METHOD(Ice_Dispatcher, setReturnedValue) {

	zval *returnedValue;

	zephir_fetch_params(0, 1, 0, &returnedValue);



	zephir_update_property_this(this_ptr, SL("_returnedValue"), returnedValue TSRMLS_CC);

}

PHP_METHOD(Ice_Dispatcher, getHandlerSuffix) {


	RETURN_MEMBER(this_ptr, "_handlerSuffix");

}

PHP_METHOD(Ice_Dispatcher, setHandlerSuffix) {

	zval *handlerSuffix;

	zephir_fetch_params(0, 1, 0, &handlerSuffix);



	zephir_update_property_this(this_ptr, SL("_handlerSuffix"), handlerSuffix TSRMLS_CC);

}

PHP_METHOD(Ice_Dispatcher, getActionSuffix) {


	RETURN_MEMBER(this_ptr, "_actionSuffix");

}

PHP_METHOD(Ice_Dispatcher, setActionSuffix) {

	zval *actionSuffix;

	zephir_fetch_params(0, 1, 0, &actionSuffix);



	zephir_update_property_this(this_ptr, SL("_actionSuffix"), actionSuffix TSRMLS_CC);

}

/**
 * Di constructor. Fetch Di and set it as a property.
 */
PHP_METHOD(Ice_Dispatcher, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zval *_0, *_1, *_2 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("_params"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("_modules"), _1 TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(&_2, ice_di_ce, "fetch", &_3);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_di"), _2 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Set a param by its name or numeric index.
 *
 * @param mixed param
 * @param mixed value
 */
PHP_METHOD(Ice_Dispatcher, setParam) {

	zval *param, *value;

	zephir_fetch_params(0, 2, 0, &param, &value);



	zephir_update_property_array(this_ptr, SL("_params"), param, value TSRMLS_CC);

}

/**
 * Gets a param by its name or numeric index.
 *
 * @param mixed param
 * @param mixed defaultValue
 * @return mixed
 */
PHP_METHOD(Ice_Dispatcher, getParam) {

	zval *param, *defaultValue = NULL, *value, *_0;

	zephir_fetch_params(0, 1, 1, &param, &defaultValue);

	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_params"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&value, _0, param, 1 TSRMLS_CC)) {
		RETURN_CTORW(value);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	return;

}

/**
 * Returns the current method to be/executed in the dispatcher.
 *
 * @return string
 */
PHP_METHOD(Ice_Dispatcher, getActiveMethod) {

	zval *_0, *_1;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_action"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_actionSuffix"), PH_NOISY_CC);
	ZEPHIR_CONCAT_VV(return_value, _0, _1);
	return;

}

/**
 * Dispatches a handle action taking into account the routing parameters.
 *
 * @return object
 */
PHP_METHOD(Ice_Dispatcher, dispatch) {

	zend_class_entry *_26;
	zval *_11 = NULL, *_31 = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_6 = NULL, *_7 = NULL, *_10 = NULL, *_13 = NULL, *_15 = NULL, *_17 = NULL, *_19 = NULL, *_20 = NULL, *_21 = NULL, *_22 = NULL, *_23 = NULL, *_27 = NULL, *_28 = NULL, *_29 = NULL, *_30 = NULL;
	int i = 0, ZEPHIR_LAST_CALL_STATUS;
	zend_bool fresh;
	zval *handler = NULL, *response = NULL, *handlerName = NULL, *actionName = NULL, *params = NULL, *handlerSuffix, *actionSuffix, *handlerClass = NULL, *actionMethod = NULL, *module = NULL, *modules = NULL, *moduleNamespace = NULL, *path = NULL, *moduleClass = NULL, *loader = NULL, *_0, *_1 = NULL, *_2, *_3, *_5 = NULL, *_8 = NULL, *_9 = NULL, *_12 = NULL, *_14 = NULL, *_16, *_18 = NULL, *_24 = NULL, *_25 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "response", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&response, _0, "get", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	fresh = 1;
	ZEPHIR_INIT_VAR(handler);
	ZVAL_NULL(handler);
	ZEPHIR_OBS_VAR(handlerSuffix);
	zephir_read_property_this(&handlerSuffix, this_ptr, SL("_handlerSuffix"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(actionSuffix);
	zephir_read_property_this(&actionSuffix, this_ptr, SL("_actionSuffix"), PH_NOISY_CC);
	zephir_update_property_this(this_ptr, SL("_finished"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	while (1) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
		if (!(!(zephir_is_true(_2)))) {
			break;
		}
		i++;
		if (i == 16) {
			_3 = zephir_fetch_nproperty_this(this_ptr, SL("_silent"), PH_NOISY_CC);
			if (zephir_is_true(_3)) {
				ZEPHIR_INIT_NVAR(_1);
				ZVAL_LONG(_1, 508);
				ZEPHIR_CALL_METHOD(NULL, response, "setstatus", &_4, _1);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_1);
				ZVAL_LONG(_1, 508);
				ZEPHIR_CALL_METHOD(&_5, response, "getmessage", &_6, _1);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, response, "setbody", &_7, _5);
				zephir_check_call_status();
				RETURN_CCTOR(response);
			}
			ZEPHIR_INIT_NVAR(_1);
			object_init_ex(_1, ice_exception_ce);
			ZEPHIR_INIT_NVAR(_8);
			ZVAL_STRING(_8, "Dispatcher has detected a cyclic routing causing stability problems", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_NVAR(_9);
			ZVAL_LONG(_9, 1);
			ZEPHIR_CALL_METHOD(NULL, _1, "__construct", &_10, _8, _9);
			zephir_check_temp_parameter(_8);
			zephir_check_call_status();
			zephir_throw_exception_debug(_1, "ice/dispatcher.zep", 125 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_this(this_ptr, SL("_finished"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		ZEPHIR_OBS_NVAR(modules);
		zephir_read_property_this(&modules, this_ptr, SL("_modules"), PH_NOISY_CC);
		if (zephir_is_true(modules)) {
			ZEPHIR_OBS_NVAR(module);
			_3 = zephir_fetch_nproperty_this(this_ptr, SL("_module"), PH_NOISY_CC);
			if (!(zephir_array_isset_fetch(&module, modules, _3, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(_1);
				object_init_ex(_1, ice_exception_ce);
				ZEPHIR_INIT_NVAR(_11);
				zephir_create_array(_11, 2, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_8);
				ZVAL_STRING(_8, "Module '%s' isn't registered in the application container", 1);
				zephir_array_fast_append(_11, _8);
				ZEPHIR_OBS_NVAR(_12);
				zephir_read_property_this(&_12, this_ptr, SL("_module"), PH_NOISY_CC);
				zephir_array_fast_append(_11, _12);
				ZEPHIR_CALL_METHOD(NULL, _1, "__construct", &_10, _11);
				zephir_check_call_status();
				zephir_throw_exception_debug(_1, "ice/dispatcher.zep", 133 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (Z_TYPE_P(module) != IS_ARRAY) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Module definition must be an array", "ice/dispatcher.zep", 137);
				return;
			}
			ZEPHIR_OBS_NVAR(path);
			if (zephir_array_isset_string_fetch(&path, module, SS("path"), 0 TSRMLS_CC)) {
				if (!((zephir_file_exists(path TSRMLS_CC) == SUCCESS))) {
					ZEPHIR_INIT_NVAR(_1);
					object_init_ex(_1, ice_exception_ce);
					ZEPHIR_INIT_NVAR(_11);
					zephir_create_array(_11, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_8);
					ZVAL_STRING(_8, "Module definition path '%s' doesn't exist", 1);
					zephir_array_fast_append(_11, _8);
					zephir_array_fast_append(_11, path);
					ZEPHIR_CALL_METHOD(NULL, _1, "__construct", &_10, _11);
					zephir_check_call_status();
					zephir_throw_exception_debug(_1, "ice/dispatcher.zep", 142 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			ZEPHIR_OBS_NVAR(moduleClass);
			if (!(zephir_array_isset_string_fetch(&moduleClass, module, SS("class"), 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(moduleClass);
				ZVAL_STRING(moduleClass, "Module", 1);
			}
			ZEPHIR_OBS_NVAR(moduleNamespace);
			if (!(zephir_array_isset_string_fetch(&moduleNamespace, module, SS("namespace"), 0 TSRMLS_CC))) {
				ZEPHIR_CPY_WRT(moduleNamespace, moduleClass);
			}
			ZEPHIR_INIT_NVAR(loader);
			object_init_ex(loader, ice_loader_ce);
			if (zephir_has_constructor(loader TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, loader, "__construct", NULL);
				zephir_check_call_status();
			}
			zephir_update_property_this(this_ptr, SL("_namespace"), moduleNamespace TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_5, loader, "addnamespace", &_13, moduleNamespace, path);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, _5, "register", NULL);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_1);
			ZEPHIR_INIT_LNVAR(_14);
			ZEPHIR_CONCAT_VSV(_14, moduleNamespace, "\\", moduleClass);
			ZEPHIR_INIT_NVAR(_11);
			zephir_create_array(_11, 1, 0 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(_12);
			zephir_read_property_this(&_12, this_ptr, SL("_di"), PH_NOISY_CC);
			zephir_array_fast_append(_11, _12);
			ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(_1, _14, _11 TSRMLS_CC);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(module, _1);
			ZEPHIR_CALL_METHOD(NULL, module, "registerautoloaders", &_15);
			zephir_check_call_status();
			_16 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(NULL, module, "registerservices", &_17, _16);
			zephir_check_call_status();
		}
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultNamespace"), PH_NOISY_CC);
		if (!(zephir_is_true(_3))) {
			_16 = zephir_fetch_nproperty_this(this_ptr, SL("_namespace"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_18, this_ptr, "gethandlersuffix", &_19);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_14);
			ZEPHIR_CONCAT_VSV(_14, _16, "\\", _18);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdefaultnamespace", &_20, _14);
			zephir_check_call_status();
		}
		ZEPHIR_OBS_NVAR(handlerName);
		zephir_read_property_this(&handlerName, this_ptr, SL("_handler"), PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(actionName);
		zephir_read_property_this(&actionName, this_ptr, SL("_action"), PH_NOISY_CC);
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultNamespace"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_1);
		ZEPHIR_INIT_NVAR(_8);
		zephir_camelize(_8, handlerName);
		zephir_ucfirst(_1, _8);
		ZEPHIR_INIT_NVAR(handlerClass);
		ZEPHIR_CONCAT_VSVV(handlerClass, _3, "\\", _1, handlerSuffix);
		if (!(zephir_class_exists(handlerClass, 1 TSRMLS_CC))) {
			_16 = zephir_fetch_nproperty_this(this_ptr, SL("_silent"), PH_NOISY_CC);
			if (zephir_is_true(_16)) {
				ZEPHIR_INIT_NVAR(_9);
				ZVAL_LONG(_9, 404);
				ZEPHIR_CALL_METHOD(NULL, response, "setstatus", &_21, _9);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_9);
				ZVAL_LONG(_9, 404);
				ZEPHIR_CALL_METHOD(&_18, response, "getmessage", &_22, _9);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, response, "setbody", &_23, _18);
				zephir_check_call_status();
				RETURN_CCTOR(response);
			}
			ZEPHIR_INIT_NVAR(_9);
			object_init_ex(_9, ice_exception_ce);
			ZEPHIR_INIT_NVAR(_11);
			zephir_create_array(_11, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_24);
			ZVAL_STRING(_24, "%s handler class cannot be loaded", 1);
			zephir_array_fast_append(_11, _24);
			zephir_array_fast_append(_11, handlerClass);
			ZEPHIR_INIT_NVAR(_24);
			ZVAL_LONG(_24, 2);
			ZEPHIR_CALL_METHOD(NULL, _9, "__construct", &_10, _11, _24);
			zephir_check_call_status();
			zephir_throw_exception_debug(_9, "ice/dispatcher.zep", 181 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_this(this_ptr, SL("_lastHandler"), handler TSRMLS_CC);
		ZEPHIR_INIT_NVAR(handler);
		zephir_fetch_safe_class(_25, handlerClass);
		_26 = zend_fetch_class(Z_STRVAL_P(_25), Z_STRLEN_P(_25), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(handler, _26);
		if (zephir_has_constructor(handler TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, handler, "__construct", NULL);
			zephir_check_call_status();
		}
		zephir_update_property_this(this_ptr, SL("_activeHandler"), handler TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&actionMethod, this_ptr, "getactivemethod", &_27);
		zephir_check_call_status();
		if ((zephir_method_exists_ex(handler, SS("before") TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_CALL_METHOD(NULL, handler, "before", NULL);
			zephir_check_call_status();
			_3 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
			if (ZEPHIR_IS_FALSE_IDENTICAL(_3)) {
				continue;
			}
		}
		if (fresh == 1) {
			if ((zephir_method_exists_ex(handler, SS("initialize") TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_CALL_METHOD(NULL, handler, "initialize", NULL);
				zephir_check_call_status();
			}
		}
		if (!((zephir_method_exists(handler, actionMethod TSRMLS_CC)  == SUCCESS))) {
			_3 = zephir_fetch_nproperty_this(this_ptr, SL("_silent"), PH_NOISY_CC);
			if (zephir_is_true(_3)) {
				ZEPHIR_INIT_NVAR(_8);
				ZVAL_LONG(_8, 404);
				ZEPHIR_CALL_METHOD(NULL, response, "setstatus", &_28, _8);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_8);
				ZVAL_LONG(_8, 404);
				ZEPHIR_CALL_METHOD(&_5, response, "getmessage", &_29, _8);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, response, "setbody", &_30, _5);
				zephir_check_call_status();
				RETURN_CCTOR(response);
			}
			ZEPHIR_INIT_NVAR(_8);
			object_init_ex(_8, ice_exception_ce);
			ZEPHIR_INIT_NVAR(_11);
			zephir_create_array(_11, 3, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_9);
			ZVAL_STRING(_9, "Action '%s' was not found on handler '%s'", 1);
			zephir_array_fast_append(_11, _9);
			zephir_array_fast_append(_11, actionName);
			zephir_array_fast_append(_11, handlerName);
			ZEPHIR_INIT_NVAR(_9);
			ZVAL_LONG(_9, 3);
			ZEPHIR_CALL_METHOD(NULL, _8, "__construct", &_10, _11, _9);
			zephir_check_call_status();
			zephir_throw_exception_debug(_8, "ice/dispatcher.zep", 214 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(params);
		zephir_read_property_this(&params, this_ptr, SL("_params"), PH_NOISY_CC);
		if (Z_TYPE_P(params) != IS_ARRAY) {
			ZEPHIR_INIT_NVAR(_8);
			object_init_ex(_8, ice_exception_ce);
			ZEPHIR_INIT_NVAR(_9);
			ZVAL_STRING(_9, "Action parameters must be an array", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_NVAR(_24);
			ZVAL_LONG(_24, 4);
			ZEPHIR_CALL_METHOD(NULL, _8, "__construct", &_10, _9, _24);
			zephir_check_temp_parameter(_9);
			zephir_check_call_status();
			zephir_throw_exception_debug(_8, "ice/dispatcher.zep", 219 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_NVAR(_8);
		ZEPHIR_INIT_NVAR(_31);
		zephir_create_array(_31, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(_31, handler);
		zephir_array_fast_append(_31, actionMethod);
		ZEPHIR_CALL_USER_FUNC_ARRAY(_8, _31, params);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_returnedValue"), _8 TSRMLS_CC);
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
		if (ZEPHIR_IS_FALSE_IDENTICAL(_3)) {
			continue;
		}
		if ((zephir_method_exists_ex(handler, SS("after") TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_CALL_METHOD(NULL, handler, "after", NULL);
			zephir_check_call_status();
			_3 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
			if (ZEPHIR_IS_FALSE_IDENTICAL(_3)) {
				continue;
			}
		}
		fresh = 0;
	}
	RETURN_CCTOR(handler);

}

/**
 * Forwards the execution flow to another module/controller/action.
 *
 * @param array forward
 */
PHP_METHOD(Ice_Dispatcher, forward) {

	zval *forward_param = NULL, *module, *handler, *action, *params, *_0;
	zval *forward = NULL;

	zephir_fetch_params(0, 1, 0, &forward_param);

	forward = forward_param;



	if (zephir_array_isset_string_fetch(&module, forward, SS("module"), 1 TSRMLS_CC)) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_module"), PH_NOISY_CC);
		zephir_update_property_this(this_ptr, SL("_previousModule"), _0 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_module"), module TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&handler, forward, SS("handler"), 1 TSRMLS_CC)) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_handler"), PH_NOISY_CC);
		zephir_update_property_this(this_ptr, SL("_previousHandler"), _0 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_handler"), handler TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&action, forward, SS("action"), 1 TSRMLS_CC)) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_action"), PH_NOISY_CC);
		zephir_update_property_this(this_ptr, SL("_previousAction"), _0 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_action"), action TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&params, forward, SS("params"), 1 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_params"), params TSRMLS_CC);
	}
	zephir_update_property_this(this_ptr, SL("_finished"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_forwarded"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);

}


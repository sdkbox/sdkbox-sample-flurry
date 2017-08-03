#ifndef __PluginFlurryAnalyticsJS_h__
#define __PluginFlurryAnalyticsJS_h__

#include "jsapi.h"
#include "jsfriendapi.h"


#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginFlurryAnalyticsJS_PluginFlurryAnalytics(JSContext *cx, JS::HandleObject global);
void register_all_PluginFlurryAnalyticsJS(JSContext* cx, JS::HandleObject obj);
#else
void js_register_PluginFlurryAnalyticsJS_PluginFlurryAnalytics(JSContext *cx, JSObject* global);
void register_all_PluginFlurryAnalyticsJS(JSContext* cx, JSObject* obj);
#endif
#endif


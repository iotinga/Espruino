
#include "jsvar.h"

JsVar *ShadowJs_Get(int key);
int ShadwoJs_Set(int key, JsVar *value);

JsVar *jswrap_shadow_get(int key);
int jswrap_shadow_set(int key, JsVar *value);
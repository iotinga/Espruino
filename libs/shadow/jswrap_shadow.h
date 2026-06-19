
#include "jsvar.h"

JsVar *ShadowJs_Get(int key);
int ShadowJs_Set(int key, JsVar *value);
JsVar *ScheduleJs_GetSlotAtTimestamp(int key, int timestamp);
JsVar *SetpointJs_GetByKeyAndId(int key, int id);

JsVar *jswrap_shadow_get(int key);
int jswrap_shadow_set(int key, JsVar *value);
JsVar *jswrap_shadow_getScheduleSlotAtTimestamp(int key, int timestamp);
JsVar *jswrap_shadow_getSetpointByKeyAndId(int key, int id);
/*
 * jswrap_shadow.c
 *
 * JavaScript API:
 *
 *   Shadow.get(key)
 *   Shadow.set(key, value)
 */

#include "jswrap_shadow.h"

/*JSON{
  "type" : "class",
  "class" : "Shadow"
}
Native access to the application's registered Shadow instance.
*/

/* ------------------------------------------------------------------------- */
/* Shadow.get(key)                                                           */
/* ------------------------------------------------------------------------- */

/*JSON{
  "type" : "staticmethod",
  "class" : "Shadow",
  "name" : "get",
  "generate" : "jswrap_shadow_get",
  "params" : [
    ["key", "int", "Numeric ShadowKey enum value"]
  ],
  "return" : ["JsVar", "Value"]
}
Read a Shadow value.
*/
JsVar *jswrap_shadow_get(int key)
{
    return ShadowJs_Get(key);
}

/* ------------------------------------------------------------------------- */
/* Shadow.set(key, value)                                                    */
/* ------------------------------------------------------------------------- */

/*JSON{
  "type" : "staticmethod",
  "class" : "Shadow",
  "name" : "set",
  "generate" : "jswrap_shadow_set",
  "params" : [
    ["key", "int", "Numeric ShadowKey enum value"],
    ["value", "JsVar", "Value"]
  ],
  "return" : ["bool", "True on success"]
}
Write a Shadow value.
*/
int jswrap_shadow_set(int key, JsVar *value)
{
    return ShadowJs_Set(key, value);
}

/* ------------------------------------------------------------------------- */
/* Shadow.getScheduleSlotAtTimestamp(key, timestamp)                         */
/* ------------------------------------------------------------------------- */

/*JSON{
  "type" : "staticmethod",
  "class" : "Shadow",
  "name" : "getScheduleSlotAtTimestamp",
  "generate" : "jswrap_shadow_getScheduleSlotAtTimestamp",
  "params" : [
    ["key", "int", "ShadowKey of the schedule bytearray (e.g. PLACE_HEATING_SCHEDULE)"],
    ["timestamp", "int", "Local unix timestamp in seconds"]
  ],
  "return" : ["JsVar", "Object { start, id, day, index } or undefined"]
}
Get the schedule slot active at the given local timestamp.
Returns { start, id, day, index } or undefined.
*/
JsVar *jswrap_shadow_getScheduleSlotAtTimestamp(int key, int timestamp)
{
    return ScheduleJs_GetSlotAtTimestamp(key, timestamp);
}

/* ------------------------------------------------------------------------- */
/* Shadow.getSetpointByKeyAndId(key, id)                                     */
/* ------------------------------------------------------------------------- */

/*JSON{
  "type" : "staticmethod",
  "class" : "Shadow",
  "name" : "getSetpointByKeyAndId",
  "generate" : "jswrap_shadow_getSetpointByKeyAndId",
  "params" : [
    ["key", "int", "ShadowKey of the setpoint array (e.g. ENV_HEATING_SET_POINTS)"],
    ["id", "int", "Index of the setpoint in the array"]
  ],
  "return" : ["JsVar", "Setpoint object or undefined"]
}
Get a setpoint by its array index.
For thermo keys: { value }
For light keys: { hue, sat, val }
*/
JsVar *jswrap_shadow_getSetpointByKeyAndId(int key, int id)
{
    return SetpointJs_GetByKeyAndId(key, id);
}
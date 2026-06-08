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
    return ShadwoJs_Set(key, value);
}
/* This file was generated by Maki Compiler, do not edit manually */

#include <precomp.h>

#include "c_querylist.h"
#include <api/script/objcontroller.h>

C_QueryList::C_QueryList(ScriptObject *object) : C_GuiObject(object) {
  inited = 0;
  obj = NULL;
  C_hook(object);
}

C_QueryList::C_QueryList() {
  inited = 0;
  obj = NULL;
}

void C_QueryList::C_hook(ScriptObject *object) {
  ASSERT(!inited);
  ScriptObjectController *controller = object->vcpu_getController();
  obj = controller->cast(object, queryListGuid);
  if (obj != object && obj != NULL)
    controller = obj->vcpu_getController();
  else
    obj = NULL;

  if (!loaded) {
    loaded = 1;
    onresetquery_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"onResetQuery", this);
  }
  inited = 1;
}

C_QueryList::~C_QueryList() {
}

ScriptObject *C_QueryList::getScriptObject() {
  if (obj != NULL) return obj;
  return C_QUERYLIST_PARENT::getScriptObject();
}

void C_QueryList::onResetQuery() {
  ASSERT(inited);
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), onresetquery_id, NULL);
}

int C_QueryList::loaded=0;
int C_QueryList::onresetquery_id=0;

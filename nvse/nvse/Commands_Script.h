#pragma once

#include "CommandTable.h"
#include "ParamInfos.h"

DEFINE_COMMAND(IsScripted, returns 1 if the object or reference has a script attached to it., 0, 1, kParams_OneOptionalObject);
DEFINE_COMMAND(GetScript, returns the script of the reference or passed object., 0, 1, kParams_OneOptionalObject);
DEFINE_COMMAND(RemoveScript, removes the script of the reference or passed object., 0, 1, kParams_OneOptionalObject);
DEFINE_COMMAND(SetScript, sets the script of the reference or passed object., 0, 2, kParams_OneObject_OneOptionalObject);
DEFINE_COMMAND(IsFormValid, returns 1 if the reference or passed object is valid., 0, 1, kParams_OneOptionalObject);

static ParamInfo kParams_OneReference[1] =
{
	{	"reference",	kParamType_ObjectRef,	0	},
};

DEFINE_COMMAND(IsReference, returns 1 if the passed refVar is a reference., 0, 1, kParams_OneReference);

static ParamInfo kParams_GetVariable[2] =
{
	{	"variable name",	kParamType_String,	0	},
	{	"quest",			kParamType_Quest,	1	},
};

DEFINE_COMMAND(GetVariable, looks up the value of a variable by name, 0, 2, kParams_GetVariable);
DEFINE_COMMAND(HasVariable, returns true if the script has a variable with the specified name, 0, 2, kParams_GetVariable);
DEFINE_COMMAND(GetRefVariable, looks up the value of a ref variable by name, 0, 2, kParams_GetVariable);
DEFINE_CMD_ALT(GetArrayVariable, GetArrayVar, looks up an array variable by name on the calling object or specified quest, 0, 2, kParams_GetVariable);

static ParamInfo kParams_SetNumVariable[3] =
{
	{	"variable name",	kParamType_String,	0	},
	{	"variable value",	kParamType_Float,	0	},
	{	"quest",			kParamType_Quest,	1	},
};

static ParamInfo kParams_SetRefVariable[3] =
{
	{	"variable name",	kParamType_String,	0	},
	{	"variable value",	kParamType_AnyForm,	0	},
	{	"quest",			kParamType_Quest,	1	},
};

DEFINE_COMMAND(SetVariable, sets the value of a variable by name, 0, 3, kParams_SetNumVariable);
DEFINE_COMMAND(SetRefVariable, sets the value of a variable by name, 0, 3, kParams_SetRefVariable);

static ParamInfo kParams_CompareScripts[2] =
{
	{	"script",	kParamType_ObjectID,	0	},
	{	"script",	kParamType_ObjectID,	0	},
};

DEFINE_COMMAND(CompareScripts, returns true if the compiled scripts are identical, 0, 2, kParams_CompareScripts);

DEFINE_COMMAND(ResetAllVariables, sets all variables in a script to zero, 0, 0, NULL);

static ParamInfo kParams_GetFormFromMod[2] =
{
	{	"modName",	kParamType_String,	0	},
	{	"formID",	kParamType_String,	0	},
};

DEFINE_COMMAND(GetNumExplicitRefs, returns the number of literal references in a script, 0, 1, kParams_OneOptionalObjectID);

DEFINE_COMMAND(GetNthExplicitRef, returns the nth literal reference in a script, 0, 2, kParams_OneInt_OneOptionalObjectID);

DEFINE_COMMAND(RunScript, debug, 0, 1, kParams_OneObjectID);

DEFINE_COMMAND(GetCurrentScript, returns the calling script, 0, 0, NULL);
DEFINE_COMMAND(GetCallingScript, returns the script that called the executing function script, 0, 0, NULL);

#if EVENT_MANAGER
static ParamInfo kOBSEParams_SetEventHandler[4] =
{
	{ "event name",			kOBSEParamType_String,	0 },
	{ "function script",	kOBSEParamType_Form,	0 },
	{ "filter",				kOBSEParamType_Pair,	1 },
	{ "filter",				kOBSEParamType_Pair,	1 },
};

DEFINE_COMMAND(SetEventHandler, defines a function script to serve as a callback for game events, 0, 4, kOBSEParams_SetEventHandler);
DEFINE_COMMAND(RemoveEventHandler, removes event handlers matching the event, script, and optional filters specified, 0, 4, kOBSEParams_SetEventHandler);
DEFINE_COMMAND(GetCurrentEventName, returns the name of the event currently being processed by an event handler, 0, 0, NULL);

static ParamInfo kOBSEParams_DispatchEvent[3] =
{
	{	"eventName",			kOBSEParamType_String,	0	},
	{	"args",					kOBSEParamType_Array,	1	},
	{	"sender",				kOBSEParamType_String,	1	}
};

DEFINE_COMMAND(DispatchEvent, dispatches a user-defined event to any registered listeners, 0, 3, kOBSEParams_DispatchEvent);

#endif

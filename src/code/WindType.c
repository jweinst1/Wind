#include "WindType.h"


/*Strings for type message formatting*/
static const char* WindType_STR_NONE = "None";
static const char* WindType_STR_BOOL = "Bool";
static const char* WindType_STR_NUMBER = "Number";
static const char* WindType_STR_STRING = "String";
static const char* WindType_STR_ASSIGN = "Assign";
static const char* WindType_STR_NOT = "Not";
static const char* WindType_STR_PLUS = "Plus";
static const char* WindType_STR_MINUS = "Minus";
static const char* WindType_STR_MULTIPLY = "Multiply";
static const char* WindType_STR_DIVIDE = "Divide";
static const char* WindType_STR_SEP = "Separator";
static const char* WindType_STR_DEL = "Delete";
static const char* WindType_STR_LT = "LessThan";
static const char* WindType_STR_GT = "GreaterThan";

const char* WindType_get_str(WindType type)
{
        switch(type)
        {
        case WindType_None: return WindType_STR_NONE;
        case WindType_Bool: return WindType_STR_BOOL;
        case WindType_Not: return WindType_STR_NOT;
        case WindType_Number: return WindType_STR_NUMBER;
        case WindType_String: return WindType_STR_STRING;
        case WindType_Assign: return WindType_STR_ASSIGN;
        case WindType_Plus: return WindType_STR_PLUS;
        case WindType_Minus: return WindType_STR_MINUS;
        case WindType_Multiply: return WindType_STR_MULTIPLY;
        case WindType_Divide: return WindType_STR_DIVIDE;
        case WindType_Del: return WindType_STR_DEL;
        case WindType_Sep: return WindType_STR_SEP;
        case WindType_Lt: return WindType_STR_LT;
        case WindType_Gt: return WindType_STR_GT;
        }
}

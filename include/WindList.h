#ifndef WIND_LIST_H
#define WIND_LIST_H
//header for windlist functions

#include "WindObject.h"
#include "Instruction.h"

#define WindList_BEGIN(obj) (obj->value._lst.begin)
#define WindList_MARK(obj) (obj->value._lst.mark)
#define WindList_END(obj) (obj->value._lst.end)

#define WindList_LEN(obj) (obj->value._lst.mark - obj->value._lst.begin)
#define WindList_SPACE(obj) (obj->value._lst.end - obj->value._lst.mark)
#define WindList_CAP(obj) (obj->value._lst.end - obj->value._lst.begin)
#define WindList_FITS(obj, size) ((obj->value._lst.end - obj->value._lst.mark) < size + 1)

#endif

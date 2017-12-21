#ifndef WIND_LIST_H
#define WIND_LIST_H
//header for windlist functions

#include "WindObject.h"
#include "Instruction.h"
#include "SafeAlloc.h"

#define WindList_DEF_CAP 10
#define WindList_ADRES 3

#define WindList_BEGIN(obj) (obj->value._lst.begin)
#define WindList_MARK(obj) (obj->value._lst.mark)
#define WindList_END(obj) (obj->value._lst.end)

#define WindList_LEN(obj) (obj->value._lst.mark - obj->value._lst.begin)
#define WindList_SPACE(obj) (obj->value._lst.end - obj->value._lst.mark)
#define WindList_CAP(obj) (obj->value._lst.end - obj->value._lst.begin)
#define WindList_FITS(obj, size) ((obj->value._lst.end - obj->value._lst.mark) < size + 1)

#define WindList_INIT(obj) do { \
                obj->type = WindType_List; \
                SAFE_ALLOC_M(obj->value._lst.begin, WindList_DEF_CAP); \
                WindList_MARK(obj) = WindList_BEGIN(obj); \
                WindList_END(obj) = WindList_BEGIN(obj) + WindList_DEF_CAP; \
} while(0)

#define WindList_RESERVE(obj, addSize) do { \
                size_t oldLen = WindList_LEN(obj); \
                size_t newCap = oldLen + addSize + WindList_ADRES; \
                SAFE_ALLOC_RE(obj->value._lst.begin, newCap); \
                obj->value._lst.mark = WindList_BEGIN(obj) + oldLen; \
                obj->value._lst.end = WindList_BEGIN(obj) + newCap; \
} while(0)

#endif

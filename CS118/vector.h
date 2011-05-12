//! Created by Chris Miller on 24 December 2009.
//! Copyright 2010 FSDEV. Aw richts is pitten by.

#pragma once

#ifndef __VECTOR_H__
#define __VECTOR_H__

#ifdef __cplusplus
#define VECTOR_CPLUSPLUS_ESC_BEGIN extern "C" {
#define VECTOR_CPLUSPLUS_ESC_END }
#else
#define VECTOR_CPLUSPLUS_ESC_BEGIN
#define VECTOR_CPLUSPLUS_ESC_END
#endif

#if defined __GNUC__ 
     #define inline __attribute__((always_inline)) 
#elif defined _MSC_VER 
     #define inline __forceinline 
#else 
     //#error "no inlines" 
     #define inline inline 
#endif
	
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
	
static
float __vector_growth = 2.0f;
	
#define VECTOR_PROTOTYPE(name, type)											\
VECTOR_CPLUSPLUS_ESC_BEGIN														\
typedef struct {																\
	type * data;																\
	union {																		\
		size_t length;															\
		size_t size;															\
	};																			\
	size_t capacity;															\
} name##_vector;																\
inline																			\
name##_vector* name##_vector_create_heap(register size_t capacity) {			\
	name##_vector * v;															\
	v->data = (type *)malloc(sizeof(type) * capacity);							\
	v->length = 0;																\
	v->capacity = capacity;														\
	return v;																	\
}																				\
inline																			\
name##_vector name##_vector_create(register size_t capacity) {					\
	name##_vector v;															\
	v.data = (type *)malloc(sizeof(type) * capacity);							\
	v.length = 0;																\
	v.capacity = capacity;														\
	return v;																	\
}																				\
inline																			\
void name##_vector_free_heap(name##_vector * v) {								\
	free(v->data);																\
	free(v);																	\
}																				\
inline																			\
void name##_vector_free_stack(name##_vector * v) {								\
	free(v->data);																\
}																				\
inline																			\
name##_vector* name##_vector_grow(name##_vector * v) {							\
	v->data = (type*)realloc(v->data,											\
							 (size_t)(sizeof(type) * v->capacity * __vector_growth)); \
	v->capacity = (size_t)(v->capacity * __vector_growth);						\
	return v;																	\
}																				\
inline																			\
name##_vector* name##_vector_grow_to(name##_vector * v, register size_t s) {	\
	v->data = (type*)realloc(v->data, (size_t)(sizeof(type) * s));				\
	v->capacity = s;															\
	return v;																	\
}																				\
inline																			\
name##_vector* name##_vector_shrink(name##_vector * v) {						\
	return name##_vector_grow_to(v, v->size);									\
}																				\
inline																			\
void name##_vector_push_back(name##_vector * v, const type t) {					\
	if(v->capacity <= v->length)												\
		v = name##_vector_grow(v);												\
	v->data[v->length ++] = t;													\
}																				\
inline																			\
type name##_vector_pop_back(name##_vector * v) {								\
	return v->data[-- v->length];												\
}																				\
inline																			\
void name##_vector_insert(name##_vector * v,									\
						  register const size_t idx,							\
						  const type t) {										\
	if(v->capacity <= v->length)												\
		v = name##_vector_grow(v);												\
	memmove(v->data+idx+1, v->data+idx, sizeof(t) * (v->length - idx));			\
	++ v->length;																\
	v->data[idx] = t;															\
}																				\
inline																			\
void name##_vector_insert_range(name##_vector * v,								\
								register const size_t idx,						\
								type * begin,									\
								type * end) {									\
	register size_t a1 = end - begin;											\
	register size_t a2 = a1 + v->length;										\
	if(v->capacity <= a2)														\
		v = name##_vector_grow_to(v, a2);										\
	memmove(v->data+idx+a1, v->data+idx, sizeof(type) * (v->length - idx));		\
	memcpy(v->data+idx, begin, sizeof(type) * a1);								\
	v->length += a1;															\
}																				\
inline																			\
void name##_vector_remove_range(name##_vector * v,								\
								register const size_t begin,					\
								register const size_t end) {					\
	type * tmp = (type*)calloc(v->length - end, sizeof(type));					\
	memcpy(tmp, v->data+end, sizeof(type) * (v->length - end));					\
	memcpy(v->data+begin, tmp, sizeof(type) * (v->length - end));				\
	v->length -= end - begin;													\
	free(tmp);																	\
}																				\
inline																			\
void name##_vector_remove(name##_vector * v, register const size_t idx) {		\
	name##_vector_remove_range(v, idx, idx+1);									\
}																				\
VECTOR_CPLUSPLUS_ESC_END

#undef inline

#endif

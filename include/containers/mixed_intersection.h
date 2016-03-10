/*
 * mixed_intersection.h
 *
 */

#ifndef INCLUDE_CONTAINERS_MIXED_INTERSECTION_H_
#define INCLUDE_CONTAINERS_MIXED_INTERSECTION_H_

/* These functions appear to exclude cases where the
 * inputs have the same type and the output is guaranteed
 * to have the same type as the inputs.  Eg, array intersection
 */

#include "array.h"
#include "bitset.h"
#include "run.h"

/* Compute the intersection of src_1 and src_2 and write the result to
 * dst. It is allowed for dst to be equal to src_1. We assume that dst is a
 * valid container. */
void array_bitset_container_intersection(const array_container_t *src_1,
                                         const bitset_container_t *src_2,
                                         array_container_t *dst);

/*
 * Compute the intersection between src_1 and src_2 and write the result
 * to *dst. If the return function is true, the result is a bitset_container_t
 * otherwise is a array_container_t. We assume that dst is not pre-allocated. In
 * case of failure, *dst will be NULL.
 */
bool bitset_bitset_container_intersection(const bitset_container_t *src_1,
                                          const bitset_container_t *src_2,
                                          void **dst);

/*
 * Same as bitset_bitset_container_intersection except that if the output is to
 * be a
 * bitset_container_t, then src_1 is modified and no allocation is made.
 * If the output is to be an array_container_t, then will be freed.
 * In all cases, the result is in *dst.
 */
bool bitset_bitset_container_intersection_inplace(
    bitset_container_t *src_1, const bitset_container_t *src_2, void **dst);

#endif /* INCLUDE_CONTAINERS_MIXED_INTERSECTION_H_ */

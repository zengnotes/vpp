/*
 * Copyright (c) 2015 Cisco and/or its affiliates.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef included_vector_avx512_h
#define included_vector_avx512_h

#include <vppinfra/clib.h>
#include <x86intrin.h>

#define foreach_avx512_vec512i \
  _(i,8,64,epi8) _(i,16,32,epi16) _(i,32,16,epi32)  _(i,64,8,epi64)
#define foreach_avx512_vec512u \
  _(u,8,64,epi8) _(u,16,32,epi16) _(u,32,16,epi32)  _(u,64,8,epi64)
#define foreach_avx512_vec512f \
  _(f,32,8,ps) _(f,64,4,pd)

/* splat, load_unaligned, store_unaligned */
#define _(t, s, c, i) \
static_always_inline t##s##x##c						\
t##s##x##c##_splat (t##s x)						\
{ return (t##s##x##c) _mm512_set1_##i (x); }				\
\
static_always_inline t##s##x##c						\
t##s##x##c##_load_unaligned (void *p)					\
{ return (t##s##x##c) _mm512_loadu_si512 (p); }				\
\
static_always_inline void						\
t##s##x##c##_store_unaligned (t##s##x##c v, void *p)			\
{ _mm512_storeu_si512 ((__m512i *) p, (__m512i) v); }			\
\

foreach_avx512_vec512i foreach_avx512_vec512u
#undef _
#endif				/* included_vector_avx512_h */
/*
 * fd.io coding-style-patch-verification: ON
 *
 * Local Variables:
 * eval: (c-set-style "gnu")
 * End:
 */

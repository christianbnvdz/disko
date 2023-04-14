/*  Typedef for the Option struct and associated functions.
    Copyright (C) 2023 Christian Benavidez

    disko is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    disko is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with disko.  If not, see <https://www.gnu.org/licenses/>. */

#ifndef OPTIONS
#define OPTIONS

#include <stdint.h>
#include <stdbool.h>

/*
 * The Options struct is currently implemented as a uint32_t where the bits
 * are manipulated to denote options being set.
 * Only lowercase letters a-z are accepted currently.
 *
 * a being set is indicated by ...0001
 * b is set with ...0010
 * e is set with ...00010000
 * and so on.
 *
 */
typedef struct {
  uint32_t option_bits;
} Options;

void set_option(Options* options, char option);
bool has_option(Options* options, char option);

#endif

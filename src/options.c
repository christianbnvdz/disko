/*  Implementation for the Options struct associated functions.
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

#include "options.h"

void set_option(Options* options, char option) {
  options->option_bits |= (1 << (option - 97));
}

bool has_option(Options* options, char option) {
  return options->option_bits & (1 << (option - 97));
}

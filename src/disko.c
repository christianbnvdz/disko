/*  Program for displaying info about MBR and GPT partitions
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

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <stdint.h>
#include "options.h"
#include "program_info.h"

#define OPTSTRING "ghv"

int main(int argc, char* argv[]) {
  Options flags;
  opterr = 0;
  for (int opt; (opt = getopt(argc, argv, OPTSTRING)) != -1; ) {
    switch (opt) {
      case 'h':
      case 'v':
      case 'g':
        set_option(&flags, opt);
        break;
      case '?':
        fprintf(stderr, "disko: unrecognized option \"%c\"\n", optopt);
        return EXIT_FAILURE;
      default:
        fprintf(stderr, "\"%c\"\n", opt);
        return EXIT_FAILURE;
    }
  }

  // Don't do anything else if help or version is specified. Help takes precedence.
  if (has_option(&flags, 'h')) {
    printf(get_help_string());
    return EXIT_SUCCESS;
  }

  if (has_option(&flags, 'v')) {
    printf(get_version_string());
    return EXIT_SUCCESS;
  }

  // We need exactly one disk specified after this point. Anything else is an error.
  if (argc - 1 != optind) {
    fprintf(stderr, "disko: you must specify exactly one disk or disk image.\n");

    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}

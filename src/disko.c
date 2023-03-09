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
#include <getopt.h>
#include "program_info.h"

#define OPTSTRING "hv"

int main(int argc, char* argv[]) {
  if (argc == 1) {
    fprintf(stderr, "disko: nothing specified\nSee usage with 'disko -h' or man disko.\n");

    return 1;
  }

  opterr = 0;
  for (int opt; (opt = getopt(argc, argv, OPTSTRING)) != -1; ) {
    switch (opt) {
      case 'h':
        printf(get_help_string());
        return 0;
      case 'v':
        printf(get_version_string());
        return 0;
      case '?':
        fprintf(stderr, "disko: unrecognized option \"%c\"\n", optopt);
        return 1;
      default:
        fprintf(stderr, "\"%c\"\n", opt);
        return 1;
    }
  }

  return 0;
}

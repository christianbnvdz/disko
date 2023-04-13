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
#include "program_info.h"

#define OPTSTRING "ghv"

// This is used to set a bit at the position where the character is in the alphabet
// Ex: a -> ...0001 | d -> ...00001000
// Only use this on lowercase characters.
#define get_bit(character) (1 << (character - 97))

int main(int argc, char* argv[]) {
  // Make sure that something is supplied to the command
  if (argc == 1) {
    fprintf(stderr, "disko: nothing specified\nSee usage with 'disko -h' or man disko.\n");

    return 1;
  }

  // Scan options, reporting will be handled by us, and make note of them by using a
  // uint32_t. Set a 1 in the position of the uint32_t where the letter of the alphabet is.
  // Ex: a -> ...0001 | d -> ...00001000
  // Use the get_bit macro function to do this conversion
  // Currently, this only supports using a-z as options.
  opterr = 0;
  uint32_t flagbits = 0;
  for (int opt; (opt = getopt(argc, argv, OPTSTRING)) != -1; ) {
    switch (opt) {
      case 'h':
      case 'v':
      case 'g':
        flagbits |= get_bit(opt);
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
  if (flagbits & get_bit('h')) {
    printf(get_help_string());
    return EXIT_SUCCESS;
  }

  if (flagbits & get_bit('v')) {
    printf(get_version_string());
    return EXIT_SUCCESS;
  }

  // We need exactly one disk specified after this point. Anything else is an error.
  if (argc - 1 != optind) {
    fprintf(stderr, "disko: you must specify exactly one disk or disk image.\n");

    return EXIT_FAILURE;
  }

  // If no options were specified, or if 'g' was specified, then print the gpt table
  if (flagbits & get_bit('g') || flagbits == 0) {
    printf("In G.\n");
    
    // If no options were specified then exit now
    if (flagbits == 0) return EXIT_SUCCESS;
  }

  return EXIT_SUCCESS;
}

/*  Definitions for functions that retrieve program information strings
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

#define VERSION "0.1.0"

char* get_help_string(void) {
  return "Usage: disko [OPTIONS] DRIVE\n"
         "       disko -[hv]\n"
         "DRIVE refers to an entire, physical, bootable drive or a disk image.\n\n"
         "Recognized Options:\n"
         "  -h     Prints this help message\n"
         "  -v     Prints disko's version\n";
}

char* get_version_string(void) {
  return "Disko "VERSION"\n";
}

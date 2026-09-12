#ifndef INPUT_PARSER_H
#define INPUT_PARSER_H

/*

This file is part of VROOM.

Copyright (c) 2015-2025, Julien Coupey.
All rights reserved (see LICENSE).

*/

#include "structures/vroom/input/input.h"
#include "structures/vroom/input/vehicle_step.h"

namespace vroom::io {

void parse(Input& input, const std::string& input_str, bool geometry);

// Looks for an optional top-level "exclude_polygons" object in
// input_str, keyed by profile name, each holding a Valhalla-format
// polygon array (e.g. [[[lon,lat],...]]). Any profile found gets its
// Server::exclude_polygons field populated in servers (existing
// entries are updated in place, new ones created with default
// host/port if not already present via -a/-p). Must run before
// Input is constructed, since Input::_servers is immutable once set.
void apply_exclude_polygons(Servers& servers, const std::string& input_str);

} // namespace vroom::io

#endif

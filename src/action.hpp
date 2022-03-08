//
// Copyright 2020 Stéphane ALBERT
//
// This file is part of libasecs.
//
// libasecs is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// libasecs is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
// GNU Affero General Public License for more details.
//
// You should have received a copy of the GNU Affero General Public License
// along with libasecs.	If not, see <https://www.gnu.org/licenses/>.
//

#pragma once

#ifndef ECS_ACTION_HPP
#define ECS_ACTION_HPP 0x54470000F233C0D3


#include "actor.hpp"
#include "system.hpp"
#include "vec2.hpp"

#include <memory>


namespace ecs
{

  // Command design-pattern.
  // Closure concept.
  struct action : public system
  {
    using pointer = std::unique_ptr< action >;

    using result = bool;

    action( pointer && alternate_ = nullptr ) : alternate( std::move( alternate_ ) ) {}

    virtual result perform( actor & ) { return true; }

    pointer alternate;
  };

  struct move_action : public action
  {
    move_action( vec2i v ) : velocity( v ) {}

    result perform( actor & a ) override
    {
      if( a.pos.is_zero() )
	return false;

      a.pos += velocity;

      return true;
    }

  private:
    vec2i velocity;
  };

  struct rest_action : public action
  {
  };

} // ecs


#endif // ECS_ACTION_HPP

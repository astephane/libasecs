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

#ifndef ECS_COMPONENT_HPP
#define ECS_COMPONENT_HPP 0x54470000F233C0D3


namespace ecs
{

  struct actor;

  struct component
  {
    virtual ~component();
  };

  // see: http://gameprogrammingpatterns.com/component.html
  struct in_component : public component
  {
    virtual void update( actor & ) = 0;
  };

  struct human_component : public in_component
  {
  };

  struct ai_component : public in_component
  {
    void update( actor & ) override;
  };

} // ecs


#endif // ECS_COMPONENT_HPP

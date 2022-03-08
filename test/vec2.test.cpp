#include <catch2/catch.hpp>

#include "vec2.hpp"

SCENARIO( "Zero ecs::vec2i", "" )
{
  GIVEN( "A an uninitialized ecs::vec2i" )
  {
    ecs::vec2i u;

    THEN( "All components must be zero" )
    {
      CAPTURE( u );
      CAPTURE( u.x );
      CAPTURE( u.y );

      REQUIRE( u.x == 0 );
      REQUIRE( u.y == 0 );

      AND_THEN( "ecs::vec2i:is_zero() must be true" )
      {
	CAPTURE( u );
	CAPTURE( u.x );
	CAPTURE( u.y );
	CAPTURE( u.is_zero() );

	REQUIRE( u.is_zero() );
      }
    }
  }
}

SCENARIO( "Construction of ecs::vec2i", "" )
{
  GIVEN( "An initialized ecs::vec2i" )
  {
    ecs::vec2i u( -1, +2 );

    THEN( "All components must match their initialization value" )
    {
      CAPTURE( u );
      CAPTURE( u.x );
      CAPTURE( u.y );

      REQUIRE( u.x == -1 );
      REQUIRE( u.y == +2 );

      AND_THEN( "ecs::vec2i:is_zero() must be false" )
      {
	CAPTURE( u );
	CAPTURE( u.x );
	CAPTURE( u.y );
	CAPTURE( u.is_zero() );

	REQUIRE( !u.is_zero() );
      }
    }
  }
}

SCENARIO( "Addition of ecs::vec2i", "" )
{
  GIVEN( "A an uninitialized vec2i" )
  {
    ecs::vec2i u;

    AND_GIVEN( "Another non-zero ecs::vec2i" )
    {
      ecs::vec2i v( -1, +2 );

      AND_GIVEN( "The addition of both ecs::vec2i" )
      {
	ecs::vec2i w = u + v;

	THEN( "" )
	{
	  CAPTURE( w );
	  CAPTURE( w.x );
	  CAPTURE( w.y );

	  REQUIRE( w.x == -1 );
	  REQUIRE( w.y == +2 );

	  AND_THEN( "" )
	  {
	    CAPTURE( w );
	    CAPTURE( w.x );
	    CAPTURE( w.y );
	    CAPTURE( w.is_zero() );

	    REQUIRE( !w.is_zero() );
	  }
	}
      }
    }
  }
}


SCENARIO( "Negation of ecs::vec2i", "" )
{
  GIVEN( "An uninitialized ecs::vec2i" )
  {
    ecs::vec2i u;

    AND_GIVEN( "Its negation" )
    {
      ecs::vec2i v = -u;

      THEN( "" )
      {
	CAPTURE( v );
	CAPTURE( v.x );
	CAPTURE( v.y );

	REQUIRE( v.x == 0 );
	REQUIRE( v.y == 0 );

	AND_THEN( "" )
	{
	  CAPTURE( v );
	  CAPTURE( v.x );
	  CAPTURE( v.y );
	  CAPTURE( v.is_zero() );

	  REQUIRE( v.is_zero() );
	}
      }
    }
  }

  GIVEN( "An initialized ecs::vec2i" )
  {
    ecs::vec2i u( -1, +2 );

    AND_GIVEN( "Its negation" )
    {
      ecs::vec2i v = -u;

      THEN( "" )
      {
	CAPTURE( v );
	CAPTURE( v.x );
	CAPTURE( v.y );

	REQUIRE( v.x == +1 );
	REQUIRE( v.y == -2 );

	AND_THEN( "" )
	{
	  CAPTURE( v );
	  CAPTURE( v.x );
	  CAPTURE( v.y );
	  CAPTURE( v.is_zero() );

	  REQUIRE( !v.is_zero() );
	}
      }
    }
  }
}

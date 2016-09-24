//
// Created by Clark Burton Chambers on 9/24/16.
//

// Link to Boost
#define BOOST_TEST_DYN_LINK

// Define our Module
#include "EntityManager.hpp"
#include "includes.hpp"
#define BOOST_TEST_MODULE EntityManagerTest

// INCLUDE THIS LAST
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE( em_test0 )
{
    EntityManager em;
    BOOST_CHECK(em.create_entity());
}



// EOF
#include "catch2/catch_all.hpp"
#include "atp.h"
#include "association.h"    

TEST_CASE("ATP Constructors Tests") {
    SECTION("Test default constructor") {
        ATP atp("Company");
        REQUIRE(atp.getName() == "Company");
    }

    SECTION("Test copy constructor") {
        ATP atp1("Company");
        atp1.hire("Employee", "CEO_to");

        ATP atp2(atp1);

        REQUIRE(atp2.getName() == "Company");
        REQUIRE(atp2.find("Employee") == true);
    }
    
    SECTION("Test assignment operator") {
        ATP atp1("Company");
        atp1.hire("Employee", "CEO_to");

        ATP atp2("AnotherCompany");

        atp2 = atp1;

        REQUIRE(atp2.getName() == "Company");
        REQUIRE(atp2.find("Employee") == true);
    }
}

TEST_CASE("ATP find Test") {
    SECTION("Test find()") {
        ATP atp("Company");

        REQUIRE(atp.find("CEO_to") == true);
        REQUIRE(atp.find("Employee") == false);
        REQUIRE(atp.find("Manager") == false);
    }
}

TEST_CASE("ATP hire Test") {
    SECTION("Test hire()") {
        ATP atp("Company");
        atp.hire("Manager", "CEO_to");

        atp.hire("Employee1", "Manager");
        REQUIRE(atp.find("Employee1") == true);
        REQUIRE(atp.getManager("Employee1") == "Manager");

        atp.hire("Employee2", "Manager");
        atp.hire("Employee2", "CEO_to");
        REQUIRE(atp.getManager("Employee2") == "CEO_to");

        REQUIRE_THROWS_AS(atp.hire("Manager", "Employee1"), std::logic_error);
    }
}

TEST_CASE("ATP fire Test", "[ATP]") {
    SECTION("Test fire()") {
        ATP atp("Company");
        atp.hire("Manager", "CEO_to");
        atp.hire("Employee1", "Manager");
        atp.hire("Employee2", "Manager");

        atp.fire("Employee1");
        REQUIRE(atp.find("Employee1") == false); 

        REQUIRE_THROWS_AS(atp.fire("CEO_to"), std::logic_error);
        REQUIRE(atp.find("CEO_to") == true);
    }
}

TEST_CASE("ATP numSubordinates and numEmployees Tests") {
    SECTION("Test numSubordinates()") {
        ATP atp("Company");
        atp.hire("Manager", "CEO_to");
        atp.hire("Employee1", "Manager");
        atp.hire("Employee2", "Manager");
        atp.hire("Employee3", "Manager");

        REQUIRE(atp.numSubordinates("Manager") == 3);
        REQUIRE(atp.numSubordinates("CEO_to") == 1);
        REQUIRE(atp.numSubordinates("Employee1") == 0);
    }

    SECTION("Test numSubordinates() with default ATP") {
        ATP atp("Company");

        REQUIRE(atp.numSubordinates("Employee1") == 0);
    }

    SECTION("Test numEmployees()") {
        ATP atp("Company");

        atp.hire("Manager", "CEO_to");
        atp.hire("Employee1", "Manager");
        atp.hire("Employee2", "Manager");
        atp.hire("Employee3", "Manager");

        REQUIRE(atp.numEmployees() == 5);
    }

    SECTION("Test numEmployees() with default ATP") {
        ATP atp("Company");

        REQUIRE(atp.numEmployees() == 1);
    }
}

TEST_CASE("ATP getManager Test") {
    SECTION("Test getManager()") {
        ATP atp("Company");
        atp.hire("Manager", "CEO_to");
        atp.hire("Employee1", "Manager");
        atp.hire("Employee2", "Manager");

        REQUIRE(atp.getManager("Manager") == "CEO_to");
        REQUIRE(atp.getManager("Employee1") == "Manager");
        REQUIRE(atp.getManager("Employee2") == "Manager");
        REQUIRE(atp.getManager("CEO_to") == "");
    }
}

TEST_CASE("ATP maxChainLength Test") {
    SECTION("Test maxChainLength() with default ATP having max length 1") {
        ATP atp("Company");
        REQUIRE(atp.maxChainLength() == 1);
    }

    SECTION("Test maxChainLength() with hired employees") {
        ATP atp("Company");
        atp.hire("Manager", "CEO_to");
        atp.hire("Employee1", "Manager");
        atp.hire("Employee4", "Employee1");
        atp.hire("Employee2", "Employee1");
        atp.hire("Employee3", "Employee2");

        REQUIRE(atp.maxChainLength() == 5);
    }
}

TEST_CASE("ATP salary Test") {
    SECTION("Test salary()") {
        ATP atp("Company");
        atp.hire("Manager", "CEO_to");
        atp.hire("Employee1", "Manager");
        atp.hire("Employee2", "Employee1");
        atp.hire("Employee3", "Employee2");
        atp.hire("Employee4", "Employee2");

        REQUIRE(atp.salary("Manager") == 650);
        REQUIRE(atp.salary("Employee1") == 600);
        REQUIRE(atp.salary("Employee2") == 1000);
        REQUIRE(atp.salary("Employee3") == 0);
        REQUIRE(atp.salary("CEO_to") == 700);
    }
}

TEST_CASE("ATP overloaded Test") {
    SECTION("Test overloaded()") {
        ATP atp("Company");
        atp.hire("Manager", "CEO_to");
        atp.hire("Employee1", "Manager");
        atp.hire("Employee2", "Manager");
        atp.hire("Employee3", "Employee1");
        atp.hire("Employee4", "Employee2");

        REQUIRE(atp.overloaded(1) == 2);

        REQUIRE(atp.overloaded(0) == 4); 
    }
}

TEST_CASE("Association getInstance Tests") {
    SECTION("Test getInstance() returns same instance") {
        Association& association1 = Association::getInstance();
        Association& association2 = Association::getInstance();

        REQUIRE(&association1 == &association2);
    }
}

TEST_CASE("Association add and getATP Tests") {
    SECTION("Test add and getATP") {
        Association& association = Association::getInstance();
        association.add("Company");

        ATP* atp = association.getATP("Company");

        REQUIRE(atp != nullptr);
        REQUIRE(atp->getName() == "Company");

        delete atp;
    }
}







//
// Created by super on 6/1/23.
//

#include "sources/MagicalContainer.hpp"
#include "doctest.h"
#include <iostream>
using namespace std;
using namespace ariel;

TEST_CASE("checking that the size of the container is increasing when adding elements") {
    ariel::MagicalContainer mc;
    CHECK(mc.size() == 0);

    mc.addElement(1);
    CHECK(mc.size() == 1);
}

TEST_CASE("checking that the size of the container is decreasing when removing elements") {
    ariel::MagicalContainer mc;
    CHECK(mc.size() == 0);

    mc.addElement(1);
    CHECK(mc.size() == 1);

    mc.removeElement(1);
    CHECK(mc.size() == 0);
}

TEST_CASE("checking that the size of the container is not decreasing when removing elements that are not in the container") {
    ariel::MagicalContainer mc;
    CHECK(mc.size() == 0);

    mc.addElement(1);
    CHECK(mc.size() == 1);

    mc.removeElement(2);
    CHECK(mc.size() == 1);
}

TEST_CASE("check that the Prime iterator iterates only over primes"){
    MagicalContainer mc;
    mc.addElement(1);
    mc.addElement(2);
    mc.addElement(3);
    mc.addElement(4);
    mc.addElement(5);
    mc.addElement(6);
    mc.addElement(7);
    mc.addElement(8);
    mc.addElement(9);
    mc.addElement(10);
    mc.addElement(11);

    MagicalContainer::PrimeIterator ascIter(mc);
    MagicalContainer::PrimeIterator it = ascIter.begin();
    CHECK(*it == 2);
    cout << *it << endl;
    ++it;
    cout << *it << endl;
    CHECK(*it == 3);
    ++it;
    CHECK(*it == 5);
    it++;
    CHECK(*it == 7);
    it++;
    CHECK(*it == 11);
}

TEST_CASE("Ascending iterator iterates over the elements in ascending order"){
    MagicalContainer mc;
    mc.addElement(1);
    mc.addElement(2);
    mc.addElement(3);
    mc.addElement(4);
    mc.addElement(5);

    MagicalContainer::AscendingIterator ascIter(mc);
    MagicalContainer::AscendingIterator it = ascIter.begin();
    CHECK(*it == 1);
    ++it;
    CHECK(*it == 2);
    ++it;
    CHECK(*it == 3);
    ++it;
    CHECK(*it == 4);
    ++it;
    CHECK(*it == 5);
}

TEST_CASE("check that the SideCross iterator iterates in an side cross order"){
    MagicalContainer mc;
    mc.addElement(1);
    mc.addElement(2);
    mc.addElement(3);
    mc.addElement(4);
    mc.addElement(5);

    MagicalContainer::SideCrossIterator ascIter(mc);
    MagicalContainer::SideCrossIterator it = ascIter.begin();

    CHECK(*it == 1);
    it++;
    CHECK(*it == 5);
    it++;
    CHECK(*it == 2);
    it++;
    CHECK(*it == 4);
    it++;
    CHECK(*it == 3);
}

TEST_CASE("check that ++ operator throws an exception when trying to iterate over an empty container"){
    MagicalContainer mc;
    MagicalContainer::SideCrossIterator ascIter(mc);
    MagicalContainer::SideCrossIterator it = ascIter.begin();
    CHECK_THROWS(++it);


    MagicalContainer::PrimeIterator ascIter2(mc);
    MagicalContainer::PrimeIterator it2 = ascIter2.begin();
    CHECK_THROWS(++it2);

    MagicalContainer::AscendingIterator ascIter3(mc);
    MagicalContainer::AscendingIterator it3 = ascIter3.begin();
    CHECK_THROWS(++it3);
}

TEST_CASE("check that ++ iterator throws an exception when trying to increment it forever") {
    MagicalContainer mc;
    mc.addElement(1);
    mc.addElement(2);
    mc.addElement(3);
    mc.addElement(4);
    mc.addElement(5);

    MagicalContainer::SideCrossIterator ascIter(mc);
    MagicalContainer::SideCrossIterator it = ascIter.begin();
    CHECK_NOTHROW(++it); //2
    CHECK_NOTHROW(++it); //3
    CHECK_NOTHROW(++it); //4
    CHECK_NOTHROW(++it); //5
    CHECK_THROWS(++it); //end of container

    MagicalContainer::PrimeIterator ascIter2(mc);
    MagicalContainer::PrimeIterator it2 = ascIter2.begin();
    CHECK_NOTHROW(++it2); //2
    CHECK_NOTHROW(++it2); //3
    CHECK_NOTHROW(++it2); //5
    CHECK_THROWS(++it2); //end of container

    MagicalContainer::AscendingIterator ascIter3(mc);
    MagicalContainer::AscendingIterator it3 = ascIter3.begin();
    CHECK_NOTHROW(++it3); //5
    CHECK_NOTHROW(++it3); //2
    CHECK_NOTHROW(++it3); //4
    CHECK_NOTHROW(++it3); //3
    CHECK_THROWS(++it3); //end of container

}

TEST_CASE("removeElement throws exception if trying to remove an element from an empty container"){
    MagicalContainer mc;
    mc.addElement(1);
    mc.removeElement(2);
    CHECK_NOTHROW(mc.removeElement(2));
    CHECK_NOTHROW(mc.removeElement(1));
    CHECK_THROWS(mc.removeElement(1));
}









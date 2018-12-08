/**
 * FILE: washing.cpp
 * CLASSED implemented: bool_source, averager, washer
 * 
 * INVARIANT for the bool_source class:
 *  1. The member variable probability is the approximate probability that query() returns
 *     true.
 * 
 * INVARIANT for the averager class:
 *  1. The member variable count indicates how many numbers the averager has been given.
 *  2. The member variable sum is the sum of all the numbers that the averager has been 
 *     given.
 * 
 * INVARIANT for the washer class:
 *  1. The member variable second_for_wash is the number of seconds required for one wash.
 *  2. The member variable wash_time_left is 0 if the washer is not busy;
 *     otherwise it is the number of seconds until the washer is free. 
 */ 

#include <cassert>    // Provides assert
#include <cstdlib>    // Provides rand, RAND_MAX, size_t
#include "washing.h"  // Provides bool_source, averager, washer definitions

using namespace std;

namespace main_savitch_8A {
  bool_source::bool_source(double p) {
    assert(p >= 0);
    assert(p <= 1);
    probability = p;
  }

  bool bool_source::query() const {
    return (rand() < probability * RAND_MAX);
  }

  averager::averager() {
    count = 0;
    sum = 0;
  }

  void averager::next_number(double value) {
    ++count;
    sum += value;
  }

  double averager::average() const {
    assert(how_many_numbers() > 0);
    return sum / count;
  }

  washer::washer(unsigned int s) {
    seconds_for_wash = s;
    wash_time_left = 0;
  }

  void washer::one_second() {
    if (is_busy()) {
      --wash_time_left;
    }
  }

  void washer::start_washing() {
    assert(!is_busy());
    wash_time_left = seconds_for_wash;
  }
}
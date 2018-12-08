#include <iostream>
#include <queue>
#include <ext/pb_ds/priority_queue.hpp>

#include "washing.h"
#include "Queue1.h"
#include "Queue2.h"

using namespace std;
using namespace main_savitch_8A;
using namespace main_savitch_8B;
using namespace main_savitch_8C;

// void car_wash_simulate(unsigned int wash_time,
//                        double arrival_prob,
//                        unsigned int total_time) {
//   /**
//    * Precondition: 0 <= arrival_prob <= 1.
//    * Postcondition: The function has simulated a car wash where wash_time is the number of
//    * seconds needed to wash one car, arrival_prob is the probabilty of a customer arriving in 
//    * any second, and total_time is the total number of seconds for the simulation. Before the 
//    * simulation, the function has written its three parameters to cout. After the simulation, the
//    * function has written two pieces of information to cout. (1) the number ofcars washed and
//    * (2) the average waiting time of a customer.
//   */
//   queue<unsigned int> arrival_times;    // Time stamp of the waiting customers
//   unsigned int next;                    // A value taken from the queue
//   bool_source arrival(arrival_prob);
//   washer machine(wash_time);
//   averager wait_times;
//   unsigned int current_second;

//   // Write the parameters to cout
//   cout << "Seconds to wash one car: " << wash_time << endl;
//   cout << "Probablity of customer arrival during a second: ";
//   cout << arrival_prob << endl;
//   cout << "Total simulated seconds: " << total_time << endl;

//   for (current_second = 1; current_second <= total_time; ++current_second) {
//     // Simulate the passage of one second of time.
//     // Check whether a new customer has arrived.
//     if (arrival.query()) {
//       arrival_times.push(current_second);
//     }
//     // Check whether we can start washing another car.
//     if ( (!machine.is_busy()) && (!arrival_times.empty())) {
//       next = arrival_times.front();
//       arrival_times.pop();
//       wait_times.next_number(current_second - next);
//       machine.start_washing();
//     }
//     // Tell the washer to stimulate the passage of one second.
//     machine.one_second();
//   }
//   // Write the summary information about the simulation.
//   cout << "Customers served: " << wait_times.how_many_numbers() << endl;
//   if (wait_times.how_many_numbers() > 0) {
//     cout << "Average wait: " << wait_times.average() << " sec" << endl;
//   }
// }

int main() {
  /************** example of Queue in use ***********/
  //car_wash_simulate(240, 0.0025, 6000);

  /* Queue implementation
  ** numbers is using an static array inplementation.
  ** numbers2 is using a linked list implementation.
  */

  // main_savitch_8B::Queue<int> numbers;
  // numbers.push(10);
  // numbers.push(20);
  // numbers.push(30);
  // numbers.push(40);

  // cout << numbers.size() << endl;

  // numbers.pop();

  // cout << numbers.size() << endl;

  // cout << "-------------------------------------------------------" << endl;

  // main_savitch_8C::Queue<int> numbers2;
  // main_savitch_8C::Queue<int>::iterator position;

  // numbers2.push(10);
  // numbers2.push(20);
  // numbers2.push(30);
  // numbers2.push(40);
  // numbers2.push(50);
  // numbers2.push(60);
  // numbers2.push(70);
  // numbers2.push(80);
  // numbers2.push(90);
  // numbers2.push(100);

  // cout << " size after pushing 4 items --- " << sizeof(numbers2) << endl;

  // cout << "items in Queue after push" << endl;
  // for (position = numbers2.begin(); position != numbers2.end(); ++position) {
  //   cout << *position << ", \n";
  // }

  // numbers2.pop();
  // numbers2.pop();

  // cout << "\nsize after poping 2 items --- " << sizeof(numbers2) << endl;

  // cout << "items in Queue after pop" << endl;
  // for (position = numbers2.begin(); position != numbers2.end(); ++position) {
  //   cout << *position << ", \n";
  // }

  return 0;
}

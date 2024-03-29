// -----------------------------------------------------------------------------
// main.cpp
// ./qemu-run.sh build/debug/AC++11-501.bin
//
//
// DISCLAIMER:
// Feabhas is furnishing this item "as is". Feabhas does not provide any
// warranty of the item whatsoever, whether express, implied, or statutory,
// including, but not limited to, any warranty of merchantability or fitness
// for a particular purpose or any warranty that the contents of the item will
// be error-free.
// In no respect shall Feabhas incur any liability for any damages, including,
// but limited to, direct, indirect, special, or consequential damages arising
// out of, resulting from, or any way connected to the use of the item, whether
// or not based upon warranty, contract, tort, or otherwise; whether or not
// injury was sustained by persons or property or otherwise; and whether or not
// loss was sustained from, or arose out of, the results of, the item, or any
// services that may be provided by Feabhas.
// -----------------------------------------------------------------------------

#include <iostream>
#include "Time.h"
#include "step.hpp"
#include "wash_programme.h"

using namespace Time;

int main()
{
  std::cout << "Feabhas C++11-501" << std::endl;

  WMS::Wash_programme washing_machine { };
  washing_machine.add({ WMS::invalid, 1000, "Washing machine on standby" });
  washing_machine.add({ WMS::wash, 2000, "Washing cycle" });
  washing_machine.add({ WMS::empty, 1000, "Emptying water from basin" });
  
  washing_machine.run();

  // while (true) {
  //   std::cout << "Tick..." << std::endl;
  //   sleep(1000_ms);
  // }
}
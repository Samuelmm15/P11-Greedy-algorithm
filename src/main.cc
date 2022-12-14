/**
 * @file main.cc
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief This is the main file of the program.
 * @version 0.1
 * @date 2022-12-13
 * @signature Computabilidad y Algoritmia.
 * @course 2022-2023.
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <vector>
#include <list>

#include "../include/coinsExchange.h"

int main() {
  std::cout << "<< BIENVENIDO AL PROGRAMA DE CAMBIO DE MONEDAS >>" << std::endl;
  double amount;
  std::cout << "Introduzca el valor objetivo, el cual quiere comprobar el número total de monedas: ";
  std::cin >> amount;
  coinsExchange coinsExchangeObject;
  coinsExchangeObject.setAmount(amount);
  coinsExchangeObject.SolutionFunction();
  return 0;
}



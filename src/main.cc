/**
 * @file main.cc
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief This is the main function of the program.
 * @version 0.1
 * @date 2022-12-13
 * @signature Computabilidad y Algoritmia.
 * @course 2022-2023.
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <list>
#include <vector>

#include "../include/coinsExchange.h"
#include "../include/coinsExchangeImprovement.h"

int main(int argc, char const *argv[]) {
  std::cout << "<< BIENVENIDO AL PROGRAMA DE CAMBIO DE MONEDAS >>" << std::endl;
  double amount;
  if (argc == 2) {
    std::string option = argv[1];
    if (option == "-h" || option == "--help") {
      std::cout << std::endl;
      std::cout << "AYUDA >>> Para la correcta ejecución del programa se debe "
                   "de hacer uso de: "
                << std::endl;
      std::cout << "$ ./coinsExchange [-b | -o]? [amount]" << std::endl;
      std::cout << "Donde: " << std::endl;
      std::cout << "-b: Es el modo de ejecución del programa, el cual hace uso "
                   "de billetes en vez de monedas para poder calcular la "
                   "cantidad a cambiar."
                << std::endl;
      std::cout << "-o: Es el modo de ejecución del programa, ." << std::endl;
      std::cout << std::endl;
      return 0;
    } else {
      amount = std::stod(argv[1]);
      coinsExchange coinsExchangeObject;
      coinsExchangeObject.setAmount(amount);
      coinsExchangeObject.SolutionFunction();
    }
    return 0;
  } else if (argc == 1) {
    std::cout << std::endl;
    std::cout << "Introduzca el valor objetivo, el cual quiere comprobar el "
                 "número total de monedas: ";
    std::cin >> amount;
    coinsExchange coinsExchangeObject;
    coinsExchangeObject.setAmount(amount);
    coinsExchangeObject.SolutionFunction();
    return 0;
  } else if (argc == 3) {
    std::string option = argv[1];
    if (option == "-b") {
      amount = std::stod(argv[2]);
      coinsExchange coinsExchangeObject;
      coinsExchangeObject.setAmount(amount);
      coinsExchangeObject.SolutionFunctionBills();
      return 0;
    } else if (option == "-o") {
      amount = std::stod(argv[2]);
      coinsExchangeImprovement coinsExchangeImprovementObject;
      coinsExchangeImprovementObject.setAmount(amount);
      coinsExchangeImprovementObject.SolutionFunction();
      return 0;
    } else {
      std::cout << std::endl;
      std::cout << "ERROR: El tipo de parámetro introducido no es correcto."
                << std::endl;
      std::cout << "Para más información haga uso de la opción --h o -help"
                << std::endl;
      std::cout << std::endl;
      return 0;
    }
  } else if (argc == 4) {
    std::string option_1 = argv[1];
    std::string option_2 = argv[3];
    if (option_1 == "-o" && option_2 == "-b") {
      amount = std::stod(argv[2]);
      coinsExchangeImprovement coinsExchangeImprovementObject;
      coinsExchangeImprovementObject.setAmount(amount);
      coinsExchangeImprovementObject.SolutionFunctionBills();
      return 0;
    } else {
      std::cout << std::endl;
      std::cout << "ERROR: El tipo de parámetro introducido no es correcto."
                << std::endl;
      std::cout << "Para más información haga uso de la opción --h o -help"
                << std::endl;
      std::cout << std::endl;
      return 0;
    }
  }
  return 0;
}

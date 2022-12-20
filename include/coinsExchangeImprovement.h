/**
 * @file coinsExchangeImprovement.h
 * @author Samuel Martín Morales (alu0101359526)
 * @brief 
 * @version 0.1
 * @date 2022-12-20
 * @signature Computabilidad y Algoritmia.
 * @course 2022-2023.
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>

#pragma once

class coinsExchangeImprovement {
    public:
        coinsExchangeImprovement();
        void SolutionFunction();
        void SolutionFunctionBills();
        bool FeasibleFunction();
        void SelectionFunction();
        void SelectionFunctionBills();
        bool ObjectiveFunction();
        void setAmount(double amount);
    private:
        std::vector<double> coins_; /// Este es el conjunto de candidatos de monedas viables.
        std::vector<double> bills_; /// Este es el conjunto de candidatos de billetes viables.
        double amount_; /// Este es el valor objetivo.
        double addition_; /// Este es el valor de la suma de las monedas seleccionadas.
        std::vector<double> selected_; /// Este es el conjunto de soluciones.
};
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <random>
#include <math.h>
#include <cstdlib>
#include <map>
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
//#include <matplotlibcpp.h>
//
//namespace plt = matplotlibcpp;

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> distrib(1, 1000);



std::vector<int> maldicion2(int numPoints) {
    int distanciasN = numPoints - 1;
    int dim = 2;
    std::vector<std::vector<int>> points(numPoints, std::vector<int>(dim));
    std::vector<float> distancias(distanciasN);
    std::vector<float> esc(distanciasN);
    int punto;

    for (int i = 0; i < numPoints; i++) {
        for (int j = 0; j < dim; j++) {
            points[i][j] = distrib(gen);
        }
    }

    srand(time(0));
    punto = (rand() % numPoints) + 1;

    for (int i = 0, j = 0; i < numPoints; i++) {
        if (i != punto) {
            distancias[j] = sqrt(pow(points[punto][0] - points[i][0], 2) + pow(points[i][1] - points[punto][1], 2));
            j++;
        }
    }

    std::sort(distancias.begin(), distancias.end());
    float aux;

    for (int i = 0; i < distanciasN - 1; i++) {
        aux = distancias[i] / distancias[distanciasN - 1];
        esc[i] = static_cast<float>(static_cast<int>(aux * 10.)) / 10.;
    }

    esc[distanciasN - 1] = 1;

    //for (auto i : esc) {
    //    std::cout << i << std::endl;
    //}

    std::vector<int> f(11,0);
    for (auto i : esc) {
        if (i == float(0)) f[0]++;
        else if (i == float(0.1)) f[1]++;
        else if (i == float(0.2)) f[2]++;
        else if (i == float(0.3)) f[3]++;
        else if (i == float(0.4)) f[4]++;
        else if (i == float(0.5)) f[5]++;
        else if (i == float(0.6)) f[6]++;
        else if (i == float(0.7)) f[7]++;
        else if (i == float(0.8)) f[8]++;
        else if (i == float(0.9)) f[9]++;
        else if (i == float(1)) f[10]++;
    }
    float x = 0;
    for (auto i : f) {
        std::cout <<"De "<< x <<" hay " << i << std::endl;
        x += 0.1;
    }
    //std::map<float, int> duplicate;
    //auto beg = begin(esc);
    //for (; beg != end(esc); ++beg) {
    //    if (*beg == *(beg)) {
    //        duplicate[*beg]++;
    //    }
    //}

    //for (const auto& i : duplicate){
    //    std::cout << i.first << " appear " << i.second << " times" << '\n';
    //}
    //}

    return f;
}

std::vector<int> maldicion(int numPoints, int dim) {
    int distanciasN = numPoints - 1;
    std::vector<std::vector<int>> points(numPoints, std::vector<int>(dim));
    std::vector<float> distancias(distanciasN);
    std::vector<float> esc(distanciasN);
    int punto;

    for (int i = 0; i < numPoints; i++) {
        for (int j = 0; j < dim; j++) {
            points[i][j] = distrib(gen);
        }
    }

    srand(time(0));
    punto = (rand() % numPoints - 1);
    int powersum = 0;

    for (int i = 0, j = 0; i < numPoints; i++) {
        if (i != punto) {
            /*distancias[j] = sqrt(pow(points[punto][0] - points[i][0], 2) + pow(points[i][1] - points[punto][1], 2));*/
            for (int h = 0; h < dim; h++) {
                powersum += pow(points[punto][h] - points[i][h], 2);
            }
            distancias[j] = sqrt(powersum);
            powersum = 0;
            j++;
        }
    }

    std::sort(distancias.begin(), distancias.end());
    float aux;

    for (int i = 0; i < distanciasN - 1; i++) {
        aux = distancias[i] / distancias[distanciasN - 1];
        esc[i] = static_cast<float>(static_cast<int>(aux * 10.)) / 10.;
    }

    esc[distanciasN - 1] = 1;

    //for (auto i : esc) {
    //    std::cout << i << std::endl;
    //}

    std::vector<int> f(11, 0);
    for (auto i : esc) {
        if (i == float(0)) f[0]++;
        else if (i == float(0.1)) f[1]++;
        else if (i == float(0.2)) f[2]++;
        else if (i == float(0.3)) f[3]++;
        else if (i == float(0.4)) f[4]++;
        else if (i == float(0.5)) f[5]++;
        else if (i == float(0.6)) f[6]++;
        else if (i == float(0.7)) f[7]++;
        else if (i == float(0.8)) f[8]++;
        else if (i == float(0.9)) f[9]++;
        else if (i == float(1)) f[10]++;
    }
    //float x = 0;
    //for (auto i : f) {
    //    std::cout << "De " << x << " hay " << i << std::endl;
    //    x += 0.1;
    //}
    //std::map<float, int> duplicate;
    //auto beg = begin(esc);
    //for (; beg != end(esc); ++beg) {
    //    if (*beg == *(beg)) {
    //        duplicate[*beg]++;
    //    }
    //}

    //for (const auto& i : duplicate){
    //    std::cout << i.first << " appear " << i.second << " times" << '\n';
    //}
    //}

    return f;
}

int main(){
    /*std::vector<int> first;
    first = maldicion2(20000, 2);*/
    
    std::vector<int> p2;
    std::vector<int> p5;
    std::vector<int> p10;
    std::vector<int> p15;
    std::vector<int> p20;
    std::vector<int> p25;
    p2 = maldicion(20000, 2);
    p5 = maldicion(20000, 5);
    p10 = maldicion(20000, 10);
    p15 = maldicion(20000, 15);
    p20 = maldicion(20000, 20);
    p25 = maldicion(20000, 25);

    nlohmann::json j;

    j["2 Dimensiones"] = p2;
    j["5 Dimensiones"] = p5;
    j["10 Dimensiones"] = p10;
    j["15 Dimensiones"] = p15;
    j["20 Dimensiones"] = p20;
    j["25 Dimensiones"] = p25;

    std::cout << "2 Dimensiones: ";
    for (auto i : p2) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "5 Dimensiones: ";
    for (auto i : p5) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "10 Dimensiones: ";
    for (auto i : p10) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "15 Dimensiones: ";
    for (auto i : p15) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "20 Dimensiones: ";
    for (auto i : p20) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "25 Dimensiones: ";
    for (auto i : p25) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::ofstream o("../source/vector.json");
    o << std::setw(4) << j << std::endl;
    
    system("python ../source/graficas.py");
//    plt::plot(p2);
//    plt::title("2 Dimensiones");
//    plt::show();
//    plt::plot(p5);
//    plt::title("5 Dimensiones");
//    plt::show();
//    plt::plot(p10);
//    plt::title("10 Dimensiones");
//    plt::show();
//    plt::plot(p15);
//    plt::title("15 Dimensiones");
//    plt::show();
//    plt::plot(p20);
//    plt::title("20 Dimensiones");
//    plt::show();
//    plt::plot(p25);
//    plt::title("25 Dimensiones");
//    plt::show();
//    plt::save("1.png");
//    //plt::plot(p2);
//    //plt::plot(p5);
//    //plt::plot(p10);
//    //plt::plot(p15);
//    //plt::plot(p20);
//    //plt::plot(p25);
//    
///*    plt::named_plot("2 Dim", p2);
//    plt::named_plot("5 Dim", p5);
//    plt::named_plot("10 Dim", p10);
//    plt::named_plot("15 Dim", p15);
//    plt::named_plot("20 Dim", p20);
//    plt::named_plot("25 Dim", p25);
//    
//    plt::legend();
//    plt::show(); */ 
}


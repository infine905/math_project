#include "task5.h"

namespace calc {
    std::vector <std::pair<double, double>> task5_graph(double x0, double y0, double C, double C1, double C2, double h, int n) {
        std::vector <std::pair<double, double>> points;
        double x = x0;
        double y = y0;
        points.emplace_back(x, y);
        for (int i = 0; i < n; ++i) {
            y = C2 * sin(pow(3, 0.5) * x) + C1 * cos(pow(3, 0.5) * x) + C;
            x += h;
            points.emplace_back(x, y);
        }
        return points;
    }
}
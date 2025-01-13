#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Structure to represent a route
struct Route {
    string name;
    int trafficVolume;    // Current traffic volume
    int signalTiming;     // Current signal timing (in seconds)
};

// Function to adjust signal timings based on traffic volume
void adjustSignalTimings(vector<Route>& routes, int threshold, int maxTiming, int minTiming) {
    for (auto& route : routes) {
        if (route.trafficVolume > threshold) {
            // Increase signal timing for high-traffic routes
            route.signalTiming = min(maxTiming, route.signalTiming + 10);
        } else {
            // Decrease signal timing for low-traffic routes
            route.signalTiming = max(minTiming, route.signalTiming - 5);
        }
    }
}

// Display the current state of the traffic system
void displayRoutes(const vector<Route>& routes) {
    cout << "\nCurrent Traffic Signal Timings:\n";
    cout << "----------------------------------\n";
    for (const auto& route : routes) {
        cout << "Route: " << route.name
             << ", Traffic Volume: " << route.trafficVolume
             << ", Signal Timing: " << route.signalTiming << " seconds\n";
    }
}

int main() {
    // Define traffic routes
    vector<Route> routes = {
        {"Route A", 120, 30},   // Name, Traffic Volume, Signal Timing (in seconds)
        {"Route B", 80, 25},
        {"Route C", 200, 40},
        {"Route D", 60, 20}
    };

    int threshold = 100;    // Traffic volume threshold
    int maxTiming = 60;     // Maximum signal timing
    int minTiming = 15;     // Minimum signal timing

    cout << "Initial Traffic System:\n";
    displayRoutes(routes);

    // Simulate the adjustment of signal timings
    cout << "\nAdjusting traffic signals based on traffic volume...\n";
    adjustSignalTimings(routes, threshold, maxTiming, minTiming);

    // Display updated signal timings
    displayRoutes(routes);

    return 0;
}

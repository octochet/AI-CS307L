// tsp using simulated annealing

#include <bits/stdc++.h>

using namespace std;

// Function to calculate the distance between two cities
double distance(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

// Function to calculate the total distance of the path
double total_distance(vector<int> path, vector<int> x, vector<int> y) {
    double dist = 0;
    for (int i = 0; i < path.size() - 1; i++) {
        dist += distance(x[path[i]], y[path[i]], x[path[i + 1]], y[path[i + 1]]);
    }
    dist += distance(x[path[path.size() - 1]], y[path[path.size() - 1]], x[path[0]], y[path[0]]);
    return dist;
}

// Function to generate a random path
vector<int> random_path(int n) {
    vector<int> path;
    for (int i = 0; i < n; i++) {
        path.push_back(i);
    }
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        swap(path[i], path[j]);
    }
    return path;
}

// Function to generate a random neighbor
vector<int> random_neighbor(vector<int> path) {
    vector<int> neighbor = path;
    int i = rand() % path.size();
    int j = rand() % path.size();
    swap(neighbor[i], neighbor[j]);
    return neighbor;
}

// Function to simulate annealing
vector<int> simulated_annealing(vector<int> path, vector<int> x, vector<int> y, double T, double alpha, double T_min) {
    while (T > T_min) {
        vector<int> neighbor = random_neighbor(path);
        double dE = total_distance(neighbor, x, y) - total_distance(path, x, y);
        if (dE < 0) {
            path = neighbor;
        } else {
            double r = (double)rand() / RAND_MAX;
            if (r < exp(-dE / T)) {
                path = neighbor;
            }
        }
        T *= alpha;
    }
    return path;
}

int main() {
    // Read input
    ifstream fin("input.txt");
    int n;
    fin >> n;
    vector<int> p(n), x(n), y(n);
    for (int i = 0; i < n; i++) {
        fin >> p[i] >> x[i] >> y[i];
    }
    fin.close();

    // Simulated annealing
    vector<int> path = random_path(n);
    double T = 100, alpha = 0.999, T_min = 0.0001;
    path = simulated_annealing(path, x, y, T, alpha, T_min);

    // Write output
    ofstream fout("output.txt");
    for (int i = 0; i < n; i++) {
        fout << path[i] << " ";
    }
    fout << endl;
    fout << total_distance(path, x, y) << endl;
    fout.close();

    return 0;
}

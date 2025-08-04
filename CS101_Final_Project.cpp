// M08 Final Project
// Name: Ryan Hueseman
// Course: CS101
// Date: August 3, 2025

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

// A structure to hold the grid dimensions
struct Dimensions {
    int width = 0;
    int height = 0;
};

// Reads the input file to find the maximum x and y coordinates
Dimensions find_grid_dimensions(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: The file '" << filename << "' was not found." << std::endl;
        return { -1, -1 }; // Returns error signal
    }

    Dimensions dims;
    std::string line;
    int max_x = 0, max_y = 0;

    // Reads and discards the header line
    if (!std::getline(file, line)) {
        std::cerr << "Error: Could not read header from file." << std::endl;
        return { -1, -1 };
    }

    // Loops through the rest of the file
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string part;
        int x, y;

        // Parses x
        std::getline(ss, part, ',');
        try {
            x = std::stoi(part);
        }
        catch (const std::exception& e) { continue; }

        // Skips over the character part for this pass
        std::getline(ss, part, ',');

        // Parses y
        std::getline(ss, part, ',');
        try {
            y = std::stoi(part);
        }
        catch (const std::exception& e) { continue; }

        max_x = std::max(max_x, x);
        max_y = std::max(max_y, y);
    }

    // Dimensions are max + 1 to account for 0-based index
    dims.width = max_x + 1;
    dims.height = max_y + 1;
    return dims;
}

// Populates the 2-D Vector
bool populate_grid(const std::string& filename, std::vector<std::vector<char>>& grid) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: The file '" << filename << "' could not be opened for the second pass." << std::endl;
        return false;
    }

    std::string line;
    // Reads and discards the header line again
    if (!std::getline(file, line)) {
        return false;
    }

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string part;
        int x, y;
        char character;

        // Parses the data in x,character,y order
        std::getline(ss, part, ',');
        x = std::stoi(part);

        std::getline(ss, part, ',');
        character = part[0]; // Reads the character as a char

        std::getline(ss, part, ',');
        y = std::stoi(part);

        // Places the character, checking bounds to prevent errors
        if (y >= 0 && y < grid.size() && x >= 0 && x < grid[0].size()) {
            grid[y][x] = character;
        }
    }
    return true;
}

// Prints the 2D grid to the console.
void print_grid(const std::vector<std::vector<char>>& grid) {
    for (const auto& row : grid) {
        for (const char& ch : row) {
            std::cout << ch;
        }
        std::cout << std::endl;
    }
}

// Main Program Execution
int main() {
    const std::string input_file = "input.txt";

    // Determines the maximum x and y from the input file
    std::cout << "Processing input data to determine grid size..." << std::endl;
    Dimensions dims = find_grid_dimensions(input_file);

    if (dims.width == -1) {
        return 1; // Returns an error code
    }

    std::cout << "Grid dimensions determined: " << dims.width << " width x " << dims.height << " height." << std::endl;

    // Creates a 2D vector of chars, initialized with spaces
    std::vector<std::vector<char>> grid(dims.height, std::vector<char>(dims.width, ' '));

    // Fills the vector with characters from the input data
    std::cout << "Populating grid with characters..." << std::endl;
    if (!populate_grid(input_file, grid)) {
        return 1; // Returns an error code
    }

    // Prints the vector to reveal the answer
    std::cout << "\n--- Your Message ---\n" << std::endl;
    print_grid(grid);
    std::cout << "\n--------------------\n" << std::endl;

    return 0; // Success
}

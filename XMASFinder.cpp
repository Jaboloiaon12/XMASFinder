#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <random>

// Directions: right, down, down-right, down-left, left, up, up-left, up-right
const int dx[8] = {1, 0, 1, -1, -1, 0, -1, 1};
const int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const std::string TARGET = "XMAS";

// Generate a random grid of given size
std::vector<std::string> generateGrid(int rows, int cols) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 25); // A-Z
    std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    std::vector<std::string> grid(rows, std::string(cols, ' '));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = alphabet[dis(gen)];
        }
    }
    return grid;
}

int countXMAS(const std::vector<std::string>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int count = 0;

    #pragma omp parallel for reduction(+:count) collapse(2)
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] != 'X') continue;

            for (int dir = 0; dir < 8; dir++) {
                bool found = true;
                int r = i, c = j;

                for (char ch : TARGET) {
                    if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] != ch) {
                        found = false;
                        break;
                    }
                    r += dy[dir];
                    c += dx[dir];
                }

                if (found) {
                    count++;
                }
            }
        }
    }

    return count;
}

// Test function with timing
void runTest(const std::string& testName, const std::vector<std::string>& grid) {
    auto start = std::chrono::high_resolution_clock::now();
    int result = countXMAS(grid);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;

    std::cout << testName << " (" << grid.size() << "x" << grid[0].size() 
              << "): " << result << " occurrences, " << duration.count() << " ms\n";
}

int main() {
    // Test 1: Original 10x10 example
    std::vector<std::string> grid1 = {
        "MMMSXXMASM",
        "MSAMXMSMSA",
        "AMXSXMAAMM",
        "MSAMASMSMX",
        "XMASAMXAMM",
        "XXAMMXXAMA",
        "SMSMSASXSS",
        "SAXAMASAAA",
        "MAMMMXMMMM",
        "MXMXAXMASX"
    };
    runTest("Test 1 - Original Example", grid1);

    // Test 2: Small 5x5 random grid
    auto grid2 = generateGrid(5, 5);
    runTest("Test 2 - Small Random", grid2);

    // Test 3: Medium 50x50 random grid
    auto grid3 = generateGrid(50, 50);
    runTest("Test 3 - Medium Random", grid3);

    // Test 4: Large 100x100 random grid
    auto grid4 = generateGrid(100, 100);
    runTest("Test 4 - Large Random", grid4);

    // Test 5: Very Large 500x500 random grid
    auto grid5 = generateGrid(500, 500);
    runTest("Test 5 - Very Large Random", grid5);

    return 0;
}

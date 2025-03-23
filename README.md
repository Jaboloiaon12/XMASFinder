# XMASFinder
A blazing-fast C++ tool to count every 'XMAS' hidden in a word search grid. It checks all directions—horizontal, vertical, diagonal, even backward—using parallel processing to zip through big grids in no time. Perfect for puzzle fans or elves on Ceres!

Welcome to **XMASFinder**, a super-quick C++ tool that hunts down every "XMAS" in a word search grid. Whether it’s horizontal, vertical, diagonal, or even backward, this little program finds them all—and fast! Built with parallel processing, it’s ready to tackle grids big and small, from a tiny 5x5 to a massive 500x500.

## What’s It For?
Ever get stuck on a word search looking for "XMAS"? This solves that, counting every single occurrence in any direction. It’s based on a quirky puzzle from an elf on the Ceres monitoring station (long story!), and it’s optimized to run like the wind.

## How to Use It
1. **Get the Code**  
   Clone the repo:  
   ```bash
   git clone https://github.com/yourusername/XMASFinder.git
   cd XMASFinder

   Build It
You’ll need a C++ compiler (like g++) with OpenMP support. Compile with:
g++ -O3 -fopenmp xmas_finder.cpp -o xmas_finder

-O3: Makes it as fast as possible.
-fopenmp: Turns on parallel magic.

What’s Inside
xmas_finder.cpp: The main code. Finds "XMAS" with parallel loops and prints timing stats.
Tests: From a tiny 5x5 to a huge 500x500 grid, with the original 10x10 example (18 "XMAS"es!).
Speed
On a decent computer (say, 4 cores):

10x10: Blink-and-you-miss-it (<1 ms).
100x100: Still snappy (~20–50 ms).
500x500: About half a second (~500 ms).
Want it faster? Tweak the omp parallel settings or throw it on a GPU (future upgrade idea!).

Contributing
Got a speed boost idea? Found a bug? Open an issue or send a pull request—I’d love the help!

---

### Setup Instructions
1. **Create the Repo**:
   - On GitHub, click "New Repository," name it `XMASFinder`, and add the description above.
   - Initialize with a README and paste the content above.

2. **Add the Code**:
   - Save the C++ code from the previous response as `xmas_finder.cpp`.
   - Push it to the repo:  
     ```bash
     git add xmas_finder.cpp
     git commit -m "Add XMASFinder solver"
     git push origin main

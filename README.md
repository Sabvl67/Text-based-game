Ownership: Sam Wilson, Eugene Gu & Anh Vo
Last Updated: 2022-12-15 by Nicole Wilson &lt;n.wilson@uleth.ca&gt;

Your ultimate goal is to rescue the wise man, imprisoned in a mysterious cage, who holds the key to saving the country.
Welcome, brave knight, to an epic adventure! Your quest spans nine unique settings, each with its challenges and mysteries. Explore the following lands:

Frozen Tundra

Luminous Echoes

Rizzler Canyons  

Dream Symphony

Drunken Isles

Neon Nexus

Kitty Island   

Quantum Abyss

Nefarious Civic

Strategic interaction with the environment and characters is crucial to uncovering clues and overcoming obstacles.
Your decisions shape the outcome of your journey, so choose wisely.

How to play: https://docs.google.com/document/d/1JTo12gWeHvev6dTLQG01Fr1KnGDZkEgbVR5KAC8qLz8/edit?usp=sharing
This file can also be found in pdf file in docs directory

Notes:

* The Makefile and .gitlab-ci.yml files are set up to run on Ubuntu.
* The .gitlab-ci.yml file uses the targets in the Makefile.
* These are the tools/commands/apps used:
  * Compiler: g++
  * Version: c++14
  * Style Check: cpplint 1.6.1
  * Static Check: cppcheck 1.90
  * Coverage Check: 
    * gcov (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
    * lcov 1.14
  * Memory Check: valgrind 3.15.0
  * Unit Test: gtest v.1.12.1 
  * Documentation: doxygen 1.8.17-Ounbuntu2

Certain assumptions have been made:
* One repo contains the files for one project.
* All unit testing files are found in <code>test/</code> including <code>main.cpp</code>.
* All header files for the project are found in <code>include/</code> and named <code>*.h</code>, every class must have a header file.
* All project source files for the project are named <code>*.cpp</code>.
  * Any needed source files that correspond to header files are found in <code>src/</code>.
  * There is a <code>main.cpp</code> found in <code>src/project/</code>.

# Program for detecting the densest subgraph

d(S) = E(S) / V(S)

## DSD theory: 
http://people.seas.harvard.edu/~babis/dsd.pdf

### Implemented methods:
- Goldberg's bin-search algorithm

- Faster Greedy Charikar

### to run
brew install boost

in *CMakeLists.txt:*
```
set(BOOST_ROOT "**YOUR_PATH**")
find_package(Boost **YOUR_VERSION** COMPONENTS graph REQUIRED)
```
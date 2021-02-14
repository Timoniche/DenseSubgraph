# Program for detecting the densest subgraph

d(S) = E(S) / V(S)

## DSD theory: 
http://people.seas.harvard.edu/~babis/dsd.pdf

### Implemented methods:
- **Goldberg's bin-search algorithm**

    - edges.txt format: vertices from 0
   
![alt text](https://github.com/Timoniche/DenseSubgraph/blob/main/example.jpg)

- **Faster Greedy Charikar** (not implemented yet)

### to run
brew install boost

in *CMakeLists.txt:*
```
set(BOOST_ROOT "**YOUR_PATH**")
find_package(Boost **YOUR_VERSION** COMPONENTS graph REQUIRED)
```
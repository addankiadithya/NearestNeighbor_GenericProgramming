# Nearest Neighbor

Nearest Neighbor problem deals with finding the nearest neighbor of a vertex, a
point in an n-dimensional space. This find its applications in various commonly
recurring day to day problems. For instance, traveling salesman problem, where 
the salesperson tries finding an optimal route to pass through all the 
destination cities and complete a traversal, where it is required that the next 
possible destination chosen is nearest. Other problems include clustering and 
classification which try to identify the similarity in features and grouping 
them as clusters or identifying a new feature to its belonging class. Nearest 
neighbor can also be used as a solution to find an ordering of similar entities 
using their comparable attributes to find the distance between them.

Thus the objective of the project would be finding a generic implementation of 
finding the Nearest Neighbor and apply the same to different domains, i.e., a 
sequence of characters(strings of equal length(Hamming Distance) and strings of
unequal length(Levenshtein Distance)), a set of points(Euclidean distance), a 
binary stream of zeros and ones (Jaccard index) etc.

## Implementation

Implemented the Neighboring Algorithm using templates, defined classes: point, 
point_3d, binstr and strcls for binary strings and const char *. 

The implementation requires a vector of type T and a point/sequence of chars or 
binary digits as inputs, which then determines the type T and delegates the 
distance calculation to a function template, based on the type T. 

Distance for 2d and 3d points is calculated using Euclidean Distance.
Distance for Binary Strings is calculated using Jaccard coefficients.
Distance for sequence of characters is calculated using Hamming distance 
technique(same length).
Distance for sequence of characters is calculated using Levenshtein distance
technique(unequal length).

If the distance between a given input and the neighbor could not be determined, 
the neighbor algorithm returns the input itself (essentially meaning that there 
is no nearest neighbor than the point itself).

### Limitations: 
For Jaccard and Hamming distance, it is required that the length( number of 
characters/ binary digits) to be the same as the input(the string for which 
the nearest neighbor has to be found).

This limitation for strings could be over come for character strings, using 
Levenshtein distance(implemented generically along with other distances).

### Assumptions:
It is assumed that the distance calculated is a double, and, hence, the distance 
between any pair of inputs of type T is a double.

If the distance between the input point and an other random pair of points in 
the sequence is the same, the algorithm returns the first point in the sequence.

If the distance is not defined for the inputs, the function returns infinity.

## Execution
Testcases have been written in the directory neighbor.test, after building the 
code, run make test to see the test results. 
Check BUILD/Testing/Temporary/LastTest.log for the latest test results. 

### Sample Output 1:
distance: 1 -->> 3.60555
distance: 2 -->> 5
distance: 3 -->> 5.83095
distance: 4 -->> 6.7082
distance: 5 -->> 3.16228
Nearest Neighbor-->>  x: 1  y: 3

### Sample Output 2:
distance: 1 -->> 5.80517
distance: 2 -->> 6.38357
distance: 3 -->> 9.53415
distance: 4 -->> 6.62873
distance: 5 -->> 3.64555
Nearest Neighbor-->>  x: 1.1  y: 3  z: 2.2

### Sample Output 3:
distance: 1 -->> 2
distance: 2 -->> 6
distance: 3 -->> 3
distance: 4 -->> 3
distance: 5 -->> 6
Nearest Neighbor-->>  abcdef

### Sample Output 4:
distance: 1 -->> 0.333333
distance: 2 -->> 1
distance: 3 -->> 0.166667
distance: 4 -->> 0.666667
distance: 5 -->> 0.428571
Nearest Neighbor-->>  0101010111

## Applications
Could be used to calculate the nearest point in 2-dimensional and 3-dimensional 
space,Traveling salesman problem.

Could be applied to clustering/classification problems for points in space, by 
repeated calls to neighbor algorithm.

Could be applied to finding the nearest/duplicate files by comparing the content
(though not efficient as other techniques)

Could be applied to finding the differences between files(file comparision)

## Challenges
Faced a few challenges 
1. writing the prerequisites for generic implementation of Neighbor algorithm 
and distance algorithms for different domain of inputs. 
2. while using the concepts defined under concepts.hpp

## References
Dr.Andrew Sutton class notes on https://dev.cs.uakron.edu/trac/gps14/
Elements of Programming- Alexander Stepanov and Paul McJones
The C++ Programming Language- Bjarne Stroustrup
http://en.wikipedia.org/wiki/Nearest_neighbor
http://www.cplusplus.com/forum/beginner/15316/

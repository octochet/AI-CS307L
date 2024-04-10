# Artificial Intelligence Assignment

Team: Chetan Moturi(CS21B017) and MVSK Karthikeya(CS21B033)

The Projects:

1. TSP using variable neighbour search and simulated annealing
2. Sokoban using DFS branch and bound   

## Travelling Salesman Problem using NS & SA

- The traveling salesperson problem (TSP) is a touring problem in which each city must be visited exactly once. 
- The aim is to ﬁnd the shortest tour. The problem is known to be NP-hard.
- More Formally, Given a graph in which the nodes are cities, to find a cycle containing each city exactly once, such that the total cost of the tour is as low as possible.

### How to Execute Code?

To execute the Simulated Annealing code, follow the below commands in terminal,

```sh
user@desktop:~/AI-CS307L$ cd ./TSP/SA
user@desktop:~/AI-CS307L/TSP/SA$ python tsp.py
```

Some quick pointers,
- To change the datapoints file, change the file path in node_generator.py
- Add new .tsp files in the data folder only. Other file extensions or input formats will not work.

To execute The Variable Neighbour search code, follow the below commands in terminal,

```shell
user@desktop:~/AI-CS307L$ cd ./TSP/VNS
user@desktop:~/AI-CS307L/TSP/SA$ python VNS.py
```
Some quick pointers,
- To change datapoints file, change the file path on line no. 30.
- If plot was not generated, copy the path outputted and paste it in plot.py. make sure to change the datapoints file path too. 

## Sokoban using DFS Branch and Bound

> TODO:

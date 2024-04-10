import random
import numpy as np
import tsplib95


class NodeGenerator:
    def __init__(self, width, height):
        self.width = width
        self.height = height

    def generate(self):

        data = tsplib95.load('../data/pr439.tsp')
        numnodes = len(data.node_coords)
        # get x and y coordinates of the nodes
        xs = []
        ys = []
        for i in range(1, numnodes+1):
            node = data.node_coords[i]
            xs.append(node[0])
            ys.append(node[1])

        return np.column_stack((xs, ys))

if __name__ == "__main__":
    NodeGenerator(200, 200, 107).generate()

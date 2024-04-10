from nodes_generator import NodeGenerator
from simulated_annealing import SimulatedAnnealing


def main():
    # Parameters
    temp = 10000
    stopping_temp = 0.00000001
    alpha = 0.9995
    stopping_iter = 10000000

    # Size of the grid
    size_width = 200
    size_height = 200
    
    nodes = NodeGenerator(size_width, size_height).generate()

    sa = SimulatedAnnealing(nodes, temp, alpha, stopping_temp, stopping_iter)

    sa.anneal()
    sa.animateSolutions()
    sa.plotLearning()

if __name__ == "__main__":
    main()
#!/usr/bin/python3
import queue
import sys

class dijkstras:
    def __init__(self, graph):
        self.graph = graph
        self.q = queue.Queue()
        self.path  = {}
        self.explored = []

    def setup(self):
        self.path  = {}
        self.explored = []

        for key in self.graph.keys():
            self.path[key] = (None, 1000)

    def findShortestPath(self, start, end):
        self.start = start
        self.end   = end

        self.setup()

        # distance of node from it self
        self.path[start] = (start, 0)
        self.q.put(start)
        return self.exploreGraph()

    def exploreGraph(self):
        while not self.q.empty():
            n = self.q.get()

            # check if the node has been already explored
            if n in self.explored:
                continue

            # Add the node to explored list
            self.explored.append(n)

            # add children to the BFS queue
            self.enqueueNode(n)

            # get the children of the current node
            children = self.graph[n]

            for child in children:
                # compare the current cost to the expected cost
                if self.path[child[0]][1] > self.path[n][1] + child[1]:
                    del self.path[child[0]]
                    self.path[child[0]] = (n, self.path[n][1] + child[1])

        return self.formPath()

    def formPath(self):
        n = self.end
        shortestPath = [n]

        while n is not self.start:
            shortestPath.insert(0, self.path[n][0])
            n = self.path[n][0]

        return shortestPath

    def enqueueNode(self, node):
        for n in self.graph[node]:
            self.q.put(n[0])


def main():
    if len(sys.argv) != 3:
        print ("usage: python3 dijkstras.py start end")
        return

    '''
    Graph:
    A-B : 9, A-C : 2, A-D : 14
    B-E : 6
    C-D : 9, C-F : 10, C-E = 11
    D-F : 7
    E-F : 15
    '''
    graph = {
        'A':[('B',9),('C',2),('D',14)],
        'B':[('A',9),('E',6)],
        'C':[('A',2),('D',9),('F',10),('E',11)],
        'D':[('A',14),('C',9),('F',7)],
        'E':[('B',6),('C',11),('F',15)],
        'F':[('D',7),('C',10),('E',15)]
    }

    d = dijkstras(graph)
    path = d.findShortestPath(sys.argv[1], sys.argv[2])
    print(path)

if __name__ == '__main__':
    main()
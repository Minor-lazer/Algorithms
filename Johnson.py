
#This program is for HacktoberFest 2020

#Johnson's Algorithm in Python
#The problem is to find the shortest distance between all pairs of vertices in a weighted directed graph that can have negative edge weights. For the problem to be well-defined, there should be no cycles in the graph with a negative total weight.


class Graph:
    def __init__(self):
        # dictionary containing keys that map to the corresponding vertex object
        self.vertices = {}
 
    def add_vertex(self, key):
        """Add a vertex with the given key to the graph."""
        vertex = Vertex(key)
        self.vertices[key] = vertex
 
    def get_vertex(self, key):
        """Return vertex object with the corresponding key."""
        return self.vertices[key]
 
    def __contains__(self, key):
        return key in self.vertices
 
    def add_edge(self, src_key, dest_key, weight=1):
        """Add edge from src_key to dest_key with given weight."""
        self.vertices[src_key].add_neighbour(self.vertices[dest_key], weight)
 
    def does_edge_exist(self, src_key, dest_key):
        """Return True if there is an edge from src_key to dest_key."""
        return self.vertices[src_key].does_it_point_to(self.vertices[dest_key])
 
    def __len__(self):
        return len(self.vertices)
 
    def __iter__(self):
        return iter(self.vertices.values())
 
 
class Vertex:
    def __init__(self, key):
        self.key = key
        self.points_to = {}
 
    def get_key(self):
        """Return key corresponding to this vertex object."""
        return self.key
 
    def add_neighbour(self, dest, weight):
        """Make this vertex point to dest with given edge weight."""
        self.points_to[dest] = weight
 
    def get_neighbours(self):
        """Return all vertices pointed to by this vertex."""
        return self.points_to.keys()
 
    def get_weight(self, dest):
        """Get weight of edge from this vertex to dest."""
        return self.points_to[dest]
 
    def set_weight(self, dest, weight):
        """Set weight of edge from this vertex to dest."""
        self.points_to[dest] = weight
 
    def does_it_point_to(self, dest):
        """Return True if this vertex points to dest."""
        return dest in self.points_to
 
 
def johnson(g):
    """Return distance where distance[u][v] is the min distance from u to v.
 
    distance[u][v] is the shortest distance from vertex u to v.
 
    g is a Graph object which can have negative edge weights.
    """
    # add new vertex q
    g.add_vertex('q')
    # let q point to all other vertices in g with zero-weight edges
    for v in g:
        g.add_edge('q', v.get_key(), 0)
 
    # compute shortest distance from vertex q to all other vertices
    bell_dist = bellman_ford(g, g.get_vertex('q'))
 
    # set weight(u, v) = weight(u, v) + bell_dist(u) - bell_dist(v) for each
    # edge (u, v)
    for v in g:
        for n in v.get_neighbours():
            w = v.get_weight(n)
            v.set_weight(n, w + bell_dist[v] - bell_dist[n])
 
    # remove vertex q
    # This implementation of the graph stores edge (u, v) in Vertex object u
    # Since no other vertex points back to q, we do not need to worry about
    # removing edges pointing to q from other vertices.
    del g.vertices['q']
 
    # distance[u][v] will hold smallest distance from vertex u to v
    distance = {}
    # run dijkstra's algorithm on each source vertex
    for v in g:
        distance[v] = dijkstra(g, v)
 
    # correct distances
    for v in g:
        for w in g:
            distance[v][w] += bell_dist[w] - bell_dist[v]
 
    # correct weights in original graph
    for v in g:
        for n in v.get_neighbours():
            w = v.get_weight(n)
            v.set_weight(n, w + bell_dist[n] - bell_dist[v])
 
    return distance
 
 
def bellman_ford(g, source):
    """Return distance where distance[v] is min distance from source to v.
 
    This will return a dictionary distance.
 
    g is a Graph object which can have negative edge weights.
    source is a Vertex object in g.
    """
    distance = dict.fromkeys(g, float('inf'))
    distance[source] = 0
 
    for _ in range(len(g) - 1):
        for v in g:
            for n in v.get_neighbours():
                distance[n] = min(distance[n], distance[v] + v.get_weight(n))
 
    return distance
 
 
def dijkstra(g, source):
    """Return distance where distance[v] is min distance from source to v.
 
    This will return a dictionary distance.
 
    g is a Graph object.
    source is a Vertex object in g.
    """
    unvisited = set(g)
    distance = dict.fromkeys(g, float('inf'))
    distance[source] = 0
 
    while unvisited != set():
        # find vertex with minimum distance
        closest = min(unvisited, key=lambda v: distance[v])
 
        # mark as visited
        unvisited.remove(closest)
 
        # update distances
        for neighbour in closest.get_neighbours():
           if neighbour in unvisited:
               new_distance = distance[closest] + closest.get_weight(neighbour)
               if distance[neighbour] > new_distance:
                   distance[neighbour] = new_distance
 
    return distance
 
 
g = Graph()
print('Menu')
print('add vertex <key>')
print('add edge <src> <dest> <weight>')
print('johnson')
print('display')
print('quit')
 
while True:
    do = input('What would you like to do? ').split()
 
    operation = do[0]
    if operation == 'add':
        suboperation = do[1]
        if suboperation == 'vertex':
            key = int(do[2])
            if key not in g:
                g.add_vertex(key)
            else:
                print('Vertex already exists.')
        elif suboperation == 'edge':
            src = int(do[2])
            dest = int(do[3])
            weight = int(do[4])
            if src not in g:
                print('Vertex {} does not exist.'.format(src))
            elif dest not in g:
                print('Vertex {} does not exist.'.format(dest))
            else:
                if not g.does_edge_exist(src, dest):
                    g.add_edge(src, dest, weight)
                else:
                    print('Edge already exists.')
 
    elif operation == 'johnson':
        distance = johnson(g)
        print('Shortest distances:')
        for start in g:
            for end in g:
                print('{} to {}'.format(start.get_key(), end.get_key()), end=' ')
                print('distance {}'.format(distance[start][end]))
 
    elif operation == 'display':
        print('Vertices: ', end='')
        for v in g:
            print(v.get_key(), end=' ')
        print()
 
        print('Edges: ')
        for v in g:
            for dest in v.get_neighbours():
                w = v.get_weight(dest)
                print('(src={}, dest={}, weight={}) '.format(v.get_key(),
                                                             dest.get_key(), w))
        print()
 
    elif operation == 'quit':
        break

Program Explanation

1. An instance of Graph is created.
2. A menu is presented to the user to perform various operations on the graph.
3. To find shortest distances between all pairs, johnson is called to get the dictionary distance.
4. The distances between each pair of vertices are then displayed.
Runtime Test Cases

Case 1:
Menu
add vertex <key>
add edge <src> <dest> <weight>
johnson
display
quit
What would you like to do? add vertex 1
What would you like to do? add vertex 2
What would you like to do? add vertex 3
What would you like to do? add vertex 4
What would you like to do? add vertex 5
What would you like to do? add edge 1 2 3
What would you like to do? add edge 1 3 8
What would you like to do? add edge 1 5 -4
What would you like to do? add edge 2 5 7
What would you like to do? add edge 2 4 1
What would you like to do? add edge 3 2 4
What would you like to do? add edge 4 3 -5
What would you like to do? add edge 4 1 2
What would you like to do? add edge 5 4 6
What would you like to do? johnson
Shortest distances:
1 to 1 distance 0
1 to 2 distance 1
1 to 3 distance -3
1 to 4 distance 2
1 to 5 distance -4
2 to 1 distance 3
2 to 2 distance 0
2 to 3 distance -4
2 to 4 distance 1
2 to 5 distance -1
3 to 1 distance 7
3 to 2 distance 4
3 to 3 distance 0
3 to 4 distance 5
3 to 5 distance 3
4 to 1 distance 2
4 to 2 distance -1
4 to 3 distance -5
4 to 4 distance 0
4 to 5 distance -2
5 to 1 distance 8
5 to 2 distance 5
5 to 3 distance 1
5 to 4 distance 6
5 to 5 distance 0
What would you like to do? quit
 
Case 2:
python 226__graph_johnson.py
Menu
add vertex <key>
add edge <src> <dest> <weight>
johnson
display
quit
What would you like to do? add vertex 1
What would you like to do? add vertex 2
What would you like to do? johnson
Shortest distances:
1 to 1 distance 0
1 to 2 distance inf
2 to 1 distance inf
2 to 2 distance 0
What would you like to do? add edge 1 2 100
What would you like to do? add vertex 3
What would you like to do? add edge 2 3 -50
What would you like to do? add edge 1 3 60
What would you like to do? johnson
Shortest distances:
1 to 1 distance 0
1 to 2 distance 100
1 to 3 distance 50
2 to 1 distance inf
2 to 2 distance 0
2 to 3 distance -50
3 to 1 distance inf
3 to 2 distance inf
3 to 3 distance 0
What would you like to do? quit

#Program written by Siddhesh Shinde
#This program is for HacktoberFest 2020

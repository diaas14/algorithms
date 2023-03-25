/**
 * There is a bi-directional graph with n vertices, 
 * where each vertex is labeled from 0 to n - 1 (inclusive). 
 * The edges in the graph are represented as a 2D integer array edges, 
 * where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. 
 * Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.
 * You want to determine if there is a valid path that exists from vertex source to vertex destination.
 * Given edges and the integers n, source, and destination,
 * return true if there is a valid path from source to destination, or false otherwise.
 */

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

class PathExists {
    
    public boolean validPath(int n, int[][] edges, int source, int destination) {
        ArrayList<Integer>[] graph = new ArrayList[n];
        for (int i=0; i<n; i++) {
            graph[i] = new ArrayList<>();
        }
        
        for (int [] edge: edges) {
            graph[edge[0]].add(edge[1]);
            graph[edge[1]].add(edge[0]);
        }
        
        boolean [] visited = new boolean[n];
        Queue<Integer> bfs = new LinkedList<Integer>();
        bfs.add(source);
        visited[source] = true;
        
        while(!bfs.isEmpty()) {
            int cur = bfs.remove();
            if (cur == destination) return true;
            for (Integer neighbor: graph[cur]) {
                if (visited[neighbor]) continue;
                visited[neighbor] = true;
                bfs.add(neighbor);
            }
        }
        return false;
    }
}

package UndirectedGraphNode;

import java.util.ArrayList;
import java.util.List;

/**
 * Definition for undirected graph.
 */
public class UndirectedGraphNode {
	public int label;
	public List<UndirectedGraphNode> neighbors;

	public UndirectedGraphNode(int x) {
		label = x;
		neighbors = new ArrayList<UndirectedGraphNode>();
	}
};

package UndirectedGraphNode;

import java.util.ArrayList;
import java.util.List;

/**
 * Definition for undirected graph.
 */
public class UndirectedGraphNode {
	int label;
	List<UndirectedGraphNode> neighbors;

	UndirectedGraphNode(int x) {
		label = x;
		neighbors = new ArrayList<UndirectedGraphNode>();
	}
};

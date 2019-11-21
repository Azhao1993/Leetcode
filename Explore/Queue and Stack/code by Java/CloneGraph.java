package Leetcode_133_CloneGraph;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Set;
import java.util.Stack;

import UndirectedGraphNode.UndirectedGraphNode;

/*
	克隆一张无向图，图中的每个节点包含一个 label （标签）和一个 neighbors （邻接点）列表 。
	
	OJ的无向图序列化：
	
	节点被唯一标记。
	
	我们用 # 作为每个节点的分隔符，用 , 作为节点标签和邻接点的分隔符。
	
	例如，序列化无向图 {0,1,2#1,2#2,2}。
	
	该图总共有三个节点, 被两个分隔符  # 分为三部分。 
	
	第一个节点的标签为 0，存在从节点 0 到节点 1 和节点 2 的两条边。
	第二个节点的标签为 1，存在从节点 1 到节点 2 的一条边。
	第三个节点的标签为 2，存在从节点 2 到节点 2 (本身) 的一条边，从而形成自环。
	我们将图形可视化如下：
	
	       1
	      / \
	     /   \
	    0 --- 2
	         / \
	         \_/
 */
public class CloneGraph {

	// 133. 克隆图
	public UndirectedGraphNode cloneGraph(UndirectedGraphNode node) {
		if (node == null) {
			return null;
		}
		// 存放复制的对等节点
		HashMap<UndirectedGraphNode, UndirectedGraphNode> map = new HashMap<UndirectedGraphNode, UndirectedGraphNode>();
		// DFS复制节点
		Stack<UndirectedGraphNode> nodeStack = new Stack<UndirectedGraphNode>();

		Set<UndirectedGraphNode> set = new HashSet<UndirectedGraphNode>();
		DFS(node, nodeStack, map, set);
		// 复制邻居节点
		for (UndirectedGraphNode copynbNode : map.keySet()) {
			for (UndirectedGraphNode nbNode : copynbNode.neighbors) {
				map.get(copynbNode).neighbors.add(map.get(nbNode));
			}
		}

		return map.get(node);
	}

	private void DFS(UndirectedGraphNode node, Stack<UndirectedGraphNode> nodeStack,
			HashMap<UndirectedGraphNode, UndirectedGraphNode> map, Set<UndirectedGraphNode> set) {

		nodeStack.push(node);
		while (!nodeStack.isEmpty()) {
			UndirectedGraphNode curNode = nodeStack.peek();
			// 复制标签
			UndirectedGraphNode newNode = new UndirectedGraphNode(curNode.label);
			//
			map.put(curNode, newNode);
			set.add(curNode);
			for (UndirectedGraphNode nbNode : curNode.neighbors) {
				if (!set.contains(nbNode)) {
					nodeStack.push(nbNode);
					DFS(nbNode, nodeStack, map, set);
				}
			}
			nodeStack.pop();
			return;
		}

	}

	// 2ms
	HashMap<Integer, UndirectedGraphNode> cloned = new HashMap<>();

	public UndirectedGraphNode cloneGraph0(UndirectedGraphNode node) {
		// 空节点
		if (node == null)
			return null;
		// 已复制
		if (cloned.containsKey(node.label))
			return cloned.get(node.label);
		// 未复制
		UndirectedGraphNode ans = new UndirectedGraphNode(node.label);
		cloned.put(node.label, ans);
		// 遍历邻居节点
		for (UndirectedGraphNode ugn : node.neighbors) {
			ans.neighbors.add(cloneGraph0(ugn));
		}
		return ans;
	}
}

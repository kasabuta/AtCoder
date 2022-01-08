#include "Question198E.h"
#include "../../Utility/AtCoderInOut.h"
#include "../../Utility/Utility.h"
namespace Question198E {
namespace {
	const char* INPUT_CASE[] = {
	R"(6
1 2 3 4 5 6
1 2
2 3
2 4
2 5
2 6
)",
	R"(6
1 1 3 4 5 6
1 2
2 3
2 4
2 5
2 6
)",
	};
	const char* OUTPUT_CASE[] = {
	R"(1
2
3
4
5
6
)",
	R"(1
)",
	};
	static_assert(SIZEOF(OUTPUT_CASE) == SIZEOF(INPUT_CASE), "num of OUTPUT_CASE is invalid.");
}	// end of anonymous namespace.
const char* AtCoderQuestion::GetInputCase(uint8_t index) const {
	if (index < SIZEOF(INPUT_CASE)) {
		return INPUT_CASE[index];
	}
	return "";
}
const char* AtCoderQuestion::GetOutputCase(uint8_t index) const {
	if (index < SIZEOF(OUTPUT_CASE)) {
		return OUTPUT_CASE[index];
	}
	return "";
}
AtCoderQuestion::AtCoderQuestion() : AtCoderQuestionBase<InputStruct, OutputStruct>() {
	m_numTestCase = SIZEOF(INPUT_CASE);
}
InputStruct AtCoderQuestion::Input() {
	InputStruct input;
	InputFormat("%d\n", &input.sizeTree);
	char buf[64];
	InputFormat("%[^\n]", buf);
	std::string colors(buf);
	auto arrayColor = split(colors, " ");
	for (auto color : arrayColor) {
		input.colors.push_back(std::atoi(color.c_str()));
	}
	repeat(i, input.sizeTree - 1) {
		Edge edge;
		InputFormat("%d %d", &edge.start, &edge.end);
		input.edges.push_back(edge);
	}
	return input;
}
void AtCoderQuestion::Output(const OutputStruct& output, std::string* outStr) {
	for (auto result : output.nodes) {
		OutputFormat(outStr, "%d\n", result);
	}
}

struct TreeNode {
	std::vector<TreeNode*> connect;
	bool isSearchedFlag;

	int color;
	bool isGoodNode;
};

class Tree {
public:
	std::vector<TreeNode> m_nodes;

	void MakeTree(const int sizeTree, const std::vector<Edge>& edges) {
		m_nodes.resize(sizeTree);
		repeat(i,sizeTree) {
			m_nodes[i].isSearchedFlag = false;
		}
		for (auto edge : edges) {
			m_nodes[edge.start - 1].connect.push_back(&m_nodes[edge.end - 1]);
			m_nodes[edge.end - 1].connect.push_back(&m_nodes[edge.start - 1]);
		}
	}

	void SetColor(const std::vector<int>& colors) {
		repeat(i, colors.size()) {
			m_nodes[i].color = colors[i];
		}
	}


	void DFS(TreeNode* node, std::vector<TreeNode*> path){
		node->isSearchedFlag = true;

		node->isGoodNode = true;
		for (auto route : path) {
			if (route->color == node->color) {
				node->isGoodNode = false;
				break;
			}
		}

		path.push_back(node);
		for (auto&& next : node->connect) {
			if (next->isSearchedFlag) {
				continue;
			} else {
				DFS(next, path);
			}
		}
		path.pop_back();
	}

	std::vector<int> SearchGoodNodes() {
		std::vector<TreeNode*> path;
		DFS(&m_nodes[0], path);

		std::vector<int> result;
		repeat(i, m_nodes.size()) {
			if (m_nodes[i].isGoodNode) {
				result.push_back(i+1);
			}
		}
		return result;
	}
};


OutputStruct AtCoderQuestion::Solver(const InputStruct& input) {
	Tree tree;
	tree.MakeTree(input.sizeTree, input.edges);
	tree.SetColor(input.colors);

	OutputStruct result;
	result.nodes = tree.SearchGoodNodes();

	return result;
}
}

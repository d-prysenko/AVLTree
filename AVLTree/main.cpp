#include <iostream>
#include <vector>
#include <conio.h>
#include "AVLTree.hpp"

void pause(std::string message);

int main()
{
	std::vector<std::string> dumps;

	com::AVLTree<int> tree;

	tree.insert(1);
	dumps.push_back(com::util::dot_export(tree));

	tree.insert(2);
	dumps.push_back(com::util::dot_export(tree));

	tree.insert(3);
	dumps.push_back(com::util::dot_export(tree));

	tree.insert(4);
	dumps.push_back(com::util::dot_export(tree));

	tree.insert(5);
	dumps.push_back(com::util::dot_export(tree));

	tree.insert(6);
	dumps.push_back(com::util::dot_export(tree));


	for (auto& graph : dumps)
	{
		com::util::copy_to_clipboard(graph);
		pause("Tree in clipboard! Press any key to load next tree..");
	}

	int to_remove = 5;
	pause("Press any key to remove " + std::to_string(to_remove));

	std::cout << "Is tree contains " << to_remove << "? " << (tree.find(to_remove) ? "Yes!" : "No") << std::endl;
	tree.remove(to_remove);
	std::cout << to_remove << " removed" << std::endl;
	std::cout << "Is tree contains " << to_remove << "? " << (tree.find(to_remove) ? "Yes!" : "No") << std::endl;

	com::util::copy_to_clipboard(com::util::dot_export(tree));

	pause("Tree in the clipboard\nPress any key to exit..");

	return 0;
}

void pause(std::string message)
{
	std::cout << message << std::endl;
	_getch();
}
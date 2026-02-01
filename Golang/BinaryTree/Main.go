package main

import (
	"fmt"
	"math/rand"
)

//binaryTree Node
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// Function to perform inorder traversal of the binary tree
func inorderTraversal(root *TreeNode) []int {
	var result []int
	var inorder func(node *TreeNode)
	inorder = func(node *TreeNode) {
		if node == nil {
			return
		}
		inorder(node.Left)
		result = append(result, node.Val)
		inorder(node.Right)
	}
	inorder(root)
	return result
}

func generateRandomTree(depth int) *TreeNode {
	if depth == 0 {
		return nil
	}
	node := &TreeNode{
		Val:   rand.Intn(100),
		Left:  generateRandomTree(depth - 1),
		Right: generateRandomTree(depth - 1),
	}
	return node
}

func testInorderTraversal() {
	root := generateRandomTree(3)
	result := inorderTraversal(root)
	fmt.Println("Inorder Traversal Result:", result)
}

func main() {
	testInorderTraversal()
}

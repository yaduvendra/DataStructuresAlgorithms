# Node class to represent a 
# node in the binary tree 
# with value, left and right attributes 
class Node(object): 
	def __init__(self, value, left = None, right = None): 
		self.value = value 
		self.left = left 
		self.right = right 

# To store count of pairs 
count = 0

# To store difference between 
# current node's value and x, 
# acts a lookup for counting pairs 
hash_t = set() 

# The input, we need to count 
# pairs whose sum is equal to x 
x = 10

# Function to count number of pairs 
# Does a pre-order traversal of the tree 
def count_pairs_w_sum(root): 
	# global count 
	if root: 
		if root.value in hash_t: 
			count += 1
		else: 
			hash_t.add(x-root.value) 
		
		count_pairs_w_sum(root.left) 
		count_pairs_w_sum(root.right) 

# Create a 
# binary tree and call the function 
# to get the count 
if __name__ == '__main__': 
	root = Node(5) 
	
	root.left = Node(3) 
	root.right = Node(7) 
	
	root.left.left = Node(2) 
	root.left.right = Node(4) 
	
	root.right.left = Node(6) 
	root.right.right = Node(8) 
	
	count_pairs_w_sum(root) 
	
	print count 

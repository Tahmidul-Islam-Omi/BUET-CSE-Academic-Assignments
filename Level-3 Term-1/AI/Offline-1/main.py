import sys
import heapq
from copy import deepcopy

class Node:
    def __init__(self, board, priority=0, parent=None):
        self.board = board          # Current board configuration
        self.priority = priority    # Priority value for search
        self.parent = parent        # Reference to the previous search node

    # For priority queue comparison
    def __lt__(self, other):
        return self.priority < other.priority

def Hamming_Distance(board):
    size = len(board)
    hamming_distance = 0
    goal_number = 1
    
    for i in range(size):
        for j in range(size):
            if board[i][j] != 0 and board[i][j] != goal_number:  # Don't count blank tile (0)
                hamming_distance += 1
            goal_number += 1
    
    return hamming_distance


def Manhattan_Distance(board):
    manhattan_distance = 0
    size = len(board)
    
    for i in range(size):
        for j in range(size):
            if board[i][j] != 0:  # Skip the blank tile
                # Calculate goal position (0-based indexing)
                goal_row = (board[i][j] - 1) // size
                goal_col = (board[i][j] - 1) % size
                manhattan_distance += abs(i - goal_row) + abs(j - goal_col)

    return manhattan_distance

def Euclidean_Distance(board):
    euclidean_distance = 0
    size = len(board)

    for i in range(size):
        for j in range(size):
            if board[i][j] != 0:  # Skip the blank tile
                # Calculate goal position (0-based indexing)
                goal_row = (board[i][j] - 1) // size
                goal_col = (board[i][j] - 1) % size
                euclidean_distance += ((i - goal_row) ** 2 + (j - goal_col) ** 2) ** 0.5

    return euclidean_distance

def Linear_Conflict_heuristic(board):
    size = len(board)
    manhattan = Manhattan_Distance(board)
    linear_conflicts = 0
    
    # Check rows for linear conflicts
    for i in range(size):
        # Get tiles that belong to this row in the goal state
        row_tiles = []
        for j in range(size):
            tile = board[i][j]
            if tile != 0:  # Skip blank tile
                goal_row = (tile - 1) // size
                if goal_row == i:  # Tile belongs to this row in goal state
                    row_tiles.append((tile, j))
        
        # Check for conflicts in this row
        for idx1 in range(len(row_tiles)):
            for idx2 in range(idx1 + 1, len(row_tiles)):
                tile1, pos1 = row_tiles[idx1]
                tile2, pos2 = row_tiles[idx2]
                # If tile with higher value is to the left of tile with lower value
                if tile1 > tile2 and pos1 < pos2:
                    linear_conflicts += 1
                # If tile with lower value is to the right of tile with higher value
                elif tile1 < tile2 and pos1 > pos2:
                    linear_conflicts += 1
    
    # Check columns for linear conflicts
    for j in range(size):
        # Get tiles that belong to this column in the goal state
        col_tiles = []
        for i in range(size):
            tile = board[i][j]
            if tile != 0:  # Skip blank tile
                goal_col = (tile - 1) % size
                if goal_col == j:  # Tile belongs to this column in goal state
                    col_tiles.append((tile, i))
        
        # Check for conflicts in this column
        for idx1 in range(len(col_tiles)):
            for idx2 in range(idx1 + 1, len(col_tiles)):
                tile1, pos1 = col_tiles[idx1]
                tile2, pos2 = col_tiles[idx2]
                # If tile with higher row value is above tile with lower row value
                if (tile1 - 1) // size > (tile2 - 1) // size and pos1 < pos2:
                    linear_conflicts += 1
                # If tile with lower row value is below tile with higher row value
                elif (tile1 - 1) // size < (tile2 - 1) // size and pos1 > pos2:
                    linear_conflicts += 1
    
    return manhattan + 2 * linear_conflicts

def count_inversions(board):
    
    inversion_count = 0
    # Convert 2D board to 1D array, ignoring the blank tile
    flat_board = []
    for row in board:
        for num in row:
            if num != 0:  # Skip the blank tile
                flat_board.append(num)
    
    # Count inversions
    for i in range(len(flat_board)):
        for j in range(i + 1, len(flat_board)):
            if flat_board[i] > flat_board[j]:
                inversion_count += 1
    
    return inversion_count

def find_blank_position(board):
    size = len(board)
    for i in range(size - 1, -1, -1):    # Search from bottom (size-1) to top (0)
        for j in range(size):
            if board[i][j] == 0:
                return i    # Returns the row number where blank (0) is found
                
def get_blank_position(board):
    size = len(board)
    for i in range(size):
        for j in range(size):
            if board[i][j] == 0:
                return (i, j)
    return None  # Should never reach here if board is valid

def get_possible_moves(board):
    
    size = len(board)
    blank_row, blank_col = get_blank_position(board)
    possible_moves = []
    
    # Check all four directions (up, down, left, right)
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    
    for dr, dc in directions:
        new_row, new_col = blank_row + dr, blank_col + dc
        
        # Check if the new position is valid
        if 0 <= new_row < size and 0 <= new_col < size:
            # Create a new board with the move applied
            new_board = deepcopy(board)
            # Swap the blank tile with the adjacent tile
            new_board[blank_row][blank_col] = new_board[new_row][new_col]
            new_board[new_row][new_col] = 0
            possible_moves.append(new_board)
    
    return possible_moves

def is_goal_state(board):
    size = len(board)
    expected = 1
    
    for i in range(size):
        for j in range(size):
            # Skip the last cell which should be 0 (blank)
            if i == size - 1 and j == size - 1:
                return board[i][j] == 0
            
            if board[i][j] != expected:
                return False
            expected += 1
    
    return True

def print_solution(node):

    moves = 0
    path = []
    current = node
    
    # Build path from goal to start
    while current is not None:
        path.append(current)
        current = current.parent
        if current is not None:  # Don't count the initial state
            moves += 1
    
    # Print solution in correct order (start to goal)
    print(f"\nMinimum number of moves = {moves}\n")
    print("Solution path:")
    for node in reversed(path):
        print_board(node.board)
        print()

def print_board(board):
    size = len(board)
    for i in range(size):
        print(" ".join(str(board[i][j]) for j in range(size)))
    print()

def a_star_search(initial_board, heuristic_func):
    """A* search algorithm implementation"""
    # Create the initial node
    initial_node = Node(initial_board, heuristic_func(initial_board), None)
    
    # Priority queue for open list
    open_list = []
    # heapq.heappush(open_list, (initial_node.priority, id(initial_node), initial_node))
    heapq.heappush(open_list, (initial_node.priority, heuristic_func(initial_node.board), initial_node))
    
    # Set for closed list to avoid revisiting states
    closed_set = set()
    closed_set.add(str(initial_board))
    
    # Counters for nodes
    expanded_nodes = 0  # Nodes popped and processed
    explored_nodes = 1  # Nodes discovered (pushed to open list)
    
    while open_list:
        # Get the node with the lowest priority
        _, _, current_node = heapq.heappop(open_list) # ignoring priority value, unique id
        expanded_nodes += 1
        
        # Check if we've reached the goal
        if is_goal_state(current_node.board):
            print(f"Expanded {expanded_nodes} nodes.")
            print(f"Explored {explored_nodes} nodes.")
            print_solution(current_node)
            return True
        
        # Generate all possible moves
        for next_board in get_possible_moves(current_node.board):
            # Skip if we've already visited this state
            board_str = str(next_board)
            if board_str in closed_set:
                continue
            
            # Calculate g(n) - cost so far (parent's g + 1)
            g_cost = (current_node.priority - heuristic_func(current_node.board)) + 1
            
            # Calculate h(n) - heuristic estimate to goal
            h_cost = heuristic_func(next_board)
            
            # Create new node with f(n) = g(n) + h(n)
            next_node = Node(next_board, g_cost + h_cost, current_node)
            
            # Add to open list and increment explored nodes counter
            heapq.heappush(open_list, (next_node.priority, id(next_node), next_node))
            explored_nodes += 1
            
            # Mark as visited
            closed_set.add(board_str)

def main():
    board_size = int(input("Enter board size: "))
    board = [[0 for _ in range(board_size)] for _ in range(board_size)]

    # Take input for each position in the board
    print(f"Enter the elements row by row (Size {board_size} * {board_size}).")

    for i in range(board_size):
        row = input().split()
        for j in range(board_size):
            board[i][j] = int(row[j])

    # Check if the puzzle is solvable
    if board_size % 2 != 0 and count_inversions(board) % 2 != 0:
        print("Unsolvable Puzzle.")
        sys.exit()
        
    elif board_size % 2 == 0:
        blank_row_from_bottom = board_size - find_blank_position(board)  # Convert to counting from bottom
        if (blank_row_from_bottom % 2 == 0 and count_inversions(board) % 2 != 1) or \
            (blank_row_from_bottom % 2 == 1 and count_inversions(board) % 2 != 0):
            print("Unsolvable Puzzle.")
            sys.exit()
    
    # Choose heuristic function
    print("\nChoose a heuristic function:")
    print("1. Hamming Distance")
    print("2. Manhattan Distance")
    print("3. Euclidean Distance")
    print("4. Linear Conflict with Manhattan Distance")
    
    choice = int(input("Enter your choice (1-4): "))
    
    heuristic_functions = {
        1: Hamming_Distance,
        2: Manhattan_Distance,
        3: Euclidean_Distance,
        4: Linear_Conflict_heuristic
    }
    
    if choice not in heuristic_functions:
        print("Invalid choice. Using Manhattan Distance by default.")
        choice = 2
    
    print(f"\nSolving puzzle using {list(heuristic_functions.keys())[choice-1]} heuristic...")
    a_star_search(board, heuristic_functions[choice])

if __name__ == "__main__":
    main()
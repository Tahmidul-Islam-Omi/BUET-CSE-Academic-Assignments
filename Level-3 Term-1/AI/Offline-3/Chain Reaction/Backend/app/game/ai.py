from typing import List, Tuple, Optional
import math, time
from .models import GameState, Player
from .engine import GameEngine

class AIPlayer:
    def __init__(self, depth: int = 3, heuristic_type: str = "critical_mass"):
        self.depth = depth
        self.heuristic_type = heuristic_type

    def get_best_move(self, state: GameState) -> Tuple[int, int]:
        """Returns the best move (row, col) for the current player"""
        start_time = time.time()
        _, move = self.minimax(state, self.depth, -math.inf, math.inf, True, self.heuristic_type)
        end_time = time.time()
        move_time = end_time - start_time
        print(f"AI move took {move_time} seconds")       
        return move

    def minimax(self, state: GameState, depth: int, alpha: float, beta: float, 
                maximizing_player: bool, heuristic_type: str) -> Tuple[float, Optional[Tuple[int, int]]]:
        """Minimax algorithm with alpha-beta pruning that uses the specified heuristic"""
        if depth == 0 or state.winner is not None:
            return self.evaluate(state, heuristic_type), None

        player = state.current_player
        valid_moves = self.get_valid_moves(state)
        
        if maximizing_player:
            max_eval = -math.inf
            best_move = None
            for move in valid_moves:
                new_state = self.simulate_move(state, move[0], move[1], player)
                eval, _ = self.minimax(new_state, depth-1, alpha, beta, False, heuristic_type)
                if eval > max_eval:
                    max_eval = eval
                    best_move = move
                alpha = max(alpha, eval)
                if beta <= alpha:
                    break
            return max_eval, best_move
        else:
            min_eval = math.inf
            best_move = None
            for move in valid_moves:
                new_state = self.simulate_move(state, move[0], move[1], player)
                eval, _ = self.minimax(new_state, depth-1, alpha, beta, True, heuristic_type)
                if eval < min_eval:
                    min_eval = eval
                    best_move = move
                beta = min(beta, eval)
                if beta <= alpha:
                    break
            return min_eval, best_move

    def get_valid_moves(self, state: GameState) -> List[Tuple[int, int]]:
        """Returns list of valid moves (row, col)"""
        moves = []
        for row in range(state.rows):
            for col in range(state.cols):
                cell = state.board[row][col]
                if cell.player is None or cell.player == state.current_player:
                    moves.append((row, col))
        return moves

    def simulate_move(self, state: GameState, row: int, col: int, player: Player) -> GameState:
        """Create a new game state with the move applied"""
        import copy
        new_state = copy.deepcopy(state)
        engine = GameEngine(new_state)
        engine.make_move(row, col, player)
        return new_state

    def evaluate(self, state: GameState, heuristic_type: str = "critical_mass") -> float:
        """Evaluate the game state using the specified heuristic"""
        # Select the appropriate heuristic function
        if heuristic_type == "orb_count":
            return self._evaluate_orb_count(state)
        elif heuristic_type == "corner_control":
            return self._evaluate_corner_control(state)
        elif heuristic_type == "edge_control":
            return self._evaluate_edge_control(state)
        elif heuristic_type == "critical_mass":
            return self._evaluate_critical_mass(state)
        elif heuristic_type == "territory_control":
            return self._evaluate_territory_control(state)
        elif heuristic_type == "mobility":
            return self._evaluate_mobility(state)
        elif heuristic_type == "chain_potential":
            return self._evaluate_chain_potential(state)
        else:
            # Default to critical mass heuristic
            return self._evaluate_critical_mass(state)
    
    def _evaluate_orb_count(self, state: GameState) -> float:
        """
        Basic Orb Count Heuristic
        
        Simply counts the difference in orbs between the current player and opponent.
        This is the most basic material advantage evaluation.
        
        Effectiveness: Good baseline but doesn't consider strategic positioning.
        """
        current = state.current_player
        opponent = Player.BLUE if current == Player.RED else Player.RED
        
        current_orbs = 0
        opponent_orbs = 0
        
        for row in state.board:
            for cell in row:
                if cell.player == current:
                    current_orbs += cell.count
                elif cell.player == opponent:
                    opponent_orbs += cell.count
                    
        return current_orbs - opponent_orbs
    
    def _evaluate_corner_control(self, state: GameState) -> float:
        """
        Corner Control Heuristic
        
        Corners are strategic positions (only 2 neighbors) that are easier to defend
        and harder to capture, making them valuable territory. This heuristic values
        controlling corner cells, with higher value as they approach critical mass.
        
        Effectiveness: Very strong in early to mid-game for establishing stable positions.
        """
        current = state.current_player
        opponent = Player.BLUE if current == Player.RED else Player.RED
        
        corners = [(0, 0), (0, state.cols-1), (state.rows-1, 0), (state.rows-1, state.cols-1)]
        current_corner_control = 0
        opponent_corner_control = 0
        
        for r, c in corners:
            cell = state.board[r][c]
            critical_mass = state.get_critical_mass(r, c)
            
            if cell.player == current:
                # Value increases with orb count, especially when close to critical mass
                current_corner_control += cell.count * (1 + 0.5 * (cell.count / critical_mass))
            elif cell.player == opponent:
                opponent_corner_control += cell.count * (1 + 0.5 * (cell.count / critical_mass))
                
        return current_corner_control - opponent_corner_control
    
    def _evaluate_edge_control(self, state: GameState) -> float:
        """
        Edge Control Heuristic
        
        Edges are the second most stable positions (3 neighbors).
        Controlling edges provides strategic advantage for expansion.
        This heuristic values controlling edge cells, with higher value as they approach critical mass.
        
        Effectiveness: Strong for building a stable perimeter and limiting opponent's expansion.
        """
        current = state.current_player
        opponent = Player.BLUE if current == Player.RED else Player.RED
        
        current_edge_control = 0
        opponent_edge_control = 0
        
        # Top and bottom edges (excluding corners)
        for c in range(1, state.cols-1):
            # Top edge
            cell = state.board[0][c]
            critical_mass = state.get_critical_mass(0, c)
            if cell.player == current:
                current_edge_control += cell.count * (1 + 0.3 * (cell.count / critical_mass))
            elif cell.player == opponent:
                opponent_edge_control += cell.count * (1 + 0.3 * (cell.count / critical_mass))
                
            # Bottom edge
            cell = state.board[state.rows-1][c]
            critical_mass = state.get_critical_mass(state.rows-1, c)
            if cell.player == current:
                current_edge_control += cell.count * (1 + 0.3 * (cell.count / critical_mass))
            elif cell.player == opponent:
                opponent_edge_control += cell.count * (1 + 0.3 * (cell.count / critical_mass))
        
        # Left and right edges (excluding corners)
        for r in range(1, state.rows-1):
            # Left edge
            cell = state.board[r][0]
            critical_mass = state.get_critical_mass(r, 0)
            if cell.player == current:
                current_edge_control += cell.count * (1 + 0.3 * (cell.count / critical_mass))
            elif cell.player == opponent:
                opponent_edge_control += cell.count * (1 + 0.3 * (cell.count / critical_mass))
                
            # Right edge
            cell = state.board[r][state.cols-1]
            critical_mass = state.get_critical_mass(r, state.cols-1)
            if cell.player == current:
                current_edge_control += cell.count * (1 + 0.3 * (cell.count / critical_mass))
            elif cell.player == opponent:
                opponent_edge_control += cell.count * (1 + 0.3 * (cell.count / critical_mass))
                
        return current_edge_control - opponent_edge_control
    
    def _evaluate_critical_mass(self, state: GameState) -> float:
        """
        Critical Mass Heuristic
        
        Cells that are close to exploding provide tactical advantage.
        This encourages building up cells to create chain reactions.
        The heuristic values cells more as they get closer to their critical mass,
        with an exponential increase to emphasize cells very close to exploding.
        
        Effectiveness: Very strong for tactical play and setting up chain reactions,
        which is the core winning mechanic in Chain Reaction.
        """
        current = state.current_player
        opponent = Player.BLUE if current == Player.RED else Player.RED
        
        current_critical = 0
        opponent_critical = 0
        
        for r in range(state.rows):
            for c in range(state.cols):
                cell = state.board[r][c]
                critical_mass = state.get_critical_mass(r, c)
                
                if cell.player == current and cell.count > 0:
                    # Value increases exponentially as we get closer to critical mass
                    critical_ratio = cell.count / critical_mass
                    current_critical += critical_ratio ** 2  # Squared for emphasis
                elif cell.player == opponent and cell.count > 0:
                    critical_ratio = cell.count / critical_mass
                    opponent_critical += critical_ratio ** 2
                    
        return current_critical - opponent_critical
    
    def _evaluate_territory_control(self, state: GameState) -> float:
        """
        Territory Control Heuristic
        
        Measures board area control by counting cells and their neighbors.
        This encourages spreading across the board strategically.
        The heuristic counts fully controlled cells and also considers
        influence over empty cells based on neighboring orb counts.
        
        Effectiveness: Strong for mid to late game when board position
        and area control become more important.
        """
        current = state.current_player
        opponent = Player.BLUE if current == Player.RED else Player.RED
        
        current_territory = 0
        opponent_territory = 0
        
        # Count controlled cells and their influence
        for r in range(state.rows):
            for c in range(state.cols):
                cell = state.board[r][c]
                if cell.count == 0:
                    # Empty cell - check neighboring influence
                    current_neighbors = 0
                    opponent_neighbors = 0
                    
                    for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                        nr, nc = r + dr, c + dc
                        if 0 <= nr < state.rows and 0 <= nc < state.cols:
                            neighbor = state.board[nr][nc]
                            if neighbor.player == current:
                                current_neighbors += neighbor.count
                            elif neighbor.player == opponent:
                                opponent_neighbors += neighbor.count
                    
                    # Cell is under influence of player with more neighboring orbs
                    if current_neighbors > opponent_neighbors:
                        current_territory += 0.5  # Partial control
                    elif opponent_neighbors > current_neighbors:
                        opponent_territory += 0.5  # Partial control
                else:
                    # Occupied cell
                    if cell.player == current:
                        current_territory += 1
                    else:
                        opponent_territory += 1
                        
        return current_territory - opponent_territory
    
    def _evaluate_mobility(self, state: GameState) -> float:
        """
        Mobility Heuristic
        
        Count possible valid moves for both players.
        More available moves = more flexibility and options.
        This heuristic values having more potential moves than the opponent,
        which indicates greater freedom and tactical options.
        
        Effectiveness: Good for maintaining flexibility and avoiding situations
        where move options become limited.
        """
        current = state.current_player
        opponent = Player.BLUE if current == Player.RED else Player.RED
        
        current_mobility = 0
        opponent_mobility = 0
        
        for r in range(state.rows):
            for c in range(state.cols):
                cell = state.board[r][c]
                # A cell is a valid move if it's empty or owned by the player
                if cell.count == 0 or cell.player == current:
                    current_mobility += 1
                if cell.count == 0 or cell.player == opponent:
                    opponent_mobility += 1
                    
        return current_mobility - opponent_mobility
    
    def _evaluate_chain_potential(self, state: GameState) -> float:
        """
        Chain Potential Heuristic

        Evaluates how close the player's orbs are to causing chain reactions,
        especially if adjacent enemy cells are near critical mass.
        Encourages clustering orbs near weak enemy positions to maximize explosion potential.

        Effectiveness: High tactical value for mid-late game where chain explosions
        can reverse control quickly.
        """
        current = state.current_player
        opponent = Player.BLUE if current == Player.RED else Player.RED

        current_chain_score = 0
        opponent_chain_score = 0

        for r in range(state.rows):
            for c in range(state.cols):
                cell = state.board[r][c]
                if cell.count == 0:
                    continue

                critical_mass = state.get_critical_mass(r, c)


                if cell.player == current:
                    # Check if this cell is near critical mass
                    critical_ratio = cell.count / critical_mass
                    if critical_ratio >= 0.75:
                        # Check if neighbors are weak enemy cells
                        for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                            nr, nc = r + dr, c + dc
                            if 0 <= nr < state.rows and 0 <= nc < state.cols:
                                neighbor = state.board[nr][nc]
                                neighbor_cm = state.get_critical_mass(nr, nc)
                                if neighbor.player == opponent and neighbor.count < neighbor_cm:
                                    current_chain_score += 1 + critical_ratio  # Bonus for build-up
                elif cell.player == opponent:
                    critical_ratio = cell.count / critical_mass
                    if critical_ratio >= 0.75:
                        for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                            nr, nc = r + dr, c + dc
                            if 0 <= nr < state.rows and 0 <= nc < state.cols:
                                neighbor = state.board[nr][nc]
                                neighbor_cm = state.get_critical_mass(nr, nc)
                                if neighbor.player == current and neighbor.count < neighbor_cm:
                                    opponent_chain_score += 1 + critical_ratio

        return current_chain_score - opponent_chain_score
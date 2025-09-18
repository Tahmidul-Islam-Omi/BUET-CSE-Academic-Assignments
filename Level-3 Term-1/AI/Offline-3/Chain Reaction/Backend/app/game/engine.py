from .models import GameState, Player

class GameEngine:
    def __init__(self, state: GameState):
        self.state = state

    def make_move(self, row: int, col: int, player: Player) -> bool:
        """Make a move and handle explosions. Returns True if move was valid."""
        if player != self.state.current_player:
            return False
        
        cell = self.state.board[row][col]
        
        # Check if move is valid
        if cell.player is not None and cell.player != player:
            return False
            
        # Place the orb
        cell.count += 1
        cell.player = player
        
        # Handle explosions if critical mass reached
        if cell.count >= self.state.get_critical_mass(row, col):
            self._explode(row, col)
        
        # Check for winner
        self._check_winner()
        
        # Switch player if game continues
        if not self.state.winner:
            self.state.current_player = Player.BLUE if player == Player.RED else Player.RED
        
        return True

    def _explode(self, row: int, col: int):
        """Handle explosion and chain reactions"""
        queue = [(row, col)]
        
        while queue:
            r, c = queue.pop(0)
            cell = self.state.board[r][c]
            critical_mass = self.state.get_critical_mass(r, c)
            
            if cell.count < critical_mass:
                continue
                
            player = cell.player
            cell.count -= critical_mass
            if cell.count == 0:
                cell.player = None
                
            # Distribute orbs to adjacent cells
            for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                nr, nc = r + dr, c + dc
                if 0 <= nr < self.state.rows and 0 <= nc < self.state.cols:
                    neighbor = self.state.board[nr][nc]
                    neighbor.count += 1
                    neighbor.player = player
                    if neighbor.count >= self.state.get_critical_mass(nr, nc):
                        queue.append((nr, nc))

    def _check_winner(self):
        """Check if the game has been won"""
        red_exists = False
        blue_exists = False
        
        # Count total orbs to check if game has progressed
        total_orbs = 0
        
        for row in self.state.board:
            for cell in row:
                if cell.count > 0:
                    total_orbs += 1
                
                if cell.player == Player.RED:
                    red_exists = True
                elif cell.player == Player.BLUE:
                    blue_exists = True
                
                if red_exists and blue_exists:
                    return  # Both players still have orbs
        
        # Only declare a winner if the game has progressed beyond initial moves
        # This ensures both players have had a chance to place orbs
        if total_orbs > 1:
            if red_exists and not blue_exists:
                self.state.winner = Player.RED
            elif blue_exists and not red_exists:
                self.state.winner = Player.BLUE
            else:
                self.state.winner = None
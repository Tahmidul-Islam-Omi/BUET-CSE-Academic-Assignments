from pathlib import Path
import os
from typing import Optional
from .models import GameState, Player, Cell

class FileHandler:
    def __init__(self, file_path: str = None):
        # Use /tmp directory for Render or environment variable if set
        if file_path is None:
            # Check if we're on Render and use the appropriate directory
            if os.environ.get("RENDER"):
                # Use Render's persistent storage directory if available
                render_data_dir = os.environ.get("RENDER_DATA_DIR", "/tmp")
                self.file_path = Path(render_data_dir) / "gamestate.txt"
            else:
                # Use the default location for local development
                self.file_path = Path("gamestate.txt")
        else:
            self.file_path = Path(file_path)
        
        # Ensure the directory exists
        self.file_path.parent.mkdir(parents=True, exist_ok=True)

    def read_state(self) -> Optional[GameState]:
        """Read game state from file"""
        if not self.file_path.exists():
            return None
            
        with open(self.file_path, 'r') as f:
            lines = f.readlines()
            
        if not lines or not lines[0].startswith(("Human Move:", "AI Move:")):
            return None
            
        state = GameState()
        for i, line in enumerate(lines[1:10]):  # Read 9 rows
            cells = line.strip().split()
            for j, cell_str in enumerate(cells[:6]):  # Read 6 columns
                if cell_str == "0":
                    state.board[i][j] = Cell()
                else:
                    count = int(cell_str[:-1])
                    player = Player(cell_str[-1])
                    state.board[i][j] = Cell(count, player)
        
        return state

    def write_state(self, state: GameState, is_human_move: bool):
        """Write game state to file"""
        with open(self.file_path, 'w') as f:
            f.write("Human Move:\n" if is_human_move else "AI Move:\n")
            for row in state.board:
                f.write(" ".join(str(cell) for cell in row) + "\n")
            f.write("\n")
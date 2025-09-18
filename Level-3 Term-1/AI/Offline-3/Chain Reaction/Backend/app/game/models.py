from enum import Enum

class Player(str, Enum):
    RED = "R"
    BLUE = "B"

class Cell:
    def __init__(self, count: int = 0, player: Player | None = None):
        self.count = count
        self.player = player

    def __str__(self):
        return f"{self.count}{self.player.value}" if self.player else "0"

class GameState:
    def __init__(self, rows: int = 9, cols: int = 6):
        self.rows = rows
        self.cols = cols
        self.board = []
        for _ in range(rows):
            row = []
            for _ in range(cols):      
                row.append(Cell())     
            self.board.append(row)
        self.current_player = Player.RED
        self.winner: Player | None = None

    def get_critical_mass(self, row: int, col: int) -> int:
        """Returns the critical mass for a cell at (row, col)"""
        if (row == 0 or row == self.rows - 1) and (col == 0 or col == self.cols - 1):
            return 2  # Corner
        elif row == 0 or row == self.rows - 1 or col == 0 or col == self.cols - 1:
            return 3  # Edge
        return 4  # Middle
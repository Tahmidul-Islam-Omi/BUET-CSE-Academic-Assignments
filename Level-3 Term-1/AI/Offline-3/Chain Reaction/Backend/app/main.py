from fastapi import FastAPI, HTTPException
from fastapi.responses import JSONResponse
from fastapi.middleware.cors import CORSMiddleware
from .game.models import GameState
from .game.engine import GameEngine
from .game.ai import AIPlayer
from .game.file_handler import FileHandler

app = FastAPI()

# Configure CORS
app.add_middleware(
    CORSMiddleware,
    allow_origins=["*"],
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)

file_handler = FileHandler()

@app.get("/")
async def read_root():
    """Root endpoint to test if the backend is running"""
    return JSONResponse(
        status_code=200,
        content={"message": "Chain Reaction Game is running!"}
    )

# Initialize AI with the critical_mass heuristic as default
ai_player = AIPlayer(depth=3, heuristic_type="orb_count")

@app.get("/api/new-game")
def new_game():
    """Start a new game"""
    state = GameState()
    file_handler.write_state(state, is_human_move=True)
    return {"message": "New game started", "current_player": "R"}

@app.get("/api/make-move")
def make_move(row: int, col: int):
    """Make a human move and trigger AI response"""
    state = file_handler.read_state()
    if not state:
        raise HTTPException(status_code=400, detail="Game not initialized")
    
    if state.winner:
        raise HTTPException(status_code=400, detail=f"Game already won by {state.winner}")
    
    if state.current_player != "R":  # Assuming human is always RED
        raise HTTPException(status_code=400, detail="Not your turn")
    
    engine = GameEngine(state)
    if not engine.make_move(row, col, state.current_player):
        raise HTTPException(status_code=400, detail="Invalid move")
    
    # Write human move to file
    file_handler.write_state(state, is_human_move=True)
    
    # If game continues, make AI move
    if not state.winner:
        best_move = ai_player.get_best_move(state)
        ai_row, ai_col = best_move
        engine.make_move(ai_row, ai_col, state.current_player)
        file_handler.write_state(state, is_human_move=False)
    
    return {
        "board": [[str(cell) for cell in row] for row in state.board],
        "current_player": state.current_player,
        "winner": state.winner
    }

@app.get("/api/game-state")
def get_game_state():
    """Get current game state"""
    state = file_handler.read_state()
    if not state:
        raise HTTPException(status_code=404, detail="Game not found")
    
    return {
        "board": [[str(cell) for cell in row] for row in state.board],
        "current_player": state.current_player,
        "winner": state.winner
    }
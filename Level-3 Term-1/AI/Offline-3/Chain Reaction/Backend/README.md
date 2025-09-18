# Chain Reaction Backend

This is the backend for the Chain Reaction game, ready to be deployed on Render.

## File-Based Communication

This application uses file-based communication for game state management. On Render, a persistent disk is configured to store the game state file.

## Deployment on Render

### Automatic Deployment with render.yaml

If you have the `render.yaml` file in your repository, you can use Render Blueprints for automatic deployment:

1. Push your code to GitHub
2. Go to the Render Dashboard
3. Click on "New" and select "Blueprint"
4. Connect your repository
5. Render will automatically detect the `render.yaml` file and set up your services with the persistent disk

## API Endpoints

- `GET /api/new-game`: Start a new game
- `GET /api/make-move?row={row}&col={col}`: Make a move at the specified position
- `GET /api/game-state`: Get the current game state 
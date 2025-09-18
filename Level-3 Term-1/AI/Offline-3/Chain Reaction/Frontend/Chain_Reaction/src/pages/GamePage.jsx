import { useState, useEffect } from 'react';
import { Box, Container, CircularProgress, Alert, Snackbar, Paper, Typography } from '@mui/material';
import { ThemeProvider } from '@mui/material/styles';
import { motion } from 'framer-motion';
import GameBoard from '../components/GameBoard';
import GameControls from '../components/GameControls';
import GameRules from '../components/GameRules';
import theme from '../theme';
import { startNewGame, makeMove, getGameState } from '../services/api';

const GamePage = () => {
  const [gameData, setGameData] = useState({
    board: Array(9).fill(Array(6).fill('0')),
    current_player: 'R',
    winner: null
  });
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);
  const [gameStatus, setGameStatus] = useState('initializing'); // 'initializing', 'active', 'ended'
  const [rulesOpen, setRulesOpen] = useState(false);

  // Initialize game on component mount
  useEffect(() => {
    fetchGameState();
  }, []);

  // Fetch current game state from the backend
  const fetchGameState = async () => {
    setLoading(true);
    try {
      const data = await getGameState();
      console.log('Game state data received:', data);
      
      // Use the data directly without transformation
      setGameData(data);
      console.log('Game data after setting:', data);
      
      setGameStatus(data.winner ? 'ended' : 'active');
    } catch (error) {
      // If no game exists, start a new one
      if (error.response && error.response.status === 404) {
        await handleNewGame();
      } else {
        setError('Failed to connect to the game server. Please try again.');
        setTimeout(() => setError(null), 5000);
      }
    } finally {
      setLoading(false);
    }
  };

  // Start a new game
  const handleNewGame = async () => {
    setLoading(true);
    try {
      const newGameResponse = await startNewGame();
      console.log('New game response:', newGameResponse);
      
      // Set the current player from the new game response directly
      setGameData(prevData => ({
        ...prevData,
        current_player: newGameResponse.current_player
      }));
      
      const data = await getGameState();
      console.log('Game state after new game:', data);
      
      // Use the data directly without transformation
      setGameData(data);
      console.log('Game data after new game and setting:', data);
      
      setGameStatus('active');
    } catch (error) {
      setError('Failed to start a new game. Please try again.');
      setTimeout(() => setError(null), 5000);
    } finally {
      setLoading(false);
    }
  };

  // Handle cell click (player move)
  const handleCellClick = async (row, col) => {
    // Prevent moves if game is not active or it's not the player's turn
    if (gameStatus !== 'active' || gameData.current_player !== 'R') {
      return;
    }

    setLoading(true);
    try {
      const data = await makeMove(row, col);
      setGameData(data);
      if (data.winner) {
        setGameStatus('ended');
      }
    } catch (error) {
      if (error.response && error.response.data && error.response.data.detail) {
        setError(error.response.data.detail);
      } else {
        setError('Invalid move or server error. Please try again.');
      }
      setTimeout(() => setError(null), 3000);
    } finally {
      setLoading(false);
    }
  };

  const handleRulesOpen = () => {
    setRulesOpen(true);
  };

  const handleRulesClose = () => {
    setRulesOpen(false);
  };

  return (
    <ThemeProvider theme={theme}>
      <Box
        sx={{
          minHeight: '100vh',
          display: 'flex',
          flexDirection: 'column',
          backgroundColor: 'background.default',
          position: 'relative',
          overflow: 'hidden',
        }}
      >
        {/* Background pattern */}
        <Box
          sx={{
            position: 'absolute',
            top: 0,
            left: 0,
            right: 0,
            bottom: 0,
            opacity: 0.03,
            backgroundImage: 'radial-gradient(#4a148c 2px, transparent 2px)',
            backgroundSize: '30px 30px',
            zIndex: 0,
          }}
        />

        <Container maxWidth="md" sx={{ py: 4, position: 'relative', zIndex: 1 }}>
          <motion.div
            initial={{ opacity: 0, y: 20 }}
            animate={{ opacity: 1, y: 0 }}
            transition={{ duration: 0.5 }}
          >
            <GameControls
              onNewGame={handleNewGame}
              onRulesOpen={handleRulesOpen}
              gameStatus={gameStatus}
              winner={gameData.winner}
              currentPlayer={gameData.current_player}
            />
            
            {loading ? (
              <Box sx={{ display: 'flex', justifyContent: 'center', my: 8 }}>
                <CircularProgress />
              </Box>
            ) : (
              <GameBoard
                board={gameData.board}
                currentPlayer={gameData.current_player}
                onCellClick={handleCellClick}
                gameStatus={gameStatus}
              />
            )}
            
            {gameStatus === 'ended' && (
              <Paper
                component={motion.div}
                initial={{ opacity: 0, scale: 0.8 }}
                animate={{ opacity: 1, scale: 1 }}
                transition={{ duration: 0.5 }}
                elevation={3}
                sx={{
                  p: 3,
                  mt: 4,
                  textAlign: 'center',
                  borderRadius: 2,
                  backgroundColor: gameData.winner === 'R' ? 'rgba(244, 67, 54, 0.1)' : 'rgba(33, 150, 243, 0.1)',
                  border: '1px solid',
                  borderColor: gameData.winner === 'R' ? '#f44336' : '#2196f3',
                }}
              >
                <Typography
                  variant="h4"
                  sx={{
                    fontWeight: 'bold',
                    color: gameData.winner === 'R' ? '#f44336' : '#2196f3',
                  }}
                >
                  {gameData.winner === 'R' ? 'Red Player Wins!' : 'Blue Player Wins!'}
                </Typography>
              </Paper>
            )}
          </motion.div>
        </Container>

        <GameRules open={rulesOpen} onClose={handleRulesClose} />

        <Snackbar open={!!error} autoHideDuration={6000} onClose={() => setError(null)}>
          <Alert onClose={() => setError(null)} severity="error" variant="filled">
            {error}
          </Alert>
        </Snackbar>
      </Box>
    </ThemeProvider>
  );
};

export default GamePage; 
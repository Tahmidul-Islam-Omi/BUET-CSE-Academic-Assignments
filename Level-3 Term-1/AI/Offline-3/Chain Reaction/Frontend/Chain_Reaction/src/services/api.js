import axios from 'axios';

const API_BASE_URL = 'http://localhost:8000/api';

const api = axios.create({
  baseURL: API_BASE_URL,
  headers: {
    'Content-Type': 'application/json',
  },
});

export const startNewGame = async () => {
  try {
    const response = await api.get('/new-game');
    return response.data;
  } catch (error) {
    console.error('Error starting new game:', error);
    throw error;
  }
};

export const makeMove = async (row, col) => {
  try {
    const response = await api.get(`/make-move?row=${row}&col=${col}`);
    return response.data;
  } catch (error) {
    console.error('Error making move:', error);
    throw error;
  }
};

export const getGameState = async () => {
  try {
    const response = await api.get('/game-state');
    return response.data;
  } catch (error) {
    console.error('Error getting game state:', error);
    throw error;
  }
};

export default api;
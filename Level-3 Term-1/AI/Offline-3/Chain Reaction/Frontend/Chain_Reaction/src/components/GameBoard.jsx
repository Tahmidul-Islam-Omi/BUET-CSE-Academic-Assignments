import { Box, Grid, Typography, useTheme } from '@mui/material';
import GameCell from './GameCell';
import { useState, useEffect } from 'react';
import { motion } from 'framer-motion';

const GameBoard = ({ board, currentPlayer, onCellClick, gameStatus }) => {
  const theme = useTheme();
  const [selectedCell, setSelectedCell] = useState(null);
  const [lastMove, setLastMove] = useState(null);
  
  console.log('GameBoard received currentPlayer:', currentPlayer);
  
  // Reset selected cell when board changes
  useEffect(() => {
    setSelectedCell(null);
  }, [board]);
  
  const handleCellClick = (row, col) => {
    console.log(`Cell clicked: (${row}, ${col})`);
    setSelectedCell({ row, col });
    setLastMove({ row, col });
    onCellClick(row, col);
  };
  
  const isGameActive = gameStatus === 'active';
  
  // Ensure board is properly formatted
  const formattedBoard = Array.isArray(board) ? 
    board : Array(9).fill().map(() => Array(6).fill('0'));
  
  console.log('Board data:', formattedBoard);
  
  const containerVariants = {
    hidden: { opacity: 0 },
    visible: { 
      opacity: 1,
      transition: { 
        staggerChildren: 0.03,
        delayChildren: 0.1
      }
    }
  };
  
  const cellVariants = {
    hidden: { scale: 0.8, opacity: 0 },
    visible: { 
      scale: 1, 
      opacity: 1,
      transition: { 
        type: 'spring',
        stiffness: 300,
        damping: 15
      }
    }
  };
  
  return (
    <Box 
      sx={{ 
        width: '100%',
        maxWidth: 480,
        mx: 'auto',
        p: 2,
        perspective: '1000px'
      }}
    >
      <motion.div
        initial={{ rotateX: 25, scale: 0.9 }}
        animate={{ rotateX: 0, scale: 1 }}
        transition={{ duration: 0.8, ease: 'easeOut' }}
      >
        <Box 
          sx={{
            backgroundColor: theme.palette.background.paper,
            borderRadius: 2,
            p: 2,
            boxShadow: '0px 10px 40px rgba(0, 0, 0, 0.1)',
            border: '1px solid',
            borderColor: theme.palette.divider,
            overflow: 'hidden',
          }}
        >
          <motion.div
            variants={containerVariants}
            initial="hidden"
            animate="visible"
          >
            <Grid container spacing={1}>
              {formattedBoard.map((row, rowIndex) => (
                row.map((cell, colIndex) => (
                  <Grid item xs={2} key={`${rowIndex}-${colIndex}`}>
                    <motion.div variants={cellVariants}>
                      <GameCell 
                        cellData={cell}
                        row={rowIndex}
                        col={colIndex}
                        onCellClick={handleCellClick}
                        isActive={
                          selectedCell && 
                          selectedCell.row === rowIndex && 
                          selectedCell.col === colIndex
                        }
                        isCritical={false}
                      />
                    </motion.div>
                  </Grid>
                ))
              ))}
            </Grid>
          </motion.div>
        </Box>
      </motion.div>
      
      <Box sx={{ mt: 2, textAlign: 'center' }}>
        <Typography variant="body2" color="text.secondary">
          {isGameActive 
            ? `Current Player: ${currentPlayer === 'R' ? 'Red' : 'Blue'}`
            : `Game Over`}
        </Typography>
      </Box>
    </Box>
  );
};

export default GameBoard; 
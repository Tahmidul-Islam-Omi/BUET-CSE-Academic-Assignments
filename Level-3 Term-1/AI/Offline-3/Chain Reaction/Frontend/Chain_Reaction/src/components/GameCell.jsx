import { Box, Typography } from '@mui/material';
import { motion } from 'framer-motion';
import { useState, useEffect } from 'react';

const GameCell = ({ cellData, row, col, onCellClick, isActive, isCritical }) => {
  const [animate, setAnimate] = useState(false);
  
  // Extract player and count from cell data (format: "0" or "1R" or "2B" etc.)
  let count = 0;
  let player = null;
  
  if (cellData && cellData !== "0") {
    count = parseInt(cellData.substring(0, cellData.length - 1));
    player = cellData.charAt(cellData.length - 1);
  }
  
  const isCorner = (row === 0 || row === 8) && (col === 0 || col === 5);
  const isEdge = (row === 0 || row === 8 || col === 0 || col === 5) && !isCorner;
  
  useEffect(() => {
    if (count > 0) {
      setAnimate(true);
      const timer = setTimeout(() => setAnimate(false), 300);
      return () => clearTimeout(timer);
    }
  }, [count]);
  
  const getPlayerColor = () => {
    if (player === 'R') return '#f44336';
    if (player === 'B') return '#2196f3';
    return '#9e9e9e';
  };
  
  const getCellStyle = () => {
    const borderRadius = isCorner ? '16px' : isEdge ? '8px' : '0px';
    const style = {
      width: 60,
      height: 60,
      display: 'flex',
      justifyContent: 'center',
      alignItems: 'center',
      position: 'relative',
      borderRadius,
      backgroundColor: isActive ? 'rgba(255, 255, 255, 0.15)' : 'transparent',
      border: '1px solid',
      borderColor: isCritical ? '#f44336' : '#e0e0e0',
      cursor: 'pointer',
      transition: 'all 0.2s ease-in-out',
      '&:hover': {
        backgroundColor: 'rgba(255, 255, 255, 0.1)',
        transform: 'scale(1.05)',
      },
    };
    
    return style;
  };
  
  const handleClick = (e) => {
    e.preventDefault();
    e.stopPropagation();
    console.log(`Cell ${row},${col} clicked directly`);
    onCellClick(row, col);
  };
  
  const renderOrbs = () => {
    if (count === 0) return null;
    
    // Position orbs based on count and cell type
    switch(count) {
      case 1:
        return (
          <Box sx={{ 
            position: 'absolute', 
            top: '50%', 
            left: '50%', 
            transform: 'translate(-50%, -50%)'
          }}>
            <Orb player={player} animate={animate} />
          </Box>
        );
      case 2:
        return (
          <>
            <Box sx={{ 
              position: 'absolute', 
              top: '35%', 
              left: '35%', 
              transform: 'translate(-50%, -50%)'
            }}>
              <Orb player={player} animate={animate} />
            </Box>
            <Box sx={{ 
              position: 'absolute', 
              top: '65%', 
              left: '65%', 
              transform: 'translate(-50%, -50%)'
            }}>
              <Orb player={player} animate={animate} />
            </Box>
          </>
        );
      case 3:
        return (
          <>
            <Box sx={{ 
              position: 'absolute', 
              top: '30%', 
              left: '30%', 
              transform: 'translate(-50%, -50%)'
            }}>
              <Orb player={player} animate={animate} />
            </Box>
            <Box sx={{ 
              position: 'absolute', 
              top: '30%', 
              left: '70%', 
              transform: 'translate(-50%, -50%)'
            }}>
              <Orb player={player} animate={animate} />
            </Box>
            <Box sx={{ 
              position: 'absolute', 
              top: '70%', 
              left: '50%', 
              transform: 'translate(-50%, -50%)'
            }}>
              <Orb player={player} animate={animate} />
            </Box>
          </>
        );
      default:
        return (
          <>
            <Box sx={{ 
              position: 'absolute', 
              top: '30%', 
              left: '30%', 
              transform: 'translate(-50%, -50%)'
            }}>
              <Orb player={player} animate={animate} />
            </Box>
            <Box sx={{ 
              position: 'absolute', 
              top: '30%', 
              left: '70%', 
              transform: 'translate(-50%, -50%)'
            }}>
              <Orb player={player} animate={animate} />
            </Box>
            <Box sx={{ 
              position: 'absolute', 
              top: '70%', 
              left: '30%', 
              transform: 'translate(-50%, -50%)'
            }}>
              <Orb player={player} animate={animate} />
            </Box>
            <Box sx={{ 
              position: 'absolute', 
              top: '70%', 
              left: '70%', 
              transform: 'translate(-50%, -50%)'
            }}>
              <Orb player={player} animate={animate} />
            </Box>
          </>
        );
    }
  };
  
  return (
    <Box 
      sx={getCellStyle()}
      onClick={handleClick}
      component={motion.div}
      whileTap={{ scale: 0.95 }}
    >
      {renderOrbs()}
    </Box>
  );
};

// Orb component - a single game piece
const Orb = ({ player, animate }) => {
  const color = player === 'R' ? '#f44336' : '#2196f3';
  
  return (
    <motion.div
      initial={{ scale: animate ? 0.8 : 1 }}
      animate={{ 
        scale: [1, 1.2, 1],
        rotate: [0, 10, -10, 0]
      }}
      transition={{ 
        duration: 0.3,
        ease: "easeInOut",
        times: [0, 0.5, 1]
      }}
    >
      <Box
        sx={{
          width: 16,
          height: 16,
          borderRadius: '50%',
          backgroundColor: color,
          boxShadow: `0 0 10px 2px ${player === 'R' ? 'rgba(244, 67, 54, 0.5)' : 'rgba(33, 150, 243, 0.5)'}`,
        }}
      />
    </motion.div>
  );
};

export default GameCell; 